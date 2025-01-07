#ifndef CUT_SPHERE_H
#define CUT_SPHERE_H

#include "figura-geometrica.h"

class CutSphere : public FiguraGeometrica
{
private:
  int xcenter, ycenter, zcenter, radius;

public:
  CutSphere(int xcenter, int ycenter, int zcenter, int radius);

  void draw(Sculptor &t) const override;
};

#endif