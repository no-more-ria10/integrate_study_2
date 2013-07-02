
#include"object_struct.hpp"
#include"calc.hpp"
#include"motion.hpp"
#include"time_set.hpp"

//openglのライブラリ
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glx.h>

Plane plane;
Ball ball;

double p_alpha = 0;
double p_beta = 0;

void init(void)
{
    glClearColor( 0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display(void){
    glClear(GL_COROR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    
    gluLookAt(0 , 100, 10, 0, 0, 0); //画面の上向きはy軸の上。
    glFlach();
}

void IdleBallMake(){
    glLoadIdentity();
    
    
    

    
    IdleBallMake();
    IdlePlaneMake();
        
