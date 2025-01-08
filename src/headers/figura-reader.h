/**
 * @file figura-reader.h
 * @brief Declaração da classe FiguraReader para leitura de figuras geométricas de um arquivo.
 *
 * Este arquivo contém a declaração da classe FiguraReader, que é responsável por interpretar
 * um arquivo de texto contendo comandos para criar objetos derivados de FiguraGeometrica
 * e armazená-los em um container.
 */

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

/**
 * @class FiguraReader
 * @brief Classe responsável por ler figuras geométricas de um arquivo de texto.
 *
 * A classe FiguraReader interpreta comandos de um arquivo de texto e cria objetos
 * das classes derivadas de FiguraGeometrica. Esses objetos são armazenados em um
 * container interno e podem ser utilizados para manipular um objeto da classe Sculptor.
 */
class FiguraReader
{
private:
  /**
   * @brief Container para armazenar os objetos FiguraGeometrica.
   *
   * Armazena ponteiros inteligentes para os objetos derivados de FiguraGeometrica,
   * garantindo o gerenciamento automático da memória.
   */
  std::vector<std::unique_ptr<FiguraGeometrica>> figuras;

public:
  /**
   * @brief Construtor padrão da classe FiguraReader.
   */
  FiguraReader() = default;

  /**
   * @brief Lê um arquivo de texto contendo comandos para criação de figuras geométricas.
   *
   * Este método interpreta os comandos presentes no arquivo especificado e cria
   * os objetos correspondentes. Além disso, inicializa e retorna um objeto Sculptor
   * com as dimensões especificadas no comando `dim`.
   *
   * @param filename Nome do arquivo de entrada contendo os comandos.
   * @return Um ponteiro para um objeto Sculptor inicializado.
   * @throws std::runtime_error Se o arquivo não puder ser aberto.
   */
  Sculptor *readFile(const std::string &filename);

  /**
   * @brief Retorna uma referência ao container de figuras geométricas.
   *
   * Este método permite acessar os objetos FiguraGeometrica criados após a leitura
   * do arquivo. Os objetos são armazenados em um `std::vector` de `std::unique_ptr`.
   *
   * @return Referência constante ao container de figuras geométricas.
   */
  const std::vector<std::unique_ptr<FiguraGeometrica>> &getFiguras() const;
};

#endif // FIGURA_READER_H
