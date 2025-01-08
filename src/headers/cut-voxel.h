/**
 * @file cut-voxel.h
 * @brief Declaração da classe CutVoxel.
 *
 * Este arquivo contém a definição da classe CutVoxel, que representa a operação
 * de remoção de um único voxel de uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef CUT_VOXEL_H
#define CUT_VOXEL_H

#include "figura-geometrica.h"
#include "sculptor.h"

/**
 * @class CutVoxel
 * @brief Classe para remover um único voxel de um objeto Sculptor.
 *
 * A classe CutVoxel é derivada de FiguraGeometrica e implementa a operação
 * de remoção de um voxel específico identificado por suas coordenadas `(x, y, z)`.
 */
class CutVoxel : public FiguraGeometrica
{
private:
  int x; ///< Coordenada X do voxel a ser removido.
  int y; ///< Coordenada Y do voxel a ser removido.
  int z; ///< Coordenada Z do voxel a ser removido.

public:
  /**
   * @brief Construtor da classe CutVoxel.
   *
   * Inicializa as coordenadas do voxel que será removido.
   *
   * @param x Coordenada X do voxel.
   * @param y Coordenada Y do voxel.
   * @param z Coordenada Z do voxel.
   */
  CutVoxel(int x, int y, int z);

  /**
   * @brief Remove o voxel especificado do objeto Sculptor.
   *
   * O método desativa o voxel localizado nas coordenadas `(x, y, z)` no
   * objeto Sculptor.
   *
   * @param t Referência para o objeto Sculptor onde a operação será realizada.
   */
  void draw(Sculptor &t) const override;
};

#endif // CUT_VOXEL_H
