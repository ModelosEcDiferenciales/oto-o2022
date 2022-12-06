#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dy(x,y) (3*y - x)
#define F(x,y) (-2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5)
#define G(x) (-0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x + 1)

float rungeKutta4(float x, float y, float h)
{
        float k1, k2, k3, k4;

        k1 = F(x, y);
        k2 = F((x + (h/2)), (y + ((k1 * h) / 2)));
        k3 = F((x + (h/2)), (y + ((k2 * h) / 2)));
        k4 = F((x + h), (y + (k3 * h)));
        return (y + ((h/6) * (k1 + (2*k2) + (2*k3) + k4)));
}

float euler(float x, float y, float h)
{
        return (y + F(x,y)*h);
}

int main()
{
        float x=0 , xRunge;
        float yEuler=1, yRunge=1;
        float h=0.1;
        float i, reslt, k1, k2, k3, k4;

        system ("clear");

        printf ("\nValor X, Y Real, Y Euler, Y Runge, Error Euler, Error Runge\n");

        printf ("%f, %f, %f, %f, %f, %f\n", x, G(x), yEuler, yRunge, 100*((yEuler-G(x))/G(x)), 100*((yRunge-G(x))/G(x)));

        for (x=h; x<=1.0; x+=h)
        {
                printf ("%f, %f, %f, %f, %f, %f\n", x, G(x), euler(x-h, yEuler, h), rungeKutta4(x-h, yRunge, h),  100*((euler(x-h, yE>
                yEuler = euler(x-h, yEuler, h);
                yRunge = rungeKutta4(x-h, yRunge, h);
        }
        printf ("%f, %f, %f, %f, %f, %f\n", x, G(x), euler(x-h, yEuler, h), rungeKutta4(x-h, yRunge, h),  100*((euler(x-h, yEuler, h)>

        printf ("\n");
        return 0;
}
