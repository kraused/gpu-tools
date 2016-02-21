
CC       = gcc
CPPFLAGS = -I. -D_GNU_SOURCE -DDEBUG=1
CCFLAGS  = -O0 -ggdb
LD       = gcc
LDFLAGS  = -O0 -ggdb -L/usr/src/gdk/nvml/lib
LIBS     = -lnvidia-ml

Q = @

default: all

all: nvutil001.exe nvutil002.exe nvutil003.exe nvutil004.exe nvutil005.exe nvutil006.exe nvutil007.exe

nvutil%.exe: nvutil%.o common.o
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

%.o: %.c
	$(Q)$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "CC $@"

clean:
	-rm -f *.o *.exe

