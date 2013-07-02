#include "object_struct.hpp"
#include <math.h>
#include <iostream>
#include "motion.hpp"
#include "time_set.hpp"

#define ROOP_NUM 1000

//フリーフォールじゃなく坂転がすよ！！

int main(int argc, char** argv){
    double al, be;
    Plane plane;
    Ball ball;
    double p[3] = { 0, 45 ,0 };
    double p2; //l_point_plane テスト用
    if(argc != 3){
        std::cout << "error!!. num of argument is 3!!" <<std::endl;
        return 0;        
    }
    al = atof(argv[1]);
    be = atof(argv[2]); //M_PI / 2.0;
    
    plane.SetAlphaBeta(al, be);
    plane.print(); //平面の方程式のテスト

    for(int i = 0; i < ROOP_NUM; i++){
        //free_fall(&ball);
        act_motion(&ball, &plane);
        ball.print();
    }
}
    
