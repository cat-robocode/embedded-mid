#include <Arduino.h>
#include <GameBoy.h>
#include <lesson-24.hpp>

static GameBoy gb;
static int enemy_x = 3;
static int car_speed = 100;
static int mycar_x = 2;
static int mycar_y = 12;

void enemyCar(int x, int y)
{
    gb.drawPoint(x, y);
    gb.drawPoint(x, y - 1);
    gb.drawPoint(x - 1, y - 1);
    gb.drawPoint(x + 1, y - 1);
    gb.drawPoint(x, y - 2);
    gb.drawPoint(x - 1, y - 3);
    gb.drawPoint(x + 1, y - 3);
}
void playerCar(int x, int y)
{
    gb.drawPoint(x, y);
    gb.drawPoint(x, y + 1);
    gb.drawPoint(x - 1, y + 1);
    gb.drawPoint(x + 1, y + 1);
    gb.drawPoint(x, y + 2);
    gb.drawPoint(x - 1, y + 3);
    gb.drawPoint(x + 1, y + 3);
}
void clearPlayerCar(int x, int y)
{
    gb.wipePoint(x, y);
    gb.wipePoint(x, y + 1);
    gb.wipePoint(x - 1, y + 1);
    gb.wipePoint(x + 1, y + 1);
    gb.wipePoint(x, y + 2);
    gb.wipePoint(x - 1, y + 3);
    gb.wipePoint(x + 1, y + 3);
}

void clearEnemyCar(int x, int y)
{
    gb.wipePoint(x, y);
    gb.wipePoint(x, y - 1);
    gb.wipePoint(x - 1, y - 1);
    gb.wipePoint(x + 1, y - 1);
    gb.wipePoint(x, y - 2);
    gb.wipePoint(x - 1, y - 3);
    gb.wipePoint(x + 1, y - 3);
}
void createLine(int y) {
  gb.drawPoint(0, y);
  gb.drawPoint(0, y + 1);
  gb.drawPoint(0, y + 2);

  gb.drawPoint(7, y);
  gb.drawPoint(7, y + 1);
  gb.drawPoint(7, y + 2);
}

void clearLine(int y) {
  gb.wipePoint(0, y);
  gb.wipePoint(0, y + 1);
  gb.wipePoint(0, y + 2);

  gb.wipePoint(7, y);
  gb.wipePoint(7, y + 1);
  gb.wipePoint(7, y + 2);
}
void Racing::init()
{
    gb.begin(0);
  playerCar(mycar_x, mycar_y);
  randomSeed(analogRead(0));
}
void Racing::updatev0()
{
    for (int enemy_y = 0; enemy_y < 16; enemy_y++)
    {
        enemyCar(enemy_x, enemy_y);
        delay(car_speed);
        clearEnemyCar(enemy_x, enemy_y);
        ;
    }

    if (gb.getKey() == 4)
    {
        clearPlayerCar(5, 12);
        playerCar(2, 12);
    }
    else if (gb.getKey() == 5)
    {
        clearPlayerCar(2, 12);
        playerCar(5, 12);
    }
}
void Racing::updatev1()
{

    for (int enemy_y = 0; enemy_y < 16; enemy_y++)
    {
        enemyCar(enemy_x, enemy_y);
        if (gb.getKey() == 4)
        {
            clearPlayerCar(5, 12);
            playerCar(2, 12);
        }
        else if (gb.getKey() == 5)
        {
            clearPlayerCar(2, 12);
            playerCar(5, 12);
        }
        delay(car_speed);
        clearEnemyCar(enemy_x, enemy_y);
    }
}
void mainRaicing() {
  enemy_x = random(0, 10);
  if (enemy_x > 5) {
    enemy_x = 2;
  }
  else {
    enemy_x = 5;
  }
  for (int enemy_y = 0; enemy_y < 16; enemy_y++) {
    enemyCar(enemy_x, enemy_y);
    if (gb.getKey() == 4) {
      clearPlayerCar(5, 12);
      playerCar(2, 12);
    }
    else if (gb.getKey() == 5) {
      clearPlayerCar(2, 12);
      playerCar(5, 12);
    }
    delay(car_speed);
    clearEnemyCar(enemy_x, enemy_y);
  }
}
void near_last(){
    for (int enemy_y = 0; enemy_y < 16; enemy_y++) {
  createLine(enemy_y);
  createLine(enemy_y + 5);
  createLine(enemy_y + 10);
  createLine(enemy_y + 15);

  enemyCar(enemy_x, enemy_y);
  if (gb.getKey() == 4) {
    clearPlayerCar(5, 12);
    playerCar(2, 12);
  }
  else if (gb.getKey() == 5) {
    clearPlayerCar(2, 12);
    playerCar(5, 12);
  }
  delay(car_speed);
  clearLine(enemy_y);
  clearLine(enemy_y + 5);
  clearLine(enemy_y + 10);
  clearLine(enemy_y + 15);

  clearEnemyCar(enemy_x, enemy_y);
}
}
void last(){
    for (int enemy_y = 0; enemy_y < 16; enemy_y++) {
  createLine(enemy_y);
  createLine(enemy_y + 5);
  createLine(enemy_y + 10);
  createLine(enemy_y + 15);
  createLine(enemy_y - 5);
  createLine(enemy_y - 10);
  createLine(enemy_y - 15);
  
  enemyCar(enemy_x, enemy_y);
  if (gb.getKey() == 4) {
    clearPlayerCar(5, 12);
    playerCar(2, 12);
  }
  else if (gb.getKey() == 5) {
    clearPlayerCar(2, 12);
    playerCar(5, 12);
  }
  
  delay(car_speed);
  
  clearLine(enemy_y);
  clearLine(enemy_y + 5);
  clearLine(enemy_y + 10);
  clearLine(enemy_y + 15);
  clearLine(enemy_y - 5);
  clearLine(enemy_y - 10);
  clearLine(enemy_y - 15);
  
  clearEnemyCar(enemy_x, enemy_y);
}
}