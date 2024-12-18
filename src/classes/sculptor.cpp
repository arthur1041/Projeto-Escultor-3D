#include "sculptor.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
  std::cout << "Calling Sculptor()" << std::endl;

  nx = _nx;
  ny = _ny;
  nz = _nz;

  // Alocação da matriz 3D
  v = new Voxel **[nx];
  for (int i = 0; i < nx; i++)
  {
    v[i] = new Voxel *[ny];
    for (int j = 0; j < ny; j++)
    {
      v[i][j] = new Voxel[nz];
    }
  }

  // Inicialização dos valores
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        Voxel &voxel = v[i][j][k];
        voxel.r = 0.0f;
        voxel.g = 0.0f;
        voxel.b = 0.0f;
        voxel.a = 1.0f;
        voxel.show = false;
      }
    }
  }

  std::cout << "Finished calling Sculptor()" << std::endl;
}

Sculptor::~Sculptor()
{
  std::cout << "Calling ~Sculptor()" << std::endl;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      delete[] v[i][j];
    }
    delete[] v[i];
  }
  delete[] v;

  std::cout << "Finished calling ~Sculptor()" << std::endl;
}

void Sculptor::setColor(float r, float g, float b, float a)
{
  std::cout << "Calling setColor()" << std::endl;

  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;

  std::cout << "Finished calling setColor()" << std::endl;
}

void Sculptor::putVoxel(int x, int y, int z)
{
  std::cout << "Calling putVoxel()" << std::endl;

  Voxel &voxel = v[x][y][z];
  voxel.show = true;

  voxel.r = r;
  voxel.g = g;
  voxel.b = b;
  voxel.a = a;

  std::cout << "Finished calling putVoxel()" << std::endl;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
  std::cout << "Calling cutVoxel()" << std::endl;

  Voxel &voxel = v[x][y][z];
  voxel.show = false;

  std::cout << "Finished calling cutVoxel()" << std::endl;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  std::cout << "Calling putBox()" << std::endl;

  int _x0 = std::min(x0, x1);
  int _x1 = std::max(x0, x1);

  int _y0 = std::min(y0, y1);
  int _y1 = std::max(y0, y1);

  int _z0 = std::min(z0, z1);
  int _z1 = std::max(z0, z1);

  for (int i = _x0; i <= _x1; i++)
  {
    for (int j = _y0; j <= _y1; j++)
    {
      for (int k = _z0; k <= _z1; k++)
      {
        Voxel &voxel = v[i][j][k];
        voxel.r = r;
        voxel.g = g;
        voxel.b = b;
        voxel.a = a;
        voxel.show = true;
      }
    }
  }
  std::cout << "Finished calling putBox()" << std::endl;
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  std::cout << "Calling cutBox()" << std::endl;

  int _x0 = std::min(x0, x1);
  int _x1 = std::max(x0, x1);

  int _y0 = std::min(y0, y1);
  int _y1 = std::max(y0, y1);

  int _z0 = std::min(z0, z1);
  int _z1 = std::max(z0, z1);

  for (int i = _x0; i <= _x1; i++)
  {
    for (int j = _y0; j <= _y1; j++)
    {
      for (int k = _z0; k <= _z1; k++)
      {
        Voxel &voxel = v[i][j][k];

        voxel.show = false;
      }
    }
  }
  std::cout << "Finished calling cutBox()" << std::endl;
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  std::cout << "Calling putSphere()" << std::endl;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        Voxel &voxel = v[i][j][k];

        float equationLeftSideValue = (std::pow(i - xcenter, 2) + std::pow(j - ycenter, 2) + std::pow(k - zcenter, 2));
        float equationRightSideValue = std::pow(radius, 2);
        if (equationLeftSideValue <= equationRightSideValue)
        {
          voxel.r = r;
          voxel.g = g;
          voxel.b = b;
          voxel.a = a;
          voxel.show = true;
        }
      }
    }
  }

  std::cout << "Finished calling putSphere()" << std::endl;
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  std::cout << "Calling cutSphere()" << std::endl;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        Voxel &voxel = v[i][j][k];

        float equationLeftSideValue = (std::pow(i - xcenter, 2) + std::pow(j - ycenter, 2) + std::pow(k - zcenter, 2));
        float equationRightSideValue = std::pow(radius, 2);
        if (equationLeftSideValue <= equationRightSideValue)
        {
          voxel.show = false;
        }
      }
    }
  }

  std::cout << "Finished calling putSphere()" << std::endl;
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  std::cout << "Calling putEllipsoid()" << std::endl;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        Voxel &voxel = v[i][j][k];

        // Calcula a equação do elipsoide
        float termX = std::pow(i - xcenter, 2) / std::pow(rx, 2);
        float termY = std::pow(j - ycenter, 2) / std::pow(ry, 2);
        float termZ = std::pow(k - zcenter, 2) / std::pow(rz, 2);

        // Verifica se o voxel está dentro ou sobre a superfície do elipsoide
        if (termX + termY + termZ <= 1.0f)
        {
          voxel.r = r;
          voxel.g = g;
          voxel.b = b;
          voxel.a = a;
          voxel.show = true;
        }
      }
    }
  }

  std::cout << "Finished calling putEllipsoid()" << std::endl;
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  std::cout << "Calling cutEllipsoid()" << std::endl;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        Voxel &voxel = v[i][j][k];

        // Calcula a equação do elipsoide
        float termX = std::pow(i - xcenter, 2) / std::pow(rx, 2);
        float termY = std::pow(j - ycenter, 2) / std::pow(ry, 2);
        float termZ = std::pow(k - zcenter, 2) / std::pow(rz, 2);

        // Verifica se o voxel está dentro ou sobre a superfície do elipsoide
        if (termX + termY + termZ <= 1.0f)
        {
          voxel.show = false;
        }
      }
    }
  }

  std::cout << "Finished calling cutEllipsoid()" << std::endl;
}

