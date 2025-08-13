#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>

void setcolor(unsigned short color)
{ 
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hCon,color); 
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct PLAYER
{
	int gerak;
	bool com;
	char nama[20];
}pemain[2];

void game(int giliran);
void tamp_dadu(int dadu);
void tamp_pem(int gerak,int jarak,int bidak);
void map();
void clear();
void kocok_dadu(int *dadu,int giliran);
void mainMenu();
void play();
void start();
void petak(int giliran);
void winner(int giliran);

int main()
{
	system("MODE 115,40");
	mainMenu();
}

void play()
{
	system("cls");
	int select,aktif;
	aktif=24;
	setcolor(7);
	gotoxy(35,18);  printf("��������������������������������������ͻ");
	gotoxy(35,19); 	printf("�                                      �");
	gotoxy(35,20); 	printf("�      WELCOME TO BAGONG AIRLINES      �");
	gotoxy(35,21); 	printf("�                                      �");
	gotoxy(35,22); 	printf("��������������������������������������ͺ");
	gotoxy(35,23); 	printf("�                                      �");
	gotoxy(35,24); 	printf("�         Player 1 VS Player 2         �");
	gotoxy(35,25); 	printf("�            Human VS COM              �");
	gotoxy(35,26); 	printf("�              Main Menu               �");
	gotoxy(35,27); 	printf("�                                      �");
	gotoxy(35,28); 	printf("��������������������������������������ͼ");
	setcolor(11);
	gotoxy(43,24);  printf("%c",26);
	while(select!=1)
	{
		gotoxy(43,aktif);
		switch(getch())
		{
			case 80 :
				aktif+=1;
				break;
			case 72 :
				aktif-=1;
				break;
			case 13 :
				select=1;
				break;
		}

		if(aktif>26)
			aktif=24;
		if(aktif<24)
			aktif=26;
		printf(" ");
		gotoxy(43,aktif);	printf("%c",26);
	}
	system("cls");
	switch(aktif){
		case 24 :
			for(int i=0;i<2;i++)
			{
				fflush(stdin);
				printf("Masukkan nama pemain %d : ",i+1);
				gets(pemain[i].nama);
				pemain[i].com=false;
				pemain[i].gerak=0;
			}
			start();
			break;
		case 25 :
			fflush(stdin);
			printf("Masukkan nama pemain : ");
			gets(pemain[0].nama);
			strcpy(pemain[1].nama,"COM");
			pemain[0].com=false;
			pemain[0].gerak=0;
			pemain[1].com=true;
			pemain[1].gerak=0;
			start();
			break;
		case 26 :
			mainMenu();
			break;
	}
}

void start()
{
	map();
	int i,dadu,giliran=-1;
	do
	{
		for(i=0;i<2;i++)
		{
			gotoxy(10,38);	printf("%s%c%c : %2d\t%s%c%c : %2d",pemain[0].nama,179,4,pemain[0].gerak,pemain[1].nama,179,5,pemain[1].gerak);
		}
		if(dadu!=6)
			giliran++;
		if(giliran>1)
			giliran=0;
		kocok_dadu(&dadu,giliran);
		if(pemain[giliran].gerak==2||pemain[giliran].gerak==15||pemain[giliran].gerak==23||pemain[giliran].gerak==26)
		{
			petak(giliran);
		}
		else if(pemain[giliran].gerak==14||pemain[giliran].gerak==20)
		{
			game(giliran);
		}
	}while(pemain[giliran].gerak<35);
	winner(giliran);
}

