 
 int ir1=2;  
 int count=0;  
 boolean state = true;  
 void setup()  
 {  
  Serial.begin(9600);  
  pinMode(ir1, INPUT);   
 }  
 void loop()  
 {  
  if (!digitalRead(ir1) && state){  
    count++;  
    state = false;  
    Serial.print("Count: ");  
    Serial.println(count);   
    delay(100);  
  }  
  if (digitalRead(ir1))  
  {  
    state = true;  
    delay(100);  
  }  
 }
