#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

/*h es mi tamaño de paso*/
#define h 0.1

/*a, b y c son mis constantes donde (a+b+c)>0 */
#define a 10
#define b 28
#define c (8/3)

/*Xi y Yi son mis condiciones iniciales*/
#define Xi 3
#define Yi 0
#define Zi 0
#define ti 0

/*Inicio y Fin son mis limites indicados*/
#define Inicio 0
#define Fin 40

void RK(double X[]);
double fX(double X[]);
double fY(double X[]);
double fZ(double X[]);

int main(void)
{
  double i;
  double k1, k2, k3, k4;
  double X[3];

  
  //cout<<setprecision(5);

  //Se establece un arreglo unidimensional de tres espacios que contiene el valor (x, y, z) de cada punto
  X[0]=Xi;//x[0] siempre contiene el valor de X
  X[1]=Yi;//x[1] contiene el valor de Y
  X[2]=Zi;//x[2] contiene el valor de Z
  cout<<"X"<<"\t"<<"Y"<<"\t"<<"Z"<<endl;
  cout<<X[0]<<"\t"<<X[1]<<"\t"<<X[2]<<endl;//imprime los valores de x,y,z
  
  for(i=Inicio; i<Fin; i=i+h)
    {
      RK(X);//hace un loop para calcular runge kutta 4 para x, y, z, uno por uno, en total hace ((inicio-fin)/h) ciclos
    }
}

//La funcion donde se guarda el proceso para hacer una iteracion del metodo RK
//para tres variables, x, y Y z
//los resultados se guardan en arreglos y se acumulan con los del ciclo anterior
//asi como se imprimen en pantalla en la misma funcion
//Variables de entrada: arreglo double x[]
//variables de salida: ninguna (funcion void)

void RK(double X[])
{
  //se declaran cinco arreglos por cada variable necesaria para las ecuaciones de RK4
  double k1[3], k2[3], k3[3], k4[3], X1[3];
  double x, y, z;
  
  //cout<<setprecision(5);
  
  //se calculan al mismo tiempo cada k por variable (k1 de x, y y z, k2 de las mismas variables y así sucesivamente hasta k4)
  //por lo que se hace el metodo de runge-kutta de 1ero hasta 4to orden
  //x1 se usa para guardar resultados de las tres variables por ciclo

  k1[0]= h*(fX(X));//calcula runge kutta 1 con la funcion de x
  k1[1]= h*(fY(X));//... con la funcion de y
  k1[2]= h*(fZ(X));//... con la funcion de  z
  
  X1[0]=(X[0])+(0.5*(k1[0]));//calcula el resultado de x lo cual se guarda en x1[0], x[0] es la posicion inicial y k1 es runge kutta de orden 1 para x
  X1[1]=(X[1])+(0.5*(k1[1]));//resultado de y se guarda en x1[1], x[1] es el valor inicial de y, k1 es rk1 para y
  X1[2]=(X[2])+(0.5*(k1[2]));//resultado de z se guarda en x1[2], x[2] valor inicial de z, k1 es rk1 para z
  k2[0]= h*(fX(X1));//runge kutta 2 con la funcion de x, evaluando la funcion con el valor que nos dio x1
  k2[1]= h*(fY(X1));//rk2 con la funcion de y ...
  k2[2]= h*(fZ(X1));//rk2 con la funcion de z ...
  //cout<<"X0: "<<X1[0]<<"\t"<<"X1: "<<X1[1]<<"\t"<<"X2: "<<X1[2]<<endl;
  //cout<<"k2: "<<k2[0]<<"\t"<<"k2: "<<k2[1]<<"\t"<<"k2: "<<k2[2]<<endl;
  
  X1[0]=(X[0])+(0.5*(k2[0]));//guarda el resultado de rk2 de x, y se ponene los otros valores de la formula
  X1[1]=(X[1])+(0.5*(k2[1]));
  X1[2]=(X[2])+(0.5*(k2[2]));
  k3[0]= h*(fX(X1));//calcula runge kutta 3 para x
  k3[1]= h*(fY(X1));
  k3[2]= h*(fZ(X1));
  //cout<<"X0: "<<X1[0]<<"\t"<<"X1: "<<X1[1]<<"\t"<<"X2: "<<X1[2]<<endl;
  //cout<<"k3: "<<k3[0]<<"\t"<<"k3: "<<k3[1]<<"\t"<<"k3: "<<k3[2]<<endl;
  
  X1[0]=(X[0])+(k3[0]);//formula para obtener el resultado de x
  X1[1]=(X[1])+(k3[1]);
  X1[2]=(X[2])+(k3[2]);
  k4[0]= h*(fX(X1));//runge kutta 4
  k4[1]= h*(fY(X1));
  k4[2]= h*(fZ(X1));
  //cout<<"X0: "<<X1[0]<<"\t"<<"X1: "<<X1[1]<<"\t"<<"X2: "<<X1[2]<<endl;
  //cout<<"k4: "<<k4[0]<<"\t"<<"k4: "<<k4[1]<<"\t"<<"k4: "<<k4[2]<<endl;

  x=(k1[0])+(2*(k2[0]))+(2*(k3[0]))+(k4[0]);//formula para obtener el resultado de rk de x
  y=(k1[1])+(2*(k2[1]))+(2*(k3[1]))+(k4[1]);//obtner resultado de y
  z=(k1[2])+(2*(k2[2]))+(2*(k3[2]))+(k4[2]);//obtener resultado de z
  //cout<<"x: "<<x<<"\t"<<"y: "<<y<<"\t"<<"z: "<<z<<endl;
  x=(x/6);//a x, y, z les asignamos el valor de el resultado de la formula anterior entre 6
  y=(y/6);
  z=(z/6);
  //cout<<"x: "<<x<<"\t"<<"y: "<<y<<"\t"<<"z: "<<z<<endl;
  X[0]=(X[0])+(x);//se cambia la posicion inicial de x, y, z a la cual solo se le suma el valor del resultado de todos los rk
  X[1]=(X[1])+(y);
  X[2]=(X[2])+(z);
  
  cout<<X[0]<<"\t"<<X[1]<<"\t"<<X[2]<<endl;//imprimimos los resultados de x, y, z
}

/**
*Las funciones usadas en todo el proceso son funciones ya pasadas en su forma vectorial
*/

double fX(double X[])
{
  return (a*(X[1]-X[0]));//funcion de x
}
double fY(double X[])
{
  return ((X[0]*(b-X[2]))-X[1]);//funcion de y
}
double fZ(double X[])
{
  return ((X[0]*X[1])-(c*X[2]));//funcion de z
}

