# Arcade
Arcade is a software written in C ++, this one consists of the simulation of an arcade terminal.
The goal of the project is to use dynamic loading of libraries containing a game or a graphical API.

## Features:
* **Changing the runtime of the graphics library**
* **Loading runtime games**

## Build:

Install all graphic libraries
````sh
make install
````

Build The Project
````sh
make
````

# Upgrades
* **Finish Implementation of Vulkan API**
* **Use CMake instead of Make for multi-platform compilation**

# Architecture
The project is written in **C++** and uses **SDL2**, **SFML**, **NCurses** and **Vulkan** as Graphic API.   
The project is composed of an executable who loads the different libraries during the execution of the program

# Libraries
* **SDL2**
* **SFML**
* **NCurses**
* **Vulkan**

# Authors
**[Brice Lang-Nguyen](https://github.com/BriceLN)** (brice.lang-nguyen@epitech.eu)  
**[Johanne-Franck Ngbokoli](https://github.com/Franck242)** (franck.ngbokoli@epitech.eu)  
**[Bastien Guillaumat](https://github.com/bguillaumat)** (bastien.guillaumat@epitech.eu)  
