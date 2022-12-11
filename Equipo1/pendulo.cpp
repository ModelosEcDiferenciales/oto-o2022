#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define cte 1
#define gravedad -10
#define longitud 50
#define F(y) (y)
#define G(x,y) (  (gravedad/longitud)*(sin(x))  -(cte*y)  )
#define inicialx 1.0
#define inicialy 0.0
#define h 0.1

double Fpredictor(float y,float paso){
	double fp;
		fp=y+(paso*F(y));
	return fp;
}

double Gpredictor(float x, float y,float paso){
	double gp;
		gp=y+(paso*G(x,y));
	return gp;
}

int correctores (float ti, float tf, float paso){
	double yp, yc, yant, xc, xp, xant;
	float i,t=0,tant=0;
	float divisiones=(int)((tf-ti)/paso);
	
//Encabezado de la tabulacion	
	    cout<<setw(5)<<"x";
        cout<<setw(12)<<"yp";
        cout<<setw(12)<<"yc";
        cout<<setw(12)<<"xp";
        cout<<setw(12)<<"xc";
        cout<<endl<<endl;
        
        for(i=0;i<=divisiones;i++){
        	t=(int)ti+(paso*i);//Aumento en eje horizontal
        	tant=t-paso;
        	if(i==0){//En caso de la primer iteración
        		yp=inicialy;yc=yp;yant=yc;//llenando valores para y
        		xp=inicialx;xc=xp;xant=xc;//llenando valores para x
			}
			else{
				xp=Gpredictor(t,yant,paso);
				yp=Fpredictor(xc, paso);
				
				xc=xant+((paso/2)*(G(xp,yant)+G(xc,yp)));
				yc=yant+((paso/2)*(F(xp)+F(yp)));
				
				yant=yc;
				xant=xc;
			}
		
		cout<<setw(5)<<t;
		cout<<setw(12)<<yp;
        cout<<setw(12)<<yc;
        cout<<setw(12)<<xp;
        cout<<setw(12)<<xc;
        cout<<endl;
		}
return 1;
}


int correctoresCSV(float ti, float tf, float paso){
	double yp, yc, yant, xc, xp, xant;
	float i,t=0,tant=0;
	float divisiones=(int)((tf-ti)/paso);
	
//Encabezado de la tabulacion	
	    cout<<"t,";
        cout<<"yp,";
        cout<<"yc,";
        cout<<"xp,";
        cout<<"xc";
        cout<<endl;
        
        for(i=0;i<=divisiones;i++){
        	t=(int)ti+(paso*i);//Aumento en eje horizontal
        	tant=t-paso;
        	if(i==0){//En caso de la primer iteración
        		yp=inicialy;yc=yp;yant=yc;//llenando valores para y
        		xp=inicialx;xc=xp;xant=xc;//llenando valores para x
			}
			else{
				xp=Gpredictor(t,yant,paso);
				yp=Fpredictor(xc, paso);
				
				xc=xant+((paso/2)*(G(xp,yant)+G(xc,yp)));
				yc=yant+((paso/2)*(F(xp)+F(yp)));
				
				yant=yc;
				xant=xc;
			}
		
		cout<<t<<",";
		cout<<yp<<",";
        cout<<yc<<",";
        cout<<xp<<",";
        cout<<xc<<",";
        cout<<endl;
		}
return 1;
}
/*
int correctoresCSV(float xi, float xf, float paso){
	double fp, fc, fant, gc, gp, gant;
	float i,x=0,xant=0;
	float divisiones=(int)((xf-xi)/paso);
	
//Encabezado de la tabulacion	
	    cout<<"x,";
        cout<<"fp,";
        cout<<"fc,";
        cout<<"gp,";
        cout<<"gc";
        cout<<endl;
        
        for(i=0;i<=divisiones;i++){
        	x=(int)xi+(paso*i);//Aumento en eje horizontal
        	xant=x-paso;
        	if(i==0){//En caso de la primer iteración
        		fp=inicialy;fc=fp;fant=fc;//llenando valores para y
        		gp=inicialx;gc=gp;gant=gc;//llenando valores para x
			}
			else{
				
				
				gp=Fpredictor(x, paso);
				gc=(paso/2)*(F(x)+F(gant));
				gant=gc;
				
				fp=Fpredictor(gc,paso);
				fc=(paso/2)*(G(x)+G(x));
				fant=fc;
			}
		
		cout<<x<<",";
		cout<<fp<<",";
        cout<<fc<<",";
        cout<<gp<<",";
        cout<<gc<<",";
        cout<<endl;
		}	
return 1;
}

*/

int main(void){
	correctoresCSV(0,15,h);
return 0;
}


/*
double Fpredictor(float x,float y, float paso){
        double yp;
                        yp=y+(paso*F(x,y));
return yp;
}

double Gpredictor(float z,float y, float paso){
        double zp;
                        zp=z+(paso*G(z,y));
return zp;
}

int correctores(float xi, float xf, float z0, float y0, float paso){
        float yc=0, yant=0,yp=y0 ,zc=0,zant=0,zp=z0, i, x=0;
        float divisiones=(int) ((xf-xi)/paso);

        cout<<setw(5)<<"x";
        cout<<setw(12)<<"yp";
        cout<<setw(12)<<"yc";
        cout<<setw(12)<<"zp";
        cout<<setw(12)<<"zc";
        cout<<endl<<endl;

                for(i=0;i<=divisiones;i++){
                        if(i==0){
                                yant=inicial;
                                zant=inicial;
                                yc=yant;
                                zc=zant;
                        }
                        else{
                                x=xi+(i*paso);

                                yp=Fpredictor((x-paso),yp,paso);
                                yc+=(paso/2)*(F(x,yc)+F((x-paso),yp));

                                yant=yc;

                                zp=Gpredictor(zc,yp,paso);
                                zc+=(paso/2)*(G(zc,yant)+G(zp,yant));


                                zant=zc;
                        }
                        cout<<setw(5)<<x;
                        cout<<setw(12)<<yp;
                        cout<<setw(12)<<yc;
                        cout<<setw(12)<<zp;
                        cout<<setw(12)<<zc;
                        cout<<endl;
                }

return  1;
}



int main(int argc, char *argv[]){
        correctores(0,0.5,1,1,0.1);
return 0;
}



*/

