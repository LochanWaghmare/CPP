#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawRectangle(int x1, int y1, int x2, int y2)
{
    rectangle(x1, y1, x2, y2);
}

void translation()
{
    cleardevice();

    setcolor(WHITE);
    drawRectangle(150, 150, 250, 220);
    outtextxy(150, 230, "Original");

    setcolor(YELLOW);
    drawRectangle(300, 200, 400, 270);
    outtextxy(300, 280, "Translated");

    outtextxy(150, 350, "Translation: X + 150, Y + 50");
    getch();
}

void scaling()
{
    cleardevice();

    setcolor(WHITE);
    drawRectangle(150, 150, 250, 220);
    outtextxy(150, 230, "Original");

    setcolor(YELLOW);
    drawRectangle(300, 120, 500, 260);
    outtextxy(350, 270, "Scaled");

    outtextxy(150, 350, "Scaling: X2 and Y2");
    getch();
}

void rotation()
{
    cleardevice();

    int x[4], y[4];
    int i;
    float angle, rad;
    int cx = 320, cy = 240;

    x[0] = 270; y[0] = 200;
    x[1] = 370; y[1] = 200;
    x[2] = 320; y[2] = 120;
    x[3] = 270; y[3] = 200;

    setcolor(WHITE);

    for(i = 0; i < 3; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);

    outtextxy(250, 290, "Original Triangle");

    // Rotation angle
    angle = 45;
    rad = angle * 3.14159 / 180;

    for(i = 0; i < 4; i++)
    {
        int oldX = x[i];
        int oldY = y[i];

        x[i] = cx + (oldX - cx) * cos(rad)
                    - (oldY - cy) * sin(rad);

        y[i] = cy + (oldX - cx) * sin(rad)
                    + (oldY - cy) * cos(rad);
    }

    setcolor(YELLOW);

    for(i = 0; i < 3; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);

    outtextxy(250, 310, "Rotated by 45 degrees");

    getch();
}

void reflection()
{
    cleardevice();

    setcolor(WHITE);
    line(200, 180, 300, 180);
    line(300, 180, 250, 100);
    line(250, 100, 200, 180);

    outtextxy(200, 200, "Original");

    setcolor(LIGHTGRAY);
    line(100, 300, 500, 300);

    outtextxy(450, 310, "X-axis");

    setcolor(YELLOW);
    line(200, 420, 300, 420);
    line(300, 420, 250, 500);
    line(250, 500, 200, 420);

    outtextxy(200, 520, "Reflection");

    getch();
}

int main()
{
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    do
    {
        cleardevice();

        printf("\n===== 2D TRANSFORMATIONS =====\n");
        printf("\n1. Translation");
        printf("\n2. Scaling");
        printf("\n3. Rotation");
        printf("\n4. Reflection");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                translation();
                break;

            case 2:
                scaling();
                break;

            case 3:
                rotation();
                break;

            case 4:
                reflection();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice!");
                getch();
        }

    } while(choice != 5);

    closegraph();

    return 0;
} 0