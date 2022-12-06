#include <iostream>
#include <cmath>
using namespace std;

//Definicion de parametros para la funcion
#define c 0.2
#define a 300
#define w 1

//Definicion del paso que se usara en X
#define h 0.001

//Definicion de ecuacion de Duffing
#define F(t,y,x) (x-(pow(x,3))-(c*y)+(a*cos((w*t))))

//Struct para atrapar datos
typedef struct out{
  double x;
  double xp;
} out_t;


//funcion para calcular Runge Kutta 4
out_t rk4(double y0, double x0, double t0, double tf){
  double yn = y0, xn = x0;
  double kx1, kx2, kx3, kx4, ky1, ky2, ky3, ky4;
  double temp;
  for (double tn = t0; tn < tf; tn+=h) {
    kx1 = h*yn;
    ky1 = h*F(tn, yn, xn);
    kx2 = h*(yn + ky1/2);
    ky2 = h*F(tn + h/2, yn + ky1/2, xn + kx1/2);
    kx3 = h*(yn+ky2/2);
    ky3 = h*F(tn + h/2, yn + ky2/2, xn + kx2/2);
    kx4 = h*(yn+ky3);
    ky4 = h*F(tn + h, yn + ky3, xn + kx3);

    xn = xn + ((kx1 + 2*kx2 + 2*kx3 + kx4)/6);
    yn = yn + ((ky1 + 2*ky2 + 2*ky3 + ky4)/6);
  }
  out_t salida;
  salida.x = xn;
  salida.xp = yn;
  return salida;
}
    
int main()
{
  //Declaracion de variables de salida
  float t=0;
  float x=10,y=15;

  //Impresion de primera linea
  cout << "T," << "X," << "Y" << endl;
  //cout << x << "," << y << "," << t << endl;


  out_t temp = {0, 0};
  cout << "t, x(t), x'(t)" << endl;
  for (int i = 0; i <= 1000; i++){
    temp = rk4(1, 0, 0, i);
   cout << i << ", " << temp.x << ", " << temp.xp << endl;
  }
  
  return 0;
}

