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
 int led_green[]={10,11,12,13};
int led_yellow[]={14,15,16,17};
int led_red[]={18,19,20,21};

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
  pinMode(led_green,OUTPUT);
pinMode(led_yellow,OUTPUT);
pinMode(led_red,OUTPUT);
 }  
 void loop()  
 {  
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
 {
  if(Tcount1>=Tcount2 && Tcount1>=Tcount3 && Tcount1>=Tcount4)
  {
    digitalWrite(led_green[0],HIGH);
    if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
    {
      digitalWrite(led_yellow[1],HIGH);
      digitalWrite(led_red[2,3],HIGH);
  }
  else if(Tcount3>=Tcount4)
  {
    digitalWrite(led_yellow[2],HIGH);
    digitalWrite(led_red[1,3],HIGH); 
  }
  else
  {
    digitalWrite(led_yellow[3],HIGH);
    digitalWrite(led_red[1,2],HIGH);
  }
  }


  
  else if(Tcount2>=Tcount3 && Tcount2>=Tcount4)
  {
   digitalWrite(led_green[1],HIGH);
   if(Tcount1>=Tcount3 && Tcount1>=Tcount4)
   {
     digitalWrite(led_yellow[0],HIGH);
     digitalWrite(led_red[2,3],HIGH);
   }
   else if(Tcount3>=Tcount4)
   {
    digitalWrite(led_yellow[2],HIGH);
    digitalWrite(led_red[0,3],HIGH);
    }
    else
    {
      digitalWrite(led_yellow[3],HIGH);
      digitalWrite(led_red[0,2],HIGH);
    }
    }


    
    else if(Tcount3>=Tcount4)
    {
      digitalWrite(led_green[2],HIGH);
      if(Tcount1>=Tcount2 && Tcount1>=Tcount4)
      {
        digitalWrite(led_yellow[0],HIGH);
        digitalWrite(led_red[1,3],HIGH);
      }
      else if(Tcount2>=Tcount4)
      {
        digitalWrite(led_yellow[1],HIGH);
        digitalWrite(led_red[0,3],HIGH);
      }
      else
      {
        digitalWrite(led_yellow[3],HIGH);
        digitalWrite(led_red[0,1],HIGH);
      }
      }


      
      else
      {
        digitalWrite(led_green[3],HIGH);
        if(Tcount1>=Tcount2 && Tcount1>=Tcount3)
        {
          digitalWrite(led_yellow[0],HIGH);
          digitalWrite(led_red[1,2],HIGH);
        }
        else if(Tcount2>=Tcount3)
        {
          digitalWrite(led_yellow[1],HIGH);
          digitalWrite(led_red[0,2],HIGH);
        }
        else
        {
          digitalWrite(led_yellow[2],HIGH);
          digitalWrite(led_red[0,1],HIGH);
        }
        }
    }
  
  
 }
 

 
