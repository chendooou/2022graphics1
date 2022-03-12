# week01 20220301
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

# week02 20220308
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
