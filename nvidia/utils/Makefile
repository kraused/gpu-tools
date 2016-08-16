
CC       = gcc
CPPFLAGS = -I. -D_GNU_SOURCE -DNDEBUG=1
CCFLAGS  = -O0 -ggdb
LD       = gcc
LDFLAGS  = -O0 -ggdb -L/usr/src/gdk/nvml/lib
LIBS     = -lnvidia-ml

Q = @

default: all

all: nvutil001.exe nvutil002.exe nvutil003.exe nvutil004.exe nvutil005.exe nvutil006.exe nvutil007.exe nvutil008.exe nvutil009.exe

nvutil%.exe: nvutil%.o common.o
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

%.o: %.c
	$(Q)$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "CC $@"

install:
	install -m0755 -d $(PREFIX)/usr/bin/
	install -m0755 nvutil001.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil002.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil003.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil004.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil005.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil006.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil007.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil008.exe	$(PREFIX)/usr/bin/
	install -m0755 nvutil009.exe	$(PREFIX)/usr/bin/

clean:
	-rm -f *.o *.exe

