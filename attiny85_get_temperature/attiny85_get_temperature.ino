#include <SoftwareSerial.h>
#define comRx 3
#define comTx 0

SoftwareSerial soft_serial = SoftwareSerial(comRx, comTx);

void setup() {
    soft_serial.begin(9600);
    OSCCAL = 65;
    uint8_t AD_mem = ADMUX;
    ADMUX = 0b10101111 & (0b10001111 | AD_mem);// Set ADMUX to 0x8F in order to choose ADC4 and Set VREF to 1.1V (Without changing ADLAR p134 in datasheet)
}

void loop() {
    ADCSRA = 0b01000000 | ADCSRA; // run conversion
    while (bitRead(ADCSRA, 6) == 1) {
        delayMicroseconds(10);
    }
    soft_serial.println((ADCH << 8) | ADCL);
    delay(1000);
}
