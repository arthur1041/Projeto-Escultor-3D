#ifndef FIGURA_READER_H
#define FIGURA_READER_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include "figura-geometrica.h"
#include "put-voxel.h"
#include "cut-voxel.h"
#include "put-box.h"
#include "cut-box.h"
#include "put-sphere.h"
#include "cut-sphere.h"
#include "put-ellipsoid.h"
#include "cut-ellipsoid.h"
#include "sculptor.h"

class FiguraReader
{
private:
  std::vector<std::unique_ptr<FiguraGeometrica>> figuras;

public:
  FiguraReader() = default;

  Sculptor *readFile(const std::string &filename);

  const std::vector<std::unique_ptr<FiguraGeometrica>> &getFiguras() const;
};

#endif