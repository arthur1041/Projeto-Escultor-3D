/**
 * @file put-ellipsoid.h
 * @brief Declaração da classe PutEllipsoid.
 * 
 * Este arquivo contém a definição da classe PutEllipsoid, que representa a operação
 * de adição de um elipsoide em uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef PUT_ELLIPSOID_H
#define PUT_ELLIPSOID_H

#include "figura-geometrica.h"

/**
 * @class PutEllipsoid
 * @brief Classe para adicionar um elipsoide a um objeto Sculptor.
 * 
 * A classe PutEllipsoid é derivada de FiguraGeometrica e implementa a operação
 * de adição de um elipsoide. O elipsoide é definido pelo seu centro `(xcenter, ycenter, zcenter)`
 * e pelos raios `rx`, `ry` e `rz` em cada eixo. Além disso, sua cor é definida pelos valores RGBA.
 */
class PutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter; ///< Coordenada X do centro do elipsoide.
    int ycenter; ///< Coordenada Y do centro do elipsoide.
    int zcenter; ///< Coordenada Z do centro do elipsoide.
    int rx;      ///< Raio do elipsoide no eixo X.
    int ry;      ///< Raio do elipsoide no eixo Y.
    int rz;      ///< Raio do elipsoide no eixo Z.
    float r;     ///< Componente vermelha da cor (0-1).
    float g;     ///< Componente verde da cor (0-1).
    float b;     ///< Componente azul da cor (0-1).
    float a;     ///< Transparência da cor (0-1).

public:
    /**
     * @brief Construtor da classe PutEllipsoid.
     * 
     * Inicializa os atributos que definem o elipsoide, incluindo seu centro, raios
     * e os valores de cor.
     * 
     * @param xcenter Coordenada X do centro do elipsoide.
     * @param ycenter Coordenada Y do centro do elipsoide.
     * @param zcenter Coordenada Z do centro do elipsoide.
     * @param rx Raio do elipsoide no eixo X.
     * @param ry Raio do elipsoide no eixo Y.
     * @param rz Raio do elipsoide no eixo Z.
     * @param r Componente vermelha da cor (0-1).
     * @param g Componente verde da cor (0-1).
     * @param b Componente azul da cor (0-1).
     * @param a Transparência da cor (0-1).
     */
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);

    /**
     * @brief Adiciona o elipsoide especificado ao objeto Sculptor.
     * 
     * O método ativa todos os voxels que pertencem ao elipsoide definido pelo
     * centro `(xcenter, ycenter, zcenter)` e pelos raios `rx`, `ry`, `rz`, aplicando
     * a cor definida pelos valores RGBA.
     * 
     * @param t Referência para o objeto Sculptor onde a operação será realizada.
     */
    void draw(Sculptor &t) const override;
};

#endif // PUT_ELLIPSOID_H
