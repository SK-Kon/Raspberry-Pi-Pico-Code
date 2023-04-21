const int BUTTON = 17;
int count = 0;

#define min 100

void setup(){
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);
    Serial.begin(9600);
}

void loop(){
}


void switchPressed(){
  unsigned long gauge = 0;
  while(!digitalRead(BUTTON)){
    gauge++;
  }
  if(gauge > min){
    Serial.println(++count);
  }
}