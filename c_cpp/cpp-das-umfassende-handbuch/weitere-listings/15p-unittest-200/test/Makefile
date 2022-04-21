# conventience:
TARGET:=\
	testImplMultimap.x \
	testQwort.x
all: $(TARGET) check

include ../all.mk

# declarations
LIBDIR:=../src/lib
LIB:=qwort
INCDIR:=../include
# - wo habe ich die Boost-Includes?
BOOSTCXXFLAGS:=-I/home/towi/src/gcc/boost/boost_1_61_0/ -Wno-placement-new
# - wo habe ich die Boost-Libs? Für die Unittests brauche ich die nicht, also sowieso leer.
BOOSTLDFLAGS:=

# standard envs:
# - note: we add LIBDIR as include-dir because the unittests also test private stuff
CXXFLAGS:=-I$(INCDIR) $(BOOSTCXXFLAGS)  -I$(LIBDIR) -Wall -pedantic
LDFLAGS:=-L$(LIBDIR) -l$(LIB) $(BOOSTLDFLAGS)

unittest: check

RUNARGS:=--report_level=detailed --log_level=all
#RUNARGS:=--report_level=short

check: $(TARGET)
	for trg in $+ ; do \
		echo === Testing $$trg... === ; \
		./$$trg $(RUNARGS) \
			|| exit 1 ; \
	done

%.x: %.cpp $(LIBDIR)/$(LIB).a
	$(CXX) -static -o $@ $< $(CXXFLAGS) $(LDFLAGS)

# if library is missing, build it
$(LIBDIR)/$(LIB).a:
	$(MAKE) -C $(LIBDIR)
