// read_resistance.cpp

// determines the bottom resistor in a voltage divider

#include <iostream>
#include <iomanip>

#include "AnalogIn.h"

using namespace std;

int main(){
  AnalogIn AIN(0);

  float Vref = 1.8;
  int R1 = 10000;

  int number = AIN.getNumber();

  cout << "Using AIN" << number << " to read analog value." << endl;

  int reading = AIN.readAdcSample();

  cout << "Measuring resistance ..." << endl;

  cout << "ADC value is: " << reading << endl;

  float current_voltage = reading * (Vref/4096);

  float resistance = (current_voltage * R1) / (Vref - current_voltage); 

  cout << "resistance is " << resistance << endl;

  if(resistance > 1000){
    resistance = resistance / 1000;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "Resistance: " << resistance << "K Ohms" << endl;
  }
  else{
    cout << "Resistance: " << resistance << " Ohms" <<  endl;
  }
}
