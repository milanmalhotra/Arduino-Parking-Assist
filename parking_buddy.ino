//defining values
#define trigger_pin 3 
#define echo_pin 4  
#define green 10    
#define blue 11    
#define red 12  

//assigning pinModes 
void setup() {
  Serial.begin (9600); 
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() { //calculating distance 
  long duration, distance; 
  digitalWrite(trigger_pin, LOW); 
  delayMicroseconds(500);        
  digitalWrite(trigger_pin, HIGH); 
  delayMicroseconds(500);     
  digitalWrite(trigger_pin, LOW);  
  duration = pulseIn(echo_pin, HIGH);   
  distance = (duration/2) / 29.1;    

//if distance is less than or equal to 10 cm, turn red led on
  if (distance <= 10) {  
    digitalWrite(red,HIGH); 
    digitalWrite(blue,LOW);
    digitalWrite(green, LOW);
}

//if distance is between 10 and 20 cm, turn blue led on
  if (distance >10 && distance <25 ) {  
    digitalWrite(green, HIGH);  
    digitalWrite(red, LOW); 
    digitalWrite(blue,LOW);
  }

//if distance is greater than 20 cm, turn greeen led on
  if (distance >25 && distance <40) {  
    digitalWrite(blue, HIGH); 
    digitalWrite(red, LOW); 
    digitalWrite(green,LOW);
  }

//if distance is greater than or equal to 40 cm, turn led off
  if (distance >=40) {  
    digitalWrite(blue, LOW); 
    digitalWrite(red, LOW); 
    digitalWrite(green,LOW);
  }  
//showing distance in cm on serial with a delay of 500 ms
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}


  
  
