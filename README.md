# 電腦圖學筆記week01 -20220222

小葉老師的上課要點
1. What 這問課會學到什麼 (用期末作品來思考, 三個圈圈, blog)
2. How 如何學 (錄影、截圖、實作、Blog、GitHub)
3. 成績計算方式 (期中考10%) (平時90%: Blog20%, Moodle(作業/考試)40%, 期末作品40%)
4. 教學方法: 點名/座位表, moodle, blogger, facebook
5. 第1個 OpenGL程式
6. 討論: 放假(W07清明)與期末作品展示

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

小葉老師的上課要點
1. 主題: 點、線、面、色彩
2. 親手打造第1個GLUT程式
3. 實作程式
3.1. glBegin(GL_POLYGON); 開始畫
3.2. glColor3f(r,g,b); 色彩 Color
3.3. glVertex3f(x,y,z); 頂點 Vertex
3.4. glEnd(); 結束畫 
4. 小畫家配合回家作業

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

小葉老師上課要點:
1. 主題: 移動 Translate、座標換算
2. 實作: glTranslatef(x,y,z);
3. 主題: 滑鼠事件 glutMouseFunc()
4. 用滑鼠寫程式
5. 作業2: 很多點畫酷東西 (小畫家協助)

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

week04 -20220315
小葉老師上課要點:
1. 主題: 旋轉 Rotate jsyeh.org/3dcg10
2. 主題: 旋轉軸、旋轉角度
3. 實作: glRotatef(angle, x,y,z);
4. 主題: mouse motion 動
5. mouse motion 配合旋轉
6. (大象放進冰箱)
(可能教太快,重講 mouse 寫程式、GL_LINE_LOOP)

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
```C++
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
```C++
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
```C++
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
```C++
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
```C++
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
 ```C++
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
# 電腦圖學筆記week05 -20220322
小葉老師上課要點:
1. 主題: 移動、旋轉、縮放、矩陣
2. 主題: 鍵盤函式 glutKeyboardFunc()
3. 複習: 鍵盤+滑鼠操作, 模仿 Maya/Unity介面
4. 主題: 電腦圖學之父 Ivan Sutherland (Sketchpad)

## 電腦圖學之父 Ivan Sutherland (Sketchpad)
```
伊凡·愛德華·蘇澤蘭 Ivan Edward Sutherland
生於美國內布拉斯加州黑斯廷斯，計算機科學家，被認為是「計算機圖形學之父」。因發明Sketchpad，拓展了計算機圖形學的領域，為1988年圖靈獎得主。

```
## 實作GLUT程式碼 - keyboard 函式
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載三個檔案 data. zip , windows zip ,glut32.d11

2. windows.zip 解壓縮 > 下載 \ windows \ Shapes .exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型
    glut32.d11 解壓縮 > 下載 \ windows \ glut32.d11

3.執行 > 下載 \ window \ Transformation.exe 看範例
  拖曳下方綠色數值(glRotatef)可以旋轉車子
  點選上方右鍵選取Al Capone(人物)

4.裝好 freeglut 資料夾到桌面，改lib\libglut32.a
   並開啟 codeblocks 建立新的 GLUT 專案: week05_keyboard

5.先打上基礎10行程式碼
```
```C++
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week??_xxx");

    glutDisplayFunc(display);
    glutMainLoop();
}

```
```
6.用黃色小茶壺做一些神奇的事情
   *增加第21行: keyboard 函式
     增加第10行: 寫 keyboard 函式要做的事
     增加第3行 display 函式裡的印出之前的黃色小茶壺
     增加第2行: 因為第12行要用printf，所以要加標頭檔#include <stdio.h>
     
  當滑鼠停在茶壺小視窗中任一地方，並按下鍵盤中英文字母，小黑視窗會印出你按下了什麼
  英文字母和滑鼠所在的座標。

```
```
7.什麼是 Callback ?
   程式碼第20、21行就是 Callback 函式。在main函式外面寫了函式，當main函式迴圈在執
   行時，跑到需要使用函式就會去叫用註冊對應的 Callback 函式名字。
   第10行: keyboard函式內的參數細說
               char 代表字母: -128..+127
               unsigned char :0...255 只有正的
               singed 正負號、unsigned 沒有正負號
```
```C++
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key,int x,int y )
{
    printf("你按下了 %c 在 %d %d 座標\n", key ,x, y);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///今天的主角
    glutMainLoop();
}
```

## 實作GLUT程式碼 - keyboard函式 + mouse函式 + motion函式
要做移動 + 旋轉 + 放大縮小

```
1. 建立新的 GLUT 專案: week05_keyboard_mouse_motion
    接續剛剛的week05_keyboard 變成 keyboard函式 + mouse函式 + motion函式
     先寫出三個函式
```
```C++
///接續 week05_keyboard 變成 keyboard + mouse + motion
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{

}
void mouse(int button, int state, int x, int y)
{

}
void motion (int x, int y)
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///今天的主角
    glutMouseFunc(mouse);///上上週的主角 滑鼠點擊放開
    glutMotionFunc(motion);///上週的主角 滑鼠拖曳
    glutMainLoop();
}
```
```
2. 先試試看移動，要做備分還原矩陣，才不會每執行一次就跑走。
    增加9-13行: 備份、還原矩陣、學模型一樣建立移動的三個參數glTranslate(x,y,z)
    增加第3行: 給x,y,z初始值 
    修改第15、18、21的 x,y 改 mouseX, mouseY 避免和 glTranslate的 x,y 衝突
    增加第23行: motion函式裡，加上只要有移動就重畫畫面的 display()，還有讓茶壺移動      的程式
    再回去修改第10行 glTranslate 內的參數去正確的換算

    這樣就可以按下滑鼠拉動茶壺了。

```
```C++
///接續 week05_keyboard 變成 keyboard + mouse + motion
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0;
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{

}
void mouse(int button, int state, int mouseX, int mouseY)
{

}
void motion (int mouseX, int mouseY)
{
    x += (mouseX-oldX); y += (mouseY-oldY);
    oldX = mouseX;      oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///今天的主角
    glutMouseFunc(mouse);///上上週的主角 滑鼠點擊放開
    glutMotionFunc(motion);///上週的主角 滑鼠拖曳
    glutMainLoop();
}

```
```
3. 但是每點一次滑鼠都從點下去的地方拉動，要在原本停的地方繼續移動啦
    修改第21行: 為了瞬間移動的這個問題
    修改第4行: x=150,y=150，讓執行程式後茶壺一開始就顯示在視窗中央，而不是0,0的左
    上角
    新增第8行: 新增背景顏色 glClearColor()函式內有四個參數分別是 R,G,B,透明度
```
```C++
///接續 week05_keyboard 變成 keyboard + mouse + motion
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 ); ///R,G,B,A 其中A為透明度，目前功能沒開
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{

}
void mouse(int button, int state, int mouseX, int mouseY)
{///為了解決瞬間移動的錯誤,我們改用正確的方式
    oldX= mouseX; oldY= mouseY;
}
void motion (int mouseX, int mouseY)
{
    x += (mouseX-oldX); y += (mouseY-oldY);
    oldX = mouseX;      oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///今天的主角
    glutMouseFunc(mouse);///上上週的主角 滑鼠點擊放開
    glutMotionFunc(motion);///上週的主角 滑鼠拖曳
    glutMainLoop();
}
```
```
4. 接著做放大縮小，所以繼續修改程式碼
    增加第12行: 學模型加入 glScalef 使可以縮放
    修改第4行 : 宣告scale倍率
    增加第27行: y方向正向移動 scale放大，負向移動 scale縮小

