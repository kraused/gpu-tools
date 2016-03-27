
CXX      = g++
CPPFLAGS = -I. -D_GNU_SOURCE -D'GPUMOND_BIN_PREFIX="/usr/sbin"'
CXXFLAGS = -fno-exceptions -fno-rtti -fPIC -Wall -O0 -ggdb
LD       = g++
LDFLAGS  = -fno-exceptions -fno-rtti -fPIC -Wl,-export-dynamic -O0 -ggdb
LIBS     = -ldl

Q = @

default: all

all: gpumond-watchman.so

%.o: %.cxx
	$(Q)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<
	@echo "CXX $@"

%.so: %.o
	$(Q)$(CXX) $(LDFLAGS) -shared -o $@ $<
	@echo "CXX $@"

install:
	install -m0755 -d $(PREFIX)/usr/libexec/gpumond/
	install -m0755 -d $(PREFIX)/usr/lib/systemd/system/
	install -m0755 gpumond-watchman.so	$(PREFIX)/usr/libexec/gpumond/gpumond-watchman.so
	install -m0644 gpumond.service		$(PREFIX)/usr/lib/systemd/system/gpumond.service

clean:
	-rm -f *.o *.so

