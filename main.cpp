
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
    
    gluLookAt(0 , 100, 10, 0, 1.0, 0); //画面の上向きはy軸の上。
    glFlash();
}
//ボールの描画
void IdleBallMake(){
    act_motion(&ball, &plane);
    glLoadIdentity();
    glTrancelate(ball.GetPoint(0),ball.GetPoint(1),ball.GetPoint(2) );

    glutSolidSphere( ball.GetRadius(), 100, 100);
    glutPostRedisplay();
}
//平面の描画
void IdlePlaneMake(){
    double a[3][3];
    glLoadIdentity();
    for(int i = 0; i<3; i++){
        a[i] = rotate_3d_z_x( plane.m_pl_init[i], plane.GetAngle(Angle, Beta));
    }

    glBegin(GL_POLYGON);
      for(int i = 0; i<3; i++){
          glVertex3f( a[i][0], a[i][1], a[i][2]);
      }
      glColor3f(0.5 , 0.5, 0.5);
    glEnd();
}

void reshape(int w, int h)
{
    glViewport(0 , 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustnum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
//アイドルループ
void　idle{
    IdleBallMake();
    IdlePlaneMake();
}

int main(int argc, char** argv){
    glutInit(&grgc, argv);   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainRoop();

    return 0;

}
