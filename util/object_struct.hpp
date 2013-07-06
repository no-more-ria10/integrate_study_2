/*演習用の関数群。単位系はメートル、キログラム、秒のつもり*/

#ifndef __OBJECT_STRUCT_H__
#define __OBJECT_STRUCT_H__

#include<iostream>
#include<stdbool.h>
#include<stdlib.h>

#define INF 1000000.0f
//初期平面の頂点座標のx,z方向長さの半分の値。
#define INIT_X  50.0f
#define INIT_Z  50.0f
//初期半径　
#define INIT_R 10.0f

typedef enum{
    Alpha = 0,
    Beta 
}angle_type_t;

class Ball;


//平面の情報のオブジェクト
class Plane{
    //点と平面の距離を求める関数
    friend double l_point_plane(Plane plane, double p[3]);
//平面とボールのあたり判定。
    friend bool judge_hit(Ball ball, Plane plane);
    friend void slope_fall(Ball* ball, Plane* plane);//坂道転がるやつ
friend bool check_on_plane(Ball ball, Plane plane);
private:
    double m_pl_alpha; //z軸周りの回転角
    double m_pl_beta;//x軸周りの回転角
    double m_pl_a; //以下係数
    double m_pl_b;
    double m_pl_c;
    double m_pl_d;
    double nomal_vec[3]; //単位法線ベクトル;
    double theta ;//zx平面とこの平面のなす角。
public:
    //alphaとbetaから平面の方程式のa, b, c, d,単位法線ベクトルを計算し、メンバ変数に格納する。法線ベクトルの計算怪しい感じがする。
    void CalcABCD_nomarl_theta();
    //角度をセットする。丸め込みをしてから書き込むこと。INF代入された場合は何もしない。
    void SetAlphaBeta(double alpha2, double beta2);
//初期化関数。引数はとらない
    Plane();
//平面情報を標準出力する
    void print(){
        std::cout << m_pl_alpha << " "<<m_pl_beta <<"\n"<< m_pl_a <<" "<<m_pl_b<<" "<<m_pl_c<<" "<<m_pl_d<< " " <<m_pl_init[0][0]<<" "<<m_pl_init[0][1]<<" "<<m_pl_init[0][2]<<" "<< nomal_vec[0] <<" "<<nomal_vec[1] <<" "<<nomal_vec[2] << " " << theta << " #plane_data" <<std::endl ;        
};
//各値の取得用関数。
    static const double  m_pl_init[4][3] ; //初期の平面の頂点。静的メンバ
    double GetAngle(angle_type_t x){
        if( x < 0 || x > 1 ){
            std::cout << "Plane::GetAngle error" << std::endl ;
            exit(0);
        }
        if(x == Alpha)      return m_pl_alpha; //引数が０ならalphaの値。
        if(x == Beta) return m_pl_beta; //逆
    };
    double GetNum(int x){
        switch(x){
        case 0:
            return m_pl_a;
            break;
        case 1:
            return m_pl_b;
            break;
        case 2:
            return m_pl_c;
            break;
        case 3:
            return m_pl_d;
            break;
        default:
            std::cout << "Plane::GetNum error" << std::endl ;
            exit(0);
            break;
        }
    };
    double GetNomal(int x){
        if( x < 0 || x >2 ){
            std::cout << "ball::GetPoint error" << std::endl ;
            exit(0);
        }
        return nomal_vec[x];
    };
    double GetTheta(){
        return theta;
    };
};

//球のオブジェクト。座標、速度を持つ。
class Ball{
//平面とボールのあたり判定。
    friend bool judge_hit(Ball ball, Plane plane);
    friend void free_fall(Ball* ball);//自由落下用
    friend void slope_fall(Ball* ball, Plane* plane);//坂道転がるやつ
private:
    double radius ;//半径。基本的に固定？
    double point[3]; //座標 
    double vel[3]; //速度
public:
    //変化分を足しこむ
    double up_point(double p[3]){
        for(int i = 0; i<3 ; i++){
            point[i] += p[i];
        }
    };
    double up_vel(double v[3]){
        for(int i = 0; i<3 ; i++){
            vel[i] += v[i];
        }
    };
    //そのまま変更する。
    double renew_point(double p[3]){
        for(int i = 0; i<3 ; i++){
            point[i] = p[i];
        }
    }
        
    double renew_radius(double n_r){
        radius = n_r;
    } ;   
    void print(){
        std::cout<< radius << "#ball_radius\n " << point[0] << " "<<point[1] << " "<<point[2] << " #ball_point\n "<< vel[0] << " " << vel[1] << " " << vel[2] << " #ball_vel " << std::endl;        
    };
    double GetPoint(int x){
        if( x < 0 || x >2 ){
            std::cout << "ball::GetPoint error" << std::endl ;
            exit(0);
        }
        return point[x];
    };
    double GetVel(int x){
        if( x < 0 || x >2 ){
            std::cout << "ball::GetVel error" << std::endl ;
            exit(0);
        }
        return vel[x];
    };
    double GetRadius(){
        return radius;
    };
    
    Ball(){
        for(int i = 0; i < 3 ; i++){
            vel[i] = 0.0;
            point[i] = 0.0;
        }
        radius = INIT_R;
        point[1] = 100;
    };

};
    

#endif 
