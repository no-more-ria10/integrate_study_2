/*
  自由落下の関数
  1次の差分法で解く。（結果は変わらない。）
*/

#include<iostream>
#include<math.h>
#include"object_struct.hpp"
#include"calc.hpp"
#include"motion.hpp"

void free_fall(Ball* ball){
    double dv[3];
    double dp[3];
    dv[0] = 0;
    dv[1] = - G * DT;
    dv[2] = 0;

    dp[0] = ball.vel[0];
    dp[1] = ball.vel[1];
    dp[2] = ball.vel[2];
    
    ball.renew_point(dp);
    ball.renew_vel(dv);
        
}
    
void slope_fall(Ball ball, Plane plane){
    double dv[3];
    double dp[3];    
    double abs_dv = G * sin(plane.theta) * DT; //坂を転がる速度の変化の絶対値
    dv[0] = abs_dv * plane.nomal_vec[0];
    dv[1] = abs_dv * sin(plane.theta) * sin(plane.theta);
    dv[2] = abs_dv * plane.nomal_vec[2];

    ball.vel[2] = 0 ;//坂に当たったら下方向速度は０に戻す。

    dp[0] = ball.vel[0];
    dp[1] = ball.vel[1];
    dp[2] = ball.vel[2];
 
    ball.renew_point(dp);
    ball.renew_vel(dv);

}
