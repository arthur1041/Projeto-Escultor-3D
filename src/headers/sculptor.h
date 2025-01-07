#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

class PutVoxel;

class Sculptor
{
private:
  Voxel ***v;       // 3D matrix
  int nx, ny, nz;   // Dimensions
  float r, g, b, a; // Current drawing color

public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();

  Voxel ***getVoxelMatrix();
  int getNx();
  int getNy();
  int getNz();
  void setColor(float r, float g, float b, float a);

  void writeOFF(const char *filename);
};

#endif