```
```C++
///接續 week05_keyboard 變成 keyboard + mouse + motion
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 ); ///R,G,B,A 其中A為透明度，目前功能沒開
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z);
        glScalef(scale, scale, scale); ///都縮放成 scale倍
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{

}
void mouse(int button, int state, int mouseX, int mouseY)
{///為了解決瞬間移動的錯誤,我們改用正確的方式
    oldX= mouseX; oldY= mouseY;
}
void motion (int mouseX, int mouseY)
{
    if( mouseX-oldX >0 ) scale *= 1.01; ///每天多努力1%,成長看得見
    if( mouseY-oldY >0 ) scale *= 0.99;
    ///x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;      oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///今天的主角
    glutMouseFunc(mouse);///上上週的主角 滑鼠點擊放開
    glutMotionFunc(motion);///上週的主角 滑鼠拖曳
    glutMainLoop();
}
```
# 電腦圖學筆記week06 -20220329
小葉老師上課要點:
1. 主題: 打光 Light
2. 主題: 法向量 Normal
    glNormal3f(nx,ny,nz)
3. 複習: 上週移動、旋轉、縮放、矩陣
4. 期中考題

## 實作 GLUT 程式: 打光 Light 
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載三個檔案 data. zip , windows zip ,glut32.d11

2. windows.zip 解壓縮 > 下載 \ windows \ Shapes .exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型
    glut32.d11 解壓縮 > 下載 \ windows \ glut32.d11

3.執行 > 下載 \ window \ Light & Material.exe 看範例
   左上角按右鍵可以換模型
   左下角右鍵可以換 Material (材質)
   
   藍色箭頭指向的參數 glLightfv(...) 的 fv 是 float vector (陣列)
   GLfloat light_pos[] = { -2.0 , 2.0 , 2.0 , 1.0 };
   glLightfv( GL_LIGHT0 , GL_POSITION , 陣列 )
               第幾個燈        設定位置
4.裝好 freeglut 資料夾到桌面，改lib\libglut32.a
   並開啟 codeblocks 建立新的 GLUT 專案: week06_light

5.開始偷程式碼!! Ctrl + F 搜尋: light
6.把這些複製起來
7.結合之前的黃色小茶壺加上偷來的程式碼，幫黃色小茶壺打光
   *要改一下z的打光位置，茶壺會比較亮
```
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
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
    glutMainLoop();///卡在這裡，之後的程式都不會執行
}
```
## 實作 GLUT 程式: Light + mouse + motion + rotate (複習上週)
```
1.開啟 codeblocks 建立新的 GLUT 專案: week06_light_mouse_motion_rotate
2.結合打光的程式碼和上週寫的 mouse函式 + motion函式
```
```C++
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

float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z);
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
    if( mouseX-oldX >0 ) scale *= 1.01; ///每天多努力1%,成長看得見
    if( mouseY-oldY >0 ) scale *= 0.99;
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
```
```C++
3.加上旋轉 rotate
   *黃色畫線的為新加和修改的程式碼
   
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
```
```C++
4.再加入上週沒有完成的keyboard函式，讓鍵盤也發揮功用
   *開啟 codeblocks 建立新的 GLUT 專案: week06_light_mouse_motion_rotate 
   *黃色畫線的為新加和修改的程式碼，淺藍色是記得檢查要加上的函式
   
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
int oldX=0, oldY=0, now=1; ///now:1 移動 , now:2 轉動 , now:3 縮放
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 ); ///R,G,B,A 其中A為透明度，目前功能沒開
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
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    if(key=='1' || key=='w' || key=='W')now=1; ///移動
    if(key=='2' || key=='e' || key=='E')now=2; ///轉動
    if(key=='3' || key=='r' || key=='R')now=3; ///縮放
}
void mouse(int button, int state, int mouseX, int mouseY)
{///為了解決瞬間移動的錯誤,我們改用正確的方式
    oldX= mouseX; oldY= mouseY;
}
void motion (int mouseX, int mouseY)
{
    if(now==1){///移動
        x += (mouseX-oldX); y+= (mouseY-oldY); ///移動
    }else if(now==2){///轉動
        angle += (mouseX-oldX);///轉動
    }else if(now==3){
        if(mouseX-oldX > 0 ) scale *= 1.01;///縮放
        if(mouseX-oldX < 0 ) scale *= 0.99;///縮放
    }
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
    glutKeyboardFunc(keyboard); ///上週沒完成的遺憾
    glutMouseFunc(mouse);///滑鼠點擊放開
    glutMotionFunc(motion);///滑鼠拖曳
    glutMainLoop();///卡在這裡，之後的程式都不會執行
}
```
## 光線的法向量 Normal
以老師畫的圖為範例，直接由正上方照射下來會特別亮，被照到的平面面積特別集中、小。如果是從側邊一點照，照射下來的光就會散開，被照到的平面面積特別散開、大。
因為用面來計算角度很麻煩，所以光線的照射角度用法向量來決定。夾角越接近法向量就會越亮，越不接近就越不亮。

## 期中考題
```C++
glPushMatrix(); ///備份矩陣

  glTranslatef(x,y,z); ///移動
  glRotatef(角度,x,y,z); ///旋轉
  glScalef(x,y,z); ///縮放

glBegin(GL_POLYGON); ///開始畫
  glColor3f(r,g,b); ///色彩
  glNormal3f(nx,ny,nz); ///打光的法向量
  glTexCoord2f(tx,ty); ///貼圖座標
  glVertex3f(x,y,z); ///頂點
glEnd();

glPopMatrix();///還原矩陣
```
# 電腦圖學筆記week08 -20220411
小葉老師上課要點:
1. 主題: 3D模型
2. 主題: OBJ模型檔
    v vt vn f
3. 實作: glm.h glm.cpp (c)
4. 期中考題: OpenGL必背10函式

## 先測試範例 打光的3D模型
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載兩個檔案 source.zip , data. zip , windows.zip   

2. windows.zip 解壓縮 > 下載 \ windows \ Light Material.exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型

3.執行 > 下載 \ window \ Light Material.exe 看範例
   左上角按右鍵可以換模型
   GLfloat light_pos[] 可以調燈光位置
```

## 認識打光的3D模型範例程式碼
```
1.裝好 freeglut 資料夾到桌面，改lib\libglut32.a
   並開啟 codeblocks 建立新的 GLUT 專案: week08_model

2.開始偷程式碼!! 全選貼到notepad++，並另存新檔sample.cpp
   去了解 GLUT 全部117行程式碼
   *註解重點:範例誰建立的、Spinning是旋轉可以轉兩種:空殼的網格、有打光、ESC可以離開、"+"、"-"可以調
    整增加或減少效果。
```

## 實作 GLUT 程式: 把打光的黃色茶壺變成3D模型
```
1.到github複製第6週的week06_light 貼到week08_model，執行程式碼:有打光的黃色小茶壺

2.進入小葉老師的網址 https://jsyeh.org/3dcg10
   下載 source.zip 解壓縮看裡面的3個程式 lightmaterial.c 、 glm.h 、glm.c
   *glm.h 要 include 它
   *glm.c 改檔名 glm.cpp 要加入專案
   *lightmaterial.cpp 用Notepad++學習(偷程式碼) 偷第17行
   貼到week08_model第2行
   *角括號,是系統的include裡的檔案
   *雙引號,表示同目錄裡的檔案   
   
3.在lightmaterial.cpp n. 搜尋 "glm" 兩次找到第166行，偷它
   貼到week08_model第3行   
   
4.在lightmaterial.cpp n. 搜尋 "glm" 兩次找到第266行，並且偷第262-274行
   貼到week08_model第4-16行，用來畫3D模型   
```

