#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//#define h 0.1
/Xi y Yi son mis condiciones iniciales/
#define Xi 0
#define Yi 1
/Inicio y Fin son mis limites indicados/
#define Inicio 0
#define Fin 6

double F(double x, double y);/Funcion derivada/
double Y(double x);/Funcion/

int main(void)
{
  long double i, h=0.7, x, y, y4, y5, error, E, n;
  long double k1, k2, k3, k4, k5, k6;
  long double H;
  cout<<setprecision(5);
  
  x=Xi;
  y=Yi;
  n = (Yi/h);
  for(i=Inicio; i<Fin; i=i+h)
    {
      k1=F(x, y);//K1
      k2=F(x+(h/5), y+((k1*h)/5));//K2
      k3=F(x+((3*h)/10), y+((3*k1*h)/40)+((9*h*k2)/40));//K3
      k4=F(x+((3*h)/5), y+((3*k1*h)/10)-((9*k2*h)/10)+((6*k3*h)/5));//K4
      k5=F(x+h, y-((11*k1*h)/54)+((5*k2*h)/2)-((70*k3*h)/27)+((35*k4*h)/27));
      k6=F(x+((7*h)/8), y+((1631*k1*h)/55296)+((175*k2*h)/512)+((575*k3*h)/13824)-((44275*k4*h)/110592)+((253*k5*h)/4096));
      
      y4=y+((h)*(((37*k1)/378)+((250*k3)/621)+((125*k4)/594)+((512*k6)/1771)));
      y5=y+((h)*(((2825*k1)/27648)+((18575*k3)/48384)+((13525*k4)/55296)+((277*k5)/14336)+((k6)/4)));
      E=(((227/64512)*k1*h)+((-0.01866858609)*k3*h)+((0.03415502683)*k4*h)+((227/14336)*k5*h)+((-0.03910220215)*k6*h));
      error=(y5-y4);
      H=h*(pow((E/error), 0.225));//0.0225   n
      cout<<x<<"\t"<<y4<<"\t"<<y5<<"\t"<<E<<"\t"<<error<<"\t"<<H<<endl;

      x=i+h;
      y=y4;
    }
}

double F(double x, double y)
{
  return ((-2*x*x*x)+(12*x*x)-(20*x)+(8.5));
}
double Y(double x)
{
  return (((-0.5)*x*x*x*x)+(4*x*x*x)-(10*x*x)+(8.5*x)+(1));
}