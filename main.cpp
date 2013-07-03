
#include"object_struct.hpp"
#include"calc.hpp"
#include"motion.hpp"
#include"time_set.hpp"

//openglのライブラリ
#include<GL/glew.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glui.h>

Plane plane;
Ball ball;

double p_alpha = 0;
double p_beta = 0;

float light0_position[4]={0.0,1000.0, 1.0, 1.0};
float light0_specular[4]={0.0, 0.0, 1.0, 0.0};



void idle();

void init(void)
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);    
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_SPECULAR,light0_specular );
    std::cout << "#INIT_DOEN\n" << std::endl;
    plane.SetAlphaBeta(p_alpha, p_beta);
}

void display(void){
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6, 0.5, 0.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    idle();
    glFlush();    
    std::cout << "#DISPLAY_DOEN\n" << std::endl;
    ball.print();

}
//ボールの描画
void IdleBallMake(){
    glLoadIdentity();
    gluLookAt(150 , 30.0, 0.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //画面の上向きはy軸の上。
    act_motion(&ball, &plane);
    glTranslatef(ball.GetPoint(0),ball.GetPoint(1),ball.GetPoint(2) );
    glColor3f(0.0 , 1.0, 0.0);

    glutSolidSphere( ball.GetRadius(), 100.0, 100.0);
    std::cout << "#BALL_MAKE_DOEN\n" << std::endl;

}
//平面の描画
void IdlePlaneMake(){
    double* a[4];
    glLoadIdentity();
    gluLookAt(150 , 30.0, 0.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //画面の上向きはy軸の上。
    for(int i = 0; i<4; i++){
        a[i] = rotate_3d_z_x( plane.m_pl_init[i], plane.GetAngle(Alpha),  plane.GetAngle(Beta));
    }

    glBegin(GL_POLYGON);{
        glColor3f(1.0 , 0.0, 0.0);
        for(int i = 0; i<4; i++){
            glVertex3f( a[i][0], a[i][1], a[i][2]);
            std::cout <<a[i][0] << " " <<a[i][1] << " " <<a[i][2] << "#頂点\n "  << std::endl;

        }
    }
    glEnd();
        std::cout << "#PLANE_MAKE_DOEN\n" << std::endl;
}

void reshape(int w, int h)
{
    glViewport(0 , 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum( -0.5, 0.5,-0.5 ,0.5, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    std::cout << "#RESHAPE_DOEN\n" << std::endl;
}
//アイドルループ
void idle(){
    IdlePlaneMake();
    IdleBallMake();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);   
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    
//    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
//    glutIdleFunc(idle);
 glutIdleFunc(display);
    std::cout << "#GO_MAIN_LOOP\n" << std::endl;

    glutMainLoop();

    return 0;

}
