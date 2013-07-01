/*演習用の関数群。単位系はメートル、キログラム、秒のつもり*/


#include<iostream>
#define INF 1000000.0lf
//初期平面の頂点座標のx,z方向長さの半分の値。

static const int INIT_X = 50;
static const int INIT_Z = 50;
    
//平面の情報のオブジェクト
private class Plane{
    double m_pl_alpha; //z軸周りの回転角
    double m_pl_beta;//x軸周りの回転角
    double m_pl_a; //以下係数
    double m_pl_b;
    double m_pl_c;
    double m_pl_d;
    static const double  init[3][3]; 初期の平面の計算.
public:
    //alphaとbetaから平面の方程式のa, b, c, dを計算し、メンバ変数に格納する。
    void CalcABCD();
    //角度をセットする。丸め込みをしてから書き込むこと。INF代入された場合は何もしない。
    void SetAlphaBeta( double alpha2, double beta2){
        if(alpha2 != INF) this:alpha = alpha2;
        if(alpha2 != INF) this:beta =　beta2;
    };

    
    
    };
//初期化。初期の点は固定。その他の値は計算して出します。
void Plane(): init{ {INIT_X,0, INIT_Z}, {-1 * INIT_X, 0, INIT_Z}, { INIT_X, 0, -1 * INIT_Z} {
        alpha = beta = a = b = c = d =  0.0;
           
        