void winner(int giliran)
{
	int i;
	system("cls");
	gotoxy(23,21);	printf("                         Selamat %s%c%c",pemain[giliran].nama,179,giliran+4);
	for(i=0;i<8;i++)
	{
		gotoxy(23,23);	printf("                                                               ");
		gotoxy(23,24);	printf("                                                               ");
		gotoxy(23,25);	printf("                                                               ");
		gotoxy(23,26);	printf("                                                               ");
		gotoxy(23,27);	printf("                                                               ");
		gotoxy(23,28);	printf("                                                               ");
		gotoxy(23,29);	printf("                                                               ");
		Sleep(100);
		gotoxy(23,23);	printf(" ***     ***  ***    ***    ***     ***       *** *** ***   ***");
		gotoxy(23,24);	printf("  ***   *** **   **  ***    ***     ***       *** *** ****  ***");
		gotoxy(23,25);	printf("   *** *** **     ** ***    ***     ***       *** *** ***** ***");
		gotoxy(23,26);	printf("    *****  **     ** ***    ***     *** ***** *** *** *********");
		gotoxy(23,27);	printf("     ***   **     ** ***    ***     ****** ****** *** *** *****");
		gotoxy(23,28);	printf("     ***    **   **   ***  ***      *****   ***** *** ***  ****");
		gotoxy(23,29);	printf("     ***      ***      ******       ****     **** *** ***   ***");
		Sleep(100);
	}
	gotoxy(23,31);		printf("               Tekan spasi untuk kembali ke Menu               ");
	getch();
}

void petak(int giliran)
{
	int x,y;
	switch(pemain[giliran].gerak)
	{
		case 2:
			pemain[giliran].gerak=15;
			for(x=0;x<10;x++)
			{
				tamp_pem(2,giliran*3,giliran+4);
				Sleep(100);
				tamp_pem(2,giliran*3,0);
				Sleep(30);
			}
			for(x=0;x<=12;x++)
			{
				gotoxy(27+x,33-x);	printf("%c",254);
				gotoxy(28+x,33-x);	printf("%c",254);
				Sleep(100);
				gotoxy(27+x,33-x);	printf(" ");
				gotoxy(28+x,33-x);	printf(" ");
				Sleep(40);
			}
			tamp_pem(15,giliran*3,giliran+4);
			break;
		case 15:
			pemain[giliran].gerak=2;
			for(x=0;x<10;x++)
			{
				tamp_pem(15,giliran*3,giliran+4);
				Sleep(100);
				tamp_pem(15,giliran*3,0);
				Sleep(30);
			}
			for(x=0;x<=12;x++)
			{
				gotoxy(39-x,21+x);	printf("%c",254);
				gotoxy(40-x,21+x);	printf("%c",254);
				Sleep(100);
				gotoxy(39-x,21+x);	printf(" ");
				gotoxy(40-x,21+x);	printf(" ");
				Sleep(40);
			}
			tamp_pem(2,giliran*3,giliran+4);
			break;
		case 23:
			pemain[giliran].gerak=12;
			for(x=0;x<10;x++)
			{
				tamp_pem(23,giliran*3,giliran+4);
				Sleep(100);
				tamp_pem(23,giliran*3,0);
				Sleep(30);
			}
			for(x=0;x<=6;x++)
			{
				gotoxy(5,15+x);	printf("%c",254);
				gotoxy(6,15+x);	printf("%c",254);
				Sleep(100);
				gotoxy(5,15+x);	printf(" ");
				gotoxy(6,15+x);	printf(" ");
				Sleep(40);
			}
			tamp_pem(12,giliran*3,giliran+4);
			break;
		case 26:
			pemain[giliran].gerak=33;
			for(x=0;x<10;x++)
			{
				tamp_pem(26,giliran*3,giliran+4);
				Sleep(100);
				tamp_pem(26,giliran*3,0);
				Sleep(30);
			}
			for(x=0;x<=6;x++)
			{
				gotoxy(27,9-x);	printf("%c",254);
				gotoxy(28,9-x);	printf("%c",254);
				Sleep(100);
				gotoxy(27,9-x);	printf(" ");
				gotoxy(28,9-x);	printf(" ");
				Sleep(40);
			}
			tamp_pem(33,giliran*3,giliran+4);
			break;
	}
}

