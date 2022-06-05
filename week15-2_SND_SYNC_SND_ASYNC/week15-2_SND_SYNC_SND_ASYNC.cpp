///week15-2_SND_SYNC_SND_ASYNC
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

///等待只能等他播完
///不等待能夠較快執行到下一行比較適合做互動
