#include <iostream>
#include "cut-voxel.h"

CutVoxel::CutVoxel(int x, int y, int z)
    : x(x), y(y), z(z) {}

void CutVoxel::draw(Sculptor &t) const
{
  Voxel ***v = t.getVoxelMatrix();

  std::cout << "Calling CutVoxel::draw()" << std::endl;

  Voxel &voxel = v[x][y][z];
  voxel.show = false;

  std::cout << "Finished calling CutVoxel::draw()" << std::endl;
}