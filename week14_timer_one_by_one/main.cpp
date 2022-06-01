///week14_timer_one_by_one
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
    printf("起床,現在時間: %d\n", t);
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
    ///一次設好多鬧鐘,每天早上自己在那邊叫
    glutTimerFunc(5000,timer,0);///設定:5秒後,第0個timer
    glutDisplayFunc(display);
    glutMainLoop();
}
