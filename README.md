# 電腦圖學筆記week01 -20220222
```
小葉老師的上課要點
1. What 這問課會學到什麼 (用期末作品來思考, 三個圈圈, blog)
2. How 如何學 (錄影、截圖、實作、Blog、GitHub)
3. 成績計算方式 (期中考10%) (平時90%: Blog20%, Moodle(作業/考試)40%, 期末作品40%)
4. 教學方法: 點名/座位表, moodle, blogger, facebook
5. 第1個 OpenGL程式
6. 討論: 放假(W07清明)與期末作品展示
```
## 第一個 OpenGL 程式
```
0.CodeBlocks 17.12 mingw 裝好
1.File > New > Project, 選 OpenGL 專案
2.檔案名稱取Project title: week01_OPENGL
   點開[...]的目錄，路徑選桌面
3.下一步下一步，完成後，Build & Run
4.可以看到旋轉的彩色三角形
```
## 第一個GLUT專案
```
1.moodle下載freeglut壓縮檔
2.解壓縮到桌面的freeglut目錄
3.freeglut/lib/libfreeglut.a
桌面 freeglut 的1ib裡面有 1ibfreeglut.a把它複製，改成 1ibglut32.a
才能讓我們的 CodeBlocks 的 GLUT專案連結使用
4. 打開CodeBlocks：
    File > New > Project，選GLUT專案 > go > next > 
    Project title 取名 week01_GLUT
    路徑選擇在桌面 > next
5.選擇路徑並且存在桌面的freeglut目錄
6. 完成後，Build&Run。按+ - 可以調整精細程度
```
## 使用 Github 和 Git 指令來備份程式資料
```
0. 登入 GitHub.com
1. New repo 新增專案倉庫
1.1 取名 2022graphics1
1.2. Public, Add READMD,  Add .gitignore 用c++
1.3.綠色確認，看到新的專案倉庫
2. 利用 Git 指令
2.1 安裝 Git for Windows
3. 開啟 Git Bash
3.1 輸入指令進入桌面: cd desktop
3.2 : git clone https://(我的github網址)
3.3 : cd 2022graphics1
3.4 把2個程式目錄，放到2022graphics1
3.5  : git status 看狀態(紅色2個目錄)
3.6  : git add . 
3.7 : git status (變綠色)
4. 要推送上雲端
4.1 要先有 commit 的動作，第一次使用時
git config --global user.email "(信箱)"
git config --global user.name "(github名字)"
git commit -m "訊息"
4.2  : git push 推送上雲端
```

# 電腦圖學筆記week02 -20220301
```
小葉老師的上課要點
1. 主題: 點、線、面、色彩
2. 親手打造第1個GLUT程式
3. 實作程式
3.1. glBegin(GL_POLYGON); 開始畫
3.2. glColor3f(r,g,b); 色彩 Color
3.3. glVertex3f(x,y,z); 頂點 Vertex
3.4. glEnd(); 結束畫 
4. 小畫家配合回家作業
```
## step01 跑別人的範例
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載三個檔案 data. zip , windows zip ,glut32.d11
    
2. windows.zip 解壓縮 > 下載 \ windows \ Shapes .exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型
    glut32.d11 解壓縮 > 下載 \ windows \ glut32.d11

3.執行 > 下載 \ window \ Shapes.exe 看範例    
左邊可按右鍵選單：調整頂點大小、設定頂點顏色、右邊綠色數值可移動調整頂點座標
右邊可按右鍵選單：選擇點或線等等...
```
## step01-2 跑上週的程式 - 要能夠執行GLUT檔案
```
1.安裝 Git for Windows
2.Git Bash: cd desk >　git clon (github網址) ＞ cd 2022graphics1
3.下載 freeglut, 要複製改檔名 lib \ libglut32.a
4.開啟 CodeBlocks  > File > Open > week01_GLUT專案, run & bulid  
```

## step02 親手打造 GLUT 的程式
```C++
1.建立 GLUT 檔案取名 week02_color
開始畫茶壺，程式碼:

///step02-1 10行最精簡的 GLUT程式
///先全刪，目標: 5-10行寫完
#include <GL/glut.h> ///使用GLUT外掛，簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0); ///設定色彩
    glutSolidTeapot(0.3); ///實心的茶壺

    glutSwapBuffers(); ///畫好後，交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數，送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("第02週的程式哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```
## step03 學範例畫出自己的彩色三角形
```C++
///step02-1 10行最精簡的 GLUT程式
///先全刪，目標: 5-10行寫完
#include <GL/glut.h> ///使用GLUT外掛，簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0); ///設定色彩
    ///glutSolidTeapot(0.3); ///實心的茶壺 不做茶壺了所以註解掉
    glBegin(GL_POLYGON);
        glColor3f(1,0,0); ///紅色
        glVertex2f(-1,-1); ///Vertex 頂點

        glColor3f(0,1,0); ///綠色
        glVertex2f(+1,-1);

        glColor3f(0,0,1); ///藍色
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers(); ///畫好後，交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數，送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("第02週的彩色三角形程式哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}

```
# 電腦圖學筆記week03 -20220308
```
小葉老師上課要點:
1. 主題: 移動 Translate、座標換算
2. 實作: glTranslatef(x,y,z);
3. 主題: 滑鼠事件 glutMouseFunc()
4. 用滑鼠寫程式
5. 作業2: 很多點畫酷東西 (小畫家協助)
```
## 能夠讓作業加分的一些東東
```C++
1.建立GLUT專案
   位置要放在freeglut資料夾目錄
2.先copy上週得程式碼雛形，以下:

#include <GL/glut.h> 
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers(); ///畫好後，交換出來
}
int main(int argc, char** argv) 
{
    glutInit( &argc, argv); 
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("week03 作業2想加分"); 

    glutDisplayFunc(display); 
    glutMainLoop(); 
}
```

## 開始畫小小兵
```C++
#include <GL/glut.h>
#include <math.h>
void myCircle( float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( r*cos(a) , r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1,1,0 );
    myCircle(2);
    glColor3f( 0.6 ,0.6,0.6 );
    myCircle(0.6);
    glColor3f( 1,1,1);
    myCircle(0.45);
    glColor3f( 0,0,0 );
    myCircle(0.3);
    glutSwapBuffers(); ///畫好後，交換出來
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("week03 作業2想加分");
    glutDisplayFunc(display);
    glutMainLoop();
}

但是需要腮紅，所以要改良增加座標
#include <GL/glut.h>
#include <math.h>
void myCircle( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a) , y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1 , 1 , 0);
    myCircle(0 , 0 , 2);

    glColor3f(0.6 , 0.6 , 0.6);
    myCircle(0 , 0 , 0.6);

    glColor3f(1 , 1 , 1);
    myCircle(0 , 0 , 0.45);

    glColor3f(0 , 0 ,0);
    myCircle(0, 0 ,0.3);

    glColor3f(1 , 0 ,0);
    myCircle(0.8, -0.6 ,0.1);
    myCircle(-0.8, -0.6 ,0.1);
    glutSwapBuffers(); ///畫好後，交換出來
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc(display);
    glutMainLoop();
}

但是腮紅要橢圓，所以在定義一個myCircle2畫橢圓
#include <GL/glut.h>
#include <math.h>
void myCircle( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a) , y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void myCircle2( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+2*r*cos(a) , y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1 , 1 , 0);
    myCircle(0 , 0 , 2);

    glColor3f(0.6 , 0.6 , 0.6);
    myCircle(0 , 0 , 0.6);

    glColor3f(1 , 1 , 1);
    myCircle(0 , 0 , 0.45);

    glColor3f(0 , 0 ,0);
    myCircle(0, 0 ,0.3);

    glColor3f(1 , 0 ,0);
    myCircle2(0.8, -0.6 ,0.1); ///從圓改良為橢圓
    myCircle2(-0.8, -0.6 ,0.1);///從圓改良為橢圓
    glutSwapBuffers(); ///畫好後，交換出來
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衝區 + 3D深度功能
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 重點整理
```
01. glBegin(); //開始畫

      glEnd(); //結束畫 

