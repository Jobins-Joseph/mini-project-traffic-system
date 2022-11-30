int led_green[]={10,11,12,13};
int led_yellow[]={14,15,16,17};
int led_red[]={18,19,20,21};
int Tcount1,Tcount2,Tcount3,Tcount4;
void setup() {
pinMode(led_green,OUTPUT);
pinMode(led_yellow,OUTPUT);
pinMode(led_red,OUTPUT);

}

void loop() {
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
  
  
