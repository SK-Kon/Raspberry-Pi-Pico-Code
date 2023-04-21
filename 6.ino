#include<Servo.h>
#define servo 22

Servo myservo;

void setup(){
  myservo.attach(servo);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int incomingByte;

  if(Serial.available() > 0){
    char ch = Serial.read();
    if(isdigit(ch)){
      incomingByte = ch-'0';
        //Serial.println(num);
    }

    //ここで送られてきたキーに応じた処理
    int num = incomingByte;
    if(num >= 0 && num < 10){
      int degree = num*20;
      myservo.write(degree);
      
      //確認
      //Serial.println(degree);
      Serial.print("you put ");
      Serial.println(num);
      Serial.print("Rotate to ");
      Serial.println(degree);
    }
  }
  delay(15);
}
