#ifndef CUT_BOX_H
#define CUT_BOX_H

#include "figura-geometrica.h"

class CutBox : public FiguraGeometrica
{
private:
  int x0, x1, y0, y1, z0, z1;

public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    void draw(Sculptor &t) const override;
};

#endif