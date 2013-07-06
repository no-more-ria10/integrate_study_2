/*
　計算用関数
ライブラリ使えばすぐできる話でした。
*/

#include<math.h>
#include<iostream>
#include"calc.hpp"
#include"object_struct.hpp"
//z軸、x軸座標回転
double*  rotate_3d_z_x(const double p[3],double a, double b){
    double *n_p;
    n_p = new double[3];

    n_p[0] = p[0] * cos(a) - p[1] * sin(a) * cos(b) + p[2] * sin(a) * sin(b);
    n_p[1] = p[0] * sin(a) + p[1] * cos(a) * cos(b) - p[2] * cos(a) * sin(b);
    n_p[2] = p[1] * sin(b) + p[2] * cos(b);
#ifdef DEBUG_MODE
    std::cout << n_p[0] << " "<<n_p[1] << " "<<n_p[2] << std::endl;
#endif
    return n_p;
       
}
//点と平面の距離を測る
double l_point_plane( Plane p, double a[3]){
    double u,s;
    u = p.m_pl_a * a[0] + p.m_pl_b * a[1] + p.m_pl_c * a[2] + p.m_pl_d;
    s = sqrt( p.m_pl_a * p.m_pl_a + p.m_pl_b * p.m_pl_b + p.m_pl_c * p.m_pl_c);
    return (u) > ( -1.0 * u) ? u / s : -1.0 * u / s; 
}
//平面と球のヒット判定。当たったらtruex
bool judge_hit(Ball ball, Plane plane){
    if( l_point_plane( plane, ball.point) <= ball.radius )
        return true;
    else if( l_point_plane( plane, ball.point) > ball.radius )
        return false;
}
//球を平面の上側（y軸方向を上とする）に載せる。ヒット判定のあとに使う。
void put_ball_on_plane(Ball* ball, Plane* plane){
    double x[3], center[3];
    for( int i = 0; i<3 ; i++){
        center[i] = ball->GetPoint(i);
    } //中心座標の取得
    double l = l_point_plane( *plane, center); 
    for( int i = 0; i<3 ; i++){
        x[i] = center[i] + (ball->GetRadius() - l) * plane->GetNomal(i);
    }
    std::cout << "put_ball_on_plane\n" << std::endl;
    ball->renew_point(x);    
}
//坂の上にいるかチェックする関数。 乗ってたらtrue
bool check_on_plane(Ball ball, Plane plane){

    
    double* x; //回転後座標の入れ物。
    double p[3]; //球の中心座標の入れ物。
    x= rotate_3d_z_x( plane.m_pl_init[0], plane.m_pl_alpha, plane.m_pl_beta);
    for( int i = 0; i<3; i++){
        x[i] = ( x[i] > 0 ) ? x[i] : (-1.0 * x[i]);
        p[i] = ( ball.GetPoint(i) > 0 ) ? ball.GetPoint(i) : (-1.0 * ball.GetPoint(i));
    }                               
    if(  p[0] < x[0] ){
        if( p[2] < x[2]){
                return true;
        }
    }
    return false;
}
   