void game(int giliran)
{
	clear();
	int x,y,x2,y2,score=0;
	char in;
	bool win=false;
	gotoxy(71,0);	printf("��������������������������������������ͻ");
	for(y=1;y<=19;y++)
	{
		gotoxy(71,y);	printf("�");
		gotoxy(110,y);	printf("�");
	}
	gotoxy(71,20);	printf("��������������������������������������ͼ");
	
	srand(time(NULL));
	
	x2=rand()%30+75;
	y2=rand()%10+5;
	x=x2+1;
	y=y2+1;
	do
	{
		if(x2==x&&y2==y)
		{
			if(pemain[giliran].com)
			{
				x2=x+1;
				y2=y+1;
			}
			else{
				x2=rand()%30+75;
				y2=rand()%10+5;
			}
				
			score++;
		}
		gotoxy(75,22);	printf("Score : %3d",score);
		gotoxy(x2,y2);	printf("%c",15);
		gotoxy(x,y);	printf("%c",1);
		
		if(pemain[giliran].com)
		{
			int co=rand()%4;
			if(co==0)
			{
				in='w';
			}
			else if(co==1)
			{
				in='a';
			}
			else if(co==2)
			{
				in='s';
			}
			else
			{
				in='d';
			}
		}
		else
		{
			if(kbhit()){
				in=getch();
			}
		}
		gotoxy(x,y);	printf(" ");
			if(in=='w')
			{
				y--;
			}
			else if(in=='a')
			{
				x--;
			}
			else if(in=='s')
			{
				y++;
			}
			else if(in=='d')
			{
				x++;
			}
			
			if(y>=20||y<=0||x>=110||x<=71)
			{
				win=true;
			}	
					
		gotoxy(x,y);	printf("%c",1);
		Sleep(30);
	}while(!win);
	int i,pindah;
	if(giliran==1)
	{
		
		i=0;
	}
	else
	{
		i=1;
	}
	pindah=pemain[i].gerak;
	pemain[i].gerak-=score;
	if(pemain[i].gerak<0)
	{
		pemain[i].gerak=0;
	}
	for(x=0;x<10;x++)
	{
		tamp_pem(pindah,i*3,i+4);
		Sleep(100);
		tamp_pem(pindah,i*3,0);
		Sleep(30);
	}
	while(pindah>=pemain[i].gerak)
	{
		tamp_pem(pindah+1,i*3,0);
		tamp_pem(pindah,i*3,i+4);
		Sleep(300);
		pindah--;
	}
	petak(i);
}

void mainMenu()
{
	int select,aktif;
	aktif=24;
	
	setcolor(7);
	gotoxy(35,18);  printf("��������������������������������������ͻ");
	gotoxy(35,19); 	printf("�                                      �");
	gotoxy(35,20); 	printf("�         ULAR TANGGA BAGONG           �");
	gotoxy(35,21); 	printf("�                                      �");
	gotoxy(35,22); 	printf("��������������������������������������ͺ");
	gotoxy(35,23); 	printf("�                                      �");
	gotoxy(35,24); 	printf("�          Play                        �");
	gotoxy(35,25); 	printf("�          Tutorial                    �");
	gotoxy(35,26); 	printf("�          About                       �");
	gotoxy(35,27); 	printf("�          Exit                        �");	
	gotoxy(35,28); 	printf("�                                      �");
	gotoxy(35,29); 	printf("��������������������������������������ͼ");
	setcolor(11);
	gotoxy(43,24);  printf("%c",26);
	while(select!=1)
	{
		gotoxy(43,aktif);
		switch(getch())
		{
			case 80 :
				aktif+=1;
				break;
			case 72 :
				aktif-=1;
				break;
			case 13 :
				select=1;
				break;
		}

		if(aktif>27)
			aktif=24;
		if(aktif<24)
			aktif=27;
		printf(" ");
		gotoxy(43,aktif);	printf("%c",26);
	}

	switch(aktif){
		case 24 :
			play();
			mainMenu();
			break;
		case 25 :
			mainMenu();
			
			break;
		case 26 :
			mainMenu();
			
			break;
		case 27:
			gotoxy(100,35);
			exit(0);
			break;
	}
}

void kocok_dadu(int *dadu,int giliran)
{
	clear();
	int i,pindah;
	pindah=pemain[giliran].gerak;
	if(pemain[giliran].com==false)
	{
		gotoxy(70,2);	printf("%s%c%c, giliran anda",pemain[giliran].nama,179,giliran+4);
		gotoxy(70,3);	printf("Tekan spasi untuk mengocok dadu");
		getch();
	}
		else
		{
			gotoxy(70,2);	printf("Giliran COM");
			gotoxy(70,3);	printf("Silahkan menunggu");
		}
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		*dadu=rand()%6+1;
		tamp_dadu(*dadu);
//		*dadu=14;
		Sleep(150);
	}
	gotoxy(70,13);	printf("Berjalan %d langkah",*dadu);
	Sleep(300);
	pemain[giliran].gerak+=*dadu;
	while(pindah<=pemain[giliran].gerak)
	{
		tamp_pem(pindah-1,giliran*3,0);
		tamp_pem(pindah,giliran*3,giliran+4);
		Sleep(300);
		pindah++;
	}
	if(pemain[giliran].com==false)
	{
		gotoxy(70,16);	printf("Tekan spasi untuk lanjut");
		getch();
	}
}

