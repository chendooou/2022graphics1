///上週使用mouse ,這週使用mouse motion
#include <GL/glut.h>
float angle=0, oldX=0; ///oldx 用來記住舊的位置(定錨)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1); ///90改成angle
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    //angle = x; 改掉
    angle += (x-oldX); ///新的點
    oldX = x; ///記住舊的點
    display(); ///重畫畫面
}
void mouse(int button,int state, int x, int y)
{
    oldX = x; ///定錨
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion); ///mouse motion動
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}
