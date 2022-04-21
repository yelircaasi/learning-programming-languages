# Makefile

########################
# Defs

TARGETS=\
	15-utest.x \
	41vector-noncopy.x \
	41moveTiming.x \
	41reversemap.x \
	41set-vector.x \
	41allocator.x \
	apply.x \
	string-to-double.x \
	userlitVartemplate.x \
	foldExpr.x \
	07double-prec.x \
	45cpp17variant.x \
	45cpp17any.x \
	45cpp17sample.x \



#############
# source suffixes:
# - %.cpp : C++17 (was: C++11)
# - %.cppp : C++17 (was: C++11) w/formatting
# - %.cxx : C++17 (was: C++14)
# - %.cxxx : C++17 (was: C++14) w/formatting
# - %.CPP : C++17/C++1z
# - %.CXX : C++20/C++2a
# - %.c : C

########################
# Env

pwd:=$(shell pwd)

# Compiler ändern zum Beispiel mit:
#   make -k use=gcc9

ifeq ($(use),gcc9)
    CXX=docker run --rm -i -t --volume $(pwd):/workdir --workdir /workdir gcc9 \
           g++ -ltbb
else ifeq ($(use),gcc10)
    CXX=docker run --rm -i -t --volume $(pwd):/workdir --workdir /workdir gcc10 \
           g++ -fanalyzer -ltbb
else ifeq  ($(use),clang9)
    CXX=docker run --rm -i -t --volume $(pwd):/workdir --workdir /workdir clang9 \
	  clang++ -stdlib=libc++
else ifeq  ($(use),boost)
    CXX=docker run --entrypoint echo --rm -i -t --volume $(pwd):/workdir --workdir /workdir zouzias/boost:latest \
           g++
else ifeq ($(use),docker-compile)
     CXX=./docker-compile.sh
endif

EXEC:=./docker-run.sh

CXXLIBS=-lz

CXXFLAGS=-Wall -Wextra -std=c++17 -lpthread -pthread -O0 -Wno-missing-field-initializers -g
CXX14FLAGS=-Wall -Wextra -std=c++17 -lpthread -pthread -O0 -Wno-missing-field-initializers -g
CXX17FLAGS=-Wall -Wextra -std=c++17 -lpthread -pthread -O0 -Wno-missing-field-initializers -g
CXX20FLAGS=-Wall -Wextra -std=gnu++2a -lpthread -pthread -Wno-missing-field-initializers -g


########################
# Rules

all: $(TARGETS)

%.cpp: %.cppp
	./cc1plus < $< > $@

%.cxx: %.cxxx
	./cc1plus < $< > $@

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(CXXLIBS)

%.x: %.cxx
	$(CXX) $(CXX14FLAGS) -o $@ $<

%.x: %.CPP
	$(CXX) $(CXX17FLAGS) -o $@ $<

%.x: %.CXX
	$(CXX) $(CXX20FLAGS) -o $@ $<

%.x: %.c
	$(CC) $(CFLAGS) -o $@ $< $(CLIBS)

%.x.txt: %.x
	$(EXEC) ./$< | tee $@

46-zpipe.x: 46-zpipe.c
	gcc 46-zpipe.c -o 46-zpipe.x -lz

########################
# Aux

clean:
	rm -f *.o check-report.txt
	rm -f $(TARGETS) *.x *.x.txt
	$(MAKE) -C examples clean

mrproper: clean
