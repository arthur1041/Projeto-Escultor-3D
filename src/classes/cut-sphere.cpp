#include <iostream>
#include <cmath>
#include "cut-sphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) : xcenter(xcenter), ycenter(ycenter), zcenter(zcenter), radius(radius) {}

void CutSphere::draw(Sculptor &t) const
{
  std::cout << "Calling CutSphere::draw()" << std::endl;

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

        float equationLeftSideValue = (std::pow(i - xcenter, 2) + std::pow(j - ycenter, 2) + std::pow(k - zcenter, 2));
        float equationRightSideValue = std::pow(radius, 2);
        if (equationLeftSideValue <= equationRightSideValue)
        {
          voxel.show = false;
        }
      }
    }
  }

  std::cout << "Finished calling PutSphere::draw()" << std::endl;
}