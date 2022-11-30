int ir1=2;  
 int count1;  
 int Tcount1;
 boolean state1 = false; 
  int ir2=3;  
 int count2;  
 boolean state2 = false; 
 int ir3=4;  
 int count3;  
 int Tcount2;
 boolean state3 = false; 
  int ir4=5;  
 int count4;  
 boolean state4 = false; 
 int ir5=6;  
 int count5;  
 int Tcount3;
 boolean state5 = false; 
  int ir6=7;  
 int count6;  
 boolean state6 = false;  
 int ir7=8;  
 int count7;  
 int Tcount4;
 boolean state7 = false; 
  int ir8=9;  
 int count8;  
 boolean state8 = false; 
 

const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

int led_led[]={0B1000000000000000,0B0100000000000000,0B0010000000000000,0B0001000000000000,0B0000100000000000,0B0000010000000000,0B0000001000000000,0B0000000100000000,0B0000000010000000,0B0000000001000000,0B0000000000100000,0B0000000000010000};



  long int timee;
  

 void setup()  
 {  
  Serial.begin(9600);  
  pinMode(ir1, INPUT);  
  pinMode(ir2, INPUT);
  count2=0;
  count1=0;  
  Tcount1=0;
  pinMode(ir3, INPUT);  
  pinMode(ir4, INPUT);
  count4=0;
  count3=0;  
  Tcount2=0;  
   pinMode(ir5, INPUT);  
  pinMode(ir6, INPUT);
  count6=0;
  count5=0;  
  Tcount3=0;
  pinMode(ir7, INPUT);  
  pinMode(ir8, INPUT);
  count8=0;
  count7=0;  
  Tcount4=0;   
  pinMode(led_led,OUTPUT);


pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

timee=millis();


 }  
 void loop()  
 {{  
    
  if (!digitalRead(ir1) && state1){  
    count1++;  
    state1 = false;  
    Serial.print("Count1: ");  
    Serial.println(count1);   
     
  }  
  if (digitalRead(ir1))  
  {  
    state1 = true;  
     
  }  
 
   
  if (!digitalRead(ir2) && state2){  
    count2++;  
    state2 = false;  
    Serial.print("Count2: ");  
    Serial.println(count2);   
      
  }  
  if (digitalRead(ir2))  
  {  
    state2 = true;  
     
  } 
  {
  delay (500);  
 Tcount1=count1-count2;
 Serial.print("Tcount1= ");
Serial.println(Tcount1);

} 
 if (!digitalRead(ir3) && state3){  
    count3++;  
    state3 = false;  
    Serial.print("Count3: ");  
    Serial.println(count3);   
     
  }  
  if (digitalRead(ir3))  
  {  
    state3 = true;  
     
  }  
 
   
  if (!digitalRead(ir4) && state4){  
    count4++;  
    state4 = false;  
    Serial.print("Count4: ");  
    Serial.println(count4);   
      
  }  
  if (digitalRead(ir4))  
  {  
    state4 = true;  
     
  } 
  {
  delay (100);  
 Tcount2=count3-count4;
 Serial.print("Tcount2= ");
Serial.println(Tcount2);

} 
if (!digitalRead(ir5) && state5){  
    count5++;  
    state5 = false;  
    Serial.print("Count5: ");  
    Serial.println(count5);   
     
  }  
  if (digitalRead(ir5))  
  {  
    state5 = true;  
     
  }  
 
   
  if (!digitalRead(ir6) && state6){  
    count6++;  
    state6 = false;  
    Serial.print("Count6: ");  
    Serial.println(count6);   
      
  }  
  if (digitalRead(ir6))  
  {  
    state6 = true;  
     
  } 
  {
  delay (100);  
 Tcount3=count5-count6;
 Serial.print("Tcount3= ");
Serial.println(Tcount3);

} 
if (!digitalRead(ir7) && state7){  
    count7++;  
    state7 = false;  
    Serial.print("Count7: ");  
    Serial.println(count7);   
     
  }  
  if (digitalRead(ir7))  
  {  
    state7 = true;  
     
  }  
 
   
  if (!digitalRead(ir8) && state8){  
    count8++;  
    state8 = false;  
    Serial.print("Count8: ");  
    Serial.println(count8);   
      
  }  
  if (digitalRead(ir8))  
  {  
    state8 = true;  
     
  } 
  {
  delay (100);  
 Tcount4=count7-count8;
 Serial.print("Tcount4= ");
Serial.println(Tcount4);

} 
unsigned long timee1=millis();
 {
  if(Tcount1>=Tcount2 && Tcount1>=Tcount3 && Tcount1>=Tcount4)
  {
    
    //digitalWrite(led_green[0],HIGH);
    if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
    {
      digitalWrite(latchPin, LOW);
      if(timee1-timee>30000)
    {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[0,5,10,11]);

timee=timee1;
    } 
digitalWrite(latchPin, HIGH);

      //digitalWrite(led_yellow[1],HIGH);
      //digitalWrite(led_red[2,3],HIGH);
  }
  else if(Tcount3>=Tcount4)
  { 
    digitalWrite(latchPin, LOW);
    if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[0,6,9,11]);
     timee=timee1;
     }
digitalWrite(latchPin, HIGH);

    //digitalWrite(led_yellow[2],HIGH);
    //digitalWrite(led_red[1,3],HIGH); 
  }
  else
  { 
    digitalWrite(latchPin, LOW);
    if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[0,7,9,10]);
     timee=timee1;
     }
