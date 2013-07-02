#include "object_struct.hpp"
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
    double al, be;
    Plane plane;
    if(argc != 3){
        std::cout << "error!!. num of argument is 3!!" <<std::endl;
        return 0;        
    }
    al = atof(argv[1]);
    be = atof(argv[2]); //M_PI / 2.0;
   
    plane.SetAlphaBeta(al, be);
    plane.print();
}
    
