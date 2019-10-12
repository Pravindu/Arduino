//Libraries
#include <DHT.h>

//Constants
#define DHTPIN 6     // what pin we're connected to
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

float temp; 
float temp1;
int freq;
int i;
int j;
int count;
int soundsensor = A1;
int sound;
int tempsound;
float avgs;
int tots;
float temps;
int lightsensor = A0;
int light;
int light1;
bool enter;
bool motionpresent;
bool fan_on;
bool heat_on;
bool light_on;
bool motion1;
bool motion2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin(); //temperature
  pinMode(2, INPUT);// motion
  pinMode(3, INPUT);// motion
  pinMode(4, INPUT);// motion
  pinMode(5, INPUT);// motion
  pinMode(11, OUTPUT);// for lights
  pinMode(12, OUTPUT);// for AC or Fans
  pinMode(13, OUTPUT);// for Heater
  pinMode(LED_BUILTIN, OUTPUT);
  bool enter=false;
  bool motionpresent=false;
  bool light_on=false;
  bool fan_on =false;
  bool heat_on =false; 
  count = 0;
  avgs = 50;
  tots = 0;
}

void entercheck(){
  motion1=false;
  for (i=0; i<500; i++){
    if (digitalRead(2)==HIGH){
      motion1=true;
      delay(2);
    }
  }
  if (motion1){
    for (i=0;i<1000; i++){
      if (digitalRead(3)==HIGH){
        enter=true; 
      }
      delay(2);
    }
  }
}
void exitcheck(){
  motion2=false;
  for (i=0; i<500; i++){
    if (digitalRead(3)==HIGH){
      motion2=true;
      delay(2);
    }
  }
  if (motion2){
    for (i=0;i<1000; i++){ 
      if (digitalRead(2)==HIGH){
        enter=false;
      }
      delay(2);
    }
  }
  else{
  } 
}
void motioncheck(){
  motionpresent=false;
  freq=0;
  for (j=0;j<2000; j++){
    if ((digitalRead(5)==HIGH) or (digitalRead(4)==HIGH)){
      freq=freq+1;
    }
    tempsound = analogRead(soundsensor);
    if (tempsound > 0 ){
      sound = tempsound;
    }
    tots = (tots +sound)/2;
    delay(5);
  } 
  temps = temps+tots;
  count = count + 1;
  if (count == 10){
    avgs = temps/10;
    if (avgs>55){
      avgs = 55;
    }
    temps=0;   
    count=0; 
  }
  sound = analogRead(soundsensor);
  if ((not motionpresent) and (freq>5)){
    if (sound>=avgs+5){
      motionpresent = true;
    }
  }
  if (freq >250){
     motionpresent=true;
  }
  if (freq >500){
    enter=true;
  }
  if (freq <10){
    enter = false;  
    motionpresent = false;
  }
  Serial.print(sound);
  Serial.print(", "); 
  Serial.print(avgs);
  Serial.print(", ");
  tots=0;
}
void systemoff(){
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  light_on = false;
  fan_on =false;
  heat_on =false;   
  Serial.print("null");
  Serial.print(", ");  
  Serial.print("null");
  Serial.print(", ");
}

void systemon(){
  temp1 = dht.readTemperature();
  if (temp1-temp <10 or temp1-temp >-10){
    temp = temp1;
  }
  Serial.print(temp);
  Serial.print(", ");
  if (heat_on){
    if (temp>20){
      heat_on = false;
    }
  }
  if (fan_on){
    if (temp<20){
      fan_on = false;
    }
  }
  if (temp > 25){
    fan_on = true;
  }
  if (temp < 15){
    heat_on = true;
  }
  if (heat_on){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  if (fan_on){
    digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(12,LOW);
  } 
  light1 = analogRead(lightsensor);
  if (light-light1<50 or light-light1 >-50){
    light=light1;
  }
  Serial.print(light);
  Serial.print(", ");
  if (not light_on)
  {
    if (light < 200){
      digitalWrite(11,HIGH);
      light_on = true;
    }
  }
  else{
    if (light>600){
      digitalWrite(11,LOW);
      light_on = false;
    }
  }
  light=analogRead(lightsensor);
  temp = dht.readTemperature();
}



void loop() {
  // put your main code here, to run repeatedly:
  if (not enter){
    entercheck();
  }
  else{
    exitcheck();
  }
  motioncheck();
  if (enter){
    Serial.print("Enter, ");
  }
  else{
    Serial.print("Exited, ");
  }
  if (motionpresent){
    Serial.print("Active, ");
  }
  else{
    Serial.print("Inactive, ");
  }
  if (motionpresent or enter){
    digitalWrite(LED_BUILTIN,HIGH);
    systemon();
  }  
  else{
    digitalWrite(LED_BUILTIN,LOW);
    systemoff();
  }
  if (heat_on){
    Serial.print("Heater on");
    Serial.print(", ");
  }
  else{
    Serial.print("Heater off");
    Serial.print(", ");
  }
  if (fan_on){
    Serial.print("Fan on");
    Serial.print(", ");
  }
  else{
    Serial.print("Fan off");
    Serial.print(", ");
  }
  if (light_on){
      Serial.print("Lights on");
      Serial.print(", ");
  }
  else{
    Serial.print("Lights off");
    Serial.print(", ");
  }
  Serial.println();
}
