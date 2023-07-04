#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "NBxt4DsrHn8LvCL61lbFAlpAJ2z9b4M1"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ssid";
char pass[] = "pass";

//motor control value
int motor_left = D5;
int IN3 = D2;
int IN4 = D3; 

int motor_right = D4;
int IN1 = D0;
int IN2 = D1;

//motor function
void motor(int left,int right){
  //left
  if(left >= 0){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);    
  }
  else{
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    left = -left;    
  }
  analogWrite(motor_left,left);

  //right
  if(right >= 0){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);    
  }
  else{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    right = -right;    
  }
  analogWrite(motor_right,right);
}

int Speed = 300;
int TurnSpeed = 250; 

BLYNK_WRITE(V1)
{  
  if(param.asInt() == 1){motor(Speed,Speed);} // forward
  else{motor(0,0);}
}

BLYNK_WRITE(V2)
{  
  if(param.asInt() == 1){motor(-Speed,-Speed);} // bake
  else{motor(0,0);}
}
BLYNK_WRITE(V3)
{  
  if(param.asInt() == 1){motor(-TurnSpeed,TurnSpeed);} // turn left 
  else{motor(0,0);}
}
BLYNK_WRITE(V4)
{  
  if(param.asInt() == 1){motor(TurnSpeed,-TurnSpeed);}
  else{motor(0,0);}
}


void setup() {
  //motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(motor_left,OUTPUT);
  pinMode(motor_right,OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  motor(0,0);
}

void loop() {
  Blynk.run();
}
