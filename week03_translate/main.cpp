/// *�O�s�W���{���X
#include <GL/glut.h>
void myTeapot(float x, float y) ///*
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

    ///*
    myTeapot(0.5,0.5);
    myTeapot(0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,0.5);

    glutSwapBuffers(); ///�e�n��A�洫�X��
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��ѼơA�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�İ� + 3D�`�ץ\��
    glutCreateWindow("week03 ����"); ///�} GLUT ����
    glutDisplayFunc(display); ///�Ψ���ܪ��禡
    glutMainLoop(); ///�D�n���{���j��
}
