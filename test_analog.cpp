// test_analog.cpp

#include <iostream>
#include "AnalogIn.h"

using namespace std;

int main(int argc, char* argv[]){
  
  int reading;
  int number;

  AnalogIn AIN(0);

  number = AIN.getNumber();

  cout << "Reading ADC Number: " << number << endl;

  reading = AIN.readAdcSample();

  cout << "ADC Reading is: " << reading << endl;
}