void Sculptor::writeOFF(const char *filename)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
    return;
  }

  // Vetores para armazenar vértices e faces
  std::vector<std::string> vertices;
  std::vector<std::string> faces;

  int vertexIndex = 0;

  // Itera pela matriz 3D para identificar voxels "ativos"
  for (int x = 0; x < nx; x++)
  {
    for (int y = 0; y < ny; y++)
    {
      for (int z = 0; z < nz; z++)
      {
        Voxel &voxel = v[x][y][z];
        if (voxel.show)
        {
          // Adiciona os 8 vértices do voxel
          vertices.push_back(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x + 1) + " " + std::to_string(y) + " " + std::to_string(z) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x + 1) + " " + std::to_string(y + 1) + " " + std::to_string(z) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x) + " " + std::to_string(y + 1) + " " + std::to_string(z) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z + 1) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x + 1) + " " + std::to_string(y) + " " + std::to_string(z + 1) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x + 1) + " " + std::to_string(y + 1) + " " + std::to_string(z + 1) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));
          vertices.push_back(std::to_string(x) + " " + std::to_string(y + 1) + " " + std::to_string(z + 1) + " " +
                             std::to_string(voxel.r) + " " + std::to_string(voxel.g) + " " +
                             std::to_string(voxel.b) + " " + std::to_string(voxel.a));

          // Adiciona as 6 faces do voxel
          faces.push_back("4 " + std::to_string(vertexIndex) + " " + std::to_string(vertexIndex + 1) + " " +
                          std::to_string(vertexIndex + 2) + " " + std::to_string(vertexIndex + 3));
          faces.push_back("4 " + std::to_string(vertexIndex + 4) + " " + std::to_string(vertexIndex + 5) + " " +
                          std::to_string(vertexIndex + 6) + " " + std::to_string(vertexIndex + 7));
          faces.push_back("4 " + std::to_string(vertexIndex) + " " + std::to_string(vertexIndex + 1) + " " +
                          std::to_string(vertexIndex + 5) + " " + std::to_string(vertexIndex + 4));
          faces.push_back("4 " + std::to_string(vertexIndex + 1) + " " + std::to_string(vertexIndex + 2) + " " +
                          std::to_string(vertexIndex + 6) + " " + std::to_string(vertexIndex + 5));
          faces.push_back("4 " + std::to_string(vertexIndex + 2) + " " + std::to_string(vertexIndex + 3) + " " +
                          std::to_string(vertexIndex + 7) + " " + std::to_string(vertexIndex + 6));
          faces.push_back("4 " + std::to_string(vertexIndex + 3) + " " + std::to_string(vertexIndex) + " " +
                          std::to_string(vertexIndex + 4) + " " + std::to_string(vertexIndex + 7));

          // Atualiza o índice base para o próximo voxel
          vertexIndex += 8;
        }
      }
    }
  }

  // Alterando para "COFF" para suportar cores no MeshLab
  file << "COFF\n";
  file << vertices.size() << " " << faces.size() << " 0\n";

  // Escreve os vértices
  for (const auto &vertex : vertices)
  {
    file << vertex << "\n";
  }

  // Escreve as faces
  for (const auto &face : faces)
  {
    file << face << "\n";
  }

  file.close();
  std::cout << "Arquivo " << filename << " gerado com sucesso!\n";
}
