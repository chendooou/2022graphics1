# 2022grapics1
# week02
```
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
開始畫茶壺
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
