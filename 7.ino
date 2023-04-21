const int analogOutPin = 21;
unsigned long t;
int outputValue = 128, v = 128;

int incomingByte;

void setup() {
  // put your setup code here, to run once:
  analogWriteFreq(60000);
  Serial.begin(921600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(Serial.available()>0){
    //incomingByte = Serial.read();
    //incomingByte -= 48;
  //}
  if (Serial.available()>0) {
    char ch = Serial.read();
    //Serial.println(ch);
    if(isdigit(ch)){
      incomingByte = ch-'0';
        //Serial.println(num);
    }
  }

  t = micros();

  if(incomingByte == 1){
    v = (int)(128.0 * sin(2.0 * PI * 261.6 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 2){
    v = (int)(128.0 * sin(2.0 * PI * 293.7 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 3){
    v = (int)(128.0 * sin(2.0 * PI * 329.6 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 4){
    v = (int)(128.0 * sin(2.0 * PI * 349.2 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 5){
    v = (int)(128.0 * sin(2.0 * PI * 392.0 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 6){
    v = (int)(128.0 * sin(2.0 * PI * 440.0 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 7){
    v = (int)(128.0 * sin(2.0 * PI * 493.9 * (float)t/1000000.0)+127.0);
  } else if(incomingByte == 8){
    v = (int)(128.0 * sin(2.0 * PI * 523.2 * (float)t/1000000.0)+127.0);
  }
  Serial.print("num: ");
  Serial.print(incomingByte);
  Serial.print(" | v: ");
  Serial.println(v);
  analogWrite(analogOutPin, v);
}
/*
int Doremi(unsigned long t, int num){
  int v;
  if(num == 1){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 261.6 * (float)t/1000000.0)+127.0);
    Serial.println(v);
  } else if(num == 2){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 293.7 * (float)t/1000000.0)+127.0);
  } else if(num == 3){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 329.6 * (float)t/1000000.0)+127.0);
  } else if(num == 4){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 349.2 * (float)t/1000000.0)+127.0);
  } else if(num == 5){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 392.0 * (float)t/1000000.0)+127.0);
  } else if(num == 6){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 440.0 * (float)t/1000000.0)+127.0);
  } else if(num == 7){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 493.9 * (float)t/1000000.0)+127.0);
  } else if(num == 8){
    Serial.println(num);
    v = (int)(128.0 * sin(2.0 * PI * 523.2 * (float)t/1000000.0)+127.0);
  } else{
    v = 128;
  }
  return v;
}
*/
