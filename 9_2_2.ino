const int MODE = 8; //GP8
const int M1_IN_A = 9; //GP9
const int M1_IN_B = 10; //GP10

int t = 0;
float speed = 0.0;

void motor(float p){ // p must be -1.0 to 1.0
  if(p > 0){
    analogWrite(M1_IN_A, 0);
    analogWrite(M1_IN_B, (int)(p*65535.0));
  } else {
    analogWrite(M1_IN_B, 0);
    analogWrite(M1_IN_A, (int)(-p*65535.0));
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(MODE, OUTPUT);
  digitalWrite(MODE, LOW);
  analogWriteFreq(20000); //PWM set to 2kHz
  analogWriteResolution(8); // Analog range set to 0~65535
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*試す*/
  //t = (t+1)%2;
  //motor((float)(t-100)/100.0); //-1.0 to 1.0
  //delay(100);
  /**/

  
  char incomingByte;
  if(Serial.available()>0){
    incomingByte = Serial.read();

    if(incomingByte == 'f'){
      if(speed < 0){
        speed *= -1;
      }
    } else if(incomingByte == 'b'){
      if(speed > 0){
        speed *= -1;
      }
    } else if(incomingByte == 'h'){
      if(speed > 0 && speed < 1.0){
        speed += 0.05;
      } else if(speed <= 0 && speed > -1.0){
        speed -= 0.05;
      }
    } else if(incomingByte == 'l'){
      if(speed < 0){
        speed  += 0.05;
      } else if(speed >= 0){
        speed -= 0.05;
      }
    }
    Serial.println(speed);
    motor(speed);
  }
}
