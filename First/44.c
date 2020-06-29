/*
The coordinates of 3 angles of a rectangle are given. Determine the
coordinates of the fourth angle.*/

#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3 ,x4 , y4;
    printf ("Dati coordonatele");
    scanf ("%f, %f, %f, %f, %f, %f", &x1, &y1, &x2, &y2, &x3, &y3);

    if ((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1) == 0 )
    {
        x4 = x3+x2-x1;
        y4 = y3+y2-y1;
    }
    else if ((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2) == 0)
    {
        x4 = x3+x1-x2;
        y4 = y3+y1-y2;
    }
    else if ((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3) == 0)
    {
        x4 = x2+x1-x3;
        y4 = y2+y1-y3;
    }
    else
    {
        printf ("Nu sunt virfuri de dreptunghi");
        return 0;
    }

    printf ("Coordonatele  x %f si y %f", x4, y4);
    return 0;
}
