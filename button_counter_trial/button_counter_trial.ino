int PIN = 2; 
int counter = 0;
int state = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(PIN,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

state = digitalRead(PIN);

if( state == 1){
  delay(100);
  counter++;
  if(counter ==10){ counter = 0;}
}
//Serial.println("Button state" );
//Serial.print(state);
Serial.println(counter);


}
