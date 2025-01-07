#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica
{
public:
  FiguraGeometrica() = default;
  virtual ~FiguraGeometrica() = default;

  virtual void draw(Sculptor &t) const = 0;
};

#endif