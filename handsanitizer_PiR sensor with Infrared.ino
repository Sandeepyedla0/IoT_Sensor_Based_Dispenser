
int IRSensor = 13;
int lamp = 8; // choose the pin for the RELAY
int inputPin = 4; // choose the input pin (for PIR sensor)

int val = 0; // variable for reading the pin status


void setup() {
pinMode (IRSensor, INPUT); // sensor pin INPUT
pinMode(lamp, OUTPUT); // declare lamp as output

pinMode(inputPin, INPUT); // declare sensor as input

Serial.begin(9600);

}

void loop(){
int statusSensor = digitalRead (IRSensor);
val = digitalRead(inputPin); // read input value
Serial.print("Here PIR value");
Serial.println(val);

if( val== 1) {
  int statusSensor = digitalRead (IRSensor);
  Serial.print("Here Status of IR value");
  Serial.println(statusSensor);

    if(statusSensor==0){
      digitalWrite(lamp, HIGH); 
      delay(250);
      digitalWrite(lamp,LOW);
      statusSensor=1;
      val=0;
      
    }
    
    
digitalWrite(lamp,LOW);
} else {
  //Serial.println("Here Irstatus ", statusSensor);
  //Serial.println("Here PIR value",val);
  digitalWrite(lamp,LOW); // turn OFF the lamp
 
//delay(100);
}
}
