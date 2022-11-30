
 volatile int Tcount1 = 0;
 volatile int Tcount2 = 0;
 volatile int Tcount3 = 0;
 volatile int Tcount4 = 0;

 
 bool state1 = LOW; 
 bool state2 = LOW;
 bool state3 = LOW; 
 bool state4 = LOW;
 bool state5 = LOW; 
 bool state6 = LOW; 
 bool state7 = LOW; 
 bool state8 = LOW; 

 
long int lastcall1 = 0;
long int lastcall2 = 0;
long int lastcall3 = 0;
long int lastcall4 = 0;
long int lastcall5 = 0;
long int lastcall6 = 0;
long int lastcall7 = 0;
long int lastcall8 = 0;

const int latchPin = 11;
const int clockPin = 10;
const int dataPin = 12;
const int clearPin = 13;


ISR(PCINT2_vect)
{
 
   sw2h();
   sw3h();
   sw4h();
   sw5h();
   sw6h();
   sw7h();
}

//------------------------------------------------------------------------------------------------
ISR(PCINT0_vect)
{
 sw0h(); 
}

//-----------------------------------------------------------------------------------------------
void pcint2_enable()
{
    
    PCICR |= (1<<PCIE2); // Pin change intrrepts enables to PORTD pins   
    PCMSK2 = B11111100; // pin change intrrept enable for PD4 pin  
    sei();  
}
//----------------------------------------------------------------------------------------------
void pcint0_enable()
{
    
    PCICR |= (1<<PCIE0); // Pin change intrrepts enables to PORTD pins   
    PCMSK0 = B00000011; // pin change intrrept enable for PD4 pin  
    sei();
  
}
//---------------------------------------------------------------------------------------------
void sw0h()
{
  if(digitalRead(8)&&!state7)
    {
      if(millis()-lastcall7>=1000)
      {
        Tcount4++;
        lastcall7 = millis();
        state7 =LOW;
      }
     
    }
    else if (!digitalRead(8)&&state7)
    {
      state7 = HIGH;
    }
     if(digitalRead(9)&&!state8)
    {
       if(millis()-lastcall8>=1000)
      {
        Tcount4--;      
        lastcall8 = millis();
        state8 = LOW;
      }
    }
    else if(!digitalRead(9)&&state8)
    {
       state8 = HIGH;
    }}
//--------------------------------------------------------------------------------    
void sw2h()
{
  if(digitalRead(2)&&!state1)
    {
      if(millis()-lastcall1>=1000)
      {
        Tcount1++;
        lastcall1 = millis();
        state1 =LOW;
      }
     
    }
    else if (!digitalRead(2)&&state1)
    {
      state1 = HIGH;
    }

}
//-------------------------------------------------------------------------------------
     void sw3h()
     {
     if(digitalRead(3)&&!state2)
    {
       if(millis()-lastcall2>=1000)
      {
        Tcount1--;      
        lastcall2 = millis();
        state2 = LOW;
      }
    }
    else if(!digitalRead(3)&&state2)
    {
       state2 = HIGH;
    }


     }
//--------------------------------------------------------------------------------------

void sw4h()
{
    if(digitalRead(4)&&!state3)
    {
      if(millis()-lastcall3>=1000)
      {
        Tcount2++;
        lastcall3 = millis();
        state3 =LOW;
      }
     
    }
    else if (!digitalRead(4)&&state3)
    {
      state3 = HIGH;
    }

}
//----------------------------------------------------------------------------------------

    void sw5h()
    {
     if(digitalRead(5)&&!state4)
    {
       if(millis()-lastcall4>=1000)
      {
        Tcount2--;      
        lastcall4 = millis();
        state4 = LOW;
      }
    }
    else if(!digitalRead(5)&&state4)
    {
       state4 = HIGH;
    }

    }
    //-----------------------------------------------------------------------------------------

    void sw6h()
    {
if(digitalRead(6)&&!state5)
    {
      if(millis()-lastcall5>=1000)
      {
        Tcount3++;
        lastcall5 = millis();
        state5 =LOW;
      }
     
    }
    else if (!digitalRead(6)&&state5)
    {
      state5 = HIGH;
    }

    }
    //------------------------------------------------------------------------------------------------
    void sw7h()
    {
     if(digitalRead(7)&&!state6)
    {
       if(millis()-lastcall6>=1000)
      {
        Tcount3--;      
        lastcall6 = millis();
        state6 = LOW;
      }
    }
    else if(!digitalRead(7)&&state6)
    {
       state6 = HIGH;
    }
}
 //-------------------------------------------------------------------------------------------------------------------

 
