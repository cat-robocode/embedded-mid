
#include <LedControl.h>

int counter = 0;
LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
    pinMode(2, INPUT);
}

void loop() {
    if (digitalRead(2)) {
        lc.setLed(0, counter - 1, 2, 0);
        if (counter > 7) {
            counter = 0;
            lc.setLed(0, 0, 2, 0);
        }
        delay(250);
    }
    lc.setLed(0, counter, 2, 1);
}