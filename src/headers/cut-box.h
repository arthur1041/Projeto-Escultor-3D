/**
 * @file cut-box.h
 * @brief Declaração da classe CutBox.
 *
 * Este arquivo contém a definição da classe CutBox, que representa a operação de remoção
 * de um paralelepípedo de uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef CUT_BOX_H
#define CUT_BOX_H

#include "figura-geometrica.h"

/**
 * @class CutBox
 * @brief Classe para remover um paralelepípedo de um objeto Sculptor.
 *
 * A classe CutBox é derivada de FiguraGeometrica e implementa a operação de
 * remoção de um paralelepípedo definido pelas coordenadas `(x0, x1)`, `(y0, y1)` e `(z0, z1)`.
 * A região especificada terá todos os voxels desativados no objeto Sculptor.
 */
class CutBox : public FiguraGeometrica
{
private:
  int x0, x1; ///< Limites da dimensão X.
  int y0, y1; ///< Limites da dimensão Y.
  int z0, z1; ///< Limites da dimensão Z.

public:
  /**
   * @brief Construtor da classe CutBox.
   *
   * Inicializa os limites da região a ser removida no objeto Sculptor.
   *
   * @param x0 Coordenada inicial no eixo X.
   * @param x1 Coordenada final no eixo X.
   * @param y0 Coordenada inicial no eixo Y.
   * @param y1 Coordenada final no eixo Y.
   * @param z0 Coordenada inicial no eixo Z.
   * @param z1 Coordenada final no eixo Z.
   */
  CutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
   * @brief Remove a região especificada do objeto Sculptor.
   *
   * O método desativa todos os voxels dentro da região delimitada por `(x0, x1)`,
   * `(y0, y1)` e `(z0, z1)` no objeto Sculptor.
   *
   * @param t Referência para o objeto Sculptor onde a operação será realizada.
   */
  void draw(Sculptor &t) const override;
};

#endif // CUT_BOX_H
