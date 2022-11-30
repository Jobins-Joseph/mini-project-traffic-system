int RCLK = 11;
int SER = 12;
int SRCLK = 10;

#define TotalIC 1
#define TotalICPins TotalIC * 8

boolean Data[TotalICPins];

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  ClearBuffer();
}              


void loop()
{
   for(int i = TotalICPins - 1; i >=  0; i--)
   {
      Data[i] = HIGH;
      UpdateData();
      delay(300);
      ClearBuffer();
   }

   for(int i = 1;i < TotalICPins - 1;  i++)
   {
      Data[i] = HIGH;
      UpdateData();
      delay(300);
      ClearBuffer();
   }
   onBuffer();
   delay(300);
   
}

void ClearBuffer()
{
    for(int i = TotalICPins - 1; i >=  0; i--)
    {
       Data[i] = LOW;
    }
    UpdateData();
} 

void onBuffer()
{
    for(int i = TotalICPins - 1; i >=  0; i--)
    {
       Data[i] = HIGH;
    }
    UpdateData();
} 

void UpdateData()
{
   digitalWrite(RCLK, LOW);
   for(int i = TotalICPins - 1; i >=  0; i--)
   {
        digitalWrite(SRCLK, LOW);   
        digitalWrite(SER, Data[i]);
        digitalWrite(SRCLK, HIGH);

  }
  digitalWrite(RCLK, HIGH);
}
