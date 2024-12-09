#include <iostream>
#include <cmath> // Para funções trigonométricas
#include "sculptor.h"

int main()
{
  // Dimensões da matriz tridimensional
  int nx = 120, ny = 120, nz = 60;

  // Cria o objeto Sculptor
  Sculptor sculptor(nx, ny, nz);

  // Parte 1: Base inferior (elipsoide preto)
  const int xcenter = nx / 2;
  const int ycenter = ny / 2;
  const int zcenter = nz / 4;            // Base posicionada mais abaixo
  sculptor.setColor(0.0, 0.0, 0.0, 1.0); // Preto
  sculptor.putEllipsoid(xcenter, ycenter, zcenter, 50, 50, 10);

  // Parte 2: Detalhes amarelos na borda inferior
  sculptor.setColor(0.9, 0.8, 0.1, 1.0); // Amarelo
  for (int i = 0; i < 360; i += 30)
  {
    float angle = i * (3.14159 / 90.0); // Converte para radianos
    int x = xcenter + static_cast<int>(48 * cos(angle));
    int y = ycenter + static_cast<int>(48 * sin(angle));
    sculptor.putEllipsoid(x, y, zcenter, 4, 4, 5); // Detalhe amarelo
  }

  // Parte 3: Painéis laterais (vermelhos)
  sculptor.setColor(0.8, 0.0, 0.0, 1.0);                                                           // Vermelho
  sculptor.putBox(xcenter - 25, xcenter - 20, ycenter - 5, ycenter + 5, zcenter - 3, zcenter + 3); // Painel esquerdo
  sculptor.putBox(xcenter + 20, xcenter + 25, ycenter - 5, ycenter + 5, zcenter - 3, zcenter + 3); // Painel direito

  // Parte 4: Cúpula superior (elipsoide branco)
  int newZcenter = nz / 2 + 5;           // Cúpula no topo
  sculptor.setColor(1.0, 1.0, 1.0, 1.0); // Branco
  sculptor.putEllipsoid(xcenter, ycenter, newZcenter - 20, 45, 45, 15);
  sculptor.cutVoxel(60, 60, zcenter - 15);
  sculptor.cutVoxel(60, 60, zcenter + 15);
  sculptor.setColor(0.5, 0.5, 0.5, 1.0);

  // Porta Superior da nave
  sculptor.putSphere(60, 60, zcenter + 15, 13);
  sculptor.cutBox(60 - 16, 60 + 16, 60 - 16, 60 + 16, 30, nz - 1);

  // Parte 5: Janelas arredondadas (verdes)
  // sculptor.setColor(0.0, 0.8, 0.5, 1.0);                                   // Verde
  // sculptor.putEllipsoid(xcenter + 30, ycenter + 20, zcenter - 5, 6, 6, 4); // Janela superior direita
  // sculptor.putEllipsoid(xcenter - 30, ycenter + 20, zcenter - 5, 6, 6, 4); // Janela superior esquerda
  // sculptor.putEllipsoid(xcenter, ycenter - 35, zcenter - 5, 8, 8, 5);      // Janela frontal
  sculptor.setColor(0.0, 0.8, 0.5, 1.0);
  for (int i = 15; i < 360; i += 30)
  {
    float angle = i * (3.14159 / 180.0); // Converte para radianos
    int x = xcenter + static_cast<int>(51 * cos(angle));
    int y = ycenter + static_cast<int>(51 * sin(angle));
    sculptor.putVoxel(x, y, zcenter); // Detalhe verde
  }

  // Parte 6: Suportes (pés da nave)
  sculptor.setColor(1.0, 1.0, 1.0, 1.0); // Branco
  for (int i = 30; i < 360; i += 60)
  {
    float angle = i * (3.14159 / 180.0); // Converte para radianos
    int x = xcenter + static_cast<int>(50 * cos(angle));
    int y = ycenter + static_cast<int>(50 * sin(angle));
    int rx = 3;
    int ry = 3;
    int rz = 15;
    sculptor.putEllipsoid(x, y, newZcenter - 20, rx, ry, rz); // Pés
    sculptor.cutBox(x - rx, x + rx, y - ry, y + ry, newZcenter, rz);
  }

  // Base inferior preta
  sculptor.setColor(0.0, 0.0, 0.0, 1.0); // Preto
  sculptor.putEllipsoid(xcenter, ycenter, zcenter, 50, 50, 10);

  // Parte 7: Detalhes roxos no topo
  sculptor.setColor(0.5, 0.0, 0.5, 1.0);                             // Roxo
  sculptor.putSphere(xcenter + 0, ycenter + 32, newZcenter - 15, 8); // Esfera roxa no centro

  // Exporta para um arquivo .OFF para visualização
  sculptor.writeOFF("frieza_ship_detailed.off");

  std::cout << "Figura detalhada da nave do Freeza criada e exportada para frieza_ship_detailed.off\n";

  return 0;
}
