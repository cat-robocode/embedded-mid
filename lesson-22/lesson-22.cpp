#include <lesson-22.hpp>
#include <Arduino.h>
#include <GameBoy.h>

static GameBoy gb;
static int x = 0, y = 0;

void GameBOYv0::init()
{
    gb.begin(16);
}
void GameBOYv0::update()
{
    gb.drawPoint(x, y);
    y++;
    delay(250);
    gb.wipePoint(x, y - 1);
    delay(250);
    if (y > 15)
    {
        y = 0;
    }
}
void GameBOYv1::init()
{
    gb.begin(15);
}
void GameBOYv1::update()
{
    if (gb.getKey() > 0)
    {
        gb.wipePoint(x, y);
        if (gb.getKey() == 4 && gb.isFree(x - 1, y))
        {
            x--;
        }
        if (gb.getKey() == 5 && gb.isFree(x + 1, y))
        {
            x++;
        }
        if (gb.getKey() == 6 && gb.isFree(x, y + 1))
        {
            y++;
        }
        if (gb.getKey() == 3 && gb.isFree(x, y - 1))
        {
            y--;
        }
    }
    gb.drawPoint(x, y);
    delay(15);
}
void GameBOYv2::init()
{

    gb.begin(15);
}
void GameBOYv2::update()
{
    if (gb.getKey() > 0)
    {
        gb.wipePoint(x, y);
        if (gb.getKey() == 4 && gb.isFree(x - 1, y))
        {
            x--;
        }
        if (gb.getKey() == 5 && gb.isFree(x + 1, y))
        {
            x++;
        }
        if (gb.getKey() == 6 && gb.isFree(x, y + 1))
        {
            y++;
        }
        if (gb.getKey() == 3 && gb.isFree(x, y - 1))
        {
            y--;
        }
    }
    gb.drawPoint(x, y);
    delay(15);
}