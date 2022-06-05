///week15_angles_TRT_angle 改自 week14_angles_fprint_fscanf
///要把 Gundam 做出來, 需要 glm.h glm.cpp 及 gundam 5個檔案
#include <stdio.h>
#include <GL/glut.h>///為了 printf, fprintf , fopen , fclose ...
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * bot = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
float angle[20] , oldx=0;
int angleID=0;///0:第0個關節, 1:第1個關節, 2:第2個關節
FILE * fout = NULL, * fin = NULL;
void myWrite(){///每呼叫一次myWrite()
    if( fout == NULL) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///小黑印出來
        fprintf(fout, "%.1f ", angle[i] ); ///檔案印出來
    }///印出20個數字
    printf("\n");///每呼叫一次,小黑跳行
    fprintf(fout,"\n");///每呼叫一次,檔案也跳行
}
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f",&angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key , int x  , int y){
    if (key=='s') myWrite();///調好動作,再save存檔
    if (key=='r') myRead();
    if (key=='0') angleID=0;
    if (key=='1') angleID=1;
    if (key=='2') angleID=2;
    if (key=='3') angleID=3;
}
void mouse(int button , int state , int x ,int y){
    oldx=x;
}
void motion (int x, int y){
    angle[angleID]+=(x-oldx);
    ///myWrite();
    oldx=x;
    glutPostRedisplay();///請GLUT重畫畫面
}
GLMmodel * myReadOne(char * filename){ ///發明myReadOne 用來讀每個部位進來
    GLMmodel * one = NULL;
    if( one == NULL ){
        one = glmReadOBJ(filename);
        glmUnitize(one); ///把模型設為單位大小
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void display()///最新的 display(),會把身體每一塊都分別處理好
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(head==NULL) head=myReadOne("data/head.obj");
    glmDraw(head, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayNotParts()///準備新的 display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel); ///把模型設為單位大小
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayOld()///把舊的 display()改名字
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形

    glPushMatrix();///右半部
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle[0],0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle[1],0,0,1); ///(2)旋轉
            glTranslatef(-0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半部
        glTranslatef(-0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle[2],0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle[3],0,0,1); ///(2)旋轉
            glTranslatef(0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.7,0.5,-1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week15 angles TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
