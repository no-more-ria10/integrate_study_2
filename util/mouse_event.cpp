/*
　マウスの左ドラッグに応じた回転移動量を計算する関数。
総和を記録しておくことで回転のし過ぎを防ぐ。
*/

#include<GL/gl.h>
#include<GL/glut.h>
#include"object_struct.hpp"
#include<math.h>
static bool l_button_flag = false;//ボタンが押された状態かの判定。
static bool act_flag = false; //一発目のドラッグで動かないように

//移動量判定のために１つ前の座標まで取っておく。
static double old_p[2] = {0.0, 0.0};
static double now_p[2] = {0.0, 0.0};


//ボタンが押された時のみ回転をとるため。ボタンが離れると移動量をリセット。
void  move_step(int button, int state, int x, int y){
    if( button == GLUT_LEFT_BUTTON ){
        if( state == GLUT_UP){
            l_button_flag = false;
            act_flag = false;
            for(int i; i < 2 ; i++){
                old_p[i] = 0;
                now_p[i] = 0;
        }
            
        } else if( state == GLUT_DOWN){
            l_button_flag = true;
        }
    }
}
        
void motion_func( int x, int y){

    if( l_button_flag ){
            for(int i; i < 2 ; i++){
                old_p[i] = now_p[i];
        }            
            now_p[0] = x;
            now_p[1] = y;
    }

}

//x, yに応じた回転角を提供する関数。ちょっと一般的じゃないからここじゃなくていいかも...
double* get_rotate(){
    int dx,dy;
    double* angle ;  //{alpha, beta}
    angle = new double[2];
    if(act_flag == true){   //ボタン押した最初だと差分が取れないからそのまま終わる。
        dx = now_p[0]- old_p[0];
        dy = now_p[1]- old_p[1];        
        angle[0] = -1.0 * 2 * M_PI * dx / 1366.0 ;
        angle[1] =  2 * M_PI * dy / 768.0 ;        
        return angle;
    }else{
        act_flag = true;
        angle[0] = 0.0;
        angle[1] = 0.0;
        return angle;
    }
}