## 實作 GLUT 程式: 開始畫3D模型
```
*開始畫模型
(1)用哪一行程式?
(2)檔案在哪裡? 

(1)用哪一行程式? drawmodel()
把display()裡原本黃色打光茶壺註解掉改 drawmodel() 畫模型

(2)檔案在哪裡? 要放在 working dir 工作目錄裡!!!
    在CodeBlocks 下方 藍色 Build Log 最後一行有說我們的工作目錄位置
    e.g.我的電腦是 (in C:\Users\USER\OneDrive\桌面\freeglut\bin)
    
1.將 下載\data.zip 裡面的 data資料夾複製到"工作目錄"下    

2.複製 glm.h 和 glm.c 放到 week08_model 目錄，將 glm.c 改檔名成 glm.cpp
   *注意:副檔名要看到才行  在視窗>檢視>顯示>副檔名(要打勾)
   
3.最後，在week08_model 的專案中，加入 glm.cpp
   對黑黑的 week08_model 按右鍵，點 Add Files... >
   選同目錄(week08_model資料夾)的glm.cpp > 開啟 > OK   
   
4.執行結果，讚啦有一顆黃色足球!!   

5.改第8行的程式碼可以換模型

6.改第39行把week06_light改成week08_model

7.要儲存專案，glm.cpp才能夠正常推送上github雲端， File > Save project
```

## 介紹3D模型相關資料
```
*模型有obj檔和mtl檔

*.mtl 是 material 的縮寫

*obj檔裡的n是頂點，vn是法向量，vt是貼圖座標
```

# 電腦圖學筆記week09 -20220419
小葉老師上課要點:
1. 考試: OpenGL必背10函式
2. 主題: 貼圖
3. 實作: OpenCV 讀圖、秀圖
4. 實作: 貼圖設定
5. 實作: 貼圖座標

## 主題: 貼圖
```
1. 進入小葉老師的網址 https://jsyeh.org/3dcg10
    下載兩個檔案 source.zip , data. zip , windows.zip   

2. windows.zip 解壓縮 > 下載 \ windows \ Texture.exe
    data.zip 解壓縮＞下載 \ windows \ data \ 模型

3.執行 > 下載 \ window \ Texture.exe 看範例
  *glTexCoord2f 貼圖座標
```

## 下載OpenCV 
```
1.到moodle下載 OpenCV-2.1.0 win32 vs2008

2.安裝時要小心: (1) Add PATH 選第2個 (2)目錄不要改 C:\OpenCV2.1.0

3.安裝好去 C:\ 檢查有沒有 OpenCV2.1.0資料夾
```

## 實作: OpenCV 讀圖、秀圖
```
0. CodeBlocks 要重開 (PATH 安裝完之後, 便會修改 PATH 的設定。)

1. 寫程式很簡單、BUT設定很困難!!!

2.在CodeBlocks開一個新的檔，File > New > EmptyFile, 檔名存成 week09_opencv.cpp 

3.開始設定:和File同列，點選 Setting > Compiler

(1)設定 Include 目錄: Search directories > Compiler > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\include) > OK

(2)設定 Lib 目錄: Search directories > Linker > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\lib) > OK

(3)設定咒語: Linker Settings > Add >打上三個咒語: cv210 , cxcore210 , highgui210 > OK

4.讀圖秀圖:
```

## 實作: 貼圖設定 這是整合失敗版的(圖沒有貼到茶壺上)
```cpp
*非常複雜(程式碼)、非常簡單(用剪貼的)
*最簡單的整合: 把10行GLUT範例 + 3-5行OpenCV讀圖秀圖

1.CodeBlocks開一個新的檔，File > New > Project > GLUT專案 > go , 
  在桌面設定好freeglut , 檔名存成 week09_texture

2.剪貼10行GLUT範例 + 3-5行OpenCV讀圖秀圖
*注意:圖檔要放在工作目錄
不同電腦的工作目錄位置可能不一樣，可以從CodeBlocks下面除錯的最後一行知道工作目錄位置
e.g.我的電腦是(in C:\Users\USER\OneDrive\桌面\freeglut\bin)
*第7行cvWaitKey(0); 原本要寫是因為cvShowImage秀出圖檔後馬上關掉，需要這行讓圖停住
  但是和10行GLUT範例結合後，因為有glutMainLoop()會卡住，就不需要了
  
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("woo.png"); ///讀圖
    cvShowImage("opencv",img); ///秀圖
    ///cvWaitKey(0); 等待任意鍵繼續,可以不用寫,因為有glutMainLoop()卡住
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week09_texture!");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}  
```

## 實作: 貼圖設定 成功的整合
```cpp
1. 複製小葉老師提供的程式碼"myTexture.cpp"
https://gist.github.com/jsyeh/5ed01210559721ec71b659b3ffed2dd7

2.貼到原本程式碼取代原本整個的void myTexture()(紅色框部分)
   修改第36行圖檔的名稱(黃色標記)
   完成整合!!

#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week09_texture!");

    glutDisplayFunc(display);
    myTexture("woo.png");

    glutMainLoop();
}
```

# 電腦圖學筆記week10 -20220426
小葉老師上課要點:
1. 討論: 期中考成績、快篩(缺貨、APP、價錢、Seven)、覺得好累
2. 主題: 上週貼圖+貼到四邊形=背景圖
3. 主題: 上週貼圖+貼到圓球=會轉的地球
4. 主題: 上週貼圖+貼到模型=鋼彈模型

## 實作: 上週貼圖+貼到四邊形=背景圖
```C++
1.安裝 freeglut , OpenCV2.1(Add PATH)
   CodeBlocks開一個新的檔，File > New > Project > GLUT專案 > go , 
   在桌面設定好freeglut , 檔名存成 week10_texture_brackground

2.複製上週week09_texture的程式碼(myTexture()+10行GLUT範例)

#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_brackground");

    glutDisplayFunc(display);
    myTexture("woo.png");

    glutMainLoop();
}

3.OpenCV設定三部曲: (如果使用的電腦會清資料就要重新設定 e.g.使用學校電腦)

(1)設定 Include 目錄: Search directories > Compiler > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\include) > OK

(2)設定 Lib 目錄: Search directories > Linker > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\lib) > OK

(3)設定咒語: Linker Settings > Add >打上三個咒語: cv210 , cxcore210 , highgui210 > OK

4.確認圖檔放要哪裡? 工作目錄!! 我的電腦: (in C:\Users\USER\OneDrive\桌面\freeglut\bin)

5.確認貼圖ok: 到google找一張用來貼到茶壺上的地圖，在第36行把圖檔名稱換上要貼圖的儲存檔名
   *注意:圖檔要放在工作目錄!!
   
**3D座標
把圖釘到四邊形 > 釘的順序:通常從左下角開始逆時針，有時系統比較奇怪可能是順時針

**貼圖座標

6.用glBegin(GL_POLYGON) / glEnd() 開始畫和結束畫中間夾4行 glTexCoord2f(tx,ty) 和 glVertex2f(x,y) 來把背景貼圖做出來 

-glBegin(GL_POLYGON); //開始畫
-   glTexCoord2f(tx1,ty1);  glVertex2f(x1,y1); //要釘四個點所以寫四次
-   glTexCoord2f(tx2,ty2);  glVertex2f(x2,y2);
-   glTexCoord2f(tx3,ty3);  glVertex2f(x3,y3);
-   glTexCoord2f(tx4,ty4);  glVertex2f(x4,y4);
-glEnd(); //結束畫

**注意:在電腦的世界(小畫家的世界),起始頂點(0,0)在左上角，不是我們學數學習慣的左下角

舉錯誤示範: 如果以左下角當作(0,0)，世界會顛到過來

舉正確示範: 如果以左下角當作(0,0)，世界就正常不會顛到過來了!

#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
        ///左邊貼圖座標,右邊頂點座標
        ///這是正確貼圖座標示範:圖片的左上角是0,0
        glTexCoord2f( 0, 1 ); glVertex2f( -1, -1 );
        glTexCoord2f( 1, 1 ); glVertex2f( +1, -1 );
        glTexCoord2f( 1, 0 ); glVertex2f( +1, +1 );
        glTexCoord2f( 0, 0 ); glVertex2f( -1, +1 );
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_brackground");

    glutDisplayFunc(display);
    myTexture("earthmap.jpg");

    glutMainLoop();
}

```

