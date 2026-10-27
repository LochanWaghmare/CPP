#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawCircle(int xc, int yc, int r)
{
    int x, y, p;

    x = 0;
    y = r;

    p = 1 - r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cleardevice();

    drawCircle(320, 240, 100);

    outtextxy(210, 370, "Midpoint Circle Drawing Algorithm");

    getch();
    closegraph();

    return 0;
}