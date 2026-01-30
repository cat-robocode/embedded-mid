#include <Arduino.h>
#include <lesson-20.hpp>

void practice_1_random_matrix()
{
  int array[3][2];
  Serial.println("Your matrix:");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
       array[i][j] = random(0,6);
       Serial.print(array[i][j]);
       Serial.print("\t");
    }
    Serial.print("\n");
  }
}