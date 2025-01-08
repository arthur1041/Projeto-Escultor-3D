/**
 * @file cut-sphere.h
 * @brief Declaração da classe CutSphere.
 *
 * Este arquivo contém a definição da classe CutSphere, que representa a operação de remoção
 * de uma esfera de uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef CUT_SPHERE_H
#define CUT_SPHERE_H

#include "figura-geometrica.h"

/**
 * @class CutSphere
 * @brief Classe para remover uma esfera de um objeto Sculptor.
 *
 * A classe CutSphere é derivada de FiguraGeometrica e implementa a operação de remoção
 * de uma esfera. A esfera é definida pelo seu centro `(xcenter, ycenter, zcenter)`
 * e pelo raio `radius`.
 */
class CutSphere : public FiguraGeometrica
{
private:
  int xcenter; ///< Coordenada X do centro da esfera.
  int ycenter; ///< Coordenada Y do centro da esfera.
  int zcenter; ///< Coordenada Z do centro da esfera.
  int radius;  ///< Raio da esfera.

public:
  /**
   * @brief Construtor da classe CutSphere.
   *
   * Inicializa os atributos que definem a esfera a ser removida.
   *
   * @param xcenter Coordenada X do centro da esfera.
   * @param ycenter Coordenada Y do centro da esfera.
   * @param zcenter Coordenada Z do centro da esfera.
   * @param radius Raio da esfera.
   */
  CutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
   * @brief Remove a esfera especificada do objeto Sculptor.
   *
   * O método desativa todos os voxels que pertencem à esfera definida
   * pelo centro `(xcenter, ycenter, zcenter)` e pelo raio `radius`.
   *
   * @param t Referência para o objeto Sculptor onde a operação será realizada.
   */
  void draw(Sculptor &t) const override;
};

#endif // CUT_SPHERE_H
