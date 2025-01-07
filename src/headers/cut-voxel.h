#ifndef CUT_VOXEL_H
#define CUT_VOXEL_H

#include "figura-geometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica {
private:
    int x, y, z;

public:
    CutVoxel(int x, int y, int z);

    void draw(Sculptor &t) const override;
};

#endif