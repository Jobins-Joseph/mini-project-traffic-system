{
  if(Tcount1>=Tcount2 && Tcount1>=Tcount3 && Tcount1>=Tcount4)
  {
    if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
    {
      digitalWrite(latchPin, LOW);
      {
shiftOut(dataPin, clockPin, MSBFIRST, b1000000001110000); 
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b1000010000110000); 
delay(10000);
      }
digitalWrite(latchPin, HIGH);
  }
  else if(Tcount3>=Tcount4)
  { 
    digitalWrite(latchPin, LOW);
    {
shiftOut(dataPin, clockPin, MSBFIRST, 0b1000000001110000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b1000001001010000);
delay(10000);
    }
digitalWrite(latchPin, HIGH);
  }
  else
  { 
    digitalWrite(latchPin, LOW);
    {
shiftOut(dataPin, clockPin, MSBFIRST, 0b1000000001110000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b1000000101100000);
delay(10000);
    }
digitalWrite(latchPin, HIGH);
  }
  }


  
  else if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
  {
   if(Tcount1>=Tcount3 && Tcount1>=Tcount4)
   {
    digitalWrite(latchPin, LOW);
    { 
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100000010110000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100100000110000);
delay(10000);
    }
    digitalWrite(latchPin, HIGH);
   }
   else if(Tcount3>=Tcount4)
   {
    digitalWrite(latchPin, LOW);
    {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100000010110000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100001000110000);
delay(10000);
    }
digitalWrite(latchPin, HIGH);
    }
    else
    {
      digitalWrite(latchPin, LOW);
      {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100000010110000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0100000100110000);
delay(10000);
      }
digitalWrite(latchPin, HIGH);
    }
    }


    
    else if(Tcount3>=Tcount4)
    {
      if(Tcount1>=Tcount2 && Tcount1>=Tcount4)
      {
        digitalWrite(latchPin, LOW);
        {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010000011010000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010100001010000);
delay(10000);
        }
digitalWrite(latchPin, HIGH);
      }
      else if(Tcount2>=Tcount4)
      {
        digitalWrite(latchPin, LOW);
        {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010000011010000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010010010010000);
delay(10000);
        }
digitalWrite(latchPin, HIGH);
      }
      else
      {
        digitalWrite(latchPin, LOW);
        {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010000011010000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0010000111000000);
delay(10000);
        }
digitalWrite(latchPin, HIGH);
      }
      } 
      else
      {
        if(Tcount1>=Tcount2 && Tcount1>=Tcount3)
        {
          digitalWrite(latchPin, LOW);
          {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001000011100000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001100001100000);
delay(10000);
          }
digitalWrite(latchPin, HIGH);
        }
        else if(Tcount2>=Tcount3)
        {
           digitalWrite(latchPin, LOW);
           {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001000011100000);
delay(20000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001010010100000);
delay(10000);
           }
digitalWrite(latchPin, HIGH);
        }
        else
        {
          digitalWrite(latchPin, LOW);
          {
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001000011100000);
delay(10000);
shiftOut(dataPin, clockPin, MSBFIRST, 0b0001001011000000);
delay(10000);
          }
digitalWrite(latchPin, HIGH);

        }
        }
    }
  
  
