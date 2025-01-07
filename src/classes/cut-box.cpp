#include <iostream>
#include "cut-box.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) : x0(x0), x1(x1), y0(y0), y1(y1), z0(z0), z1(z1) {}

void CutBox::draw(Sculptor &t) const
{
  std::cout << "Calling CutBox::draw()" << std::endl;

  Voxel ***v = t.getVoxelMatrix();

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
  std::cout << "Finished calling CutBox::draw()" << std::endl;
}