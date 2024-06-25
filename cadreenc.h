#include<windows.h>
#include<stdlib.h>

#include<stdio.h>
/*

x correspond à la couleur du texte
y correspond à la couleur de fond

les valeurs:
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc 
*/
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   //cout.flush();
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void ASCII()
{
	int i;
	for(i=0;i<256;i++)
	{
		printf("%c = %d\n\t",i,i);
	}
}
void cadre(int x1, int x2, int y1, int y2,int c)
{
	int i;
	color(c,0);
		for(i=x1;i<=x2;i++)
	{
		gotoxy(i,y1);
		printf("%c",196);
		gotoxy(i,y2);
		printf("%c",196);
	}
	for(i=y1;i<=y2;i++)
	{
		gotoxy(x1,i);
		printf("%c",179);
		gotoxy(x2,i);
		printf("%c",179);
	}
gotoxy(x1,y1);
printf("%c",218);
gotoxy(x2,y1);
printf("%c",191);
gotoxy(x1,y2);
printf("%c",192);
gotoxy(x2,y2);
printf("%c",217);
}
char m[7][20]={"factoriel","combinaison","analyse","probabilite","algo","langage c","quitter"};
void menu(int x,int y,int c)
{int i;
color(c,0);

for(i=0;i<7;i++)
	for(i=0;i<7;i++)
	{
		gotoxy(x+2, y+1+i);
		printf("%d-%s",i+1,m[i]);
		
	}
}
 
