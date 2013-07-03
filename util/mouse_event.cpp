/*
　マウスの左ドラッグに応じた回転移動量を計算する関数。
　総和を記録しておくことで回転のし過ぎを防ぐ。
*/

#include<GL/gl.h>
#include<GL/glut.h>
#include"object_struct.hpp"
#include<math.h>
bool l_button_flag = false;

移動量判定のために１つ前の座標まで取っておく。
static int old_p[2] = {0, 0};
static int now_p[2] = {0, 0};

static double sum_angle[2] = { 0.0, 0.0 };//角度量の総和。- M_PI 〜 M_PIにするため

//ボタンが押された時のみ回転をとるため。ボタンが離れると移動量をリセット。
void  move_step(int button, int state, int x, int y){
    if( button == GLUT_LEFT_BUTTON ){
        if( state == GLUT_UP){
            l_button_flag = false;
            
        }
        else if( state == GLUT_DOWN){
            l_button_flag = true;
            for(int i; i < 2 ; i++){
                old_p[i] = 0;
                now_p[i] = 0;
        }
    }
}
        
void motion_func( int x, int y){

    if( l_button_flag ){
            for(int i; i < 2 ; i++){
                old_p[i] =　now_p[i];
        }            
            now_p[0] = x;
            now_p[1] = y;
    }
}

//x, yに応じた回転角を提供する関数。ちょっと一般的じゃないからここじゃなくていいかも...
int* get_rotate(){
    int dx,dy;
    double* angle ;  //{alpha, beta}
    double abs_sum[2] = { sum_angle[0] > 0 ? (sum_angle[0]) : (-1.0 * sum_angle[0]),sum_angle[1] > 0 ? (sum_angle[1]) : (-1.0 * sum_angle[1])  };
    angle = new double[2];
    
    dx = now_p[0]- old_p[0];
    dy = now_p[1]- old_p[1];

    if( ((2 * M_PI * abs(dx) / 1366.0 ) +  abs_sum[0]) < M_PI ){ 
        angle[0] = 2 * M_PI * dx / 1366.0 ;
        sum_angle[0] += angle[0];
    }else{
        angle[0] = 0.0;
    }
    if( ((2 * M_PI * abs(dy) / 768.0 ) +  abs_sum[1]) < M_PI ){ 
        angle[1] = 2 * M_PI * dy / 768.0 ;
        sum_angle[1] += angle[1];
    }else{
        angle[1] = 0.0 
        
    return angle;
}
