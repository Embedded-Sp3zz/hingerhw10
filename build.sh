#!/bin/bash

echo "Building the AnalogIn application"
g++ test_analog.cpp AnalogIn.cpp -o test_analog

echo "Building the gpioApp application"

config-pin p9.12 gpio

config-pin p8.16 gpio_pu

g++ gpioApp.cpp AnalogIn.cpp GPIO.cpp LED.cpp -pthread -o gpioApp

echo "Building the read_resistance application"

g++ read_resistance.cpp AnalogIn.cpp -o read_resistance

echo "Finished Building"
