#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

/*Xi y Yi son mis condiciones iniciales*/
#define Xi 0
#define Yi 1
/*Inicio y Fin son mis limites indicados*/
#define Inicio 0
#define Fin 1

double F(double x, double y);/*Funcion derivada*/
double Y(double x, double y);/*Función solución*/
double Ranita(double h);/*Metodo*/

int main(void)
{
  Ranita(0.1);
}

double F(double x, double y)
{
  return ((-2*x*x*x)+(12*x*x)-(20*x)+(8.5));
}
double Y(double x, double y)
{
  return ((-0.5*x*x*x*x)+(4*x*x*x)-(10*x*x)+(8.5*x)+(1));
}
double Ranita(double h)
{
  double Xo, Yo, X1, Yp, Yc, i;
  Xo=Xi;
  Yo=Yi;
  cout<<setprecision(5);
  cout<<"X:"<<"\t"<<"Yranita"<<"\t"<<"Yreal"<<"\t"<<"Error"<<endl;
  cout<<Xi<<"\t"<<Yi<<"\t"<<Yi<<endl;
  for(i=Inicio; i+h<=Fin; i=i+h)
    {
      Xo=i;
      Yp=Yo+((h/2)*(F(Xo, Yo)));
      X1=Xo+(h/2);
      Yc=Yo+((h)*((F(X1, Yp))));
      Yo=Yc;
      cout<<i+h<<"\t"<<Yc<<"\t"<<Y(Xo+h,Yo+h)<<"\t"<<((((Y(Xo+h, Yo+h))-(Yc))/(Y(Xo+h, Yo+h)\
))*100)<<endl;
    }
  cout<<"\n\n"<<endl;
  return 0;
}
