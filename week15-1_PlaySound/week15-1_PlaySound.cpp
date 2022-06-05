#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
        ///加入正確的音檔(音檔注意要放在工作目錄)
    PlaySound("07013033.wav",NULL, SND_SYNC);
    printf("PlaySound()之後\n");
}
