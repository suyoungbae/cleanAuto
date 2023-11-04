const int trigPin1 = 14;
const int echoPin1 = 27;
const int trigPin2 = 18;
const int echoPin2 = 19;

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);

  // 초음파 센서 핀 설정
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // 초음파 센서로 거리 측정
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // 거리 출력
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // 1초 동안 대기
  delay(1000);

  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // 거리 출력
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // 1초 동안 대기
  delay(1000);

}