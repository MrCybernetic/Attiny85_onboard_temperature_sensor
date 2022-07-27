#define LED_PIN 0

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

// Dumb test to verify VSCode config -> ✔ Test successfull
void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
}
