/*演習用の関数群。単位系はメートル、キログラム、秒のつもり*/

#ifndef __OBJECT_STRUCT_H__
#define __OBJECT_STRUCT_H__

#include<iostream>
#include<stdbool.h>
#define INF 1000000.0f
//初期平面の頂点座標のx,z方向長さの半分の値。
#define INIT_X  50.0f
#define INIT_Z  50.0f
//初期半径　
#define INIT_R 5.0f

//平面の情報のオブジェクト
class Plane{
    //点と平面の距離を求める関数
    friend double l_point_plane(Plane plane, double p[3]);
//平面とボールのあたり判定。
//    friend bool judge_hit(Ball ball, Plane plane);
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
    void SetAlphaBeta(double alpha2, double beta2);
//初期化関数。引数はとらない
    Plane();
//平面情報を標準出力する
    void print(){
        std::cout << m_pl_alpha << " "<<m_pl_beta <<"\n"<< m_pl_a <<" "<<m_pl_b<<" "<<m_pl_c<<" "<<m_pl_d<<"\n"<<m_pl_init[0][0]<<" "<<m_pl_init[0][1]<<" "<<m_pl_init[0][2]<<"#plane_data" << std::endl ;        
};

};

//球のオブジェクト。座標、速度を持つ。
class Ball{
//平面とボールのあたり判定。
//    friend bool judge_hit(Ball ball, Plane plane);
private:
    double radius ;//半径。基本的に固定？
    double point[3]; //座標 
    double vel[3]; //速度
public:
    double renew_point(double p[3]){
        for(int i = 0; i<3 ; i++){
            point[i] = p[i];
        }
    };
    double renew_vel(double v[3]){
        for(int i = 0; i<3 ; i++){
            vel[i] = v[i];
        }
    };
    double renew_radius(double n_r){
        radius = n_r;
    } ;   
    void print(){
        std::cout<< radius << " " << point[0] << " "<<point[1] << " "<<point[2] << " "<< vel[0] << " " << vel[1] << " " << vel[2] << "#ball_data " << std::endl;        
   }
    Ball(){
        for(int i = 0; i < 3 ; i++){
            vel[i] = 0.0;
            point[i] = 0.0;
            radius = INIT_R;
        }
    };

};
    

#endif 
