int ir7=8;  
 int count7;  
 int Tcount4;
 boolean state7 = false; 
  int ir8=9;  
 int count8;  
 boolean state8 = false;  
 void setup()  
 {  
  Serial.begin(9600);  
  pinMode(ir7, INPUT);  
  pinMode(ir8, INPUT);
  count8=0;
  count7=0;  
  Tcount4=0;   
 }  
 void loop()  
 {  
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
 }
 

 
