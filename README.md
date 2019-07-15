# Arduino
SIT 107

1.2P Task SOS

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500);                      
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500);                       
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500);                       
  //single 'S'
  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1500);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1500);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500); 
  //single 'O'
  
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500); 
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500); 
  //single 'S'
  
  
  delay(1000); // brief interval before the next SOS
}
