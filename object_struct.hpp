/*演習用の関数群。単位系はメートル、キログラム、秒のつもり*/


#include<iostream>
#define INF 1000000.0f
//初期平面の頂点座標のx,z方向長さの半分の値。
#define INIT_X  50.0f
#define INIT_Z  50.0f
    
//平面の情報のオブジェクト
class Plane{
private:
    double m_pl_alpha; //z軸周りの回転角
    double m_pl_beta;//x軸周りの回転角
    double m_pl_a; //以下係数
    double m_pl_b;
    double m_pl_c;
    double m_pl_d;
    static const double  m_pl_init[3][3] ; //初期の平面の頂点。静的メンバ
public:
    //alphaとbetaから平面の方程式のa, b, c, dを計算し、メンバ変数に格納する。    
    void CalcABCD();
    //角度をセットする。丸め込みをしてから書き込むこと。INF代入された場合は何もしない。
    void SetAlphaBeta(double , double);
    Plane();

        
};
