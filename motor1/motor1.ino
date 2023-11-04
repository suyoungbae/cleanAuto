#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial Serial2(2);  // Serial2 사용 (RX: GPIO 16, TX: GPIO 17)
int motorPin1 = 2;  // 2번 DC 모터 핀
int motorPin2 = 4;  // 4번 DC 모터 핀
int ledPin = 27;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);  // UART 통신 시작

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 데이터를 받아오고 분석
  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    int sensorValue1, sensorValue2;
    sscanf(data.c_str(), "%d,%d", &sensorValue1, &sensorValue2);

    // 센서 값을 사용하여 모터 속도 또는 방향을 제어
    analogWrite(motorPin1, sensorValue1);  // 2번 DC 모터
    analogWrite(motorPin2, sensorValue2);  // 4번 DC 모터

    // 다른 동작 수행
    digitalWrite(ledPin, HIGH);
    delay(1000);

    // 필요한 동작 수행
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}