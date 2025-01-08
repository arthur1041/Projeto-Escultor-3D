#include <iostream>
#include <cmath>
#include "cut-ellipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
    : xcenter(xcenter), ycenter(ycenter), zcenter(zcenter), rx(rx), ry(ry), rz(rz) {}

void CutEllipsoid::draw(Sculptor &t) const
{
  std::cout << "Calling PutEllipsoid::draw()" << std::endl;

  Voxel ***v = t.getVoxelMatrix();

  int nx = t.getNx();
  int ny = t.getNy();
  int nz = t.getNz();

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

  std::cout << "Finished calling CutEllipsoid::draw()" << std::endl;
}