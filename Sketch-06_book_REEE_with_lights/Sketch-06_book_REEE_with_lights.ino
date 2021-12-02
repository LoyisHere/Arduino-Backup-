int sensorValue;
int sensorLow = 1023;//sets the photo resistor to no sound at maximum light
int sensorHigh = 0;//REEEE at pitch black
const int ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while(millis() <5000){
    sensorValue = analogRead(A0);

    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;}
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;}
    }
    digitalWrite(ledPin, LOW);
  }
//setup calibrates yoursensor, sets the high and low parameters 

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50,4000);

  tone(8,pitch,20);

  delay(10);
}