void clear()
{
	for(int y=0;y<40;y++)
	{
		gotoxy(70,y);	printf("                                          ");
	}
}

void map()
{
	system("cls");
	
	setcolor(13);
	printf("�����������%c����������%c����������%c����������%c����������%c���������ͻ\n",203,203,203,203,203);
	printf("�  FINISH  �          �          �          �          �          �\n");
	printf("�          �          �          �          �          �          �\n");
	printf("�          �          �          �          �          �          �\n");
	printf("�          �          �   %c  %c   �          �          �          �\n",30,30);
	printf("�          �       34 �   %c  %c   �       32 �       31 �       30 �\n",30,30);
	setcolor(14);
	printf("%c�������������������������%c  %c������������������������������������%c\n",204,30,30,185);
	printf("�          �          �   %c  %c   �          �          �          �\n",30,30);
	printf("�          �          �   %c  %c   �          �          �          �\n",30,30);
	printf("�          �          �          �          �          �          �\n");
	printf("�          �          �          �          �          �          �\n");
	printf("�       24 �       25 �       26 �       27 �       28 �       29 �\n");
	setcolor(11);
	printf("%c����������%c����������%c����������%c����������%c����������%c����������%c\n",204,206,206,206,206,206,185);
	printf("�          �          �          �          �          �          �\n");
	printf("�      	   �          �          �   GAMES  �          �          �\n");
	printf("�          �          �          �          �          �          �\n");
	printf("�   %c  %c   �          �          �          �          �          �\n",31,31);
	printf("�   %c  %c   �       22 �       21 �       20 �       19 �       18 �\n",31,31);
	setcolor(12);
	printf("%c���%c  %c����������������������������������������������������������%c\n",204,31,31,185);
	printf("�   %c  %c   �          �          �          �          �          �\n",31,31);
	printf("�   %c  %c   �          �   GAMES  �          �          �          �\n",31,31);
	printf("�          �          �          �          �          �          �\n");
	printf("�          �          �          �   %c  %c   �          �          �\n",254,254);
	printf("�       12 �       13 �       14 �  %c  %c 15 �       16 �       17 �\n",254,254);
	setcolor(3);
	printf("%c����������������������������������%c  %c���������������������������%c\n",204,254,254,185);
	printf("�          �          �          �%c  %c      �          �          �\n",254,254);
	printf("�          �          �          %c  %c       �          �          �\n",254,254);
	printf("�          �          �         %c  %c        �          �          �\n",254,254);
	printf("�          �          �        %c  %c         �          �          �\n",254,254);
	printf("�       11 �       10 �       %c  %c        8 �        7 �        6 �\n",254,254);
	setcolor(10);
	printf("%c����������������������������%c  %c���������������������������������%c\n",204,254,254,185);
	printf("�          �          �     %c  %c �          �          �          �\n",254,254);
	printf("�          �          �    %c  %c  �          �          �          �\n",254,254);
	printf("�          �          �          �          �          �          �\n");
	printf("�          �          �          �          �          �          �\n");
	printf("�  START   �        1 �        2 �        3 �        4 �        5 �\n");
	printf("�����������%c����������%c����������%c����������%c����������%c���������ͼ\n",202,202,202,202,202);
	
	tamp_pem(0,0,4);
	tamp_pem(0,3,5);
}

