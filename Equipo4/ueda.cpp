#include <iostream>
#include <fstream>
#include <cmath>

// Ecuacion a resolver:
// x'' + x' + x^3 = A Sin(Omega Tau)
// y' + y + x^3 = A Sin(Omega Tau)
// y' = - y - x^3 + A Sin(Omega Tau)
// y = x'
// y(0) = x'(0) = 1
// x(0) = 0

float _A, _OMEGA;

double uedayp(double t, double y, double x){
  return - (x*x*x) - y + (_A * sin(_OMEGA*t));
}

typedef struct out{
  double x;
  double xp;
} out_t;

out_t rk4part(double y0, double x0, double t0, double tf);

int main(int argc, char *argv[]) {

  if(argc != 3){
    std::cout << "Uso: exec <A> <omega>" << std::endl;
    exit(EXIT_FAILURE);
  }

  _A = std::stof(argv[1]);
  _OMEGA = std::stof(argv[2]);

  std::ofstream file;
  file.open("out.csv");
  if(!file){
    std::cerr << "Error: no se pudo abrir el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
  out_t temp = {0, 0};
  file << "t, x(t), x'(t)" << std::endl;
  for (int i = 0; i <= 1000; i++){
    temp = rk4part(1, 0, 0, i);
   file << i << ", " << temp.x << ", " << temp.xp << std::endl;
  }

  file.close();

  return 0;
}

out_t rk4part(double y0, double x0, double t0, double tf){
  double yn = y0, xn = x0;
  double h = 0.1;
  double kx1, kx2, kx3, kx4, ky1, ky2, ky3, ky4;
  double temp;
  for (double tn = t0; tn < tf; tn+=h) {
    kx1 = h*yn;
    ky1 = h*uedayp(tn, yn, xn);
    kx2 = h*(yn + ky1/2);
    ky2 = h*uedayp(tn + h/2, yn + ky1/2, xn + kx1/2);
    kx3 = h*(yn+ky2/2);
    ky3 = h*uedayp(tn + h/2, yn + ky2/2, xn + kx2/2);
    kx4 = h*(yn+ky3);
    ky4 = h*uedayp(tn + h, yn + ky3, xn + kx3);

    xn = xn + ((kx1 + 2*kx2 + 2*kx3 + kx4)/6);
    yn = yn + ((ky1 + 2*ky2 + 2*ky3 + ky4)/6);
  }
  out_t salida;
  salida.x = xn;
  salida.xp = yn;
  return salida;
}

