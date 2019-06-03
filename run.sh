#!/usr/bin/env bash

#solo cambiar el nombre del cpp
g++ main.cpp animacionR.cpp animacionR.h -o ejecutable -lglut -lGLU -lGL -lSOIL -lSDL2 -lGLEW && ./ejecutable
