#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
void gotoxy(int x, int y)
{
	COORD pos; pos.X=x-1; pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
	system("color f0");
	long i;
	char FileName[100];
	char hi[300000];
	FILE *in;
	for(i=1;i<=4492;i++)
	{
		sprintf(FileName,"C:\\Users\\pc\\Desktop\\ËÕ¹óÓê201902575\\TXT\\(%ld).txt",i);
		in=fopen(FileName,"r");
		assert(in != NULL);
		fread(hi,1,300000,in);
		printf("%s\n%d",hi,i);
		gotoxy(1,1);
		Sleep(26);
		fclose(in);
	}
}
