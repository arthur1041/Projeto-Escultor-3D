/**
 * @file sculptor.h
 * @brief Declaração da classe Sculptor.
 * 
 * Este arquivo contém a definição da classe Sculptor, que gerencia uma matriz tridimensional de voxels.
 * A classe permite a criação, modificação e exportação de esculturas digitais no formato OFF.
 */

#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

/**
 * @class Sculptor
 * @brief Classe para manipular uma matriz tridimensional de voxels.
 * 
 * A classe Sculptor permite criar e modificar esculturas digitais tridimensionais
 * usando uma matriz de voxels. Além disso, oferece suporte para exportar a matriz
 * no formato OFF para visualização externa.
 */
class Sculptor
{
private:
    Voxel ***v;       ///< Matriz tridimensional de voxels.
    int nx, ny, nz;   ///< Dimensões da matriz (eixos X, Y, Z).
    float r, g, b, a; ///< Cor atual utilizada para desenho (RGBA).

public:
    /**
     * @brief Construtor da classe Sculptor.
     * 
     * Inicializa uma matriz tridimensional com as dimensões especificadas.
     * 
     * @param _nx Dimensão no eixo X.
     * @param _ny Dimensão no eixo Y.
     * @param _nz Dimensão no eixo Z.
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
     * @brief Destrutor da classe Sculptor.
     * 
     * Libera a memória alocada pela matriz tridimensional de voxels.
     */
    ~Sculptor();

    /**
     * @brief Retorna a matriz tridimensional de voxels.
     * 
     * Este método fornece acesso direto à matriz tridimensional gerenciada pela classe.
     * 
     * @return Um ponteiro para a matriz tridimensional de voxels.
     */
    Voxel ***getVoxelMatrix();

    /**
     * @brief Retorna a dimensão no eixo X.
     * 
     * @return A dimensão `nx` da matriz.
     */
    int getNx();

    /**
     * @brief Retorna a dimensão no eixo Y.
     * 
     * @return A dimensão `ny` da matriz.
     */
    int getNy();

    /**
     * @brief Retorna a dimensão no eixo Z.
     * 
     * @return A dimensão `nz` da matriz.
     */
    int getNz();

    /**
     * @brief Define a cor atual para desenho.
     * 
     * A cor é especificada em termos de valores RGBA.
     * 
     * @param r Componente vermelha (0-1).
     * @param g Componente verde (0-1).
     * @param b Componente azul (0-1).
     * @param a Transparência (0-1).
     */
    void setColor(float r, float g, float b, float a);

    /**
     * @brief Exporta a escultura para um arquivo no formato OFF.
     * 
     * O formato OFF permite que a escultura seja visualizada em ferramentas externas.
     * 
     * @param filename Nome do arquivo de saída.
     */
    void writeOFF(const char *filename);
};

#endif // SCULPTOR_H
