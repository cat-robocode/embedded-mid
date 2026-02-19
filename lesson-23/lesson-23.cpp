#include <Arduino.h>
#include <lesson-23.hpp>
#include <GameBoy.h>

static GameBoy gb;
static int x[4] = {2, 3, 2, 2};
static int y[4] = {3, 3, 4, 4};
static int i = 0;

void racing_game::init()
{
    gb.begin(0);
}
void racing_game::update()
{
    gb.drawPoint(x[i], y[i]);
    delay(500);
    gb.wipePoint(x[i], y[i]);
    i++;
    if (i > 3)
    {
        i = 0;
    }
}
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
void draw_car::init()
{
    gb.begin(0);
}
void draw_car::update()
{
    enemyCar(3, 12);
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
void draw_player::init()
{
    gb.begin(0);
}
void draw_player::update()
{
    playerCar(3, 1);
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
void movement::init()
{
    gb.begin(0);
}
void movement::update()
{
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