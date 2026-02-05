#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

const int SIZE = 5;
int matrix5x5[SIZE][SIZE];

bool ledState[8][8];  
int litCount = 0;

unsigned long startTime;
bool timerStarted = false;

void printMatrix() {
  Serial.println("5x5 matrix:");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      Serial.print(matrix5x5[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void fillRandomMatrix() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix5x5[i][j] = random(0, 10);
    }
  }
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));


  fillRandomMatrix();
  printMatrix();


  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      ledState[r][c] = false;
    }
  }

  startTime = millis();
  timerStarted = true;
}

void loop() {
  if (litCount >= 64) {
    if (timerStarted) {
      unsigned long elapsed = millis() - startTime;
      Serial.print("Matrix filled in ms: ");
      Serial.println(elapsed);
      timerStarted = false;
    }
    return;
  }

  int row = random(0, 8);
  int col = random(0, 8);

  if (!ledState[row][col]) {
    lc.setLed(0, row, col, true);
    ledState[row][col] = true;
    litCount++;
  }

  delay(50);
}
