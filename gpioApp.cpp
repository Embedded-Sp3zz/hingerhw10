// gpioApp.cpp

// 1. Turn on user LED number 1 and 3.
// 2. Flash user LED 2 three times.
// 3. Read the temperature sensor and display its value.
// 4. Read the push button on P8.16
// 5. If the push button on item 4 was pushed, turn on the LED on P9.12

#include <iostream>
#include <unistd.h>
#include <pthread.h>

#include "AnalogIn.h"
#include "GPIO.h"
#include "LED.h"

using namespace exploringBB;
using namespace std;

int main(){
  GPIO outGPIO(60), inGPIO(46);
  LED led0(0), led1(1), led2(2), led3(3);
  AnalogIn AIN(0);

  led1.turnOn();
  led3.turnOn();

  for(int i = 0; i < 2; i++){
    led2.turnOn();
    sleep(1);
    led2.turnOff();
    sleep(1);
  }
  
  int number = AIN.getNumber();
  int reading = AIN.readAdcSample();

  cout << "Reading from ADC: " << number << ". Value: " << reading << endl;


  inGPIO.setDirection(INPUT);
  outGPIO.setDirection(OUTPUT);

  int button = inGPIO.getValue();

  if(button == 0){
    cout << "Button pressed, setting external LED on P9.12 to HIGH" << endl;
    outGPIO.streamWrite(HIGH);    
  }
  else{
    cout << "Button released, clearing external LED on P9.12 to LOW" << endl;
    outGPIO.streamWrite(LOW);
  }

  return 0;
}
