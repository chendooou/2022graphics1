#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體

    glPushMatrix();///右邊的手臂、手肘
        glTranslatef(0.2,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot(0.2);///小茶壺 想像他是手臂
        glPushMatrix();
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot(0.2);///小茶壺 想像他是手臂
        glPopMatrix();
    glPopMatrix();

     glPushMatrix();///左邊的手臂、手肘
        glTranslatef(-0.2,0,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot(0.2);///小茶壺 想像他是手臂
        glPushMatrix();
            glTranslatef(-0.2,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.2,0,0);
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot(0.2);///小茶壺 想像他是手臂
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///如果轉太快可以改成angle += 0.1
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12_TRT_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
