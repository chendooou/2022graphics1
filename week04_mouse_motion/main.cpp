///�W�g�ϥ�mouse ,�o�g�ϥ�mouse motion
#include <GL/glut.h>
float angle=0, oldX=0; ///oldx �ΨӰO���ª���m(�w��)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle,0,0,1); ///90�令angle
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}
void motion(int x, int y)
{
    //angle = x; �ﱼ
    angle += (x-oldX); ///�s���I
    oldX = x; ///�O���ª��I
    display(); ///���e�e��
}
void mouse(int button,int state, int x, int y)
{
    oldX = x; ///�w��
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion); ///mouse motion��
    glutMouseFunc(mouse); ///�W�g��: mouse���U�h�B��}��
    glutMainLoop();
}
