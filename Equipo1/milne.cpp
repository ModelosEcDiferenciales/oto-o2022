#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

//ODE derfinition
#define F(a) ((-2*pow(a,3))+(12*pow(a,2))+(-20*a)+(8.5))
#define solucion(x) ((-0.5*pow(x,4))+(4*pow(x,3))+(-10*pow(x,2))+(8.5*x)+(1))
#define xi 0
#define xf 4
#define y0 1
#define step 0.5
//global Variables


float h=step;

float predictor(int n, float x[], float y[]){
	y[0]=y0;
		y[n]=y[n-3];
		y[n]+=((4*h)/3)*((2*F(x[n]))-(F(x[n-1]))+(2*F(x[n-2])));
return 1.0;
}

float corrector(int divisions, float x[], float y[], float yp[]){
	int i;
	y[0]=y0;
	for(i=1;i<divisions;i++){
		y[i]=y[i-1];
		y[i]+=(h/3)*(  (predictor((i+1),x,yp))  + (4*F(x[i])) +  (F(x[i-1]))  );
	}
return 1.0;
}



int main(int argc, char *argv[]){
	cout<<"\nMILNE SIMPSONP METHOD\n";
	cout<<"\nThis method solve an ODE using the four previus results\n";
	//corrector();
	int i;
	int no_div=(xf-xi)/step;
	float x[no_div], y[no_div];
	float yp[no_div];
	for (i=0;i<no_div;i++) {
		x[i]=xi+(i*step);//increasing the number of step
		if(i==0) x[i]=xi;
	}

	corrector(no_div,x,y,yp);
	x[0]=xi;
	y[0]=y0;

	 //cout<<endl<<"step"<<","<<"x"<<","<<"yp"<<","<<"yc"<<","<<"yr"<<endl;
        //for (i=0;i<no_div;i++) cout<<endl<<i<<"\t"<<x[i]<<"\t"<<yp[i]<<"\t"<<y[i]<<"\t"<<solucion(x[i])<<endl;//increasing the number of step
	 cout<<endl<<"step"<<","<<"x"<<","<<"yp"<<","<<"yc"<<","<<"yr"<<endl;//titles CSV
        for (i=0;i<no_div;i++) cout<<endl<<i<<","<<x[i]<<","<<yp[i]<<","<<y[i]<<","<<solucion(x[i])<<endl;//CSV data


return 0;
}
