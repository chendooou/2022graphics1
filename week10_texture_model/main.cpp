#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///�ϥ�3D�ҫ�
GLMmodel * pmodel = NULL; ///�ϥ�3D�ҫ�
//GLUquadric * sphere = NULL;///����,����G������
int myTexture(char * filename)///filename�O�ɮצW��
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///���ਤ��
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle,0,1,0);
        if(pmodel==NULL){ ///�ϥ�3D�ҫ�
            pmodel = glmReadOBJ("data/Gundam.obj"); ///�ϥ�3D�ҫ�
            glmUnitize(pmodel);///�ϥ�3D�ҫ�,�Y��� -1...1��,�~�ݱo��
            glmFacetNormals(pmodel);///�ϥ�3D�ҫ�,�����k�V�q
            glmVertexNormals(pmodel,90);///�ϥ�3D�ҫ�,���I���k�V�q
        }
        glmDraw(pmodel, GLM_TEXTURE);

    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///�C������ display() �[�@��
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_earth");

    glEnable(GL_DEPTH_TEST);///�}3D�`�״���,�~�|��3D���ĪG
    glutIdleFunc(display);///����idle �I�s display()
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    //myTexture("earth.jpg");
    //sphere = gluNewQuadric();///�ǳƦn�G������

    glutMainLoop();
}
