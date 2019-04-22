
# Path to a minipmi installation (see github.com/kraused/minipmi)
MINIPMI  = $(PWD)/minipmi
# Patch to the CUDA installation. This is system dependent
CUDA     = $(shell ${LMOD_CMD} load intel-para CUDA | sed -n -e 's/EBROOTCUDA="\(.*\)";/\1/p')

CC       = gcc
MPICC    = mpic++
CPPFLAGS = -I. -I$(CUDA)/include -I$(MINIPMI) -D_GNU_SOURCE -DDEBUG=1
CCFLAGS  = -O0 -ggdb -Wall
LD       = gcc
MPILD    = mpic++
LDFLAGS  = -O0 -ggdb -L/usr/src/gdk/nvml/lib -L$(CUDA)/lib -L$(MINIPMI)
LIBS     = -lnvidia-ml -lcuda -lminipmi -libverbs

Q = @

default: all

all: cuutil001.exe cuutil002.exe cuutil003.exe cuutil004.exe

cuutil003.exe: cuutil003.o 
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS) -lcudart
	@echo "LD $@"

cuutil004.exe: cuutil004.o 
	$(Q)$(MPILD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

cuutil%.exe: cuutil%.o common.o cudaapi.o
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "LD $@"

cuutil004.o: cuutil004.c
	$(Q)$(MPICC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "MPICC $@"

%.o: %.c
	$(Q)$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
	@echo "CC $@"

clean:
	-rm -f *.o *.exe

