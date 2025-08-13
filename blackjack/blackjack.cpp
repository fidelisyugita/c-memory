

#include"blackjack.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

void color(int text,char background){ 
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, background<<4 | text);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Count(address Player){
	address temp,cekAs;
	int Jumlah=0;
	temp=Player;
	cekAs=Player;
	while(temp!=NULL){
		if((temp)->isi%13+1>10){
			Jumlah=Jumlah+10;
		}else{
			Jumlah=Jumlah+(temp)->isi%13+1;
		}
			if((temp)->isi%13+1==1){
				Jumlah=Jumlah+10;
			}
		temp=(temp)->next;
	}
		while(cekAs!=NULL){
			if((cekAs)->isi%13+1==1){
				if(Jumlah>21){
					Jumlah=Jumlah-10;
				}
			}
			cekAs=(cekAs)->next;
		}
		return Jumlah;
}

void clear(){
	int i;
	color(0,0);
	for(i=0;i<15;i++){
		gotoxy(0,12+i);
		printf("                                                     ");
		printf("                                                    ");
	}
}

void turn(address *deck,address *pemain,bool *tambah,int pos){
	lagi(&(*tambah),pos);
	if(*tambah){
		bagiKartu(&(*deck),&(*pemain));
	}
	clear();
}

void Banker(address *deck,address *Banker){
	int j=1;
	while(Count(*Banker)<13){
		j++;
		bagiKartu(&(*deck),&(*Banker));
		lihat(*Banker,0,j,false);
	}
	if(Count(*Banker)<17){
		if(rand()%2==1){
			j++;
			bagiKartu(&(*deck),&(*Banker));
			lihat(*Banker,0,j,false);
		}
	}
}
void Winner(address Player, address Banker,int i){
	color(15,0);
	gotoxy(35,15);
	if((Count(Player)>Count(Banker)&&Count(Player)<21)||(Count(Player)<=21&&Count(Banker)>21)){
		printf("Player %d Anda Menang",i+1);
	}else{
		printf("Player %d Anda Kalah",i+1);
	}
}

void lagi(bool *tambah,int pos){
	int kursor=21;
	bool end=false;
	
	clear();
	color(6,0);
	gotoxy(38,15);  printf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
	gotoxy(38,16); 	printf("∫                  ∫");
	gotoxy(38,17); 	printf("∫     Pemain %d     ∫",pos+1);
	gotoxy(38,18); 	printf("∫  ÕÕÕÕÕÕÕÕÕÕÕÕÕÕ  ∫");
	gotoxy(38,19); 	printf("∫  Tambah Kartu??  ∫");
	gotoxy(38,20); 	printf("∫                  ∫");
	gotoxy(38,21); 	printf("∫      Ya          ∫");
	gotoxy(38,22); 	printf("∫      Tidak       ∫");
	gotoxy(38,23); 	printf("∫                  ∫");
	gotoxy(38,24); 	printf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
	gotoxy(43,21);  printf("%c",26);
	while(!end){
		gotoxy(43,kursor);
		switch(getch()){
			case 80 :
				kursor+=1;	break;
			case 72 :
				kursor-=1;	break;
			case 13 :
				end=true;	break;
		}
		if(kursor>22){
			kursor = 21;
		}
		if(kursor<21){
			kursor = 22;
		}
		printf(" ");
		gotoxy(43,kursor);	printf("%c",26);
	}
	if(kursor==22){
		*tambah=false;
	}
}

void shuffle(address *deck,int jmlKartu){
	int i,j,pos;
	address p;
	srand(time(NULL));
	*deck=alokasi(1);
	for(i=2;i<=jmlKartu;i++){
		p=(*deck);
		pos=rand()%i;
		if(pos==0){
			push(&(*deck),i);
		}else{
			for(j=1;j<pos;j++){
				p=p->next;
			}
			insertAfter(&p,i);
		}
	}
}

void push(address *p,int isi){
	address pNew=alokasi(isi);
	pNew->next=(*p);
	(*p)=pNew;
}

void pop(address *p,int *isi){
	address pDel=(*p);
	(*p)=(*p)->next;
	pDel->next=NULL;
	*isi=pDel->isi;
	free(pDel);
}

