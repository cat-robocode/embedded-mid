#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loop() {
    lc.setLed(0, 3, 3, 1);
    lc.setLed(0, 4, 3, 1);
    lc.setLed(0, 3, 4, 1);
    lc.setLed(0, 4, 4, 1);
}