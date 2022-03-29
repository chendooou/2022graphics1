#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0; ///新加上angle
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z);
        glRotatef(angle, 0,1,0);///對y軸轉動
        glScalef(scale, scale, scale); ///都縮放成 scale倍
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button, int state, int mouseX, int mouseY)
{///為了解決瞬間移動的錯誤,我們改用正確的方式
    oldX= mouseX; oldY= mouseY;
}
void motion (int mouseX, int mouseY)
{
    angle += (mouseX-oldX);///轉動
    ///if( mouseX-oldX >0 ) scale *= 1.01; ///每天多努力1%,成長看得見
    ///if( mouseY-oldY >0 ) scale *= 0.99;
    ///x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;      oldY = mouseY;
    display();
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06_light");

    glutDisplayFunc(display);
    ///偷來的程式碼，要放 glutCreateWindow()之後，才會有效
    glEnable(GL_DEPTH_TEST);///開啟3D功能
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 glutMainLoop()之前
    glutMouseFunc(mouse);///上上週的主角 滑鼠點擊放開
    glutMotionFunc(motion);///上週的主角 滑鼠拖曳
    glutMainLoop();///卡在這裡，之後的程式都不會執行
}





