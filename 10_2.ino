const int MODE = 8;
const int M1_IN_PHASE = 9;
const int M1_IN_ENABLE = 10;
const int M2_IN_PHASE = 11;
const int M2_IN_ENABLE = 12;

int i;


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
    Rotation_Speed_Manager(90, 1);
  } else if(incomingByte == 'b'){
    Rotation_Speed_Manager(-45, 2);
  }
}


void Rotation_Speed_Manager(int angle, int speed){
  /*step angle = 0.9*/
  int count = (int)((angle/0.9) / 4);
  int pulseHz = (int)((60*speed/0.9) / 4);

  Serial.print("count: ");
  Serial.print(count);
  Serial.print(" pulseHz: ");
  Serial.println(pulseHz);

  if(angle > 0){
    for(i = 0; i < count; i++){
      digitalWrite(M1_IN_PHASE, HIGH); // 状態：M1=正/M2=逆
      delay(pulseHz);
      digitalWrite(M2_IN_PHASE, HIGH); // 状態：M1=正/M2=正
      delay(pulseHz);
      digitalWrite(M1_IN_PHASE, LOW); // 状態：M1=逆/M2=正
      delay(pulseHz);
      digitalWrite(M2_IN_PHASE, LOW); // 状態：M1=逆/M2=逆
      delay(pulseHz);
    }
  } else if(angle < 0){
    for(i = 0; i > count; i--){
      digitalWrite(M2_IN_PHASE, HIGH); // 状態：M2=正/M1=逆
      delay(pulseHz);
      digitalWrite(M1_IN_PHASE, HIGH); // 状態：M1=正/M2=正
      delay(pulseHz);
      digitalWrite(M2_IN_PHASE, LOW); // 状態：M2=逆/M1=正
      delay(pulseHz);
      digitalWrite(M1_IN_PHASE, LOW); // 状態：M1=逆/M2=逆
      delay(pulseHz);      
    }
  }
}
