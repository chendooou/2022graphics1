///week15-2_SND_SYNC_SND_ASYNC
#include <windows.h>
#include <stdio.h>
int main()
{
    ///�����ݯ�����ְ����U�@�����A�X������
    PlaySound("07013033.wav",NULL, SND_ASYNC);///ASYNC������
    while( 1 ){
        printf("�п�J�Ʀr: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav",NULL, SND_ASYNC); ///ASYNC������
        if(N==2) PlaySound("re.wav",NULL, SND_ASYNC); ///ASYNC������
        if(N==3) PlaySound("mi.wav",NULL, SND_ASYNC); ///ASYNC������
    }
    ///�̫�@��N�����F
}

///���ݥu�൥�L����
///�����ݯ�����ְ����U�@�����A�X������
