//Sample encoder code copied from
// https//playground.arduino.cc/Main/RotaryEncoders/

#define encoder0PinA 7
#define encoder0PinB 6
volatile int encoder0Pos = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  attachInterrupt(encoder0PinA, doEncoderA, CHANGE); //割り込み関数指定
  attachInterrupt(encoder0PinB, doEncoderB, CHANGE); //割り込み関数指定
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(M_PI*(encoder0Pos%2000) / 1000);
  delay(500);
}

void doEncoderA(){
  // look for a low-to-high on channel A
  if(digitalRead(encoder0PinA) == HIGH){
    // check channel B to see which way encoder is turning
    if(digitalRead(encoder0PinB) == LOW){
      encoder0Pos = encoder0Pos + 1;        // CW
    } else {
      encoder0Pos = encoder0Pos - 1;        // CCW
    }
  } else { // must be a high-to-low edge on channel A
    // check channel B to see which way encoder is turning
    if(digitalRead(encoder0PinB) == HIGH){
      encoder0Pos = encoder0Pos + 1;        // CW
    } else {
      encoder0Pos = encoder0Pos - 1;        // CCW
    }
  }
}

void doEncoderB(){
  // look for a low-to-high on channel B
  if(digitalRead(encoder0PinB) == HIGH){
    // check channel A to see which way encoder is turning
    if(digitalRead(encoder0PinA) == HIGH){
      encoder0Pos = encoder0Pos + 1;        // CW
    } else {
      encoder0Pos = encoder0Pos - 1;        // CCW
    }
  } else { // must be a high-to-low edge on channel B
    // check channel A to see which way encoder is turning
    if(digitalRead(encoder0PinA) == LOW){
      encoder0Pos = encoder0Pos + 1;        // CW
    } else {
      encoder0Pos = encoder0Pos - 1;        // CCW
    }
  }
}


