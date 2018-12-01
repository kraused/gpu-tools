
VERSION    = 2
PATCHLEVEL = 0

CC       = gcc
CPPFLAGS = -D_GNU_SOURCE -I. -I$(shell pkg-config --cflags nvml-10.0)
CCFLAGS  = -Wall -O0 -ggdb -std=gnu11
LD       = gcc
LDFLAGS  = -O0 -ggdb
LIBS     = $(shell pkg-config --libs nvml-10.0)

Q = @

default: all

all: gpumond.exe

gpumond.exe: main.o gpumond.o alloc.o logging.o output.o monitor.o helper.o nvmlapi.o
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

%.o: %.c %.h
	$(Q)$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "CC $@"

tar:
	python2 tar.py gpumond $(VERSION).$(PATCHLEVEL)

install:
	install -m0755 -d $(PREFIX)/usr/sbin
	install -m0755 gpumond.exe	$(PREFIX)/usr/sbin/gpumond.exe

clean:
	-rm -f *.o gpumond.exe

