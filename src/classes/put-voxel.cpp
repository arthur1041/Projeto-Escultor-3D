#include <iostream>
#include "put-voxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a)
    : x(x), y(y), z(z), r(r), g(g), b(b), a(a) {}

void PutVoxel::draw(Sculptor &t) const
{
  std::cout << "Calling PutVoxel::draw()" << std::endl;

  t.setColor(r, g, b, a);
  Voxel ***v = t.getVoxelMatrix();

  Voxel &voxel = v[x][y][z];
  voxel.show = true;

  voxel.r = r;
  voxel.g = g;
  voxel.b = b;
  voxel.a = a;

  std::cout << "Finished calling PutVoxel::draw()" << std::endl;
}