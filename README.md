# Conix
> A library for easy handling of command line options

[![Version: v1.0.0](https://img.shields.io/badge/version-v1.0.0-blue)](https://vstan02.github.io/conix)
[![License: GPL v3](https://img.shields.io/badge/license-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)

## Contents
- [Usage](#usage)
- [Building and Installation](#building-and-installation)
  - [Dependencies](#dependencies)
  - [Building the project](#building-the-project)
  - [Running demo](#running-demo)
  - [Running tests](#running-tests)
  - [Installing](#installing)
- [License](#license)
- [Contributing](#contributing)

## Usage
Here is an example of usage (for the full version see [demo/main.c](https://github.com/vstan02/conix/blob/master/demo/main.c) file):
```c
// Creating an new cli instance:
cnx_cli_t* cli = cnx_cli_init((cnx_app_t) { "my_app", "2.8.1" });

// Adding some options for handling:
cnx_cli_add(cli, 5, (cnx_option_t[]) {
	// cnx_option_t -> { name, description, handler, payload }.
	{ "-a, --about", "Display something", about_option, NULL },
	{ "-p, --print", "Display passed arguments", print_args_option, NULL },
	
	// Handlers for "-v, --version" and "-h, --help" are added
	// by default, but you can add your own handlers for them.
	{ "-v, --version", "Display version", version_option, NULL },
	
	// Handler for "--default" is called when are no arguments passed.
	{ "--default", "Default option", index_option, NULL },
	
	// Handler for "*" is called when is passed an unknown cli option.
	// By default it has the same handler as the "-h, --help" option.
	{ "*", NULL, not_found_option, NULL }
});

// Running for some command line arguments:
cnx_cli_run(cli, argc, argv);

// Destroying the instance:
cnx_cli_free(cli);
```

After project building you can run this example as you can see [here](#running-demo).
Also, you can see [xcalc](https://vstan02.github.io/xcalc) - an real example of using Conix.

## Building and Installation

### Dependencies
- C compiler (gcc, clang, etc...)
- cmake (>= 3.16)

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

### Installing
To install the library run:
```
sudo make install
```
By default the libraries and headers will be installed in `/usr/local/lib` and `/usr/local/include` directories.

## License
Conix is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
For more details, see [LICENSE](https://github.com/vstan02/conix/blob/master/LICENSE) file.

## Contributing
Contributions are welcome.
If you have a feature request, or have found a bug, feel free to open a [new issue](https://github.com/vstan02/conix/issues/new).
If you wish to contribute code, see [CONTRIBUTING.md](https://github.com/vstan02/conix/blob/master/CONTRIBUTING.md) for more details.
