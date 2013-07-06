/*
  計算用の関数群
*/
#ifndef __CALC_H__
#define __CALC_H__

#include<math.h>
#include"object_struct.hpp"

//座標のオイラー角回転。回転はz軸、x軸の順で、　x軸->beta,z軸->alpha,となっていることに注意。使いづらいよ！！
double* rotate_3d_z_x(const double p[3],double a, double b);

//３次元の点と平面の距離を測る。
double l_point_plane ( Plane plane, double point[3]);
//ヒット判定。ヒットならtrue
bool judge_hit(Ball ball, Plane plane);
//中心修正用。平面にちょうどのるような位置に球を移動させる。
void put_ball_on_plane(Ball* ball, Plane* plane);
//平面領域からはみ出ていないかチェック
bool check_on_plane(Ball ball, Plane plane);




#endif 
