#include <iostream>
#include "figura-reader.h"
#include "sculptor.h"

int main()
{
  try
  {
    FiguraReader reader;
    
    Sculptor *sculptor = reader.readFile("frieza_spaceship.txt");

    for (const auto &figura : reader.getFiguras())
    {
      figura->draw(*sculptor);
    }

    const char* outputFilename = "frieza_spaceship.off";
    
    sculptor->writeOFF(outputFilename);

    delete sculptor;

    std::cout << "Escultura salva em " << outputFilename << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Erro: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