digitalWrite(latchPin, HIGH);

    //digitalWrite(led_yellow[3],HIGH);
    //digitalWrite(led_red[1,2],HIGH);
  }
  }


  
  else if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
  {
    
   //digitalWrite(led_green[1],HIGH);
   if(Tcount1>=Tcount3 && Tcount1>=Tcount4)
   {
    digitalWrite(latchPin, LOW);
    if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[1,4,10,11]);
       timee=timee1;
       }
digitalWrite(latchPin, HIGH);

    // digitalWrite(led_yellow[0],HIGH);
    // digitalWrite(led_red[2,3],HIGH);
   }
   else if(Tcount3>=Tcount4)
   {
    digitalWrite(latchPin, LOW);
    if(timee1-timee>30000)
      {
        
shiftOut(dataPin, clockPin, MSBFIRST, led_led[1,6,8,11]);
      timee=timee1;
      }
digitalWrite(latchPin, HIGH);
    //digitalWrite(led_yellow[2],HIGH);
    //digitalWrite(led_red[0,3],HIGH);
    }
    else
    {
      digitalWrite(latchPin, LOW);
     if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[1,7,8,10]);
 timee=timee1;
      }
digitalWrite(latchPin, HIGH);


     // digitalWrite(led_yellow[3],HIGH);
     // digitalWrite(led_red[0,2],HIGH);
    }
    }


    
    else if(Tcount3>=Tcount4)
    {
      digitalWrite(latchPin, LOW);
      while(millis()<timee+30000)
    {

    }
digitalWrite(latchPin, HIGH);
     // digitalWrite(led_green[2],HIGH);
      if(Tcount1>=Tcount2 && Tcount1>=Tcount4)
      {
        digitalWrite(latchPin, LOW);
        if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[2,4,9,11]);
      timee=timee1;
      }
digitalWrite(latchPin, HIGH);
delay(1000);


        //digitalWrite(led_yellow[0],HIGH);
        //digitalWrite(led_red[1,3],HIGH);
      }
      else if(Tcount2>=Tcount4)
      {
        digitalWrite(latchPin, LOW);
        if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[2,5,8,11]);
      timee=timee1;
      }
digitalWrite(latchPin, HIGH);
delay(1000);



        //digitalWrite(led_yellow[1],HIGH);
        //digitalWrite(led_red[0,3],HIGH);
      }
      else
      {
        digitalWrite(latchPin, LOW);
        if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[2,7,8,9]);

      timee=timee1;
      }
digitalWrite(latchPin, HIGH);
delay(1000);




        //digitalWrite(led_yellow[3],HIGH);
        //digitalWrite(led_red[0,1],HIGH);
      }
      }


      
      else
      {
       

        //digitalWrite(led_green[3],HIGH);
        if(Tcount1>=Tcount2 && Tcount1>=Tcount3)
        {
          digitalWrite(latchPin, LOW);
         if(timee1-timee>30000)
      {
        shiftOut(dataPin, clockPin, MSBFIRST, led_led[3,4,8,9]);
     timee=timee1;
     }
digitalWrite(latchPin, HIGH);
delay(1000);

         // digitalWrite(led_yellow[0],HIGH);
         // digitalWrite(led_red[1,2],HIGH);
        }
        else if(Tcount2>=Tcount3)
        {
           digitalWrite(latchPin, LOW);
           if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[3,5,8,10]);
timee=timee1;
      }
digitalWrite(latchPin, HIGH);
delay(1000);

         // digitalWrite(led_yellow[1],HIGH);
          //digitalWrite(led_red[0,2],HIGH);
        }
        else
        {
          digitalWrite(latchPin, LOW);
          if(timee1-timee>30000)
      {
shiftOut(dataPin, clockPin, MSBFIRST, led_led[3,7,8,9]);
timee=timee1;
      }
digitalWrite(latchPin, HIGH);
delay(1000);

          //digitalWrite(led_yellow[2],HIGH);
          //digitalWrite(led_red[0,1],HIGH);
        }
        }
    }
  
  
 } }
 
 

 