void tamp_pem(int gerak,int jarak,int bidak)
{
	switch(gerak){
		case 0:
			gotoxy(4+jarak,33);		printf("%c",bidak);
			break;
		case 1:
			gotoxy(15+jarak,33);	printf("%c",bidak);
			break;
		case 2:
			gotoxy(26+jarak,33);	printf("%c",bidak);
			break;
		case 3:
			gotoxy(37+jarak,33);	printf("%c",bidak);
			break;
		case 4:
			gotoxy(48+jarak,33);	printf("%c",bidak);
			break;
		case 5:
			gotoxy(59+jarak,33);	printf("%c",bidak);
			break;
		case 6:
			gotoxy(59+jarak,27);	printf("%c",bidak);
			break;
		case 7:
			gotoxy(48+jarak,27);	printf("%c",bidak);
			break;
		case 8:
			gotoxy(37+jarak,27);	printf("%c",bidak);
			break;
		case 9:
			gotoxy(26+jarak,27);	printf("%c",bidak);
			break;
		case 10:
			gotoxy(15+jarak,27);	printf("%c",bidak);
			break;
		case 11:
			gotoxy(4+jarak,27);		printf("%c",bidak);
			break;
		case 12:
			gotoxy(4+jarak,21);		printf("%c",bidak);
			break;
		case 13:
			gotoxy(15+jarak,21);	printf("%c",bidak);
			break;
		case 14:
			gotoxy(26+jarak,21);	printf("%c",bidak);
			break;
		case 15:
			gotoxy(37+jarak,21);	printf("%c",bidak);
			break;
		case 16:
			gotoxy(48+jarak,21);	printf("%c",bidak);
			break;
		case 17:
			gotoxy(59+jarak,21);	printf("%c",bidak);
			break;
		case 18:
			gotoxy(59+jarak,15);	printf("%c",bidak);
			break;
		case 19:
			gotoxy(48+jarak,15);	printf("%c",bidak);
			break;
		case 20:
			gotoxy(37+jarak,15);	printf("%c",bidak);
			break;
		case 21:
			gotoxy(26+jarak,15);	printf("%c",bidak);
			break;
		case 22:
			gotoxy(15+jarak,15);	printf("%c",bidak);
			break;
		case 23:
			gotoxy(4+jarak,15);		printf("%c",bidak);
			break;
		case 24:
			gotoxy(4+jarak,9);		printf("%c",bidak);
			break;
		case 25:
			gotoxy(15+jarak,9);		printf("%c",bidak);
			break;
		case 26:
			gotoxy(26+jarak,9);		printf("%c",bidak);
			break;
		case 27:
			gotoxy(37+jarak,9);		printf("%c",bidak);
			break;
		case 28:
			gotoxy(48+jarak,9);		printf("%c",bidak);
			break;
		case 29:
			gotoxy(59+jarak,9);		printf("%c",bidak);
			break;
		case 30:
			gotoxy(59+jarak,3);		printf("%c",bidak);
			break;
		case 31:
			gotoxy(48+jarak,3);		printf("%c",bidak);
			break;
		case 32:
			gotoxy(37+jarak,3);		printf("%c",bidak);
			break;
		case 33:
			gotoxy(26+jarak,3);		printf("%c",bidak);
			break;
		case 34:
			gotoxy(15+jarak,3);		printf("%c",bidak);
			break;
		case 35:
			gotoxy(4+jarak,3);		printf("%c",bidak);
			break;
	}
}

void tamp_dadu(int dadu)
{
	switch(dadu)
	{
		case 1:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("�     �");
			gotoxy(80,8);	printf("�  o  �");
			gotoxy(80,9);	printf("�     �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
		case 2:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("�     �");
			gotoxy(80,8);	printf("� o o �");
			gotoxy(80,9);	printf("�     �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
		case 3:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("�   o �");
			gotoxy(80,8);	printf("�  o  �");
			gotoxy(80,9);	printf("� o   �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
		case 4:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("� o o �");
			gotoxy(80,8);	printf("�     �");
			gotoxy(80,9);	printf("� o o �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
		case 5:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("� o o �");
			gotoxy(80,8);	printf("�  o  �");
			gotoxy(80,9);	printf("� o o �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
		case 6:
			gotoxy(80,6);	printf("�����ͻ");
			gotoxy(80,7);	printf("� o o �");
			gotoxy(80,8);	printf("� o o �");
			gotoxy(80,9);	printf("� o o �");
			gotoxy(80,10);	printf("�����ͼ");
			break;
	}
}
