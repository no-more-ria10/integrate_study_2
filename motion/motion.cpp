/*
  自由落下の関数
  1次の差分法で解く。（結果は変わらない。）
*/

#include<iostream>
#include<math.h>
#include<stdbool.h>
#include"object_struct.hpp"
#include"calc.hpp"
#include"motion.hpp"
#include"time_set.hpp"

static bool f_flag = false; //false: slope, true: free


void act_motion(Ball* ball, Plane* plane){
    if( judge_hit(*ball, *plane) ) slope_fall(ball, plane);
    else free_fall(ball);
}

void free_fall(Ball* ball){
    double dv[3];
    double dp[3];
    if( !f_flag ) {
        f_flag = true;
        std::cout<< " #flag change(false -> true)!!\n" <<std::endl;
    }
    dv[0] = 0;
    dv[1] = - G * DT;
    dv[2] = 0;

    dp[0] = ball->vel[0]  * DT;
    dp[1] = ball->vel[1] * DT;
    dp[2] = ball->vel[2] * DT;
    
    ball->up_point(dp);
    ball->up_vel(dv);
        
}

//坂の転がり。実行前にy方向の速度を０にしておくこと。
void slope_fall(Ball* ball, Plane* plane){
    double dv[3];
    double dp[3];    
    double abs_dv = G * DT; //坂を転がる速度の変化の絶対値
    if( f_flag ){
        f_flag = false;
        ball->vel[1] = 0;
        std::cout<< " #flag change(true -> false)!!\n" <<std::endl;
    }
    dv[0] = abs_dv * cos(plane->theta) * plane->nomal_vec[0] ;
    dv[1] = - 1.0 *abs_dv * sin(plane->theta) * sin(plane->theta) ;
    dv[2] = abs_dv * cos(plane->theta) * plane->nomal_vec[2] ;

    ball->up_vel(dv);

    dp[0] = ball->vel[0] * DT;
    dp[1] = ball->vel[1] * DT;
    dp[2] = ball->vel[2] * DT;
 
    ball->up_point(dp);

}

