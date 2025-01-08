/**
 * @file put-voxel.h
 * @brief Declaração da classe PutVoxel.
 * 
 * Este arquivo contém a definição da classe PutVoxel, que representa a operação
 * de adição de um único voxel em uma matriz tridimensional em um objeto Sculptor.
 */

#ifndef PUT_VOXEL_H
#define PUT_VOXEL_H

#include "figura-geometrica.h"

/**
 * @class PutVoxel
 * @brief Classe para adicionar um único voxel a um objeto Sculptor.
 * 
 * A classe PutVoxel é derivada de FiguraGeometrica e implementa a operação
 * de adição de um único voxel. O voxel é definido por suas coordenadas `(x, y, z)`
 * e sua cor é especificada pelos valores RGBA.
 */
class PutVoxel : public FiguraGeometrica
{
private:
    int x; ///< Coordenada X do voxel.
    int y; ///< Coordenada Y do voxel.
    int z; ///< Coordenada Z do voxel.
    float r; ///< Componente vermelha da cor (0-1).
    float g; ///< Componente verde da cor (0-1).
    float b; ///< Componente azul da cor (0-1).
    float a; ///< Transparência da cor (0-1).

public:
    /**
     * @brief Construtor da classe PutVoxel.
     * 
     * Inicializa as coordenadas e a cor do voxel que será adicionado.
     * 
     * @param x Coordenada X do voxel.
     * @param y Coordenada Y do voxel.
     * @param z Coordenada Z do voxel.
     * @param r Componente vermelha da cor (0-1).
     * @param g Componente verde da cor (0-1).
     * @param b Componente azul da cor (0-1).
     * @param a Transparência da cor (0-1).
     */
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);

    /**
     * @brief Adiciona o voxel especificado ao objeto Sculptor.
     * 
     * O método ativa o voxel localizado nas coordenadas `(x, y, z)` no objeto Sculptor
     * e aplica a cor definida pelos valores RGBA.
     * 
     * @param t Referência para o objeto Sculptor onde a operação será realizada.
     */
    void draw(Sculptor &t) const override;
};

#endif // PUT_VOXEL_H
