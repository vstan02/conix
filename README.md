# Conix
> A library for easy handling of command line options

[![Build Status](https://api.travis-ci.org/vstan02/conix.svg?branch=master)](https://travis-ci.org/github/vstan02/conix)
[![License: GPL v3](https://img.shields.io/badge/license-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)

## Contents
- [Building and Installation](#building-and-installation)
- [Directory structure](#directory-structure)
- [License](#license)
- [Contributing](#contributing)

## Building and Installation

### Dependencies
- C compiler (gcc, clang, etc...)
- cmake (>= 3.16)
- pkg-config (for testing)
- glib (v2.0) (for testing)

These packages can usually be installed through your distributions package manager.

### Building the project
To build the project, we first need to create a separate build directory:
```
mkdir build
```

Now that we've created our build directory (assuming it's created in the project root), we can `cd` into it and run `cmake` and pass the parent directory path to it, which is where the `CMakeLists.txt` file is located:
```
cd build
cmake ..
```

Once `cmake` is done generating makefiles, we can build the library by running `make` inside our build directory:
```
make
```

### Running demo
```
./demo
```

### Running tests
```
./test
```

### Installing
To install the library run:
```
sudo make install
```
By default the libraries and headers will be installed in `/usr/local/lib/` and `/usr/local/include` directories.

## Directory structure
- src - containing the source code of the library
- include - containing public headers
- test - containing the unit tests
- demo - containing a sample app to see how to use Conix.

## License
Conix is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
For more details, see [LICENSE](https://github.com/vstan02/conix/blob/master/LICENSE) file.

## Contributing
Contributions are welcome.
If you have a feature request, or have found a bug, feel free to open a [new issue](https://github.com/vstan02/conix/issues/new).
If you wish to contribute code, see [CONTRIBUTING.md](https://github.com/vstan02/conix/blob/master/CONTRIBUTING.md) for more details.
