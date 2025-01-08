#include "figura-reader.h"

Sculptor *FiguraReader::readFile(const std::string &filename)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    throw std::runtime_error("Erro ao abrir o arquivo: " + filename);
  }

  Sculptor *sculptor = nullptr;
  std::string line;

  while (std::getline(file, line))
  {
    std::istringstream iss(line);
    std::string command;
    iss >> command;

    if (command == "dim")
    {
      int nx, ny, nz;
      iss >> nx >> ny >> nz;
      sculptor = new Sculptor(nx, ny, nz);
    }
    else if (command == "putvoxel")
    {
      int x, y, z;
      float r, g, b, a;
      iss >> x >> y >> z >> r >> g >> b >> a;
      figuras.push_back(std::make_unique<PutVoxel>(x, y, z, r, g, b, a));
    }
    else if (command == "cutvoxel")
    {
      int x, y, z;
      iss >> x >> y >> z;
      figuras.push_back(std::make_unique<CutVoxel>(x, y, z));
    }
    else if (command == "putbox")
    {
      int x0, x1, y0, y1, z0, z1;
      float r, g, b, a;
      iss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
      figuras.push_back(std::make_unique<PutBox>(x0, x1, y0, y1, z0, z1, r, g, b, a));
    }
    else if (command == "cutbox")
    {
      int x0, x1, y0, y1, z0, z1;
      iss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
      figuras.push_back(std::make_unique<CutBox>(x0, x1, y0, y1, z0, z1));
    }
    else if (command == "putsphere")
    {
      int x, y, z, radius;
      float r, g, b, a;
      iss >> x >> y >> z >> radius >> r >> g >> b >> a;
      figuras.push_back(std::make_unique<PutSphere>(x, y, z, radius, r, g, b, a));
    }
    else if (command == "cutsphere")
    {
      int x, y, z, radius;
      iss >> x >> y >> z >> radius;
      figuras.push_back(std::make_unique<CutSphere>(x, y, z, radius));
    }
    else if (command == "putellipsoid")
    {
      int x, y, z, rx, ry, rz;
      float r, g, b, a;
      iss >> x >> y >> z >> rx >> ry >> rz >> r >> g >> b >> a;
      figuras.push_back(std::make_unique<PutEllipsoid>(x, y, z, rx, ry, rz, r, g, b, a));
    }
    else if (command == "cutellipsoid")
    {
      int x, y, z, rx, ry, rz;
      iss >> x >> y >> z >> rx >> ry >> rz;
      figuras.push_back(std::make_unique<CutEllipsoid>(x, y, z, rx, ry, rz));
    }
  }

  file.close();
  return sculptor;
}

const std::vector<std::unique_ptr<FiguraGeometrica>> &FiguraReader::getFiguras() const
{
  return figuras;
}