## 實作: 上週貼圖+貼到圓球=會轉的地球
```C++
1.CodeBlocks開一個新的檔，File > New > Project > GLUT專案 > go , 檔名存成 week10_texture_earth，貼上前面的程式

2.要如何畫圓球二次曲面? 圓球的3D座標和2D的貼圖座標要用到 sin() , cos() 算出來
  忘光 sin(),cos() 怎麼辦??? 使用以下外掛
   
   準備二次曲線:
   //Sphere 是圓球
   //gluSphere ( 一個指標 , r 半徑 , slices 柳丁切經線 , stacks 堆疊緯線 )
   gluSphere ( sphere , 1 , 30 , 30 )
   - Open GL (GL) 的函式 ex. glVertex2f()
   - Open GL Utilities (GLU) 的函式 ex. gluSphere()
   - Open User Toolkit (GLUT) 的函式 ex. glutSolidTeapot()
   
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///指標,指到二次曲面
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluQuadricTexture(sphere, 1);///設好貼圖
    gluSphere(sphere, 1, 30, 30);///畫圓球
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_brackground");

    glutDisplayFunc(display);
    myTexture("earthmap.jpg");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}  

3.讓地球轉起來!! (原本的地球有點醜，我換了一顆)
   使用 glRotatef ，設定旋轉角度 angle。地球圓球中心為軸，逆時針轉起來!!

#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///指標,指到二次曲面
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef( angle,0,0,1);
        gluQuadricTexture(sphere, 1);///設好貼圖
        gluSphere(sphere, 1, 30, 30);///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加一度
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_brackground");

    glutIdleFunc(display);///有空idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}

4.3d深度測試，讓地球更正常的旋轉
   修正 glRotatef (90,1,0,0) 把地球轉正
   增加 glEnable (GL_DEPTH_TEST) ，開3D深度測試，才會有3D的效果
   
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///指標,指到二次曲面
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(90,1,0,0);///把它轉正
        glRotatef( angle,0,0,1);
        gluQuadricTexture(sphere, 1);///設好貼圖
        gluSphere(sphere, 1, 30, 30);///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加一度
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_brackground");

    glEnable(GL_DEPTH_TEST);///開3D深度測試,才會有3D的效果
    glutIdleFunc(display);///有空idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}


```

## 實作: 上週貼圖+貼到模型=鋼彈模型
```C++
1.進入小葉老師的網址 https://jsyeh.org/3dcg10
   下載三個檔案 data. zip , windows zip , source.zip
   source.zip解壓縮後，glm.h glm.cpp放在專案的目錄 (在 main.cpp 的旁邊)
   
2.下載老師買的 Gundam 模型: myGundam.zip

3.CodeBlocks開一個新的檔，File > New > Project > GLUT專案 > go , 檔名存成 week10_texture_model

4.Gundam 3D模型要放在工作目錄裡

5.把地球的程式拿來用，改成3D的版本

6.第4、5行程式碼宣告: 使用3D模型，刪掉本來用地球的Sphere

7.第27行: glPushMatrix、glPopMatrix 內原本的程式碼都刪掉，改成用使用鋼彈的3D模型程式碼

8.第53行: main 函式裡的原本sphere刪掉

9.找不到 link 沒辦法執行，所以要在黑黑的專案名稱點右鍵 > add files > glm.cpp >OK

10.第51行: 把地球貼圖換掉，換成鋼彈的貼圖

11.但是執行出來結果鋼彈的圖貼倒了，所以到存放圖檔的工作目錄bin的data裡找出鋼彈的貼圖，到小畫家做垂直翻轉在存檔，再執行! 就可以看到站立且貼好圖的鋼彈模型的屁股。

12.讓鋼彈模型旋轉，想看到整個鋼彈的全貌
     第28行: 加上 glRotatef  
     完成!!
     
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///使用3D模型
GLMmodel * pmodel = NULL; ///使用3D模型
//GLUquadric * sphere = NULL;///指標,指到二次曲面
int myTexture(char * filename)///filename是檔案名稱
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle,0,1,0);
        if(pmodel==NULL){ ///使用3D模型
            pmodel = glmReadOBJ("data/Gundam.obj"); ///使用3D模型
            glmUnitize(pmodel);///使用3D模型,縮放到 -1...1間,才看得到
            glmFacetNormals(pmodel);///使用3D模型,面的法向量
            glmVertexNormals(pmodel,90);///使用3D模型,頂點的法向量
        }
        glmDraw(pmodel, GLM_TEXTURE);

    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加一度
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10_texture_earth");

    glEnable(GL_DEPTH_TEST);///開3D深度測試,才會有3D的效果
    glutIdleFunc(display);///有空idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    //myTexture("earth.jpg");
    //sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}

```
# 電腦圖學筆記week11 -20220503

小葉老師上課要點:
1. 主題: 持續實作 glm 模型相關練習
2. 主題: 利用 Maya 切割模型
3. 主題: 對(特定)旋轉軸轉動(下週作業&下下週考試)
4. 組合技: T移動、R旋轉、T移動

## 主題: 持續實作 glm 模型相關練習-前置作業
```C++
在學校以下都要再做一次

0.freeglut 裝好

1.到moodle下載 OpenCV-2.1.0 win32 vs2008

2.安裝時要小心: (1) Add PATH 選第2個 (2)目錄不要改 C:\OpenCV2.1.0

3.安裝好去 C:\ 檢查有沒有 OpenCV2.1.0資料夾

4. CodeBlocks 要重開 (PATH 安裝完之後, 便會修改 PATH 的設定。)

5.在CodeBlocks開一個新的檔(專案)，File > New > EmptyFile

6.開始設定:和File同列，點選 Setting > Compiler

(1)設定 Include 目錄: Search directories > Compiler > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\include) > OK

(2)設定 Lib 目錄: Search directories > Linker > Add > (打上路徑或是點選Compiler 的 Include 目錄- c:\opencv2.1\lib) > OK

(3)設定咒語: Linker Settings > Add >打上三個咒語: cv210 , cxcore210 , highgui210 > OK

7.開啟一個新的 glut專案: week11_gundam

8.myGundam.zip 解壓縮後的 data 要放到工作目錄

9.貼上第9週的opencv 程式碼 + myTexture + 剩下的讀圖秀圖程式碼
   >茶壺上有鋼彈模型貼圖
   
#include <opencv/highgui.h>
#include <GL/glut.h>
#include <opencv/cv.h>
GLUquadric * sphere = NULL; ///指標 ，指到二次曲面
int myTexture(char * filename)

{

    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖

    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)

    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能

    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID

    glGenTextures(1, &id); /// 產生Generate 貼圖ID

    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);

    return id;

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc , char**argv)

{

    glutInit( &argc , argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week11_Gundam");

    glutDisplayFunc(display);

    myTexture("data/Diffuse.jpg");///輸入圖片名稱

    glutMainLoop();

}   
```

