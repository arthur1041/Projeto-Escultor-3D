/**
 * @file put-box.h
 * @brief Declaração da classe PutBox.
 * 
 * Este arquivo contém a definição da classe PutBox, que representa a operação
 * de adição de um paralelepípedo em uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef PUT_BOX_H
#define PUT_BOX_H

#include "figura-geometrica.h"

/**
 * @class PutBox
 * @brief Classe para adicionar um paralelepípedo a um objeto Sculptor.
 * 
 * A classe PutBox é derivada de FiguraGeometrica e implementa a operação
 * de adição de um paralelepípedo. O paralelepípedo é definido por seus limites
 * nas dimensões X, Y e Z, além de possuir uma cor especificada por RGBA.
 */
class PutBox : public FiguraGeometrica
{
private:
    int x0, x1; ///< Limites da dimensão X.
    int y0, y1; ///< Limites da dimensão Y.
    int z0, z1; ///< Limites da dimensão Z.
    float r;    ///< Componente vermelha da cor (0-1).
    float g;    ///< Componente verde da cor (0-1).
    float b;    ///< Componente azul da cor (0-1).
    float a;    ///< Transparência (0-1).

public:
    /**
     * @brief Construtor da classe PutBox.
     * 
     * Inicializa os limites do paralelepípedo e define sua cor.
     * 
     * @param x0 Coordenada inicial no eixo X.
     * @param x1 Coordenada final no eixo X.
     * @param y0 Coordenada inicial no eixo Y.
     * @param y1 Coordenada final no eixo Y.
     * @param z0 Coordenada inicial no eixo Z.
     * @param z1 Coordenada final no eixo Z.
     * @param r Componente vermelha da cor (0-1).
     * @param g Componente verde da cor (0-1).
     * @param b Componente azul da cor (0-1).
     * @param a Transparência da cor (0-1).
     */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);

    /**
     * @brief Adiciona o paralelepípedo especificado ao objeto Sculptor.
     * 
     * O método ativa todos os voxels dentro da região delimitada por `(x0, x1)`,
     * `(y0, y1)` e `(z0, z1)`, aplicando a cor definida pelos valores RGBA.
     * 
     * @param t Referência para o objeto Sculptor onde a operação será realizada.
     */
    void draw(Sculptor &t) const override;
};

#endif // PUT_BOX_H
