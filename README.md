#Introduction
===

This is demo app to integrate Catch2 with GMock

git submodule add -b release-1.8.1 https://github.com/google/googletest.git

git submodule add -b v2.5.0 https://github.com/catchorg/Catch2.git

Downloading
===

- git clone --recurse-submodules https://github.com/waqqas/Catch2GMockDemo
OR
- git clone https://github.com/waqqas/Catch2GMockDemo
- git submodule update --remote

Building
===

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


