/*---------------------KRENOVATOR---------------------
  LEVEL 2
  CONTROL THE INHOUSE LIGHTS & FANS

  The codes is for Blynk apps on controls the inhouse 
  lights, with the use of relay.

!!!!!!!!!!!!!!!-------DISCLAIMER-------!!!!!!!!!!!!!!!
  The following circuit contains the connection with
  the high voltage. User is advise to study before
  do the connection. DO NOT PLAYING WITH THE HIGH
  VOLTAGE! We are not going to take any responsibility
  for any of your injury.

  Get the code at github
  https://github.com/MZulsyahmi/smart-voice-assistant-L2.0.git
  
  by M.Zulsyahmi @krenovator
  September 2018
 */


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourNetworkPassword";

//initialize the pin to be used
int diningRoom = D6;      //connect to IN1
int bedRoom = D7;         //connect to IN2
//int kitchen = D8;
//int fan = D8;

//the blynk virtual pin
//command to ON or OFF all lights
BLYNK_WRITE(V1) {
  int pinV1 = param.asInt();
  if(param.asInt()){
    digitalWrite(diningRoom, HIGH);
    digitalWrite(bedRoom, HIGH);
    //digitalWrite(kitchen, HIGH);
  }
  else{
    digitalWrite(diningRoom, LOW);
    digitalWrite(bedRoom, LOW);
    //digitalWrite(kitchen, LOW);
  }
}

//command to control Dining Room
BLYNK_WRITE(V2){
  int pinV2 = param.asInt();
  if(param.asInt()){
    digitalWrite(diningRoom, HIGH);
  }
  else{
    digitalWrite(diningRoom, LOW);
  }
}

//command to control BedRoom
BLYNK_WRITE(V3){
  int pinV2 = param.asInt();
  if(param.asInt()){
    digitalWrite(bedRoom, HIGH);
  }
  else{
    digitalWrite(bedRoom, LOW);
  }
}

//command to control kitchen
/*BLYNK_WRITE(V4){
  int pinV2 = param.asInt();
  if(param.asInt()){
    digitalWrite(kitchen, HIGH);
  }
  else{
    digitalWrite(kitchen, LOW);
  }
}*/

//command to control Fan
/*BLYNK_WRITE(V5){
  int pinV2 = param.asInt();
  if(param.asInt()){
    digitalWrite(fan, HIGH);
  }
  else{
    digitalWrite(fan, LOW);
  }
}*/

void setup(){
  // Debug console
  Serial.begin(9600);

  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
