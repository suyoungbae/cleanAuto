//서보모터 2개 작동//led 작동
int servo1 = 5;
int servo2 = 4;

void setup() {
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
}
void loop() {
  digitalWrite(servo1, HIGH);
  digitalWrite(servo2, HIGH); 
  delay(1000);
  digitalWrite(servo1, LOW);
  digitalWrite(servo2, LOW);
  delay(1000); 
}










