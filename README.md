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

### 01-hello-muni ###

Example of building C/C++ project by Gradle.
Gradle is using build.gradle file in main project directory.
Check out project layout. Source code is stored in src/main/cpp, 
because gradle is using "Build by convention".
No further configuration is needed.
Gradle is able to determine compiler chain and use available compiler, e.g. g++ or Visual Studio.

Note for Visual Studio 2013: Use Gradle at least night build 1.10-20131122230018

How to run:

    cd gradle/01-hello-muni
    gradle mainExecutable
    cd build/binaries/mainExecutable
    ./01-hello-muni


### 02-hello-muni-with-gradle-wrapper ###

It's not necessary to download Gradle manually like in previous example.
Gradle projects are sometimes provided with wrapper which downloads all necessary files with Gradle.
It's sufficient to start wrapper and then you can work with local instance of Gradle.
This is useful when you want to fix version of Gradle or simplify bootstrap process.

Configuration file in gradle/hello-with-wrapper/gradle contains reference to Gradle with VS 2013
support.

How to run:

    cd gradle/02-hello-muni-with-gradle-wrapper
    ./gradlew mainExecutable  (or .\gradle.bat mainExecutable for PowerShell)
    cd build/binaries/mainExecutable
    ./02-hello-muni-with-gradle-wrapper

### 03-hello-muni-with-debug ###

Current implementation of C++ support in Gradle is in early stage, but it's very promising.
This example shows how to update build script to add debug flags for compilers like GCC or VS.

How to run:

    cd gradle/03-hello-muni-with-debug
    gradle mainExecutable
    cd build/binaries/mainExecutable
    ./03-hello-muni-with-debug

Minunit testing
---------------

Minunit is very minimalistic C testing framework. It contains just two lines of code.

How to run:

    cd minunit
    make
    ./test

REST SDK
--------

Example based on C++ REST SDK - Casablanca which has support for asynchronous calls.
Documentation: http://msdn.microsoft.com/en-us/library/jj969455.aspx
Project page: https://casablanca.codeplex.com/
This example requires Visual Studio 2013 with NuGet.

How to run (PowerShell + VS 2013):

    cd rest\rest-client
    ii rest-client.sln
    right click the project and select: Manage NuGet Packages for solution
    restore C++ REST SDK
    CTRL+F5 to run the project

## Simple DirectMedia Layer 2

SDL2 is multiplatform library suitable for developing applications like games.
You can use Gradle to build SDL2 examples.

### Preparing dependencies for Windows

Root project contains reference to SDL2 library. Type:

    gradle prepare

It will download Windows version of SDL2 library for all projects.
Libraries will be placed in directory build.
Now you can build earch of subprojects.

### 01-sdl2-init

Simple example - init and quit SDL.
How to build:

    gradle clean mainExecutable

Shorter version:

    gradle clean mE

It is possible to generate project for Visual Studio:

    gradle mainVisualStudio

Compiled binary will be stored in:

    build/binaries/mainExecutable

Copy required resources/dll to mainExecutable by command:

    gradle prepare

### 02-sdl2-video

Graphic initialization example for SDL2.
Initialize graphic interface, load BMP file and display it.

Commands (PowerShell):

    gradle prepare mE
    cd build\binaries\mainExecutable
    .\main.exe

Commands (Shell):

    gradle prepare mE
    cd build/binaries/mainExecutable
    ./main

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
