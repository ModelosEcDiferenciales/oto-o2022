/***********************************************
*	Prog. de modelos de ec. dif
*	Otoño 2022
*    
*   Programa que da la solucion de
*   una EDO con el metodo de Euler predictor, 
*	corrector, punto medio y Taylor
*
**********************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funcion(float x, float y){
	
	float EC;
	
	EC = (-2*x*x*x) + (12*x*x) - (20*x) + (8.5);   //ec. dif primera derivada
	
	return EC;
	
}//funcion


float YReal(float x){
	
	float Y;
	
	Y = (-1.0*0.5*x*x*x*x) + (4.0*x*x*x) - (10.0*x*x) + (8.5*x) + 1.0 ;  //solucion a la ec.dif
	
	return Y;

}//YReal


float SegundaDfProgresiva(float x, float h){
	
	float Df1 = (funcion(x+h, 0)-funcion(x, 0))/(h);
	return Df1;

}//SegundaDfProgresiva


float TerceraDfProgresiva(float x, float h){

	float Df2 = (SegundaDfProgresiva(x+h,h) - SegundaDfProgresiva(x,h))/(h);
	return Df2;

}//TerceraDfProgresiva


float CuartaDfProgresiva(float x, float h){

	float Df3 = (TerceraDfProgresiva(x+h,h) - TerceraDfProgresiva(x,h))/(h);
	return Df3;
	
}//CuartaDfProgresiva


float Derivada(int grado_derivada, float x){
	
	float valor;
	float h = 0.001f; //tamaño de paso derivada
	
	if(grado_derivada == 1){
		
		valor = funcion(x, 0);
		return valor;
		
	}//if 1
	
	if(grado_derivada == 2){
		
		valor = SegundaDfProgresiva(x, h);
		return valor;
		
	}//if 2
	
	if(grado_derivada == 3){
		
		valor = TerceraDfProgresiva(x, h);
		return valor;
		
	}//if 3
	
	if(grado_derivada == 4){
		
		valor = CuartaDfProgresiva(x, h);
		return valor;
		
	}//if 4
	
}//Derivada


int factorial(int n){
	
    if (n == 0){
    	
        return 1;
        
    }else{
    	
        return(n * factorial(n-1));
        
    }//else
    
}//factorial


void Ycalculadas(float h1){
	
//       y(0) = 1,   y(4) = ?,   h = 0.5                      Condiciones
//		 y' = -2x^3+ 12x^2 -20x +8.5       y'(0) = 8.5	                     

	
	float valoresX[50];  //valores de y euler predictor
	float valoresY[50];
	  
	float valoresYC[50];  //valores de y euler corrector
	
	float valoresYPM[50]; //valores punto medio
	
	float valoresYT[50]; //valores de y con suc. de Taylor
	
	float valoresYR[50]; //valores de y real
	
	float Taylor1;
	float Taylor2;   //valores de la sucesion de Taylor
	float Taylor3;
	float Taylor4;
	
	int i,n;  //contador
	int limit = (4/h1); // numero de iteraciones
	
	valoresX[0] = 0.00f; // valores actuales
	valoresY[0] = 1.00f; 
	valoresYC[0] = 1.00f; 
	valoresYPM[0] = 1.00f;
	valoresYT[0] = 1.00f;
	
	//y euler predictor
	for(i = 1; i<= limit; i++){
		
		valoresX[i] = valoresX[i-1] + h1;
		valoresY[i] = (valoresY[i-1]) + (funcion(valoresX[i-1], valoresY[i-1]))*(h1);
		
	}//for
	
	
	//y euler corrector
	for(i = 1; i<= limit; i++){
		
		valoresYC[i] = valoresYC[i-1] + (h1/2)*((funcion(valoresX[i-1], valoresYC[i-1])) + (funcion(valoresX[i], valoresY[i]))); 
		
	}//for
	

	//y punto medio
	for(i = 1; i<= limit; i++){
		
		valoresYPM[i] = valoresYPM[i-1] + (funcion((valoresX[i] + valoresX[i-1])/(2), valoresY[i] + ((funcion(valoresX[i], valoresY[i]))*(h1)/(2)))); 
		
	}//for
	
		
	//y Taylor
	for(i = 1; i<= limit; i++){
		
		Taylor1 = valoresX[i-1];
		Taylor2 = ((Derivada(1, valoresX[0])) / (factorial(1))) * (pow(h1,1));
		Taylor3 = ((Derivada(2, valoresX[0])) / (factorial(2))) * (pow(h1,2));
		Taylor4 = ((Derivada(3, valoresX[0])) / (factorial(3))) * (pow(h1,3));
		
		valoresYT[i] = Taylor1 + Taylor2 + Taylor3 + Taylor4; 
				
	}//for
	
	
	//y real
	for(i = 0; i<= limit; i++){
		
		valoresYR[i] = YReal(i*h1); 
		
	}//for
	
	
	//Resultado de x,y
	printf("\nX\t\tYp\t\tYc\t\tYPM\t\tYT\t\tYr\t\tError Porcentual\n\n");
	for (i = 0; i <= limit; i++){
		
		printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n", valoresX[i], valoresY[i], valoresYC[i], valoresYPM[i], valoresYT[i], valoresYR[i], ((valoresYT[i]-valoresYR[i])/(valoresYR[i]))*(100));
		
	}//for
	
	printf("\nCon h = %.1f\n\n", h1);
	
	
}//Ycalculadas


int main (void){
	
	float h1 = 0.5f;  //tamaño de paso
	
	Ycalculadas(h1); //Prototipos
	
	return 0; // fin del programa
	
}//main
