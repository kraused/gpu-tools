
import os
import sys
import subprocess
import shutil
import re
import time
import datetime


#
# A copy of the haskell fst function
def fst(tpl):
	return tpl[0]

#
# A copy of the haskell snd function
def snd(tpl):
	return tpl[1]


#
# Create a process and return the handle
def createProcess(argv):
	p = subprocess.Popen(argv,
			     stdout = subprocess.PIPE,
			     stderr = subprocess.PIPE)

	return p

#
# Wait for termination of a process.
def waitForProcess(p):
	o, e = p.communicate()
	x = p.wait()

	return (x, o, e)

#
# Create a subprocess and wait for it to exit. Return the exit
# code and standard output/exit as a triplet.
def createProcessAndWait(argv):
	return waitForProcess(createProcess(argv))

#
# Variant of createProcessAndWait which does not return the exit code but
# raises an exception if the command failed.
def createProcessAndWait_(argv):
	x, o, e = createProcessAndWait(argv)
	if x:
		raise Exception("Command '%s' failed with exit code %d." % (argv, x))

	return o, e

#
# Get the short form of the HEAD commit.
def gitHeadCommit():
	return fst(createProcessAndWait_(["git", "rev-parse", "--verify", "--short", "HEAD"])).strip()

def main(name, version):
	date   = datetime.datetime.fromtimestamp(time.time()).strftime("%Y%m%d")
	commit = gitHeadCommit()
	files  = os.listdir(".")

	# Naming scheme following the Fedora naming guidelines:
	# https://fedoraproject.org/wiki/Packaging:NamingGuidelines?rd=Packaging/NamingGuidelines#NonNumericRelease
	D = "%s-%s-%sgit%s" % (name, version, date, commit)

	os.mkdir(D)
	for f in files:
		cp = None

		if ".git" == f:
			continue

		if os.path.isdir(f):
			cp = shutil.copytree
		else:
			cp = shutil.copy

		cp(f, D + "/" + f)

	createProcessAndWait_(["tar", "-czf", D + ".tar.gz", D])

	shutil.rmtree(D)

	return 0


main(sys.argv[1], sys.argv[2])

