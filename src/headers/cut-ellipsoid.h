/**
 * @file cut-ellipsoid.h
 * @brief Declaração da classe CutEllipsoid.
 *
 * Este arquivo contém a definição da classe CutEllipsoid, que representa a operação de remoção
 * de um elipsoide de uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef CUT_ELLIPSOID_H
#define CUT_ELLIPSOID_H

#include "figura-geometrica.h"

/**
 * @class CutEllipsoid
 * @brief Classe para remover um elipsoide de um objeto Sculptor.
 *
 * A classe CutEllipsoid é derivada de FiguraGeometrica e implementa a operação de remoção
 * de um elipsoide. O elipsoide é definido pelo seu centro `(xcenter, ycenter, zcenter)`
 * e pelos raios `rx`, `ry`, e `rz` em cada um dos eixos.
 */
class CutEllipsoid : public FiguraGeometrica
{
private:
  int xcenter; ///< Coordenada X do centro do elipsoide.
  int ycenter; ///< Coordenada Y do centro do elipsoide.
  int zcenter; ///< Coordenada Z do centro do elipsoide.
  int rx;      ///< Raio do elipsoide no eixo X.
  int ry;      ///< Raio do elipsoide no eixo Y.
  int rz;      ///< Raio do elipsoide no eixo Z.

public:
  /**
   * @brief Construtor da classe CutEllipsoid.
   *
   * Inicializa os atributos que definem o elipsoide a ser removido.
   *
   * @param xcenter Coordenada X do centro do elipsoide.
   * @param ycenter Coordenada Y do centro do elipsoide.
   * @param zcenter Coordenada Z do centro do elipsoide.
   * @param rx Raio do elipsoide no eixo X.
   * @param ry Raio do elipsoide no eixo Y.
   * @param rz Raio do elipsoide no eixo Z.
   */
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
   * @brief Remove o elipsoide especificado do objeto Sculptor.
   *
   * O método desativa todos os voxels que pertencem ao elipsoide definido
   * pelo centro `(xcenter, ycenter, zcenter)` e pelos raios `rx`, `ry`, `rz`.
   *
   * @param t Referência para o objeto Sculptor onde a operação será realizada.
   */
  void draw(Sculptor &t) const override;
};

#endif // CUT_ELLIPSOID_H
