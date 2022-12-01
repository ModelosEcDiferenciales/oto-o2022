#include <iostream>
#include <cmath>
using namespace std;
#define F(x,y) ((-2*pow(x,3))+(12*pow(x,2))+(-20*x)+(8.5))
#define solucion(x,y) ((-0.5*pow(x,4))+(4*pow(x,3))+(-10*pow(x,2))+(8.5*x)+(1))


float euler(float x0, float y0, float paso){
        float resultado;
                        resultado=y0;
			resultado+=(F(x0,y0))*((paso)/2);
        return resultado;
}

/*

float corrector(float xi, float xf, float x0, float y0, float paso){
        float resultado;
        float i,ciclos=(xf-xi)/paso,temporal, xn,xant,error;
                cout<<"|\t"<<"X"<<"\t|\t"<<"YP"<<"\t|\t"<<"YC"<<"\t|\t"<<"REAL"<<"\t|\t"<<"ERROR"<<endl;
                for(i=0; i<=ciclos; i++){
                        if(i==0) {
                                resultado=1;
                                cout<<"|\t"<<x0<<"\t|\t"<<"1"<<"\t|\t"<<resultado<<"\t|\t"<<"1"<<"\t|\t"<<"0 %"<<endl;
                        }
                        else{
                                xn=xi+(paso*i);
                                xant=xn-paso;
                                resultado=temporal+(paso/2)*(F(xant,temporal)+F(xn, predictor(xn,temporal,paso)));
				error=(abs(resultado-solucion(xn,resultado))/solucion(xn,resultado))*100;
                                cout<<"|\t"<<x0+(paso*i)<<"\t|\t"<<predictor(xant,temporal,paso)<<"\t|\t"<<resultado<<"\t|\t"<<solucion(xn,resultado)<<"\t|\t"<<error<<" %"<<endl;
                        }
                        temporal=resultado;
                }
		cout<<endl<<endl;
        return resultado;
}
*/

float puntoMedio(float xi, float xf, float paso){
	float i, ciclos=(xf-xi)/(paso), temporal, resultado, xn,xmd,xr=0;
                cout<<"|\t"<<"X"<<"\t|\t"<<"REAL"<<"\t|\t"<<"Ypm"<<endl;
		for(i=0;i<=ciclos;i++){
        		if(i==0){
                		resultado=1;
                		cout<<"|\t"<<xi<<"\t|\t"<<"1"<<"\t|\t"<<resultado<<"\t|\t"<<endl;
        		}
			else{
				xmd=(xr+(xr+paso))/2;
				xr=xi+(paso*i);
				resultado=temporal;
				resultado+=F(xmd, euler(xr ,temporal,paso))*paso;
                                cout<<"|\t"<<xr<<"\t|\t"<<solucion(xr,resultado)<<"\t|\t"<<resultado<<" | "<<endl;
			}
			temporal=resultado;
		}
return 1;
}

float puntoMedioCSV(float xi, float xf, float paso){
        float i, ciclos=(xf-xi)/(paso), temporal, resultado, xn,xmd,xr=0;
                cout<<"X,"<<"REAL,"<<"Ypm"<<endl;
                for(i=0;i<=ciclos;i++){
                        if(i==0){
                                resultado=1;
                                cout<<xi<<","<<"1,"<<resultado<<endl;
                        }
                        else{
                                xmd=(xr+(xr+paso))/2;
                                xr=xi+(paso*i);
                                resultado=temporal;
                                resultado+=F(xmd, euler(xr ,temporal,paso))*paso;
                                cout<<xr<<","<<solucion(xr,resultado)<<","<<resultado<<endl;
                        }
                        temporal=resultado;
                }
return 1;
}


/*
float correctorCSV(float xi, float xf, float x0, float y0, float paso){
        float resultado;
        float i,ciclos=(xf-xi)/paso,temporal, xn,xant;
                cout<<"X,"<<"PREDICTOR,"<<"CORRECTOR"<<endl;
                for(i=0; i<=ciclos; i++){
                        if(i==0) {
                                resultado=1;
                                cout<<x0<<","<<"1"<<","<<resultado<<endl;
                        }
                        else{
                                xn=xi+(paso*i);
                                xant=xn-paso;
                                resultado=temporal+(paso/2)*(F(xant,temporal)+F(xn, predictor(xn,temporal,paso)));
                                cout<<x0+(paso*i)<<","<<predictor(xant,temporal,paso)<<","<<resultado<<endl;
                        }
                        temporal=resultado;
                }
                cout<<endl<<endl;
        return resultado;
}
*/

int main(int argc, char *argv[]){
//puntoMedio(0,4,0.5);
puntoMedioCSV(0,4,0.5);
//puntoMedio(0,4,0.25);
//puntoMedio(0,4,0.1);

return 0;
}