//void insertAfter(address *p,int isi){
//	address pNew=alokasi(isi);
//	pNew->next=(*p)->next;
//	(*p)->next=pNew;
//}

address alokasi(int isi){
	address p;
	p=(address) malloc (sizeof(KARTU));
	if(p==NULL){
		printf("\nAlokasi gagal!");
	}else{
		(p)->next=NULL;
		(p)->isi=isi;
	}
	return p;
}

void bagiKartu(address *deck,address *pemain){
	int isi;
	pop(&(*deck),&isi);
	push(&(*pemain),isi);
	clear();
	color(6,0);
	gotoxy(38,15);  printf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
	gotoxy(38,16); 	printf("∫                  ∫");
	gotoxy(38,17); 	printf("∫    Bagi kartu    ∫");
	gotoxy(38,18); 	printf("∫  ÕÕÕÕÕÕÕÕÕÕÕÕÕÕ  ∫");
	gotoxy(38,19); 	printf("∫ Silahkan  tunggu ∫");
	gotoxy(38,20); 	printf("∫                  ∫");
	gotoxy(38,21); 	printf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
	Sleep(1000);
}

void lihat(address p,int pos,int kartuKe,bool tutup){
	int i=0;
	address q=p;
	while(q!=NULL){
		q=q->next;
		i++;
	}
	if(i==kartuKe+1){
		tampKartu(pos,kartuKe,p->isi,tutup);
	}
}

void tampKartu(int posisi,int kartuKe,int nilai,bool tutup){
	int i,x,y;
	color(9,0);
	switch(posisi){
		case 0:
			x=40;
			y=5;
			gotoxy(x+5,y-1);	printf("Banker");
			x+=8*(kartuKe);
			break;
		case 1:
			x=40;
			y=45;
			gotoxy(x+4,y-1);	printf("Pemain 1");
			x+=8*(kartuKe);
			break;
		case 2:
			x=30;
			y=35;
			gotoxy(x-4,y-1);	printf("Pemain 2");
			if(kartuKe>3){
				y-=8;
				x-=8*(kartuKe-4);
			}else{
				x-=8*(kartuKe);
			}
			break;
		case 3:
			x=65;
			y=35;
			gotoxy(x+4,y-1);	printf("Pemain 3");
			if(kartuKe>3){
				y-=8;
				x+=8*(kartuKe-4);
			}else{
				x+=8*(kartuKe);
			}
			break;
	}
	color(2,0);
	gotoxy(x,y);		printf("…ÕÕÕÕÕª");
	for(i=1;i<=5;i++){
		gotoxy(x,y+i);	printf("∫     ∫");
	}
	gotoxy(x,y+6);		printf("»ÕÕÕÕÕº");
	
	for(i=1;i<=5;i++){
		gotoxy(x+1,y+i);
		if(tutup){
			printf("%c%c%c%c%c",176,176,176,176,176);
		}else{
			color(15,15);
			printf("     ");
		}
	}
	if(!tutup){
		gotoxy(x+2,y+3);	tampIsi(nilai);
	}
	Sleep(100);
}

void tampIsi(int nilai){
	int jenis=3;
	int isi;
	color(12,15);
	if(nilai>13){
		jenis++;
		if(nilai>26){
			color(0,15);
			jenis++;
			if(nilai>39){
				jenis++;
			}
		}
	}
	isi=nilai%13+1;
	switch(isi){
		case 11:
			printf("%c J",jenis);
			break;
		case 12:
			printf("%c Q",jenis);
			break;
		case 13:
			printf("%c K",jenis);
			break;
		case 1:
			printf("%c A",jenis);
			break;
		default:
			printf("%c%2d",jenis,isi);
			break;
	}
}

