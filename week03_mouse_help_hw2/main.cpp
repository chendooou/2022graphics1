#include <GL/glut.h>
float mouseX=0, mouseY=0; ///*
void myTeapot(float x, float y)
{
    glPushMatrix();///�ƥ��x�}(�ƥ��ª���m)
        ///���ʷ|�ֿn�A�]�����|�ק�x�}
        //glTranslatef(0.5,0.5,0); ///�k�W�� �令�U����
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///����
        glutSolidTeapot(0.3); ///����
    glPopMatrix();///�٭�x�}(�٭��ª���m)
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0 ); ///*
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y)
{
    mouseX=x; mouseY=y; ///*
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv); ///��ѼơA�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�İ� + 3D�`�ץ\��
    glutCreateWindow("week03 ����"); ///�} GLUT ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡
    glutMouseFunc(mouse); ///*

    glutMainLoop(); ///�D�n���{���j��
}
