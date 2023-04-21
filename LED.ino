//const int ledPin = LED_BUILTIN;
const int ledPin = 28;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if(millis()%2000 < 1000){
    digitalWrite(ledPin, HIGH);
  } else {
     digitalWrite(ledPin, LOW);
  }
  */
  digitalWrite(ledPin, HIGH);

}
