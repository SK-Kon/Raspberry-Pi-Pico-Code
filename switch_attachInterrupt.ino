const int LED = 28;
const int BUTTON = 17;

void switchPressed()
{
  if (digitalRead(BUTTON) == HIGH){
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}

void setup()
{
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);
}

void loop ()
{
} 