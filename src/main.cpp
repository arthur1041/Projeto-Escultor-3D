#define PI 3.14159265358979323846 

#include <iostream>
#include <cmath> // Para funções trigonométricas
#include "sculptor.h"

int main()
{
  // Dimensões da matriz tridimensional
  const int nx = 120, ny = 120, nz = 60;
  const int xcenter = nx / 2, ycenter = ny / 2, zcenter = nz / 4;
  const int newZcenter = nz / 2 + 5;

  // Cria o objeto Sculptor
  Sculptor sculptor(nx, ny, nz);

  // Parte 1: Base inferior (elipsoide preto)
  sculptor.setColor(0.0, 0.0, 0.0, 1.0);
  sculptor.putEllipsoid(xcenter, ycenter, zcenter, 50, 50, 10);

  // Parte 2: Detalhes amarelos na borda inferior
  sculptor.setColor(0.9, 0.8, 0.1, 1.0);
  for (int i = 0; i < 360; i += 30)
  {
    float angle = i * (PI / 90.0); // Converte para radianos
    int x = xcenter + static_cast<int>(48 * cos(angle));
    int y = ycenter + static_cast<int>(48 * sin(angle));
    sculptor.putEllipsoid(x, y, zcenter, 4, 4, 5);
  }

  // Parte 3: Painéis laterais (vermelhos)
  sculptor.setColor(0.8, 0.0, 0.0, 1.0);
  sculptor.putBox(xcenter - 25, xcenter - 20, ycenter - 5, ycenter + 5, zcenter - 3, zcenter + 3); // Esquerdo
  sculptor.putBox(xcenter + 20, xcenter + 25, ycenter - 5, ycenter + 5, zcenter - 3, zcenter + 3); // Direito

  // Parte 4: Cúpula superior (elipsoide branco)
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  sculptor.putEllipsoid(xcenter, ycenter, newZcenter - 20, 45, 45, 15);

  // Detalhes da cúpula
  sculptor.cutVoxel(60, 60, zcenter - 15);
  sculptor.cutVoxel(60, 60, zcenter + 15);
  sculptor.setColor(0.5, 0.5, 0.5, 1.0);
  sculptor.putSphere(60, 60, zcenter + 15, 13);
  sculptor.cutBox(60 - 16, 60 + 16, 60 - 16, 60 + 16, 30, nz - 1);

  // Parte 5: Detalhes verdes
  sculptor.setColor(0.0, 0.8, 0.5, 1.0);
  for (int i = 15; i < 360; i += 30)
  {
    float angle = i * (PI / 180.0); // Converte para radianos
    int x = xcenter + static_cast<int>(51 * cos(angle));
    int y = ycenter + static_cast<int>(51 * sin(angle));
    sculptor.putVoxel(x, y, zcenter);
  }

  // Parte 6: Suportes (pés da nave)
  sculptor.setColor(1.0, 1.0, 1.0, 1.0);
  for (int i = 30; i < 360; i += 60)
  {
    float angle = i * (PI / 180.0); // Converte para radianos
    int x = xcenter + static_cast<int>(50 * cos(angle));
    int y = ycenter + static_cast<int>(50 * sin(angle));
    int rx = 3, ry = 3, rz = 15;
    sculptor.putEllipsoid(x, y, newZcenter - 20, rx, ry, rz);
    sculptor.cutBox(x - rx, x + rx, y - ry, y + ry, newZcenter, rz);
  }

  // Base inferior preta (repetição)
  sculptor.setColor(0.0, 0.0, 0.0, 1.0);
  sculptor.putEllipsoid(xcenter, ycenter, zcenter, 50, 50, 10);

  // Parte 7: Detalhes roxos no topo
  sculptor.setColor(0.5, 0.0, 0.5, 1.0);
  sculptor.putSphere(xcenter, ycenter + 32, newZcenter - 15, 8);

  // Exporta para arquivo .OFF
  sculptor.writeOFF("frieza_ship_detailed.off");

  std::cout << "Figura detalhada da nave do Freeza criada e exportada para frieza_ship_detailed.off\n";

  return 0;
}