void menu(){
	system("MODE 105,55");
	int kursor=24;
	bool end=false;
	
	color(6,0);
	gotoxy(35,18);  printf("       …ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª       ");
	gotoxy(35,19); 	printf("       ∫                  ∫       ");
	gotoxy(35,20); 	printf("       ∫     BLACKJACK    ∫       ");
	gotoxy(35,21); 	printf("       ∫                  ∫       ");
	gotoxy(35,22); 	printf("       ∫  ÕÕÕÕÕÕÕÕÕÕÕÕÕÕ  ∫       ");
	gotoxy(35,23); 	printf("       ∫                  ∫       ");
	gotoxy(35,24); 	printf("       ∫      Mulai       ∫       ");
	gotoxy(35,25); 	printf("…ÕÕÕÕÕÕ∫      Keluar      ∫ÕÕÕÕÕÕª");
	gotoxy(35,26); 	printf("∫€€€€€€∫                  ∫€€€€€€∫");	
	gotoxy(35,27); 	printf("∫€€€€€€∫                  ∫€€€€€€∫");
	gotoxy(35,28); 	printf("∫€€€€€€»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº€€€€€€∫");
	gotoxy(35,29); 	printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,30); 	printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,31); 	printf("∫€€€€€…Õª€€€€€€…ÕÕª€€€€€€…Õª€€€€€∫");
	gotoxy(35,32);  printf("∫   …Õº »Õª    »ÕÕº    …Õº »Õª   ∫");
	gotoxy(35,33);  printf("∫   »Õª …Õº    …ÕÕª    »Õª …Õº   ∫");
	gotoxy(35,34);  printf("∫€€€€€»Õº€€€€€€»ÕÕº€€€€€€»Õº€€€€€∫");
	gotoxy(35,35);  printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,36);  printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,37);  printf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
	gotoxy(46,24);  printf("%c",26);
	while(!end){
		gotoxy(46,kursor);
		switch(getch()){
			case 80 :
				kursor+=1;	break;
			case 72 :
				kursor-=1;	break;
			case 13 :
				end=true;	break;
		}
		if(kursor>25){
			kursor = 24;
		}
		if(kursor<24){
			kursor = 25;
		}
		printf(" ");
		gotoxy(46,kursor);	printf("%c",26);
	}
	system("cls");
	if(kursor==25){
		exit(0);
	}
}

void player(int *n){
	int kursor=24;
	bool end=false;
	
	gotoxy(35,18);  printf("       …ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª       ");
	gotoxy(35,19); 	printf("       ∫                  ∫       ");
	gotoxy(35,20); 	printf("       ∫   Jumlah Pemain  ∫       ");
	gotoxy(35,21); 	printf("       ∫                  ∫       ");
	gotoxy(35,22); 	printf("       ∫  ÕÕÕÕÕÕÕÕÕÕÕÕÕÕ  ∫       ");
	gotoxy(35,23); 	printf("       ∫                  ∫       ");
	gotoxy(35,24); 	printf("       ∫     1 Pemain     ∫       ");
	gotoxy(35,25); 	printf("…ÕÕÕÕÕÕ∫     2 Pemain     ∫ÕÕÕÕÕÕª");
	gotoxy(35,26); 	printf("∫€€€€€€∫     3 Pemain     ∫€€€€€€∫");	
	gotoxy(35,27); 	printf("∫€€€€€€∫                  ∫€€€€€€∫");
	gotoxy(35,28); 	printf("∫€€€€€€»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº€€€€€€∫");
	gotoxy(35,29); 	printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,30); 	printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,31); 	printf("∫€€€€€…Õª€€€€€€…ÕÕª€€€€€€…Õª€€€€€∫");
	gotoxy(35,32);  printf("∫   …Õº »Õª    »ÕÕº    …Õº »Õª   ∫");
	gotoxy(35,33);  printf("∫   »Õª …Õº    …ÕÕª    »Õª …Õº   ∫");
	gotoxy(35,34);  printf("∫€€€€€»Õº€€€€€€»ÕÕº€€€€€€»Õº€€€€€∫");
	gotoxy(35,35);  printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,36);  printf("∫€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€∫");
	gotoxy(35,37);  printf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
	gotoxy(46,24);  printf("%c",26);
	while(!end){
		gotoxy(46,kursor);
		switch(getch()){
			case 80 :
				kursor+=1;	break;
			case 72 :
				kursor-=1;	break;
			case 13 :
				end=true;	break;
		}
		if(kursor>26){
			kursor = 24;
		}
		if(kursor<24){
			kursor = 26;
		}
		printf(" ");
		gotoxy(46,kursor);	printf("%c",26);
	}
	system("cls");
	*n=kursor-23;
}
