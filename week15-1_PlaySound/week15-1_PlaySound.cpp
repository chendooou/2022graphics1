#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
        ///�[�J���T������(���ɪ`�N�n��b�u�@�ؿ�)
    PlaySound("07013033.wav",NULL, SND_SYNC);
    printf("PlaySound()����\n");
}
