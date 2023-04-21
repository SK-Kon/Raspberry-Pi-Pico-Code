const int MODE = 8; //GP8
const int M1_IN_A = 9; //GP9
const int M1_IN_B = 10; //GP10

int t = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MODE, OUTPUT);
  pinMode(M1_IN_A, OUTPUT);
  pinMode(M1_IN_B, OUTPUT);
  digitalWrite(MODE, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = (t+1)%2;

  if(t==0){
    digitalWrite(M1_IN_A, HIGH);
    digitalWrite(M1_IN_B, LOW);
  } else {
    digitalWrite(M1_IN_A, LOW);
    digitalWrite(M1_IN_B, HIGH);
  }
  delay(1000);
}