## 主題: 持續實作 glm 模型相關練習-讀入模型、畫出來
```C++
1.進入小葉老師的網址 https://jsyeh.org/3dcg10
  下載  source.zip , 要用到裡面的 glm.h , glm.c , transformation.c

2.把 glm.c 改檔名成 glm.cpp ， 把 glm.cpp , glm.h 放到 week11_gundam 專案目錄裡

3.在 week11_gundam 專案中，Add Files > 加入 glm.cpp

4.加入程式碼，秀出鋼彈模型

**程式碼筆記

*pmodel 指標解釋

GLMmodel * pmodel = NULL;
//假設 pmodel 是女朋友(模型)，如果沒有女朋友就給空指標，表示沒女朋友

 if ( pmodel==NULL ){///如果是空指標 代表模型沒問題了
// 沒有女朋友，可是一定要有，所以要加入相親迴圈大會
        pmodel=glmReadOBJ("data/Gundam.obj");
        //分配一個對象給你做女朋友
        glmUnitize(pmodel); ///使用3D模型 ,縮放到-1...+1才看的到
        //決定女朋友身材 設定好大小
        glmFacetNormals(pmodel);///使用3d模型，面的法向量
        //重新設定法向量，因為要打光所以法向量很重要
        glmVertexNormals(pmodel,90); ///使用3D模型，頂點的法向量
        //如果頂點遇到90度直角，向上的面法向量就90度向上，向左的面法向量也90度向左

5.因為是用自己的電腦，所以之前已經把鋼彈貼圖垂直翻轉過了
   假如第一次遇到貼倒了，要到小畫家垂直翻轉過來

6.秀出的模型似乎有點壓扁。原因: 因為沒開3D前後深度測試

#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體
    glPushMatrix();
        glTranslatef(0.2,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot(0.2);///小茶壺 想像他是手臂
    glPopMatrix();
    glutSwapBuffers();
    angle++; ///如果轉太快可以改成angle += 0.1
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

7.加入3D深度測試，使有立體的感覺；加入 rotatef ，讓鋼彈模型轉動起來 

#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <GL/glut.h>
#include <opencv/cv.h>
#include "glm.h"///使用3d模型
GLMmodel * pmodel = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if ( pmodel==NULL ){///如果是空指標 代表模型沒問題了
        pmodel=glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel); ///使用3D模型 ,縮放到-1...+1才看的到
        glmFacetNormals(pmodel);///使用3d模型，面的法向量
        glmVertexNormals(pmodel,90); ///使用3D模型，頂點的法向量
      }

      glPushMatrix();
        glRotatef(angle, 0,1,0);
        glmDraw(pmodel , GLM_TEXTURE);
      glPopMatrix();

    glutSwapBuffers();
    angle += 1;
}
int main(int argc , char**argv)
{
    glutInit( &argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11_Gundam");

    glEnable(GL_DEPTH_TEST);///開3D深度測試,才會有3D的效果
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");///輸入圖片名稱
    glutMainLoop();
}
```

## 主題: 利用 Maya 切割模型
```
1.到 youtube 搜尋: 如何用 Maya 匯出 3D模型檔(obj)

2.之後作業不可以抄襲，如果手腳轉動怪怪成是可以正常運作那就有問題
```

## 主題: 對(特定)旋轉軸轉動
```C++
1.新建一個新的 GLUT 專案 : week11_TRT

2.準備好一顆白色茶壺(沒有貼圖、沒有打光)

3.畫一個黃色茶壺當身體，再畫另一個綠色茶壺當手臂，但是疊在一起了

4.既然綠色茶壺是手臂，要把它移到右邊而且讓他轉動
#include <GL/glut.h>
void hand(){
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body(){
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle++; ///如果轉太快可以改成angle += 0.1
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week11_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();
}
```

# 電腦圖學筆記week12 -20220510
小葉老師上課要點:
1. 主題:T-R-T (移動、旋轉、移動)對特定軸轉動
2. 作業: T-R-T
3. 下週考試: T-R-T 對特定軸轉動

## 主題: T-R-T (移動、旋轉、移動)對特定軸轉動
```
1.進入小葉老師的網址 https://jsyeh.org/3dcg10
   下載 windows.zip 解壓縮> \windows\Transformation.exe
   下載 data.zip  解壓縮 > \windows\data\模型

2.*觀察和學習模型

3.到小葉老師做的網頁
   https://120.125.80.50/GL/opengl_TRT_demo.html
   這網頁不安全，因為老師們沒有付費
   1.點右下角 " ToDraw " , 左邊小黑可以畫圖 (畫個身體和手臂)
   2.Ctrl-R Reload 可以清空畫面
   3.可以移動程式碼順序
   4.可以按 angle= 在按空白鍵,會產生動畫

   *黃色手臂可以旋轉起來
   
   
   5.點 glTranslatef() 那一行,點它可以移動小黑裡的圖，讓黃色手臂在中間旋轉   
   
   6.再點另一個 glTranslatef() 把整個會旋轉的手臂移動到身體的右上方
```

## 實作: T-R-T (移動、旋轉、移動)
```cpp
1.開啟 Codeblocks , File > New > Project > 開啟一個新的 GLUT 專案 : week12_TRT

2.放上去基礎10行程式碼 + 6行 T-R-T

3.並且讓他會自動轉動 
  ( float angle=0, 加上 glRotatef(angle,0,0,1) , 再加上 angle++ , 最後還有 glutIdleFunc( display ) 讓他轉起來)
  
  #include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(0,0,0);
        glRotatef(angle,0,0,1);
        ///glTranslatef(0,0,0);
        glutSolidTeapot(0.2);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

4.做出一個茶壺超人:白色茶壺當身體，再加上紅色小茶壺掛到右邊當手臂而且旋轉

#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體
    glPushMatrix();
        glTranslatef(0.2,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot(0.2);///小茶壺 想像他是手臂
    glPopMatrix();
    glutSwapBuffers();
    angle++; ///如果轉太快可以改成angle += 0.1
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

5.再開啟一個新的 GLUT 專案: week12_TRT_TRT
   再增加一個TRT紅色小茶壺，當作下手肘，左邊也要
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體
    glPushMatrix();
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
```

## 複習: 使用 Git 指令備份程式碼到 GitHub
```
1.安裝 Git for Window , 開啟 Git Bash

*以下有淺藍色襯底的是要輸入Git Bash的指令

2.cd desktop  : cd 是改變目錄的意思(change directory)
   黃色字會說明經過什麼目錄在哪個目錄
   要備份的程式碼資料夾在哪個目錄就到哪個目錄去
   在學校通常都是 desktop，我自己的電腦就要先進入 OneDrive 再進入 桌面

3.start .  : 開啟現在所在目錄

4.git clone https://github.com/chendooou/2022graphics1
   : 可以把在 GitHub 上面的雲端 clone(複製) 下來
   如果已經 clone 過了會出現錯誤訊息: already exist ，那表示 2022graphics1 這個資料夾已經在電腦裡不需要
   再 clone 了

5.cd 2022graphics1  : 進入你的(倉庫)目錄

6.git pull  : 是把雲端拉下來到我的硬碟倉庫

7.start .  : 開啟現在所在目錄，然後就可以把在要備份的程式碼資料夾複製到 2022graphics1

8.git status  :查看倉庫狀況，這時會紅色呈現剛剛複製進去的目錄名稱

9.git add .  :把紅色的目錄加進去 git 帳冊

10.git status  :再次查看倉庫狀況，原本呈現紅色的目錄會變成綠色呈現

11.git commit -m"week12"  :確認 git 帳冊，如果沒有做過(例如用每次開機就會重整資料的學校電腦)，他
     會顯示說不認識你，這時按照格式輸入就好
     (git config --global user name , git config --global user name )
     然後記得再次 git commit -m"week12" ，week12是會註記在GitHub上的簽名(?)

12.git push  : 推送上雲端，到 GitHub 更新頁面看看是否有成功上傳要備份的程式碼目錄
```
# 電腦圖學筆記week13 -20220517
小葉老師上課要點:
1. 示範複習作業/考試的 TRT(實際例子)
2. TRT 的R角度
3. 利用 keyboard/mouse 來改變
4. 如何轉正模型、如何調整模型大小


