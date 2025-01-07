#ifndef PUT_SPHERE_H
#define PUT_SPHERE_H

#include "figura-geometrica.h"

class PutSphere : public FiguraGeometrica
{
private:
  int xcenter, ycenter, zcenter, radius;
  float r, g, b, a;

public:
  PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);

  void draw(Sculptor &t) const override;
};

#endif