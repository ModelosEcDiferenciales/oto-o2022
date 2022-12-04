/**
*@file: sistemasEG.cpp
*@brief: Este programa da solucion a una ecuacion diferencial
*       de segundo orden, haciendo una sustitucion de la segunda
*       derivada por una variable que cre un sistema de evcuaciones
*       diferenciales
*@author: Manuel Estrada
+@date: November 22 2022
*/
        //INCLUSION DE LIBRERIAS
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

        //DEFINICION DE CONSTANTES Y FUNCIONES MATEMÁTICAS
#define F(u) (u) // yp. yc
#define U(x,y) ((3*y)-x) // up. uc
#define inicialy 0.0
#define inicialu 1.0

        //DECLARACIÓN DE FUNCIONES

/**
*@brief: Esta funcion calcula el predictor de y para cierta posicion x
*@author: Manuel Estrada
*@date: November 22 2022
*@param: x, float, posicion anterior de x
*@param: y, float, valor de anterior de y
*@param: paso, float, cantidad recorrida en x
*@param: yp, float, valor para ypredictor
*/
double Upredictor(float x,float y, float paso){ //Predictor para y´=u
        double yp;
                        yp=y+(paso*U(x,y));
return yp;
}
/**
*@brief: Esta funcion calcula el predictor de u para cierta posicion x
*@author: Manuel Estrada
*@date: November 22 2022
*@param: u, float, posicion anterior de u
*@param: paso, float, cantidad recorrida en x
*@param: fp, float, valor para upredictor
*/
double Fpredictor(float u, float paso){//Predictor para u'=3y-x
        double up;
                        up=u+(paso*F(u));
return up;
}
/**
*@brief: Esta funcion calcula los predictores para u, y apartir de sus correctores
*@author: Manuel Estrada
*@date: November 22 2022
*@param: xi, float, posicion inicial de x
*@param: xf, float, posicion final de x
*@param: u0, float, valor de origen para u
*@param: y0, float, valor de origen para y
*@param: paso, float, cantidad recorrida en x
*@param: int 1, valor para comprobar ejecución
*/
int correctores(float xi, float xf, float paso){//Correctores para u' e y'
        double yc=0, yant=0,yp=0 ,uc=0,uant=0,up=0, x=0,xant=0;
        float divisiones=(int) ((xf-xi)/paso),i;

        cout<<setw(5)<<"x";
        cout<<setw(12)<<"yp";
        cout<<setw(12)<<"yc";
        cout<<setw(12)<<"up";
        cout<<setw(12)<<"uc";
        cout<<endl<<endl;

                for(i=0;i<=divisiones;i++){//recorrido de x
                        if(i==0){
                                yant=inicialy;yc=yant;yp=yc;
                                uant=inicialu;uc=uant;up=uc;
                        }
                        else{
                                x=xi+(i*paso);//incremento x

                                up=Upredictor(xant,uc,paso);//upredictor
                                yp=Fpredictor(uc,paso);//ypredictor

                                uc=uant+((paso/2)*(U(xant,uc)+U(x,up)));//ucorrector
                                yc=yant+((paso/2)*(F(uc)+F(yp)));//ycorrector

                                uant=uc;
                                yant=yc;
                        }
                        cout<<setw(5)<<x;
                        cout<<setw(12)<<yp;
                        cout<<setw(12)<<yc;
                        cout<<setw(12)<<up;
                        cout<<setw(12)<<uc;
                        cout<<endl;
                }
return  1;
}


        //MAIN
int main(int argc, char *argv[]){
        correctores(0,0.3,0.1);
return 0;
}
