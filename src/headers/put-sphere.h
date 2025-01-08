/**
 * @file put-sphere.h
 * @brief Declaração da classe PutSphere.
 * 
 * Este arquivo contém a definição da classe PutSphere, que representa a operação
 * de adição de uma esfera em uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef PUT_SPHERE_H
#define PUT_SPHERE_H

#include "figura-geometrica.h"

/**
 * @class PutSphere
 * @brief Classe para adicionar uma esfera a um objeto Sculptor.
 * 
 * A classe PutSphere é derivada de FiguraGeometrica e implementa a operação
 * de adição de uma esfera. A esfera é definida pelo seu centro `(xcenter, ycenter, zcenter)`
 * e pelo raio `radius`. Sua cor é especificada pelos valores RGBA.
 */
class PutSphere : public FiguraGeometrica
{
private:
    int xcenter; ///< Coordenada X do centro da esfera.
    int ycenter; ///< Coordenada Y do centro da esfera.
    int zcenter; ///< Coordenada Z do centro da esfera.
    int radius;  ///< Raio da esfera.
    float r;     ///< Componente vermelha da cor (0-1).
    float g;     ///< Componente verde da cor (0-1).
    float b;     ///< Componente azul da cor (0-1).
    float a;     ///< Transparência da cor (0-1).

public:
    /**
     * @brief Construtor da classe PutSphere.
     * 
     * Inicializa os atributos que definem a esfera, incluindo seu centro, raio
     * e os valores de cor.
     * 
     * @param xcenter Coordenada X do centro da esfera.
     * @param ycenter Coordenada Y do centro da esfera.
     * @param zcenter Coordenada Z do centro da esfera.
     * @param radius Raio da esfera.
     * @param r Componente vermelha da cor (0-1).
     * @param g Componente verde da cor (0-1).
     * @param b Componente azul da cor (0-1).
     * @param a Transparência da cor (0-1).
     */
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);

    /**
     * @brief Adiciona a esfera especificada ao objeto Sculptor.
     * 
     * O método ativa todos os voxels que pertencem à esfera definida pelo
     * centro `(xcenter, ycenter, zcenter)` e pelo raio `radius`, aplicando a cor
     * definida pelos valores RGBA.
     * 
     * @param t Referência para o objeto Sculptor onde a operação será realizada.
     */
    void draw(Sculptor &t) const override;
};

#endif // PUT_SPHERE_H
