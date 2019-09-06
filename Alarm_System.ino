void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);

}



void loop() {

  // put your main code here, to run repeatedly:

  if ((digitalRead(1) == HIGH) OR (digitalRead(2) == HIGH) OR (digitalRead(3) == HIGH)){  //position 1 sensors
    if ((digitalRead(4) == HIGH) OR (digitalRead(5) == HIGH) OR (digitalRead(6) == HIGH)){ //position 2 sensors
      if ((digitalRead(7) == HIGH) OR (digitalRead(8) == HIGH)){  //position 3 sensors
        if ((digitalRead(9) == HIGH) OR (digitalRead(10) == HIGH)){ //position 4 sensors
          if ((digitalRead(11) == HIGH) OR (digitalRead(12) == HIGH)){ //position 5 sensors
              digitalWrite(13,HIGH);     // Activate Alarm
              delay(3000);
          }
        }
      }
    }
  }
  else{
    digitalWrite(13,LOW);   // deactivate alarm
  }

  delay(1000);

}
