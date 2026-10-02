#include <graphics.h>
#include <conio.h>

int pupilX = 320;
int pupilY = 240;

/* Draw the complete virtual eye */
void drawEye()
{
    cleardevice();

    /* White portion / sclera */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(320, 240, 0, 360, 200, 110);
    floodfill(320, 240, WHITE);

    /* Iris */
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    circle(pupilX, pupilY, 55);
    floodfill(pupilX, pupilY, BLUE);

    /* Pupil */
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(pupilX, pupilY, 25);
    floodfill(pupilX, pupilY, BLACK);

    /* Reflection / highlight */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(pupilX - 10, pupilY - 10, 8);
    floodfill(pupilX - 10, pupilY - 10, WHITE);

    /* Eyelids */
    setcolor(LIGHTRED);
    setlinestyle(SOLID_LINE, 0, 3);
    arc(320, 240, 0, 180, 200);
    arc(320, 240, 180, 360, 200);

    /* Instructions */
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(210, 400, "ARROW KEYS = MOVE PUPIL");
    outtextxy(235, 420, "ESC = EXIT");
}

/* Update pupil position */
void moveEye(int key)
{
    int step = 10;

    if (key == 75)
        pupilX -= step;       /* Left */

    else if (key == 77)
        pupilX += step;       /* Right */

    else if (key == 72)
        pupilY -= step;       /* Up */

    else if (key == 80)
        pupilY += step;       /* Down */

    /* Boundary control */
    if (pupilX < 250)
        pupilX = 250;

    if (pupilX > 390)
        pupilX = 390;

    if (pupilY < 200)
        pupilY = 200;

    if (pupilY > 280)
        pupilY = 280;
}

int main()
{
    int gd = DETECT;
    int gm;
    int key;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    while (1)
    {
        drawEye();
        key = getch();

        if (key == 27)
            break;

        /* Extended keyboard key */
        if (key == 0 || key == 224)
        {
            key = getch();
            moveEye(key);
        }
    }

    closegraph();
    return 0;
}
