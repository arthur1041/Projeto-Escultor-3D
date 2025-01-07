#ifndef PUT_VOXEL_H
#define PUT_VOXEL_H

#include "figura-geometrica.h"

class PutVoxel : public FiguraGeometrica
{
private:
  int x, y, z;
  float r, g, b, a;

public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);

    void draw(Sculptor &t) const override;
};

#endif