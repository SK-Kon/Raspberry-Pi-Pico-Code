const int ADC0 = 26; //GP26
const int ADC1 = 27; //GP27
const int ADC2 = 28; //GP28
const int CheckPin = 16; //GP16

struct repeating_timer st_tm1ms;
int ax, ay, az;
int chk = 0;


bool tm1ms(struct repeating_timer *t){
  chk = !chk;
  digitalWrite(CheckPin, chk);
  ax = analogRead(ADC1);
  ay = analogRead(ADC0);
  az = analogRead(ADC2);

  Serial.write(ax>>6);
  Serial.write(ax&0x3F);
  Serial.write(ay>>6);
  Serial.write(ay&0x3F);
  Serial.write(az>>6);
  Serial.write(az&0x3F);
  Serial.write(0xFF);

  return true;
}



void setup() {
  pinMode(CheckPin, OUTPUT);
  Serial.begin(921600);
  analogReadResolution(12); //set the ADC resolution to 12bit
  add_repeating_timer_us(1000, tm1ms, NULL, &st_tm1ms);
}

void loop() {
}
