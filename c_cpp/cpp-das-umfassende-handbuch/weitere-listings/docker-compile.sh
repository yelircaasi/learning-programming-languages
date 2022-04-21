#!/bin/bash

set -u # no undefs
set -e # exit immediatly in pipes

# Das erste "if true" entscheidet, welcher Compiler genommen wird.
# Default ist der letzte und das ist gcc9

if false
then
   docker run --rm -i -t --volume $PWD:/workdir --workdir /workdir clang9 \
	  clang++ -stdlib=libc++ $* \
       || exit 9
elif false
then
    docker run --rm -i -t --volume $PWD:/workdir --workdir /workdir gcc10 \
           g++ $* -fanalyzer -ltbb \
        || exit 9
elif false
then
        docker run --entrypoint echo --rm -i -t --volume $PWD:/workdir --workdir /workdir zouzias/boost:latest \
           g++ $* \
        || exit 9
else
    docker run --rm -i -t --volume $PWD:/workdir --workdir /workdir gcc9 \
           g++ $* -ltbb \
        || exit 9
fi

# -l tbb : intel thread building blocks for parallel stuff from #include <execution>
