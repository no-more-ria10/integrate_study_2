#include<math.h>
#include<iostream>
#include"object_struct.hpp"
/*平面の計算のメンバ変数。*/

void Plane::CalcABCD(){
    int p[3][3]; //回転後の頂点の格納。
    //頂点の回転後座標の計算。ｚ軸周りがalpha,x軸周りがbeta
    for(int i = 0; i < 3 ; i++){   
        p[i][0] = init[i][0] * cos(alpha) - init[i][1] * sin(alpha) * cos(beta) + init[i][2] * sin(alpha) * sin(beta);
        p[i][1] = init[i][0] * sin(alpha) + init[i][1] * cos(alpha) * cos(beta) - init[i][2] * cos(alpha) * sin(beta);
        p[i][2] = init[i][0] * 0.0 + init[i][1] * sin(beta) - init[i][2] * cos(beta);
    }
    //a,b,c,dの計算。dの計算にはa,b,cを用いることに注意
    m_pl_a = ( p[1][1] - p[0][1] ) * ( p[2][2] - p[0][2] ) - (p[2][1] - p[0][1] ) * (p[1][2] - p[0][2] );
    m_pl_b = ( p[1][2] - p[0][2] ) * ( p[2][0] - p[0][0] ) - (p[2][2] - p[0][2] ) * (p[1][0] - p[0][0] ) ;
    m_pl_c = ( p[1][0] - p[0][0] ) * ( p[2][1] - p[0][1] ) - (p[2][0] - p[0][0] ) * (p[1][1] - p[0][1] ); 
    m_pl_d = -p[0][0] * m_pl_a -p[0][1] * m_pl_b -p[0][0] * m_pl_c;
}

//初期化。初期の点は固定。その他の値は計算して出します。
void Plane::Plane(): init{ {INIT_X,0, INIT_Z}, {-1 * INIT_X, 0, INIT_Z}, { INIT_X, 0, -1 * INIT_Z} } {
        alpha = beta = a = b = c = d =  0.0;
        CalcABCD();
}
