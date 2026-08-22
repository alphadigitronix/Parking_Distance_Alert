/*
 * ALPHA DIGITRONIX SOLUTIONS
 * ADS Arduino Inventor Kit
 *
 * PROJECT 18: PARKING DISTANCE ALERT
 *
 * HC-SR04:
 * TRIG -> D9
 * ECHO -> D10
 *
 * LEDs:
 * GREEN  -> D4
 * YELLOW -> D5
 * RED    -> D6
 *
 * BUZZER -> D8
 */

#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 4
#define YELLOW_LED 5
#define RED_LED 6

#define BUZZER 8

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

void allLEDsOff() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  Serial.println("--------------------------------");
  Serial.println("ALPHADIGITRONIX SOLUTIONS");
  Serial.println("PARKING DISTANCE ALERT");
  Serial.println("--------------------------------");
}

void loop() {

  float distance = getDistance();

  if (distance < 0) {

    allLEDsOff();
    noTone(BUZZER);

    Serial.println("Object out of range");

    delay(300);
    return;
  }

  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.print(" cm | ");

  allLEDsOff();

  // SAFE
  if (distance > 50) {

    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);

    Serial.println("SAFE");

    delay(300);
  }

  // CAUTION
  else if (distance > 20) {

    digitalWrite(YELLOW_LED, HIGH);

    Serial.println("CAUTION");

    tone(BUZZER, 1000);
    delay(150);
    noTone(BUZZER);
    delay(650);
  }

  // WARNING
  else if (distance >= 10) {

    digitalWrite(RED_LED, HIGH);

    Serial.println("WARNING");

    tone(BUZZER, 1200);
    delay(120);
    noTone(BUZZER);
    delay(180);
  }

  // STOP
  else {

    digitalWrite(RED_LED, HIGH);

    Serial.println("STOP!");

    tone(BUZZER, 1500);

    delay(100);
  }
}