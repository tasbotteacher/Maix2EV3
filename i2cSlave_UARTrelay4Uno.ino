// https://www.arduino.cc/en/Tutorial/LibraryExamples/MasterReader

// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

int ctr;
int incomingByte = 0; // for incoming serial data


#include <Wire.h>

void setup() {
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);  // start serial for output

  incomingByte = 0;
}

void loop() {
  // Read the data from the MAIX
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  }
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(incomingByte); // respond with message of 1 byte
}

