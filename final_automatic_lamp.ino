const int ledPin = 3;
const int ldrPin = A0;
int pirPin = 7;                 
int pirStat = 0; 
String movement = "Yes";
void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);
pinMode(pirPin, INPUT); 

}

void loop() {
  

int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 50) {
if(movement=="Yes"){
digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);
delay(60000);
}
digitalWrite(ledPin,LOW);
pirStat = digitalRead(pirPin);
Serial.println(pirStat);
if(pirStat == 1){
  Serial.println(pirStat);
  Serial.print("Movement\n");
  movement = "Yes";
  digitalWrite(ledPin,HIGH);
}
else{
  Serial.println(pirStat);
  Serial.print(" No Movement\n");
  movement = "No";
  digitalWrite(ledPin,LOW);
  
}
while(movement == "No"){
  Serial.print("Noooo movement");
  pirStat = digitalRead(pirPin);
  if (pirStat == 1){
    movement = "Yes";
    }
  
  }

}

 
else {

digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}


}
