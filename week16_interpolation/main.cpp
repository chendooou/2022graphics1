///week16_interpolation 改自 week15_angles_TRT_angle
#include <stdio.h>
#include <GL/glut.h>
float angle[20] , oldx=0;
int angleID=0;///0號關節 1號關節
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
float NewAngle[20], OldAngle[20];
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i];///原來新的變舊的
        fscanf(fin,"%f",&NewAngle[i] );///讀到新的角度
    }
    glutPostRedisplay();///重畫畫面
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
    }
}
///int t=0;
void timer(int t){
    if( t%50==0 ) myRead();
    myInterpolate( (t%50)/50.0 );
    glutPostRedisplay();
    glutTimerFunc(20, timer, t+1 );
}
void keyboard(unsigned char key , int x  , int y)
{
    if (key=='p'){///Play
        myRead();
    glutTimerFunc( 0, timer, 0 );
        ///if(t%30==0) myRead();
        ///myInterpolate( (t%30)/30.0 );///介於 0.0~1.0
        ///glutPostRedisplay();
        ///t++;
    }
    if (key=='s') myWrite();///調好動作,再save存檔
    if (key=='r') myRead();
    if (key=='0') angleID=0;
    if (key=='1') angleID=1;
    if (key=='2') angleID=2;
    if (key=='3') angleID=3;
}
void mouse(int button , int state , int x ,int y)
{
    oldx=x;
}
void motion (int x, int y)
{
    angle[angleID]+=(x-oldx);
    ///myWrite();
    oldx=x;
    glutPostRedisplay();///請GLUT重畫畫面
}
void display()
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
    glutCreateWindow("week16_interpolation");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
