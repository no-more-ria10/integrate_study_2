/*
　計算用関数
ライブラリ使えばすぐできる話でした。
*/

#include<math.h>
#include<iostream>
#include"calc.hpp"
//z軸、x軸座標回転
double*  rotate_3d_z_x(double p[3],double a, double b){
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

bool judge_hit(Ball ball, Plane plane){
    if( l_point_plane( plane, ball.point) <= ball.radius )
        return true;
    else if( l_point_plane( plane, ball.point) > ball.radius )
        return false;
}
