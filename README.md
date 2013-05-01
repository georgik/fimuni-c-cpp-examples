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

node
----

Example from Node.js web site. Create simple server.

How to run:

    cd node.js
    node echo-server.js

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
