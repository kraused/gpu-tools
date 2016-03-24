
import os
import sys
import subprocess
import re

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


def retrieveAPI(url):
	API = []

	x, o, e = createProcessAndWait(["/usr/bin/curl", "-s", url])
	
	lines = [u for u in map(lambda z: z.strip(), o.split("\n")) if u]
	lines = filter(lambda z: re.match(r'.*member_type.*', z), lines)
	
	for line in lines:
		if not re.match(r'.*<span class="member_name"><a [^>]+>([^<]*)</a>', line) or \
		   not re.match(r'.*\( (.*) \).*', line):
			continue

		func = re.match(r'.*<span class="member_name"><a [^>]+>([^<]*)</a>', line).group(1)
		args = filter(lambda z: len(z) > 0,
			map(lambda z: z.strip(),
				re.sub(r'void([^*]|$)', r'\1',
					re.sub(r'<a[^>]*>([^>]*)</a>', r'\1',
						re.sub(r'<span[^>]*>[^>]*</span>', '',
								re.match(r'.*\( (.*) \).*', line).group(1)))).split(",")))

#		# Fix a bug in the Doxygen documentation
#		for i, a in enumerate(args):
#			args[i] = re.sub(r'unsignedlong', 'unsigned long', a)

		API += [(func, args)]

	return API

def functionPrototype(func, args):
	return "void %s(%s);" % (re.sub(r'^cu(.*)', r'Nvcu_\1', func), ", ".join(args))

def functionDefinition(func, args):
	function = []

	function += ["void %s(%s)" % (re.sub(r'^cu(.*)', r'Nvcu_\1', func), ", ".join(["%s a%d" % (x, i) for i, x in enumerate(args)]))]
	function += ["{"]
	function += ["\tCUresult err;"]
	function += ["\tconst char *errName;"]
	function += ["\tconst char *errString;"]
	function += ["\terr = %s(%s);" % (func, ", ".join(["a%d" % i for i, _ in enumerate(args)]))]
	function += ["\tcuGetErrorName(err, &errName); /* Ignore error. */"]
	function += ["\tcuGetErrorString(err, &errString); /* Ignore error. */"]
	function += ["\tnvcu_return_handler(\"%s\", \"%s\", err, errName, errString);" % (re.sub(r'^nvml(.*)', r'Nvml_\1', func), func)]
	function += ["}"]

	return "\n".join(function)

pages = ["TYPES", "ERROR", "INITIALIZE", "VERSION", "DEVICE", "PRIMARY__CTX", "CTX", "MODULE", "MEM", "UNIFIED", "STREAM", "EVENT", "EXEC", "OCCUPANCY", "TEXREF", "SURFREF", "TEXOBJECT", "SURFOBJECT", "PEER__ACCESS", "GRAPHICS", "PROFILER"] #, "GL", "D3D9", "D3D10", "D3D11", "VDPAU"]

API = []

for url in ["http://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__%s.html" % p for p in pages]:
	API += retrieveAPI(url)

prototypes  = [functionPrototype (func, args)  for func, args in API]
definitions = [functionDefinition(func, args) for func, args in API]

sys.stdout.write("""\
/* Wrapper around CUDA driver API library calls.
 *
 * Generated with python2 %s.
 */

""" % " ".join(sys.argv))

if   "--prototypes"  == sys.argv[1]:
	sys.stdout.write("\n".join(prototypes) + "\n")
elif "--definitions" == sys.argv[1]:
	sys.stdout.write("\n\n".join(definitions) + "\n")
else:
	sys.stderr.write("Invalid first argument.\n")
	sys.exit(1)

