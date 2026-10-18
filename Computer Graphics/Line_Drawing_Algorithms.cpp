#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, steps, xInc, yInc;
    float x, y;
    int i;

    dx = x2 - x1;
    dy = y2 - y1;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    xInc = dx / steps;
    yInc = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)x, (int)y, WHITE);
        x = x + xInc;
        y = y + yInc;
    }
}

void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx, dy, p;
    int x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x <= x2)
    {
        putpixel(x, y, YELLOW);

        x++;

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("\n===== LINE DRAWING ALGORITHMS =====\n");
    printf("\n1. DDA Line Drawing");
    printf("\n2. Bresenham Line Drawing");
    printf("\n3. Both Algorithms");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    cleardevice();

    if (choice == 1)
    {
        DDA(150, 150, 450, 300);
        outtextxy(200, 330, "DDA Line Drawing Algorithm");
    }
    else if (choice == 2)
    {
        Bresenham(150, 150, 450, 300);
        outtextxy(180, 330, "Bresenham Line Drawing Algorithm");
    }
    else if (choice == 3)
    {
        DDA(100, 150, 300, 300);
        outtextxy(120, 320, "DDA");

        Bresenham(350, 150, 550, 300);
        outtextxy(390, 320, "Bresenham");
    }
    else
    {
        outtextxy(200, 200, "Invalid Choice");
    }

    getch();
    closegraph();

    return 0;
}