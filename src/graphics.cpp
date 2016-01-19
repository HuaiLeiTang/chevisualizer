// graphics.cpp

#include <QtOpenGL>

#include "graphics.h"
// DDA algorithm
void Graphics::DDA(int x1, int y1, int x2, int y2)
{
    int steps;
    int dx = x2 -x1;
    int dy = y2 -y1;
    if(abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    float stepx, stepy;
    if (steps != 0)
    {
        stepx = (float) dx /steps;
        stepy = (float) dy /steps;
    }
    int i;
    float x = (float)x1,y = (float)y1;
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    for(i=0;i<steps;i++)
    {
        glVertex2f((int)x,(int)y);
        printf("%d,%d\n",(int)x,(int)y);
        x += stepx;
        y += stepy;
    }
    glEnd();
    glFlush();
}
// Bresenhams algorithm
void Graphics::Bresenham(int x1, int y1, int x2, int y2)
{
    int steps;
    int dx = x2 -x1;
    int dy = y2 -y1;
    int x = x1,y = y1;
    int stepx, stepy;
    stepx = (dx<0)?-1:1;
    stepy = (dy<0)?-1:1;

    if(abs(dx) > abs(dy))
    {
        steps = abs(dx);
        int p = 2*abs(dy) - abs(dx);
        glBegin(GL_POINTS);
        int stepl= 2*abs(dy);
        int stepg= 2*abs(dy)-2*abs(dx);
        for(int i=0;i<steps;i++)
        {
            if (p<0)
            {
                p += stepl;
            }
            else
            {
                p += stepg;
                y += stepy;
            }
            x += stepx;
            glVertex2f(x,y);
            printf("%d,%d\n",x,y);
        }
        glEnd();
    }
    else
    {
        int p = 2*abs(dx) - abs(dy);
        steps = abs(dy);
        int stepl= 2*abs(dx);
        int stepg= 2*abs(dx)-2*abs(dy);
        glBegin(GL_POINTS);
        for(int i=0;i<steps;i++)
        {
            if (p<0)
            {
                p += stepl;
            }
            else
            {
                p += stepg;
                x += stepx;
            }
            y += stepy;
            glVertex2f(x,y);
            printf("%d,%d\n",x,y);
        }
        glEnd();
    }
    //glFlush();
}
// Midpoint algorithm
void Graphics::Circle(int xc, int yc, int r)
{
    int x = 0,y = r,p=1-r;
    glBegin(GL_POINTS);
    do
    {
        x+=1;
        if (p<0)
        {
            p += 2*x+1;
        }
        else
        {
            y -= 1;
            p += (2*x-2*y+2);
        }

        glVertex2f(xc+x,yc+y);
        glVertex2f(xc-x,yc+y);
        glVertex2f(xc+x,yc-y);
        glVertex2f(xc-x,yc-y);
        glVertex2f(xc+y,yc+x);
        glVertex2f(xc-y,yc+x);
        glVertex2f(xc+y,yc-x);
        glVertex2f(xc-y,yc-x);
        printf("%d,%d\n",xc+x,yc+y);
    }
    while(x<=y);
    glEnd();
    glFlush();
}
