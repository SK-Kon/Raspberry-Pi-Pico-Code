const int MODE = 8;
const int M1_IN_PHASE = 9;
const int M1_IN_ENABLE = 10;
const int M2_IN_PHASE = 11;
const int M2_IN_ENABLE = 12;


void setup() {
  // put your setup code here, to run once:
  pinMode(MODE, OUTPUT);
  digitalWrite(MODE, HIGH);  // Phase/Enableモード
  pinMode(M1_IN_PHASE, OUTPUT);
  pinMode(M1_IN_ENABLE, OUTPUT);
  pinMode(M2_IN_PHASE, OUTPUT);
  pinMode(M2_IN_ENABLE, OUTPUT);
  digitalWrite(M1_IN_ENABLE, HIGH);  //ブレーキ解除
  digitalWrite(M2_IN_ENABLE, HIGH);  //ブレーキ解除
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char incomingByte;
    
  if(Serial.available()>0){
    incomingByte = Serial.read();
  }
  if(incomingByte == 'f'){
    digitalWrite(M1_IN_PHASE, HIGH); // 状態：M1=正/M2=逆
    delay(10);
    digitalWrite(M2_IN_PHASE, HIGH); // 状態：M1=正/M2=正
    delay(10);
    digitalWrite(M1_IN_PHASE, LOW); // 状態：M1=逆/M2=正
    delay(10);
    digitalWrite(M2_IN_PHASE, LOW); // 状態：M1=逆/M2=逆
    delay(10);
  } else if(incomingByte == 'b'){
    digitalWrite(M2_IN_PHASE, HIGH); // 状態：M2=正/M1=逆
    delay(10);
    digitalWrite(M1_IN_PHASE, HIGH); // 状態：M1=正/M2=正
    delay(10);
    digitalWrite(M2_IN_PHASE, LOW); // 状態：M2=逆/M1=正
    delay(10);
    digitalWrite(M1_IN_PHASE, LOW); // 状態：M1=逆/M2=逆
    delay(10);
  }
}
