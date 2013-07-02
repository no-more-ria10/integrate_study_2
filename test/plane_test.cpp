#include "object_struct.hpp"
#include <stdlib.h>
#include <math.h>
#include <iostream>

int main(int argc, char** argv){
    double al, be;
    Plane plane;
    double p[3] = { 100, 10 , 7 };
    double p2; //l_point_plane テスト用
    if(argc != 3){
        std::cout << "error!!. num of argument is 3!!" <<std::endl;
        return 0;        
    }
    al = atof(argv[1]);
    be = atof(argv[2]); //M_PI / 2.0;
    
    plane.SetAlphaBeta(al, be);
    plane.print(); //平面の方程式のテスト

    p2 = l_point_plane(plane, p);
    std::cout << p2 << std::endl;
    
}
    
