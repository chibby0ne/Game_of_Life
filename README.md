# John Conway's Game of Life 

## Description

Implementation of the [John Conway](https://en.wikipedia.org/wiki/John_Horton_Conway "Wikipedia Article")'s [Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life "Wikipedia Article") based on terminal for Linux Operating Systems

## Installation
```
git clone https://github.com/chibby0ne/gameoflife
```

```
cd gameoflife/
```

```
cmake .
```

## Usage

`./life`

## Implementation

* C language
* Random function seed uses system time
* refresh rate using time.h (instead of sleep system call which is open to interrupts)

## Contributions

Contributions and pull requests are welcome. As long as you comply with this guideline: 

* Adhere as much as possible to the existing coding style, mainly, everything that could have curly braces has them

## License 

MIT License. Copyright (c) 2013-2014 Antonio Gutierrez
