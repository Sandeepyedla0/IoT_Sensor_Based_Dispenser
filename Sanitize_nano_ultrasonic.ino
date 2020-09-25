const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
int Relay = 12; 
int count=0;
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(Relay, OUTPUT);
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(Relay,HIGH);
   long duration, inches, cm;
   
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);
   
    cm = microsecondsToCentimeters(duration);
   if(count==0){
        digitalWrite(Relay,HIGH);
        count=count+1;
        Serial.println("Count  zero");
        delay(500);
    }
  if(count==1){
   if(cm<=15){
      digitalWrite(Relay, LOW);
      Serial.print("relay high here :");
      Serial.println(cm);
      delay(750);
      digitalWrite(Relay,HIGH);
      delay(1000);
   
    }
  }
    else{
      delayMicroseconds(10);
      Serial.print("Relay Low");
      digitalWrite(Relay,HIGH);
      }
   
   Serial.print(cm);
   Serial.print("cm");
   
   Serial.println();
   digitalWrite(Relay,HIGH);
   
}



long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
