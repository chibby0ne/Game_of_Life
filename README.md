# John Conway's Game of Life 

## Description

Implementation of the [John Conway](https://en.wikipedia.org/wiki/John_Horton_Conway "Wikipedia Article")'s [Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life "Wikipedia Article") based on terminal for Linux Operating Systems

## Installation
```
git clone https://github.com/chibby0ne/gameoflife
cd Game_of_Life/CMake
cmake .
make
```

## Usage
```
cd bin/
./gameoflife [OPTIONS] [arguments]...
```

### Options

The available options are:
* `-w` _value_ Sets width of the terminal to be used the simulation (default: width of terminal window)
* "-h` _value_ Sets height of the terminal to be used the simulation (default: height of terminal window)
* `-r` _value_ Sets refresh time of the terminal in useconds (default: 0.2 sec) (time between generations of cells)
* `-p` _value_ Sets initial probability of living cell in percentage (default: 10)
* `-h`         Shows help 


## Implementation

* C language
* Random function seed uses system time
* adjustable refresh rate
* adjustable probability of live/dead cell for initial generation
* adjustable width/height of universe (place where cells live/die)


## Contributions

Contributions and pull requests are welcome. As long as you comply with these guideline: 

* Adhere as much as possible to the existing coding style, mainly, everything that could have curly braces has them
* Good descriptive variable names

## License 

GPLv2