void setup() {
  

Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);

pinMode(clearPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);


pcint0_enable();
pcint2_enable(); 
digitalWrite(clearPin, LOW); 
digitalWrite(clearPin, HIGH);
 

}

//--------------------------------------------------------------------------

void count(){
  if(Tcount1>=Tcount2 && Tcount1>=Tcount3 && Tcount1>=Tcount4)
  {
    if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
    {

      {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001110); 
shiftOut(dataPin, clockPin, MSBFIRST, B00000001);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001100);
shiftOut(dataPin, clockPin, MSBFIRST, B00100001); 
digitalWrite(latchPin, HIGH);
delay(10000);
      }
digitalWrite(latchPin, HIGH);
  }
  else if(Tcount3>=Tcount4)
  { 
    
    {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001110);
shiftOut(dataPin, clockPin, MSBFIRST, B00000001);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001010);
shiftOut(dataPin, clockPin, MSBFIRST, B01000001);
digitalWrite(latchPin, HIGH);
delay(10000);
    }

  }
  else
  { 
    
    {
      
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001110);
shiftOut(dataPin, clockPin, MSBFIRST, B00000001);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000110);
shiftOut(dataPin, clockPin, MSBFIRST, B10000001);
digitalWrite(latchPin, HIGH);
delay(10000);
    }

  }
  }


  
  else if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
  {
   if(Tcount1>=Tcount3 && Tcount1>=Tcount4)
   {
    
    { 
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001101);
shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001100);
shiftOut(dataPin, clockPin, MSBFIRST, B00010010);
digitalWrite(latchPin, HIGH);
delay(10000);
    }
   
   }
   else if(Tcount3>=Tcount4)
   {
    
    {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001101);
shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001100);
shiftOut(dataPin, clockPin, MSBFIRST, B01000010);
digitalWrite(latchPin, HIGH);
delay(10000);
    }

    }
    else
    {
      
      {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001101);
shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001100);
shiftOut(dataPin, clockPin, MSBFIRST, B10000010);
digitalWrite(latchPin, HIGH);
delay(10000);
      }
    }
    }


    
    else if(Tcount3>=Tcount4)
    {
      if(Tcount1>=Tcount2 && Tcount1>=Tcount4)
      {
       
        {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001011);
shiftOut(dataPin, clockPin, MSBFIRST, B00000100);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001010);
shiftOut(dataPin, clockPin, MSBFIRST, B00010100);
digitalWrite(latchPin, HIGH);
delay(10000);
        }

      }
      else if(Tcount2>=Tcount4)
      {
        
        {
          digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001011);
shiftOut(dataPin, clockPin, MSBFIRST, B00000100);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001001);
shiftOut(dataPin, clockPin, MSBFIRST, B00100100);
digitalWrite(latchPin, HIGH);
delay(10000);
        }

      }
      else
      {
       
        {
          digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00001011);
shiftOut(dataPin, clockPin, MSBFIRST, B00000100);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000011);
shiftOut(dataPin, clockPin, MSBFIRST, B10000100);
digitalWrite(latchPin, HIGH);
delay(10000);
        }

      }
      } 
      else
      {
        if(Tcount1>=Tcount2 && Tcount1>=Tcount3)
        {
          
          {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000111);
shiftOut(dataPin, clockPin, MSBFIRST, B00001000);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000011);
shiftOut(dataPin, clockPin, MSBFIRST, B00011000);
digitalWrite(latchPin, HIGH);
delay(10000);
          }
        }
        else if(Tcount2>=Tcount3)
        {
           
           {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000111);
shiftOut(dataPin, clockPin, MSBFIRST, B00001000);
digitalWrite(latchPin, HIGH);
delay(20000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000101);
shiftOut(dataPin, clockPin, MSBFIRST, B00010100);
digitalWrite(latchPin, HIGH);
delay(10000);
           }

        }
        else
        {
          
          {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000111);
shiftOut(dataPin, clockPin, MSBFIRST, B00001000);
digitalWrite(latchPin, HIGH);
delay(10000);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000011);
shiftOut(dataPin, clockPin, MSBFIRST, B01001000);
digitalWrite(latchPin, HIGH);
delay(10000);
          }


        }
        }
    }
 //------------------------------------------------------------------------------------------------


void loop() {
  
Serial.print("TCount1 :");
Serial.println(Tcount1);
Serial.print("TCount2 :");
Serial.println(Tcount2);
Serial.print("TCount3 :");
Serial.println(Tcount3);
Serial.print("TCount4 :");
Serial.println(Tcount4);
delay(1000);


count();
  
}