## 主題: 示範複習作業/考試的 TRT(實際例子)
```cpp
1.開啟 codeblocks 建 新的 GLUT 專案 : week13_rect_TRT

2.用 glRect() 來畫一個矩形，作為身體 (左上角座標、右下角座標)
   *glutInitWindowSize(600,600) 可以讓小黑視窗顯示的大一些
   
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRectf(0.3,0.5,-0.3,-0.5);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}

3.再畫一個紅色的矩形作為小手臂，而且能夠轉動
   *先把 300*300 的小黑視窗放到小畫家認識座標關係，思考手臂(紅色矩形)應擺放的座標
   *寫程式碼準備做出會旋轉的紅色手臂: 給身體一個 glColor3f (1,1,1) 的白色，準備好備份還原矩陣、TRT、紅色矩形 > 先做出紅色手臂的位置
   
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        ///glTranslatef(x,y,z); //(3)把手臂掛回身體
        ///glRotatef(angle,0,0,1); //(2)旋轉
        ///glTranslatef(x2,y2,z2); //(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}
4. * T R T 的第一個 T > (1)把手臂的旋轉中心，放中心
    > 旋轉中心(綠點0.3 , 0.4) 移到中心要左移0.3，下移0.4 > gltranslatef(-0.3, -0.4, 0)

#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        ///glTranslatef(x,y,z); //(3)把手臂掛回身體
        ///glRotatef(angle,0,0,1); //(2)旋轉
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}

5. * T R T 的第二個 R > (2)旋轉
    > 對 z 軸旋轉45度 > glRotatef (angle, 0,0,1);  
 
#include <GL/glut.h>
float angle=45;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        ///glTranslatef(x,y,z); //(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}

6. * T R T 的第三個 T > (3)把手臂掛回身體
    > 把手臂掛回去 (0.3,0.4) 的位置 > gltranslatef(0.3, 0.4, 0)
#include <GL/glut.h>
float angle=45;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(-3,-4,0); //(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}        
```

## 主題: 利用 mouse motion 來旋轉手臂的角度值
```cpp
1. 用 mouse motion 來旋轉角度

#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

2.開啟 codeblocks 建新的 GLUT 專案 : week13_rect_TRT_TRT，再加一個綠色手臂(關節)
*複製 week13_rect_TRT 的程式碼來改
*先弄清楚程式碼結構(身體、紅色上手臂)，先弄清楚綠色下手肘要放哪裡

*加上綠色手臂程式碼，綠色矩形座標: (0.7 , 0.5 ), (1.0 , 0.3) > glRectf ( 0.7 , 0.5 , 1.0 , 0.3 )

///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂,紅色手臂

        glPushMatrix();
            ///glTranslatef(x,y,z); //(3)把手臂掛回身體
            ///glRotatef(angle,0,0,1); //(2)旋轉
            ///glTranslatef(x2,y2,z2); //(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

3.下手臂加上(1)T找到選轉中心( 0.7 , 0.4 )放小黑中心 (2)R 旋轉，先註解掉上手臂的 R 以免干擾
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        //glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            ///glTranslatef(x,y,z); //(3)把手臂掛回身體
            glRotatef(angle,0,0,1); ///(2)旋轉
            glTranslatef(-0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

4.把綠色手臂掛回去紅色手臂旁邊的位置
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        //glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle,0,0,1); ///(2)旋轉
            glTranslatef(-0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

5.上手臂的轉動還回去，取消上手臂 R 註解
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle,0,0,1); ///(2)旋轉
            glTranslatef(-0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
```

## 主題: 更多TRT
```cpp
1.開啟 codeblocks 建新的 GLUT 專案 : week13_rect_many_TRT
*複製 week13_rect_TRT_TRT 的程式碼來改

2.把右半部的上手臂和下手肘再複製一份給左半部用，改掉x座標(加上一個負號)

///week13_rect_many_TRT
#include <GL/glut.h>
float angle=45 , oldX=0;
void mouse(int button, int status , int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);///身體,四邊形

    glPushMatrix();///右半部
        glTranslatef(0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(-0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle,0,0,1); ///(2)旋轉
            glTranslatef(-0.7,-0.4,0); ///(1)把手臂的旋轉中心，放中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘,綠色手臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半部
        glTranslatef(-0.3,0.4,0); ///(3)把手臂掛回身體
        glRotatef(angle,0,0,1); ///(2)旋轉 對z軸轉動
        glTranslatef(0.3,-0.4,0); ///(1)把手臂的旋轉中心，放中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0); ///(3)把手臂掛回身體
            glRotatef(angle,0,0,1); ///(2)旋轉
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
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

3.只有一個角度 angle 沒有辦法有更多變化，所以使用 keyboard 函式來控制關節做切換
   *最後記得 main() 要加上 glutKeyboardFunc(keyboard);
   
///week13_rect_many_TRT
#include <GL/glut.h>
float angle[4] , oldx=0;
int angleID=0;///0號關節 1號關節
void keyboard(unsigned char key , int x  , int y)
{
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
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}   
```

# 電腦圖學筆記week14 -20220524

小葉老師上課要點:
1. 寫檔、讀檔
2. 關節、做動畫
3. 計時器 glutTimerFunc(時間, timer, 參數t)
4. 播放聲音

## 主題: 寫檔、讀檔
```cpp
* fopen() 開檔  ( 開啟檔案 )
* fprintf() 寫檔
* fclose() 關檔 ( 關閉檔案 )

1. 在桌面上建立一個 week14-1_fprintf 資料夾

2. 開啟 codeblocks 建立一個新檔 ( File > New > Empty File )  : 在 week14-1_fprintf 目錄下 
    建立 week14.cpp  
**寫檔 File Output ( 紀錄 ) : 為了記錄動畫的動作

程式碼: FILE  *  fout = fopen( "file.txt" , "w+" );
           檔案  指標          開啟檔案  檔名     write模式
** FILE:檔案 *:指標 fopen:開啟檔案(檔名, write模式)
打完後先按齒輪，和檔案所在的同目錄會迸出 .exe 和 .o 兩個檔案
再按綠色三角加齒輪 執行 : 小黑會印出 Hello World 目錄會再迸出 .txt 檔案 (第4行code)

#include <stdio.h>
int main()
{///FILE:檔案 *:指標 fopen:開啟檔案(檔名, write模式)
    FILE * fout = fopen("file.txt","w+");
     printf(     "Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案

}

3. 開啟 codeblocks 建立一個新檔 ( File > New > Empty File )  : 在 week14-2_fprintf_fscanf 
   目錄下建立 week14-2.cpp  
**讀檔 File Input ( 紀錄 ) :
複製 week14.cpp 來用

///week14-2.cpp
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);///關閉檔案

    float angle=0;
    FILE * fin = fopen("file.txt","r");
    fscanf(fin,"%f", &angle );///angle前面記得加&
    printf("讀到了角度:%f", angle);
    fclose(fin);

}

```

