FI MUNI - C and C++ examples
============================

Examples related to talks at FI MUNI.
Georgik's blog: http://georgik.sinusgear.com

Allegro
-------

Allegro is library for interactive applications like games written in C.

Three examples for Allegro 5.0 library.
- example-01 - display smiley
- example-02 - display smiley when pressed space
- example-03 - smiley follows mouse

Requirements: Allegro 5.0 (works also with 5.1)
Package for Debian: liballegro5-dev

How to run:

    cd allegro
    make
    ./example-01
    ./example-02
    ./example-03

Check - unit test
-----------------

Check is unit testing framework for C: http://check.sourceforge.net/

This directory contains simple example. You can uncomment age++ to create bug and rerun tests.

How to run:

    cd check
    make
    ./test

curl
----

curl command line tool for sending requests via http and many other protocols.
It is also able to create skeleton of C application for libcurl.

How to run:

    cd curl
    ./generate-source-code.sh
    ./compile-source-code.sh
    ./download
    

GTK+
----

GTK+ is library for GUI applications written in C. 
It has also bindings for many other languages.

Helloworld example from http://en.wikipedia.org/wiki/Gtk.
Requires: GTK+-3
Package for Debian: libgtk-3-dev

How to run:

    cd gtk
    make
    ./helloworld

Gradle
------

Example of building C/C++ project by Gradle.
Gradle is using build.gradle file in main project directory.
Check out project layout. Source code is stored in src/main/cpp, 
because gradle is using "Build by convention".
No further configuration is needed.
Gradle is able to determine compiler chain and use available compiler, e.g. g++ or Visual Studio.

Note for Visual Studio 2013: Use Gradle at least night build 1.10-20131122

How to run:

    cd gradle/hellomuni
    gradle mainExecutable
    cd build/binaries/mainExecutable
    ./hellomuni


Gradle with wrapper
-------------------

In gradle/hellomuni example you have to download and install Gradle manually.
Gradle projects are often sometimes with wrapper which downloads all necessary file with Gradle.
It's sufficient to start wrapper and then you can work with local instance of Gradle.
This is useful when you want to fix version of Gradle or simplify bootstrap process.

How to run:

    cd gradle/hello-with-wrapper
    ./gradlew mainExecutable  (or .\gradle.bat mainExecutable for PowerShell)
    cd build/binaries/mainExecutable
    ./hello-with-wrapper

Minunit testing
---------------

Minunit is very minimalistic C testing framework. It contains just two lines of code.

How to run:

    cd minunit
    make
    ./test

node
----

Example from Node.js web site. Create simple server.

How to run:

    cd node.js
    node echo-server.js

Objective-C
-----------

Objective-C is primary programing language for Apple world.
This is ismple Hello Muni example. Open this project in Xcode.

How to run:

    cd objective-c
    open hellomuni.xcodeproj

uv
--

libuv is library which has support for event loops, networking and many other
features required by cloud computing. This library is core part of Node.js.

Requires: libuv (part of Node.js)
Package for Debian: none, you need to build it from sources. You can use Node.js package.

How to run hello example:

    cd libuv/hello
    make
    ./hello

How to run echo_server example:

    cd libuv/echo_server
    make
    ./echo_server

Note: Do not forget to set LD_LIBRARY_PATH so the linker will be able to locate libuv
 E.g.: export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
