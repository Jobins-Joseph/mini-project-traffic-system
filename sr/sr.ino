/*
  74HC595 & 74HC165 Shift Register Demonstration 2
  74hc595-to-74ch165-pattern.ino
  Input from 8 pushbuttons using 74HC165
  Output to 8 LEDs using 74HC595
  
  Select LED pattern using pushbuttons
  
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
// Define Connections to 74HC165

// PL pin 1 
int load = 7;   
// CE pin 15       
int clockEnablePin = 4;  
// Q7 pin 7  
int dataIn = 5;   
 // CP pin 2  
int clockIn = 6;    

// Define Connections to 74HC595

// ST_CP pin 12
const int latchPin = 10;
// SH_CP pin 11
const int clockPin = 11;
// DS pin 14
const int dataPin = 12; 

// Define data array
int led_green[]={100000000000,010000000000,001000000000,000100000000};
int led_yellow[]={000010000000,000001000000,000000100000,000000010000};
int led_red[]={000000001000,000000000100,000000000010,000000000001};

void setup () {
  
// Setup Serial Monitor
Serial.begin(9600);
  
// 74HC165 pins
pinMode(load, OUTPUT);
pinMode(clockEnablePin, OUTPUT);
pinMode(clockIn, OUTPUT);
pinMode(dataIn, INPUT);

// 74HC595 pins
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);

}


void loop() {

// Read Switches      

// Write pulse to load pin
digitalWrite(load,LOW);
delayMicroseconds(5);
digitalWrite(load,HIGH);
delayMicroseconds(5);

// Get data from 74HC165
digitalWrite(clockIn,HIGH);
digitalWrite(clockEnablePin,LOW);
byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
digitalWrite(clockEnablePin,HIGH);

// Print to serial monitor
Serial.print("Pin States:\r\n");
Serial.println(incoming, BIN);

// Setup array for LED pattern

switch (incoming) {

  case B11111110:
  
    datArray[0] = B11111111;
    datArray[1] = B01111110;
    datArray[2] = B10111101;
    datArray[3] = B11011011;
    datArray[4] = B11100111;
    datArray[5] = B11011011;
    datArray[6] = B10111101;
    datArray[7] = B01111110;
  
    break;
  
  case B11111101:
  
    datArray[0] = B00000001;
    datArray[1] = B00000010;
    datArray[2] = B00000100;
    datArray[3] = B00001000;
    datArray[4] = B00010000;
    datArray[5] = B00100000;
    datArray[6] = B01000000;
    datArray[7] = B10000000;
  
    break;
  
  case B11111011:
  
    datArray[0] = B10000001;
    datArray[1] = B01000010;
    datArray[2] = B00100100;
    datArray[3] = B00011000;
    datArray[4] = B00000000;
    datArray[5] = B00100100;
    datArray[6] = B01000010;
    datArray[7] = B10000001;
  
    break;

 
  case B11110111:
  
    datArray[0] = B10101010;
    datArray[1] = B01010101;
    datArray[2] = B10101010;
    datArray[3] = B01010101;
    datArray[4] = B10101010;
    datArray[5] = B01010101;
    datArray[6] = B10101010;
    datArray[7] = B01010101;
  
    break;

 
  case B11101111:
  
    datArray[0] = B10000000;
    datArray[1] = B00000001;
    datArray[2] = B01000000;
    datArray[3] = B00000010;
    datArray[4] = B00100000;
    datArray[5] = B00000100;
    datArray[6] = B00010000;
    datArray[7] = B00001000;
  
    break;

  case B11011111:
  
    datArray[0] = B11000000;
    datArray[1] = B01100000;
    datArray[2] = B00110000;
    datArray[3] = B00011000;
    datArray[4] = B00001100;
    datArray[5] = B00000110;
    datArray[6] = B00000011;
    datArray[7] = B10000001;
  
    break;

 case B10111111:
  
    datArray[0] = B11100000;
    datArray[1] = B01110000;
    datArray[2] = B00111000;
    datArray[3] = B00011100;
    datArray[4] = B00001110;
    datArray[5] = B00000111;
    datArray[6] = B10000011;
    datArray[7] = B11000001;
  
    break;

 case B01111111:
  
    datArray[0] = B10001000;
    datArray[1] = B01000100;
    datArray[2] = B00100010;
    datArray[3] = B00010001;
    datArray[4] = B10001000;
    datArray[5] = B01000100;
    datArray[6] = B00100010;
    datArray[7] = B00010001;
  
    break;
    
  default:

    break;

  }

// Write to LEDs

// Count from 0 to 7
  for(int num = 0; num < 8; num++)
  {
    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchPin, LOW);
    
    // Shift out the bits
    shiftOut(dataPin,clockPin,MSBFIRST,datArray[num]);

    // ST_CP HIGH change LEDs
    digitalWrite(latchPin, HIGH);
    
    delay(200); 
  }

} 
