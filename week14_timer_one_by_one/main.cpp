///week14_timer_one_by_one
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
    printf("�_��,�{�b�ɶ�: %d\n", t);
    PlaySound("do.wav",NULL, SND_ASYNC);
    glutTimerFunc(2000, timer, t+1);
}
void display()
{

}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week14_timer");
    ///�@���]�n�h�x��,�C�Ѧ��W�ۤv�b����s
    glutTimerFunc(5000,timer,0);///�]�w:5���,��0��timer
    glutDisplayFunc(display);
    glutMainLoop();
}
