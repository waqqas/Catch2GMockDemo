Introduction
===

This is demo app to integrate Catch2 with GMock

git submodule add https://github.com/google/googletest.git

git submodule add https://github.com/catchorg/Catch2.git

Downloading
===

- git clone --recurse-submodules https://github.com/waqqas/Catch2GMockDemo
OR
- git clone https://github.com/waqqas/Catch2GMockDemo
- git submodule update --remote --init

Building
===

- cd Catch2GMockDemo
- mkdir build
- cd build
- cmake ..
- make


Running app
===


- pwd (should be build)
- ./demo

Running unit-tests
===

- pwd (should be build)
- ./demo test


