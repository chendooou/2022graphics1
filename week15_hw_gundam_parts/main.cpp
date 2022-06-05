///week15_angles_TRT_angle ��� week14_angles_fprint_fscanf
///�n�� Gundam ���X��, �ݭn glm.h glm.cpp �� gundam 5���ɮ�
#include <stdio.h>
#include <GL/glut.h>///���F printf, fprintf , fopen , fclose ...
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
int angleID=0;///0:��0�����`, 1:��1�����`, 2:��2�����`
FILE * fout = NULL, * fin = NULL;
void myWrite(){///�C�I�s�@��myWrite()
    if( fout == NULL) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///�p�¦L�X��
        fprintf(fout, "%.1f ", angle[i] ); ///�ɮצL�X��
    }///�L�X20�ӼƦr
    printf("\n");///�C�I�s�@��,�p�¸���
    fprintf(fout,"\n");///�C�I�s�@��,�ɮפ]����
}
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f",&angle[i] );
    }
    glutPostRedisplay();///���e�e��
}
void keyboard(unsigned char key , int x  , int y){
    if (key=='s') myWrite();///�զn�ʧ@,�Asave�s��
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
    glutPostRedisplay();///��GLUT���e�e��
}
GLMmodel * myReadOne(char * filename){ ///�o��myReadOne �Ψ�Ū�C�ӳ���i��
    GLMmodel * one = NULL;
    if( one == NULL ){
        one = glmReadOBJ(filename);
        glmUnitize(one); ///��ҫ��]�����j�p
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void display()///�̷s�� display(),�|�⨭��C�@�������O�B�z�n
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(head==NULL) head=myReadOne("data/head.obj");
    glmDraw(head, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayNotParts()///�ǳƷs�� display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel); ///��ҫ��]�����j�p
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayOld()///���ª� display()��W�r
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.5);///����,�|���

    glPushMatrix();///�k�b��
        glTranslatef(0.3,0.4,0); ///(3)����u���^����
        glRotatef(angle[0],0,0,1); ///(2)���� ��z�b���
        glTranslatef(-0.3,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(0.3,0.5,0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)����u���^����
            glRotatef(angle[1],0,0,1); ///(2)����
            glTranslatef(-0.7,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(0.7,0.5,1.0,0.3);///�U��y,�����u
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3,0.4,0); ///(3)����u���^����
        glRotatef(angle[2],0,0,1); ///(2)���� ��z�b���
        glTranslatef(0.3,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3,0.5,-0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0); ///(3)����u���^����
            glRotatef(angle[3],0,0,1); ///(2)����
            glTranslatef(0.7,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(-0.7,0.5,-1.0,0.3);///�U��y,�����u
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
