#include <iostream>
#include <cmath>
using namespace std;
float F(float x,float y){
  float fa = (-2*pow(x, 3))+(12*pow(x,2))-(20*x)+8.5;
    return fa; 
}//f
float Euler(float x, float h, float yf)
{
  float y[24];
  int i;
  y[0]=yf;
  for(i=0; i<=8; i++)//x es hasta 4 pero como los arreglos no pueden ir de .5 en .5 lo multiplique por 2(porque es 1/2), si es para .25 por 4(porque es 1/4) 
    {
      y[i+1]=y[i]+(F(x, y[i])*h);
    printf("%.2f,%.2f,%.2f\n", x,y[i], y[i+1]);
     x=x+h;
    }
  return y[8];
}
float ErrorRelativo(float Eu, float real)
{
  float ER=(real-Eu)/real;
  return ER;
}
int main(void)
{
  float h=.5, y=1, x=0, Eu, real=3.2187;
  printf("x,y, y+.5\n");
  Eu=Euler(x, h,y);
  printf("El error relativo es %f\n",ErrorRelativo(Eu, real));
}