02. glVertex2f( , );  //Vertex是頂點 , 2f所以兩個浮點數參數

03. glColor3f ( ,  ,  );  //3f所以三個浮點數參數

04. 使用 sin , cos , 圓一圈要2拍 , for迴圈 , 函式
```
## 移動 Translate
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載三個檔案 data. zip , windows zip ,glut32.d11

2. windows.zip 解壓縮 > 下載 \ windows \ Shapes .exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型
    glut32.d11 解壓縮 > 下載 \ windows \ glut32.d11

3.執行 > 下載 \ window \ Transformation.exe 看範例
拖曳下方綠色數值(glRotatef)可以旋轉車子
上面右方按右鍵可以選擇其他項目的模型
```

## 實作 Transformation 的 GLUT 程式 
```C++
1.建立新的 GLUT 專案,檔名為: week03_translate
2.先畫一個上周的茶壺出來
   * 這個茶壺不會動
   
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0); ///黃色
    glutSolidTeapot(0.3); ///茶壺

    glutSwapBuffers(); 
}

int main(int argc, char** argv) 
{
    glutInit( &argc, argv); 
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); 
    glutCreateWindow("第02週的程式哦!"); 

    glutDisplayFunc(display); 

    glutMainLoop();
}
```
```C++
* 使茶壺往右上角移動
  結果茶壺出現在右上角的位置了，然後再點一次就又往右上角移動，然後會跑出視窗外
  移動會累積，因為它會修改矩陣
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ///移動會累積,因為它會修改矩陣
    glTranslatef(0.5 , 0.5 , 0);///右上角
    glColor3f(1,1,0); ///黃色
    glutSolidTeapot(0.3); ///茶壺

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);

    glutMainLoop();
}
```
```C++
* 加上備份/還原矩陣，茶壺不會點一下就跑走了
    glPushMatrix();
    glPopMatrix();
    
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///備份矩陣，他會記住舊的位置
        ///移動會累積,因為它會修改矩陣
        glTranslatef(0.5 , 0.5 , 0);///右上角
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.3); ///茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);

    glutMainLoop();
}
```
```C++
* 想要四個茶壺
   建立一個myTeapot函式，給能夠修改的x,y座標
   畫茶壺輸入四個座標就有四個茶壺
   
#include <GL/glut.h>
void myTeapot( float x , float y )
{
    glPushMatrix();///備份矩陣，他會記住舊的位置
        ///移動會累積,因為它會修改矩陣
        //glTranslatef(0.5 , 0.5 , 0);///右上角
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.3); ///茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot(0.5,0.5);
    myTeapot(0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,0.5);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);

    glutMainLoop();
}

```

## 滑鼠事件 glutMouseFunc()
```C++
* 使用滑鼠事件實現滑鼠點在哪,茶壺就移動到哪
#include <GL/glut.h>
float mouseX=0, mouseY=0;///新加的!!!!
void myTeapot( float x , float y )
{
    glPushMatrix();///備份矩陣，他會記住舊的位置
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.3); ///茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0);///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///滑鼠x座標,滑鼠y座標!!!!
{
    mouseX=x; mouseY=y;///新加的!!!!
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件!!!!
    glutMainLoop();
}
```

## 用滑鼠寫程式
```C++
1.建立新的GLUT專案，檔名:week03_mouse_hw2

2.將week03_mouse的程式碼copy過來

3.增加兩行程式碼
   #include <stdio.h> ///printf()印東西用的
   printf("%d %d %d %d\n", button, state, x, y);

4.縮小茶壺: glutSolidTeapot(0.1);  ///變成小茶壺 

* mose 的座標系統，也是 window 視窗的座標系統
  座標轉換: 可把 mouse (0...300 , 0...300)換算成 3D 的世界(-1...+1 , -1...+1)  
   (mouseX-150)/150.0, -(mouseY-150)/150.0) 
  口訣: 減一半、除一半。y要反過來
  
///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h> ///printf()印東西用的
float mouseX=0, mouseY=0;///新加的!!!!
void myTeapot( float x , float y )
{
    glPushMatrix();///備份矩陣，他會記住舊的位置
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.1); ///變成小茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0);///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///滑鼠x座標,滑鼠y座標!!!!
{
    printf("%d %d %d %d\n", button, state, x, y);
    mouseX=x; mouseY=y;///新加的!!!!
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件!!!!
    glutMainLoop();
}

```

