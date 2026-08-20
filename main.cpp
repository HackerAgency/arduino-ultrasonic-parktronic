#include <Arduino.h>

#define PIN_SPEAKER 13
#define PIN_LED 12
#define ECHO_PIN 10
#define TRIG_PIN 11

void setup() {
    Serial.begin(115200);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_SPEAKER, OUTPUT);
}

float readDistanceCM() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    int duration = pulseIn(ECHO_PIN, HIGH);
    return duration / 58;
}

void loop() {
    int durationCM = readDistanceCM();

    if (durationCM < 75) {
        digitalWrite(PIN_LED, HIGH);
        tone(PIN_SPEAKER, 800);
        delay(150);
        digitalWrite(PIN_LED, LOW);
        noTone(PIN_SPEAKER);
        delay((durationCM * 10));
    }
}
