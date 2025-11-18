#include <glew.h>
#include <freeglut.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include <string>

#pragma comment(lib, "glew32.lib")
#define p 3.1415f

using namespace std;


float caseRad = 350.0f;
float secRad = 300.0f;
float secRotAngle = 0.0f;
float minRotAngle = 0.0f;
float minRad = 230.0f;
float hourRotAngle = 0.0f;
float hourRad = 170.0f;

void drawText(string text, float x, float y, float scale = 0.05, float r = 1, float g = 1, float b = 1, float angle = 0.0f) {
    
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);
    for (int i = 0;  text[i] != '\0'; i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    }
    glPopMatrix();
}

int getTime(int id)
{
    auto now = chrono::system_clock::now();
    auto nown = chrono::system_clock::to_time_t(now);
    tm local;
    localtime_s(&local, &nown);

    switch (id)
    {
    case 1:
        return local.tm_hour % 12;
        break;
    case 2:
        return local.tm_min;
        break;
    case 3:
        return local.tm_sec;
        break;
    default:
        return 0;
        break;
    }
}

void updateTime()
{
    int hour = getTime(1);
    int minute = getTime(2);
    int second = getTime(3);

    secRotAngle = (90.0f - second * 6.0f);
    minRotAngle = (90.0f - (minute * 6.0f));
    hourRotAngle = (90.0f - (hour * 30.0f));
}

void drawNumber(int id, int j = 1, float deg = 6.0f, float rad = 270.0f) {

    string num = to_string(j);

    if (id == 1) {
        for (int i = 1; i <= 12; i++) {
            float angle = (90.0f - i * 30.0f) * p / 180.0f;
            float distance = 300.0f;
            float x = distance * cos(angle);
            float y = distance * sin(angle);

            drawText(to_string(i), x - 15, y - 5, 0.3f, 1.0f, 0.5f, 0.0f);
        }
    }

    else if (id == 2) {

        float angle = (90.0f - j * deg) * p / 180.0f;
        float x = rad * cos(angle);
        float y = rad * sin(angle);

        drawText(num, x, y, 0.3f, 1.0f, 1.0f, 1.0f, secRotAngle);
    }

    else if (id == 3) {
        float angle = (90.0f - j * deg) * p / 180.0f;
        float x = rad * cos(angle);
        float y = rad * sin(angle);

        drawText(num, x, y, 0.3f, 1.0f, 1.0f, 1.0f, minRotAngle);
    }

    else if (id == 4) {
        float angle = (90.0f - j * deg) * p / 180.0f;
        float x = rad * cos(angle);
        float y = rad * sin(angle);

        drawText(num, x, y, 0.3f, 1.0f, 1.0f, 1.0f, hourRotAngle);
    }
}

void initTime(int v)
{
    updateTime();
    glutPostRedisplay();
    glutTimerFunc(1000, initTime, 0);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // بدنه ساعت
    glColor3f(1.0f, 0.3f, 0.0f);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 720; i++)
    {
        float a = 2.0f * p * (float(i) / 720.0f);
        float x = caseRad * cos(a);
        float y = caseRad * sin(a);
        glVertex2f(x, y);
    }
    glEnd();

    // دقیقه ها خطوط
    glColor3f(1.0f, 0.3f, 0.0f);
    for (int i = 0; i < 60; i++) {

        float angle = (90.0f - i * 6.0f) * p / 180.0f;
        if (i % 5 == 0) {

            float x1 = 330 * cos(angle);
            float y1 = 330 * sin(angle);

            float x2 = 350 * cos(angle);
            float y2 = 350 * sin(angle);
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
        }
        else {
            float x1 = 340 * cos(angle);
            float y1 = 340 * sin(angle);

            float x2 = 350 * cos(angle);
            float y2 = 350 * sin(angle);
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
        }
    }

    // عقربه ساعت
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(hourRad * cos(hourRotAngle * p / 180.0f), hourRad * sin(hourRotAngle * p / 180.0f));
    glEnd();

    // عقربه دقیقه
    glColor3f(0.0f, 0.2f, 0.8f);
    glLineWidth(6);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(minRad * cos(minRotAngle * p / 180.0f), minRad * sin(minRotAngle * p / 180.0f));
    glEnd();

    // عقربه ثانیه
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(secRad * cos(secRotAngle * p / 180.0f), secRad * sin(secRotAngle * p / 180.0f));
    glEnd();

    // اعداد ساعت
    drawNumber(1); // اعداد صفحه اصلی
    drawNumber(2, getTime(3)); // عدد روی عقربه ثانیه
    drawNumber(3, getTime(2), 6.0f, 200.0f); // عدد روی عقربه دقیقه
    drawNumber(4, getTime(1), 30.0f, 150.0f); // عدد روی عقربه ساعت

    glFlush();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500, 500, -500, 500, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int, int)
{
    if (key == 27) exit(0);
}

void setup()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("clock");

    glewInit();

    updateTime();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    setup();
    glutTimerFunc(1000, initTime, 1);
    glutMainLoop();
    return 0;
}
