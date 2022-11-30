int IR1=2;
int count=0;
int n=0;
void setup() {
  // put your setup code here, to run once:
pinMode(IR1,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int irstate1=!digitalRead(IR1);
if(irstate1 == n)
{
  digitalWrite(n,LOW);
  if( n == LOW)
  {
    count++;
  }
  digitalWrite(n,HIGH);
  Serial.println(count);
  delay(1000);
} 
}
