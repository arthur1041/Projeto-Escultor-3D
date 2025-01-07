#ifndef CUT_ELLIPSOID_H
#define CUT_ELLIPSOID_H

#include "figura-geometrica.h"

class CutEllipsoid : public FiguraGeometrica
{
private:
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  void draw(Sculptor &t) const override;
};

#endif