## 主題: 關節
```cpp
1. 開啟 codeblocks 建新的 GLUT 專案 : week14_angle_fprintf 
    用上週 week13_rect_many_TRT 來改
*用 讀檔,寫檔 將動作紀錄在小黑

2. 但是可讀性太差 , 改良!!
*加上兩行跳行 ( 小黑跳行、檔案也跳行
每印出一堆數字就跳行

///week14_angle_fprintf 改自 week13_rect_many_TRT
#include <GL/glut.h>
#include <stdio.h>
float angle[20] , oldx=0;
int angleID=0;///0號關節 1號關節
FILE * fout = NULL;
void myWrite(){///每呼叫一次myWrite()
    if( fout == NULL) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///小黑印出來
        fprintf(fout, "%.1f ", angle[i] );///檔案印出來
    }///印出20個數字
    printf("\n");///每呼叫一次,小黑跳行
    fprintf(fout,"\n");///每呼叫一次,檔案也跳行
}
void keyboard(unsigned char key , int x  , int y)
{
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
    myWrite();
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
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

```

## 主題: 做動畫
```cpp
1. 開啟 codeblocks 建新的 GLUT 專案 : week14_angles_fprintf_fscanf 
    從上一個程式( week14_angle_fprintf  ) 做修改
    目標: 使用 void myRead() ，在 keyboard() , 按下 ' r ' 呼叫 myRead()

    * myWrite() 結尾沒有 fclose 所以在 myRead()一開始先 fclose() 做收尾
    * 當做好一連串動作，長按 r ，便會開始播出剛剛做的一連串動作

///week14_angle_fprintf_fscanf 改自 week14_angle_fprintf
#include <GL/glut.h>
#include <stdio.h>
float angle[20] , oldx=0;
int angleID=0;///0號關節 1號關節
FILE * fout = NULL, * fin = NULL;
void myWrite(){///每呼叫一次myWrite()
    if( fout == NULL) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///小黑印出來
        fprintf(fout, "%.1f ", angle[i] );///檔案印出來
    }///印出20個數字
    printf("\n");///每呼叫一次,小黑跳行
    fprintf(fout,"\n");///每呼叫一次,檔案也跳行
    ///這裡沒有fclose
}
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }///fclose寫在這裡收尾myWrite()開的檔案
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f",&angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key , int x  , int y)
{
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
    myWrite();
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
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

2. 奇怪的地方
    為什麼專案產生的檔案 file.txt 放在奇怪的目錄 (in C:\Users\USER\OneDrive\桌面\freeglut\bin) ?

 原因: 是歷史遺毒(以前設定造成的原因) GLUT專案需要 freeglut.dll 所以 working_dir 
            被設定在 freeglut\bin 裡面
            
     怎麼做能夠讓 file.txt 和專案放在同一個目錄?
     2.1 將專案目錄裡的 .cbp 檔案使用 Notepad++ 開啟，
         找到 working_dir="C:/Users/USER/OneDrive/桌面/freeglut/bin" 
         都改成 working_dir="." (小數點) 
         記得按 ctrl +s 存檔  
         
     2.2 回到 codeblocks 會詢問是否 Reload Project ， 按 Yes 
     
     2.3 按下綠色三角形齒輪執行看看，會出現系統錯誤找不到 freeglut.dll 
     
     2.4 到 freeglut/bin 目錄去複製 freeglut.dll 貼到專案資料夾( week14_angles_fprintf_fscanf )
     
     2.5 再回到codeblocks 按綠三角形加齒輪執行，就可以成功!! 動動機器人的關節，
           會記錄在小黑視窗，開啟的txt檔也會出現再專案目錄資料夾。
           ( txt 檔內同樣紀錄小黑視窗中的動作紀錄)
```

## 主題: 計時器 glutTimerFunc(時間, timer, 參數t)
```cpp
* 持續按 r 可以播出動畫，但是友人的速度可能有點慢，這是要看每一台電腦 keyboard 設定的速度
   為了解決這樣的問題，可以使用計時器 glutTimerFunc

1. 開啟 codeblocks 建新的 GLUT 專案 : week14_timer
    
    * void timer(int t) 寫 timer 函式
    * glutTimerFunc ( 等多久 , timer , t 參數 );
    
///week14_timer 
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("起床,現在時間: %d\n", t);
}
void display()
{

}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week14_timer");
    ///前一晚一次設好多鬧鐘,每天早上時間到了就響
    glutTimerFunc(1000,timer,1);
    glutTimerFunc(2000,timer,2);
    glutTimerFunc(3000,timer,3);
    glutTimerFunc(4000,timer,4);
    glutTimerFunc(5000,timer,5);
    glutDisplayFunc(display);
    glutMainLoop();
}    

2. * 但是期末作品30秒，每秒30格，需要設900個timer太麻煩了
   > 使用 函式呼叫函式 讓程式自動能夠 timer 接著 timer 設

   開啟 codeblocks 建新的 GLUT 專案 : week14_timer_one_by_one
   * 設定5秒後 第0個timer開始起床，然後接下來函式會自己呼叫函式，每一秒建立一個t+1個timer

///week14_timer_one_by_one
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("起床,現在時間: %d\n", t);
    glutTimerFunc(1000, timer, t+1);
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
```

## 主題: 播放聲音
```cpp
* 播放聲音用 PlaySound ，要先下載 音檔 "do.wav"

1. 使用 week14_timer_one_by_one 繼續改程式碼

*要加標頭檔 #include <mmsystem.h>
*播聲音函式: PlaySound("do.wav" , NULL , SND_ASYNC );
                       音檔    , 空指標(沒有指定要把音樂掛哪裡) , 非同步播出
                       
                       
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
```cpp
# 電腦圖學筆記week15 -20220531

小葉老師上課要點:
1. 播聲音、播MP3
2. 播放動畫、內插
3. 機器人擺動作、跳舞

