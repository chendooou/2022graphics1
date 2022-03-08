///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h> ///printf()印東西用的 *
float mouseX=0, mouseY=0;
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積，因為它會修改矩陣
        //glTranslatef(0.5,0.5,0); ///右上角 改成下面的
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.1); ///茶壺 *
    glPopMatrix();///還原矩陣(還原舊的位置)
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0 ); ///
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y)
{
    printf("  glVertex2f( (%d-150)/150.0, -(%d-150)/150.0  ); \n" , x, y );
    //printf("%d %d %d %d\n", button, state, x, y); ///
    mouseX=x; mouseY=y;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv); ///把參數，送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("week03 移動"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式
    glutMouseFunc(mouse); ///*

    glutMainLoop(); ///主要的程式迴圈
}
