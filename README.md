Unbox
=====

Introduction
------------

Unbox is a GPLv3 licensed version of the J programming language interpreter derived from the initial J Software source release. The goals of this project are to provide bug fixes in the short term and language enhancements and new features in the long term. Although this is intended to be used as a drop in replacement for the J shared library the behavior of the interpreter and the definition of the language itself will likely diverge from the official J Software version over time.

Building
--------

### Prerequisites

1. Unbox uses the tup build system. [Install tup for your platform](http://gittup.org/tup/index.html).
2. Clone the repository
3. Edit tup.config
   + `CONFIG_RELEASE`: toggle the optimizations / debugging information
   + `CONFIG_TEST`: toggle whether or not to run the test script suite after a successful build
   + `CONFIG_CLANG`: y to use clang instead of gcc on Linux
   + `CONFIG_X86_64`: toggle 64/32 bit build
   + `CONFIG_READLINE`: toggle readline support for jconsole on Linux

### Linux

1. Make sure tup is in your PATH
2. Type `tup` in the working directory

### Windows (Visual Studio 2013 Community)

1. Make sure tup is in your PATH
2. From the Visual Studio Tools folder run the command prompt appropriate for your build
3. Change to the Unbox source directory and type `tup`

### Mac

I do not have access to a Mac and have not tried building this yet. If you are a Mac user, please test and report your results and I will update this section.

Tests
-----

To run the test suite set the `CONFIG_TEST=y` in tup.config and rerun tup.

If a test fails run `bin/jconsole -debug test/<path-to-test>` to see where the failure is occuring.

Contributing
------------

If you would like to contribute code changes, you can either send a patch or commit to 
the `develop` branch in your local repository and submit a pull request.