## 用滑鼠寫程式
```C++
1. 模仿茶壺程式碼，放到滑鼠事件
2. 在 "week03 移動" 視窗滑鼠點一下就會產生一行程式碼，放開滑鼠也會產生一行程式碼
    可以這樣在視窗上點出???的輪廓
    
///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h> ///printf()印東西用的
float mouseX=0, mouseY=0;///新加的!!!!
void myTeapot( float x , float y )
{
    glPushMatrix();///備份矩陣，他會記住舊的位置
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.1); ///變成小茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0);///新加的

    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///滑鼠x座標,滑鼠y座標!!!!
{
    ///printf("%d %d %d %d\n", button, state, x, y);
    printf(" glVertex2f( (%d-150)/150.0 , -(%d-150)/150.0 );\n",x,y);
    mouseX=x; mouseY=y;///新加的!!!!
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件!!!!
    glutMainLoop();
}

3.將程式碼複製起來，貼到 bonus 去測試

4.程式碼測試出來的詭異多邊形，就是利用滑鼠事件繪製出來點接起來的模樣

* 注意: 左側深黑色的檔名是目前會執行的程式碼，欲切換其他檔案: 對該檔名點右鍵 > Activate project
```

## 用小畫家寫作業
```
1.開啟小畫家，將畫布大小設為300*300像素(windows視窗預設一樣)

2.鼠標停在畫布上，從左下角就可以從像素得知x,y座標

3.可以用滴管吸顏色、點擊編輯色彩，就可以知道顏色的RGB

4.但是GLUT顏色值表示只能介於0-1之間怎麼辦?
   : 將RGB各/255.0
    e.g 某黃色RGB為255,208,32，寫到GLUT : glColor3f(255/255.0 , 208/255.0 , 32/255.0 )
```

# 電腦圖學筆記week04 -20220315
```
week04 -20220315
小葉老師上課要點:
1. 主題: 旋轉 Rotate jsyeh.org/3dcg10
2. 主題: 旋轉軸、旋轉角度
3. 實作: glRotatef(angle, x,y,z);
4. 主題: mouse motion 動
5. mouse motion 配合旋轉
6. (大象放進冰箱)
(可能教太快,重講 mouse 寫程式、GL_LINE_LOOP)
```
## 旋轉 Rotate 
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載三個檔案 data. zip , windows zip ,glut32.d11

2. windows.zip 解壓縮 > 下載 \ windows \ Shapes .exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型
    glut32.d11 解壓縮 > 下載 \ windows \ glut32.d11

3.執行 > 下載 \ window \ Transformation.exe 看範例
  拖曳下方綠色數值(glRotatef)可以旋轉車子
  點選上方右鍵選取Al Capone(人物)
  
4.紫色框起來是旋轉軸，旋轉軸的前一個數字是選轉角度。
   根據安培右手定理，比讚的四隻手指頭方向決定選轉方向
   (0,1,0 固定y軸 讚向上 旋轉軸方向向上) 
   (1,0,0 固定x軸 讚向右 往前轉)
   (0,0,1 固定z軸 讚向自己胸前 往左邊轉)

   *右手座標: 拇指x座標、食指y座標、中指z座標
   
```
## 實作 Rotate 的 GLUT 程式
```C
1.建立新的 GLUT 專案,檔名為: week03_translate 
2.先從上周的筆記(備份/還原茶壺)複製精簡的10行程式碼
   改寫單純在那邊的旋轉90度茶壺
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glRotatef(90,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix(); ///還原矩陣
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 Rotate");

    glutDisplayFunc(display);

    glutMainLoop();
}
```
## 實作 Rotate 加上 motion 的 GLUT 程式
```C
可以使用滑鼠拖曳茶壺使轉動了!
   新增第25行: glutMotionFunc(motion); ///mouse motion動
   新增第14行:motion的函式，給一個angle使可以修改的數值
   修改第9行:把原本固定的90度改成可以修改的angle
   新增第4行:宣告angle
    
   但是有瑕疵: 按下滑鼠拖曳放開後，再按下滑鼠又重回上方的位置
   原因: 第16行程式碼 angle = x; 
           x 為x座標(1,0,0)
