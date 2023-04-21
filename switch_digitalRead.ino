const int LED = 28;
const int BUTTON = 17;


void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
} 
