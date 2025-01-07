#include <iostream>
#include "put-sphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) : xcenter(xcenter), ycenter(ycenter), zcenter(zcenter), radius(radius), r(r), g(g), b(b), a(a) {}

void PutSphere::draw(Sculptor &t) const
{
  std::cout << "Calling PutSphere::draw()" << std::endl;

  t.setColor(r, g, b, a);
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
          voxel.r = r;
          voxel.g = g;
          voxel.b = b;
          voxel.a = a;
          voxel.show = true;
        }
      }
    }
  }

  std::cout << "Finished calling PutSphere::draw()" << std::endl;
}