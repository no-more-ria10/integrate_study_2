
#include"object_struct.hpp"
#include"calc.hpp"
#include"motion.hpp"
#include"time_set.hpp"
#include"mouse_event.hpp"

//openglのライブラリ
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glui.h>

Plane plane;
Ball ball;

double p_alpha = 0;
double p_beta = 0;

float light0_position[4]={0.0,1000.0, 2.0, 1.0};
float light0_specular[4]={0.0, 0.0, 3.0, 0.0};
float light1_position[4]={0.0,100.0, 100, 1.0};
float light1_specular[4]={0.0, 1.0, 0.0, 0.0};


void idle();

void init(void)
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);    
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_SPECULAR,light0_specular );
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_SPECULAR,light1_specular );
    plane.SetAlphaBeta(p_alpha, p_beta);
}

void display(void){
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.6, 0.5, 0.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    std::cout << p_alpha << " " << p_beta<< " #Alpha_Beta\n " << std::endl;

    plane.SetAlphaBeta(p_alpha, p_beta);
    
    idle();
    glFlush();    

}
//ボールの描画
void IdleBallMake(){
    glLoadIdentity();
    gluLookAt(120.0 , 10.0,120.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //画面の上向きはy軸の上。
    act_motion(&ball, &plane);
    glTranslatef(ball.GetPoint(0),ball.GetPoint(1),ball.GetPoint(2) );
    glColor3f(0.0 , 1.0, 0.0);
//    std::cout<< ball.GetPoint(1) << "#ball_y" << std::endl;    
    glutSolidSphere( ball.GetRadius(), 100.0, 100.0);

}
//平面の描画
void IdlePlaneMake(){
    double* a[4];
    glLoadIdentity();
    gluLookAt(120 ,30.0,120.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //画面の上向きはy軸の上。
    for(int i = 0; i<4; i++){
        a[i] = rotate_3d_z_x( plane.m_pl_init[i], plane.GetAngle(Alpha),  plane.GetAngle(Beta));
    }

    glBegin(GL_POLYGON);{
        glColor3f(1.0 , 0.0, 0.0);
            glVertex3f( a[0][0], a[0][1], a[0][2]);
            glVertex3f( a[1][0], a[1][1], a[1][2]);
        glColor3f(0.0 , 0.0, 1.0);
            glVertex3f( a[2][0], a[2][1], a[2][2]);
            glVertex3f( a[3][0], a[3][1], a[3][2]);

    }glEnd();
    
}
//普通のリシェイプ
void reshape(int w, int h)
{
    glViewport(0 , 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum( -0.5, 0.5,-0.5 ,0.5, 1, 500);
    glMatrixMode(GL_MODELVIEW);
}
//描画関数を２つ実行する。
void idle(){
    IdlePlaneMake();
    IdleBallMake();
}
//図形の回転を行う関数。util/mouth_event.hppを参照。
void drag_rotate(int x, int y){
    motion_func(x, y);
    double* a; //ドラック角度を格納。
    a = get_rotate();
    if((p_alpha + a[0]) < (M_PI /2) && (p_alpha + a[0])> - (M_PI/2)){        
    p_alpha += a[0];
    }
    if((p_beta + a[1]) < (M_PI/2) && (p_beta + a[1]) > - (M_PI/2)){            
    p_beta += a[1];
    }
//    std::cout << p_alpha << " " << p_beta << " #alpha_beta " << std::endl;
    delete a;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);   
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMouseFunc(move_step);
    glutMotionFunc(drag_rotate);
    
//    std::cout << "#GO_MAIN_LOOP\n" << std::endl;

    glutMainLoop();

    return 0;

}
