#include "sculptor.h"
#include "put-voxel.h"
#include "cut-voxel.h"
#include <iostream>

int main() {
    Sculptor sculptor(10, 10, 10);

    PutVoxel voxel(5, 5, 5, 1.0f, 0.0f, 0.0f, 0.5f);
    voxel.draw(sculptor);

    // CutVoxel cutVoxel(5, 5, 5);

    // cutVoxel.draw(sculptor);
    
    sculptor.writeOFF("cutvoxel.off");
    std::cout << "Voxel desenhado e salvo como putvoxel.off" << std::endl;



    return 0;
}