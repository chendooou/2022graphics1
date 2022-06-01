#include <stdio.h>
int main()
{///FILE:檔案 *:指標 fopen:開啟檔案(檔名, write模式)
    FILE * fout = fopen("file.txt","w+");
     printf(     "Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案

}
