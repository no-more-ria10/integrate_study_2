#include<math.h>
#include<iostream>
#include"object_struct.hpp"
/*平面の計算のメンバ変数。*/
const double Plane::m_pl_init[4][4]  = { {INIT_X,0, INIT_Z}, {-1 * INIT_X, 0, INIT_Z}, { INIT_X, 0, -1 * INIT_Z}, {-1 * INIT_X, 0, -1*INIT_Z}}; //初期の平面の頂点。静的メンバ

void Plane::CalcABCD(){
    int p[3][3]; //回転後の頂点の格納。
    //頂点の回転後座標の計算。ｚ軸周りがm_pl_alpha,x軸周りがbeta
    for(int i = 0; i < 3 ; i++){   
        p[i][0] = m_pl_init[i][0] * cos(m_pl_alpha) - m_pl_init[i][1] * sin(m_pl_alpha) * cos(m_pl_beta ) + m_pl_init[i][2] * sin(m_pl_alpha) * sin(m_pl_beta );
        p[i][1] = m_pl_init[i][0] * sin(m_pl_alpha) + m_pl_init[i][1] * cos(m_pl_alpha) * cos(m_pl_beta ) - m_pl_init[i][2] * cos(m_pl_alpha) * sin(m_pl_beta );
        p[i][2] = m_pl_init[i][0] * 0.0 + m_pl_init[i][1] * sin(m_pl_beta ) - m_pl_init[i][2] * cos(m_pl_beta );
    }
    //a,b,c,dの計算。dの計算にはa,b,cを用いることに注意
    m_pl_a = ( p[1][1] - p[0][1] ) * ( p[2][2] - p[0][2] ) - (p[2][1] - p[0][1] ) * (p[1][2] - p[0][2] );
    m_pl_b = ( p[1][2] - p[0][2] ) * ( p[2][0] - p[0][0] ) - (p[2][2] - p[0][2] ) * (p[1][0] - p[0][0] ) ;
    m_pl_c = ( p[1][0] - p[0][0] ) * ( p[2][1] - p[0][1] ) - (p[2][0] - p[0][0] ) * (p[1][1] - p[0][1] ); 
    m_pl_d = -p[0][0] * m_pl_a -p[0][1] * m_pl_b -p[0][2] * m_pl_c;
    return ;
}

//初期化。初期の点は固定。その他の値は計算して出します。
Plane::Plane() 
 {
        this->m_pl_alpha = m_pl_beta  = m_pl_a = m_pl_b = m_pl_c = m_pl_d =  0.0;
        this->CalcABCD();
 }

void Plane::SetAlphaBeta ( double alpha2, double beta2){
    if(alpha2 != INF) this->m_pl_alpha = alpha2;
    if(alpha2 != INF) this->m_pl_beta = beta2;
    CalcABCD();
    return;
}    
