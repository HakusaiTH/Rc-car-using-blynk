#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "<token>"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "<ssid>";
char pass[] = "<pass>";

int IN1 = D1;
int IN2 = D2;
int IN3 = D3;
int IN4 = D4;

void fd() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
}

void bk() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void sl() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void sr() {
 digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void ao() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);

}

BLYNK_WRITE(V1)
{  
  if(param.asInt() == 1){fd();}
  else{ao();}
}

BLYNK_WRITE(V2)
{  
  if(param.asInt() == 1){bk();}
  else{ao();}
}
BLYNK_WRITE(V3)
{  
  if(param.asInt() == 1){sl();}
  else{ao();}
}
BLYNK_WRITE(V4)
{  
  if(param.asInt() == 1){sr();}
  else{ao();}
}


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  ao();
}

void loop() {
  Blynk.run();
}
