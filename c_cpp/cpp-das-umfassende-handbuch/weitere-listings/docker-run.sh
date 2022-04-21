#!/bin/bash

set -u # no undefs
set -e # exit immediatly in pipes

# Das erste "if true" entscheidet, welcher Compiler genommen wird.
# Default ist der letzte und das ist gcc9

if true
then
    docker run --rm -i -t --volume $PWD:/workdir --workdir /workdir clang9 $*
else
    docker run --rm -i -t --volume $PWD:/workdir --workdir /workdir gcc9 $*
fi
