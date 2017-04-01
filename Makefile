#
# Created by gmakemake (Sparc Jan 11 2011) on Wed Jan 12 20:21:33 2011
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c

########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb $(shell pkg-config --cflags dbus-cxx-1.0)
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	$(shell pkg-config --libs dbus-cxx-1.0)
########## End of default flags


CPP_FILES =	receive.cpp send.cpp
C_FILES =	
S_FILES =	
H_FILES =	
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	

#
# Main targets
#

all:	receive send

receive:	receive.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o receive receive.o $(OBJFILES) $(CCLIBFLAGS)

send:   send.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o send send.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

receive.o:	

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) send.o receive.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf receive send