///上週使用mouse ,這週使用mouse motion
/// mouse
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1); ///90改成angle
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    display(); ///重畫畫面
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 Rotate");
    glutDisplayFunc(display);
    glutMotionFunc(motion); ///mouse motion動
    glutMainLoop();
}
```
## 實作 Rotate 加上 motion 再加上 mouse 繼續改良 GLUT 程式
```C
* 如何改良: 冰箱門打開 、 大型放進去、 冰箱關起來
           滑鼠按下去 、 滑鼠拖曳  、 滑鼠放開來 
           
新增第32行: glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
新增第20行: 定義mouse函式，紀錄舊的位置(定錨)
更新第3行: 宣告oldX=0;
這樣就可以成功進行持續且順利的旋轉茶壺了!!

///上週使用mouse ,這週使用mouse motion
#include <GL/glut.h>
float angle=0, oldX=0; ///oldx 用來記住舊的位置(定錨)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1); ///90改成angle
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    //angle = x; 改掉
    angle += (x-oldX); ///新的點
    oldX = x; ///記住舊的點
    display(); ///重畫畫面
}
void mouse(int button,int state, int x, int y)
{
    oldX = x; ///定錨
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion); ///mouse motion動
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}
```
## 重新複習滑鼠寫程式
```
1.建立新的GLUT專案:week04_review_mouse_draw

2.第12行:printf("%d %d %d %d\n", button, state, x, y);
  button : 0代表按下左鍵、1代表按下中鍵、2代表按下右鍵
```
```C
///複習滑鼠畫東西
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}
void mouse(int button,int state, int x, int y)
{
    printf("%d %d %d %d\n", button, state, x, y);
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04_review_mouse_draw");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}
```
```
3.改寫第12行: printf("   glVertex2f( (%d-150)/150.0, (%d-150/150.0);\n" ,x,y);
             可以印出滑鼠按下去位置的座標和放開滑鼠位置的座標
```
```C
///複習滑鼠畫東西
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}
void mouse(int button,int state, int x, int y)
{//printf("%d %d %d %d\n", button, state, x, y);
    printf("   glVertex2f( (%d-150)/150.0, (%d-150/150.0);\n" ,x,y);
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04_review_mouse_draw");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}
```
```
4.增加第12行: 修改程式碼為印出按下去的滑鼠位置座標就好
   * 問題: 黑壓壓的點根本看不出畫了什麼
```
```C
///複習滑鼠畫東西
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}
void mouse(int button,int state, int x, int y)
{//printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN){///耴果state是按下去0,才印程式碼
        printf("   glVertex2f( (%d-150)/150.0, (%d-150/150.0);\n" ,x,y);
    }
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04_review_mouse_draw");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}
```
```
5. * 問題: 黑壓壓的點根本看不出畫了什麼，所以從x,y去做修改看看
       
       增加第4-5行 : mx,my用來記錄點的位置
       增加第9-13行: 把點們用LINE_LOOP和神奇for迴圈連起來
       增加第18-23行: 讓小黑顯示座標
 ```
 ```C
///複習滑鼠畫東西
#include <GL/glut.h>
#include <stdio.h>
int mx[1000],my[1000];///用來備份你的mouse的座標
int N=0;///有幾個點按好了?
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state, int x, int y)
{//printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN){///如果state是按下去0,才印程式碼
        printf("   glVertex2f( (%d-150)/150.0, (%d-150/150.0);\n" ,x,y);
        N++;
        mx[N-1]=x; my[N-1]=y;
    }
    display();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04_review_mouse_draw");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///上週教: mouse按下去、放開來
    glutMainLoop();
}

```
