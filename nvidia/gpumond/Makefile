
VERSION    = 2
PATCHLEVEL = 0

CC       = gcc
CPPFLAGS = -I. -D_GNU_SOURCE
CCFLAGS  = -Wall -O0 -ggdb -std=gnu11
LD       = gcc
LDFLAGS  = -O0 -ggdb -L/usr/src/gdk/nvml/lib
LIBS     = -lnvidia-ml

Q = @

default: all

all: gpumond.exe

gpumond.exe: main.o gpumond.o alloc.o logging.o output.o monitor.o helper.o nvmlapi.c
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

%.o: %.c
	$(Q)$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "CC $@"

tar:
	python2 tar.py gpumond $(VERSION).$(PATCHLEVEL)

install:
	install -m0755 -d $(PREFIX)/usr/sbin
	install -m0755 gpumond.exe	$(PREFIX)/usr/sbin/gpumond.exe

clean:
	-rm -f *.o gpumond.exe

