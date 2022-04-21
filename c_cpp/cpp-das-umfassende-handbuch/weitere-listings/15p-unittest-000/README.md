Dieses Beispiel dient hauptsächlich dem Zweck, ein komplettes Projekt für Unittests fit zu halten.
Daher ist das `test` Unterverzeichnis von besonderem Interesse.

Es wird einfach mit `make` gebaut, denn es wurde manuell per `Makefile`s gesteuert. Das
Layout des Projektes ist jedoch für den [Einsatz mit *CMake*][1] grob vorbereitet.

> You will end up with something like this:

     └── prj
         ├── CMakeLists.txt <-- (1)
         ├── include
         │   └── prj
         │       ├── header2.hpp
         │       └── header.hpp
         ├── src
         │   ├── CMakeLists.txt <-- (2)
         │   └── x.cpp
         └── test
             ├── CMakeLists.txt <-- (3)
             ├── data
             │   └── testdata.yyy
             └── testcase.cpp

[1]: http://stackoverflow.com/a/13521867/472245 "Stackoverflow: C++ project organisation (with gtest, cmake and doxygen)"

