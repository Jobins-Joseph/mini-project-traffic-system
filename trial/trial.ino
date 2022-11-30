int ir1=2;  
 volatile int count1 = 0;  

   int ir2=3;  
volatile int count2 = 0;
long int lastcall1 = 0;
long int lastcall2 = 0;


int ir3=4;  
 volatile int count3 = 0;  

   int ir4=5;  
volatile int count4 = 0;
long int lastcall3 = 0;
long int lastcall4 = 0;


int ir5=6;  
 volatile int count5 = 0;  

   int ir6=7;  
volatile int count6 = 0;
long int lastcall5 = 0;
long int lastcall6 = 0;


int ir7=8;  
 volatile int count7 = 0;  

   int ir8=9;  
volatile int count8 = 0;
long int lastcall7 = 0;
long int lastcall8 = 0;



const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

int led_green[]={0B1000000000000000,0B0100000000000000,0B0010000000000000,0B0001000000000000};
int led_yellow[]={0B0000100000000000,0B0000010000000000,0B0000001000000000,0B0000000100000000};
int led_red[]={0B0000000010000000,0B0000000001000000,0B0000000000100000,0B0000000000010000};



ISR(PCINT2_vect)
{
  cli();
  
   if(digitalRead(ir1)==0)
    {
      if(millis()-lastcall1>=1000)
      {
        count1++;
        
        lastcall1 = millis();
      }
    }
    else if(digitalRead(ir2)==0)
    {
       if(millis()-lastcall2>=1000)
      {
        count2++;
        
        lastcall2 = millis();
      }
    } 
    else if(digitalRead(ir3)==0)
    {
       if(millis()-lastcall3>=1000)
      {
        count3++;
        
        lastcall3 = millis();
      }
    } 
    else if(digitalRead(ir4)==0)
    {
       if(millis()-lastcall4>=1000)
      {
        count4++;
        
        lastcall4 = millis();
      }
    } 
    else if(digitalRead(ir5)==0)
    {
       if(millis()-lastcall5>=1000)
      {
        count5++;
        
        lastcall5 = millis();
      }
    } 
    else if(digitalRead(ir6)==0)
    {
       if(millis()-lastcall6>=1000)
      {
        count6++;
        
        lastcall6 = millis();
      }
    } 
    

sei();
}


ISR(PCINT0_vect)
{
   if(digitalRead(ir7))
    {
      if(millis()-lastcall7>=1000)
      {
        count7++;

        lastcall7 = millis();
      }
    }
    else if(digitalRead(ir8))
    {
      if(millis()-lastcall2>=1000)
      {
        count8++;
        
        lastcall8 = millis();
      }
    } 

}

void pcint0_enable()
{
    
    PCICR |= B00000001; // Pin change intrrepts enables to PORTD pins(1<<PCIE0)   
    PCMSK0 = B00000011; // pin change intrrept enable for PD4 pin  
    sei();
  
}

void pcint2_enable()
{
    
    PCICR |= B00000100; // Pin change intrrepts enables to PORTD pins (1<<PCIE2)  
    PCMSK2 = B11111100; // pin change intrrept enable for PD4 pin  
    sei();
  
}
void setup()  
 {  
   
Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
  

pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);

pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);

pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);
  
  
  pcint0_enable();
  pcint2_enable(); 
 }

 void loop() {
  
Serial.print("Count1 :");
Serial.println(count1);
Serial.print("Count2 :");
Serial.println(count2);


delay(500);
Serial.print("Count3 :");
Serial.println(count3);
Serial.print("Count4 :");
Serial.println(count4);
delay(500);

Serial.print("Count5 :");
Serial.println(count5);
Serial.print("Count6 :");
Serial.println(count6);
  delay(500);


Serial.print("Count7 :");
Serial.println(count7);
Serial.print("Count8 :");
Serial.println(count8);
  
  delay(500);





{
  if(count1-count2>=count3-count4 && count1-count2>=count5-count6 && count1-count2>=count7-count8)
  {
    
    if(count3-count4>=count5-count6 && count3-count4>=count7-count8)
    {
      digitalWrite(latchPin, LOW);
     
shiftOut(dataPin, clockPin, MSBFIRST, led_green[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[1]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[2,3]);
digitalWrite(latchPin, HIGH);

  }
  else if(count5-count6>=count7-count8)
  { 
    digitalWrite(latchPin, LOW);
    
shiftOut(dataPin, clockPin, MSBFIRST, led_green[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[2]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[1,3]);
      
digitalWrite(latchPin, HIGH);

    
  }
  else
  { 
    digitalWrite(latchPin, LOW);
    
shiftOut(dataPin, clockPin, MSBFIRST, led_green[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[3]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[1,2]);
      
digitalWrite(latchPin, HIGH);

    
  }
  }


  
  else if(count3-count4>=count5-count6 && count3-count4>=count7-count8)
  { 
   if(count1-count2>=count5-count6 && count1-count2>=count7-count8)
   {
    digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, led_green[1]);    
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[2,3]);
      
digitalWrite(latchPin, HIGH);

   }
   else if(count5-count6>=count7-count8)
   {
    digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, led_green[1]);   
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[2]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,3]);
     
digitalWrite(latchPin, HIGH);
    
    }
    else
    {
      digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, led_green[1]);      
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[3]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,2]);

  
digitalWrite(latchPin, HIGH);


    }
    }


    
    else if(count5-count6>=count7-count8)
    {
      
      if(count1-count2>=count3-count4 && count1-count2>=count7-count8)
      {
        digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, led_green[2]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[1,3]);
      
digitalWrite(latchPin, HIGH);
      }
      else if(count3-count4>=count7-count8)
      {
        digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, led_green[2]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[1]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,3]);
    
digitalWrite(latchPin, HIGH);
      }
      else
      {
        digitalWrite(latchPin, LOW);
 shiftOut(dataPin, clockPin, MSBFIRST, led_green[2]);
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[3]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,1]);
      
digitalWrite(latchPin, HIGH);





      }
      }


      
      else
      {
       
        
        if(count1-count2>=count3-count4 && count1-count2>=count5-count6)
        {
          digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, led_green[3]);  
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[0]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[1,2]);
      
digitalWrite(latchPin, HIGH);

        }
        else if(count3-count4>=count5-count6)
        {
           digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, led_green[3]);  
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[1]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,2]);
     
digitalWrite(latchPin, HIGH);

        }
        else
        {
          digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, led_green[3]);  
shiftOut(dataPin, clockPin, MSBFIRST, led_yellow[3]);
shiftOut(dataPin, clockPin, MSBFIRST, led_red[0,1]);
      
digitalWrite(latchPin, HIGH);


        }
        }
    }



  
}
