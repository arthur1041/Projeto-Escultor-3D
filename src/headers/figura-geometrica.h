/**
 * @file figura-geometrica.h
 * @brief Declaração da classe abstrata FiguraGeometrica.
 *
 * Este arquivo contém a definição da classe FiguraGeometrica, que serve como base
 * para a criação de objetos geométricos que podem ser desenhados em um objeto Sculptor.
 */

#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

#include "sculptor.h"

/**
 * @class FiguraGeometrica
 * @brief Classe abstrata para representar figuras geométricas.
 *
 * A classe FiguraGeometrica define uma interface para figuras geométricas que
 * podem ser desenhadas em um objeto Sculptor. Classes derivadas devem implementar
 * o método draw para especificar como a figura será desenhada.
 */
class FiguraGeometrica
{
public:
  /**
   * @brief Construtor padrão da classe FiguraGeometrica.
   */
  FiguraGeometrica() = default;

  /**
   * @brief Destrutor virtual da classe FiguraGeometrica.
   *
   * Garante que as classes derivadas terão seus destrutores chamados corretamente.
   */
  virtual ~FiguraGeometrica() = default;

  /**
   * @brief Método virtual puro para desenhar a figura em um objeto Sculptor.
   *
   * Este método deve ser implementado pelas classes derivadas para definir
   * como a figura geométrica será desenhada na matriz tridimensional do objeto Sculptor.
   *
   * @param t Referência para o objeto Sculptor onde a figura será desenhada.
   */
  virtual void draw(Sculptor &t) const = 0;
};

#endif // FIGURA_GEOMETRICA_H
