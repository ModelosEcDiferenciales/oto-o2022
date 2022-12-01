#include<iostream>
#include<cmath>
using namespace std;

/h es mi tamaño de paso/
#define h 0.1
/Xi y Yi son mis condiciones iniciales/
#define Xi 0
#define Yi 1
/Inicio y Fin son mis limites indicados/
#define Inicio 0
#define Fin 1

double F(double x, double y);/Funcion derivada/
double Y(double x);/Funcion/

int main(void)
{
  double i, x, y, res[100], x1, y1, x2, y2;
  double k1, k2, k3;
  int cont=1;

  res[0]=Yi;
  for(i=Inicio; i<Fin; i=i+h)
    {
      /Punto 1/
      x=i;
      y=res[cont-1];
      k1=F(x, y);//K1
      k2=F(x+(h/2), y+((k1*h)/2));//K2
      k3=F(x+h, y-(k1*h)+(2*k2*h));//K3

      res[cont]=y+((h/6)*(k1+(4*k2)+k3));
      cont++;
    }

  /Código para imprimir bonito los datos/
  i=cont;
  x=Xi;
  cout<<"X\tYrk3\t\tY\t\tError%"<<endl;
  for(cont=0; cont<i; cont++)
    {
      //cout<<x<<"\t"<<res[cont]<<endl;
      cout<<x<<"\t"<<res[cont]<<"\t\t"<<Y(x)<<"\t\t"<<(((res[cont])-(Y(x)))/(Y(x)))*100<<endl;
      x=x+h;
    }
}

double F(double x, double y)
{
  //return ((-2*y*y)+(x*y)+(x*x));
  //return ((x)+(2*x*y));
  return ((-2*x*x*x)+(12*x*x)-(20*x)+(8.5));
}
double Y(double x)
{
  return (((-0.5)*x*x*x*x)+(4*x*x*x)-(10*x*x)+(8.5*x)+(1));
}
