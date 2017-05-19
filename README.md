# Aleva Game Library 2 - AGL2

AGL2, the successor of [AGL](http://github.com/yds12/agl), is a game library designed to support the task of developing games in C++. It relies on [SDL 1.2](https://www.libsdl.org/index.php).

## Compiling and Installing AGL

First, install the dependencies (SDL development files): the base SDL library (the first version, not SDL 2), SDL mixer, SDL ttf, SDL image and SDL net. For the compilation, it might be necessary to install the C++ compiler **g++**. In Ubuntu 16.04, for example, you can type this:

```
sudo apt-get install libsdl1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev libsdl-image1.2-dev libsdl-net1.2-dev g++
```

Now installing AGL is easy. Just type the following in a terminal (from the `src` directory):

```
make install
```

This will install the library for use and development. If you want to use AGL for development you can type `make install_debug` instead, to install it with debug symbols.