## 主題: PlaySound() 播聲音
```cpp
1. 開啟 codeblocks 建立一個新檔(File > New > Empty File) : week15-1_PlaySound.cpp

2. 上週使用 #include <mmsystem.h>

    本週使用 #include <windows.h> 
    PlaySound( "檔名.wav" , NULL , SND_ASYNC);  //不等待/不同步
    PlaySound( "檔名.wav" , NULL , SND_SYNC);  //等待/同步

3. 要注意工作執行目錄 working_dir (in C:\....)

4. 要成功播出聲音，要加入咒語wimnn : 
    * 設定咒語步驟複習:
    1. Settings > Compiler
    2. Linker settings > Add > 輸入:winmm
    3. 按綠色三角行加齒輪執行 :
        *程式音檔不存在，所以出現的聲音是 window 內建的錯誤提示聲

#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
        ///檔案不存在,會有很小聲的錯誤聲
    PlaySound("badbad.wav",NULL, SND_SYNC);
    printf("PlaySound()之後\n");
}
    
  4. 在 codeblocks 下方的 Build log 裡確定工作目錄位置後，將正確音檔放進這個目錄，就會正常
        播放聲音了
     *我放了鵝叫聲的音檔在工作目錄裡 ，音檔一定要是 .wav 檔 (PlaySound() 只能播 wav檔)

#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
        ///加入正確的音檔(音檔注意要放在工作目錄)
    PlaySound("07013033.wav",NULL, SND_SYNC);
    printf("PlaySound()之後\n");
}
        
```
## 主題: PlaySound() 更多參數
```cpp
1. 開啟 codeblocks 建立一個新檔(File > New > Empty File): 
    week15-2_SND_SYNC_SND_ASYNC.cpp

    *PlaySound( "檔名.wav" , NULL , SND_ASYNC);  //不等待/不同步
      > 如果沒有迴圈控制，程式會直接執行到最後一行。
         有迴圈控制，可以不播完，再背景播，繼續做下一個指令 ，適合做互動

    *PlaySound( "檔名.wav" , NULL , SND_SYNC);  //等待/同步
     > 會把這一行音檔播完，等到天荒地老才會執行下一行，不適合做互動

2. 將 do.wav , re.wav, mi.wav 三個音檔放入目錄資料夾，用 SYNC (等待)，會完整播完 do , re , mi 音檔

#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("do.wav",NULL, SND_SYNC); ///ASYNC不等待
    PlaySound("re.wav",NULL, SND_SYNC); ///ASYNC不等待
    PlaySound("mi.wav",NULL, SND_SYNC); ///ASYNC不等待
    ///最後一行就結束了
}

3. 使用 ASYNC (不等待) + 迴圈控制 : 達到互動效果
    * 一開始播鵝叫聲，按數字1: do ；數字2: re ； 數字3: mi
    
#include <windows.h>
#include <stdio.h>
int main()
{
    ///不等待能夠較快執行到下一行比較適合做互動
    PlaySound("07013033.wav",NULL, SND_ASYNC);///ASYNC不等待
    while( 1 ){
        printf("請輸入數字: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav",NULL, SND_ASYNC); ///ASYNC不等待
        if(N==2) PlaySound("re.wav",NULL, SND_ASYNC); ///ASYNC不等待
        if(N==3) PlaySound("mi.wav",NULL, SND_ASYNC); ///ASYNC不等待
    }
    ///最後一行就結束了
}    
```
## 主題:  PlaySound() 播 mp3
```cpp
*     wav                v.s                MP3 
     檔案大                                檔案小            
    原始檔案                             壓縮過檔案
  40年前就有                             20年前出現  
簡單:程式碼只要一行                   複雜:要用較多行程式碼

PlaySound()只要一行使用 wav 即可播聲音

到 moodle 下載 CMP3_MCI.h 這個檔可以在 #include "CMP3_MCI.h" 後, 解鎖 mp3.Play()功能

** wav 檔案不可以直接改檔名為 mp3 ，因為將兩個音檔用notepad++開啟看程式碼，
會發現兩個檔案內容根本不一樣，所以不可以騙人不能這麼做

1. 開啟 codeblocks 建立一個新檔(File > New > Empty File> : week15-3_mp3.cpp

2. 在 moodle 下載 CMP_mci.h ，下載要播的 mp3 音檔，放在同目錄

3.標頭檔 #include "CMP3_MCI.h"
   宣告 CMP3_MCI mp3;
   mp3.Load("檔名.mp3");
   mp3.Play();

#include <stdio.h>
#include "CMP3_MCI.h" ///記得要下載、放同目錄
CMP3_MCI mp3; ///宣告變數

int main()
{
    mp3.Load("0505906.mp3");
    mp3.Play();

    printf("隨便等你輸入數字,程式就卡住囉: ");
    int N; ///為了卡住程式不要直接就結束
    scanf("%d",&N);
}
```
## 主題:  關節、做動畫
```cpp
1. 開啟 codeblocks 建新的 GLUT 專案 : week15_angles_TRT_again 
    從上一個程式( week14_angle_fprintf_fscanf  ) 做修改關節 ，最後長按 ' r ' 會讀入資料做出
    原本擺過的動作

2. 但是以上原本的程式很不像動畫執行的很慢 
    原因 : 每拉一個關節 myWrite() 就寫一行 ，myRead 會讀一行

    解決 : 不要把 myWrite() 放 motion() ，就不會有拉一個關節就紀錄導致動畫又慢又卡的問題
              把一個動作對應的關節全部調好後，再紀錄 myWrite (一行)動作

3. 把原 motion() 函式內的 myWrite(); 註解掉
    在 keyboard 函式 新增 if (key=='s') myWrite(); ///調好動作,再save存檔

4. 但是目前我只有8個動作，按8次 ' r ' 就結束動畫了。
    希望能夠一樣的動作重複多做幾次怎麼做呢 ?

   * 找到工作目錄開啟 " file.txt " ，會看到剛剛在小黑裡記錄的8行動作

   * 把原本的8個(行)動作複製起來，貼上看要重複幾次
     以下截圖複製貼上了8次，所以總共能夠按 72 次 ' r ' 做動作
     
   * 再回到 codeblock 再執行一次，就能夠按72次 ' r ' 重複動作了  
   
///week15_angles_TRT_angle 改自 week14_angles_fprint_fscanf
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
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f",&angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key , int x  , int y)
{
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
    glutCreateWindow("week15 angles TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}


```
## 主題: 機器人擺動作、跳舞
*我們甲班在講解這個部分有錄影檔壞掉，所以有參考乙班的上課內容

```cpp
1. 開啟 codeblocks 建新的 GLUT 專案 : week15_homework_gundam_parts
    從上一個程式( week15_angles_TRT_again  ) 做修改

2. 寫一個新的 display() ，原本舊的 display()改為 displayOld() 
   再舊的偷兩行程式碼到新的
   
3. 將 glm.cpp , glm.h , data(裡面有五個檔案) 放入目錄資料夾

4. 回到 codeblocks 在左邊的專案，加入 Add glm.cpp

    * 在專案名稱上 按右鍵，選擇 Add files > 選擇專案目錄內的 glm.cpp > OK 
    
5. 開始寫程式碼讀入模型
    
6. 檢查工作目錄是否在奇怪偏僻的桌面上 freeglut 的 bin ，總之要把工作目錄設在專案資料夾
    *詳細圖解可參考 第14週 > 主題: 做動畫 > 2.奇怪的地方

   **更改工作執行目錄步驟:
   a. 使用 notepad++ 開啟目錄資料夾 (week15_homework_gundam_parts) 的 cbp 檔
    b. 找到cbp 檔內所有 working_dir  (在第11、21行)
        將原本的奇怪偏僻路徑改為一個小數點 <Option working_dir="." /> 改完記得存檔
   c. 回到 codeblcks 會被詢問 Reload Project? 選擇 Yes 
       被問是否存檔就給他存，在回去 notepad++看 working_dir 是否有改成功 
       沒成功就在重複上一個 b. 工作 
   d. 確認好之後按綠色三角加齒輪執行，出現錯誤，表示找不到 freeglut.dll
       往下面 Build log 確認工作執行目錄是否為在專案目錄了，沒有就回去在重新修正
   e. 到桌面上的 freeglut \ bin 裡的 freeglut 複製到專案目錄裡就好，不需重裝

7. 這個新的 display() 身體沒有分區塊，不要了，改為 displayNotParts()
    再準備一個最新的 display() ///最新的 display(),會把身體每一塊都分別處理好

8. 到 teams 下載老師的 Gundam.zip , 解壓縮後有很多切割好的模型，
    將26個切割的部位複製到專案目錄資料夾內的data資料夾 
    
9. 發明 myReadOne 函式用來把每個部位都讀進來，最新的 display()就可以簡短清爽的只使用
    一行程式碼就讀入一個部位，舊的display們就是示範以前讀入一個部位就要各自寫很多行 
    
///week15_homework_gundam_parts 改自 week15_angles_TRT_angle
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
```
