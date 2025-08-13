#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setcolor(unsigned short color) { 
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hCon,color); 
}

void arena(){
	gotoxy(0,1);	printf("|     Bebas    Setiabudhi |   Ledeng   |            |   %c%c%c%c%c%c   |    PDAM    |  Sukajadi  |  Cipaganti |            |",31,31,31,31,31,31);
	gotoxy(0,2);	printf("|  Parkir                 |            | Mimilikan  |            |            |            |            | Pengadilan |");
	gotoxy(0,5);	printf("                                                         %c%c%c%c                                                         ",31,31,31,31);
	gotoxy(0,7);	printf("|                                                                                                       |            |");
	gotoxy(0,8);	printf("|    Coin                                                                                               |    Games   |");
	gotoxy(0,13);	printf("| Ciumbuleuit                                                                                           |   Cibodas  |");
	gotoxy(0,20);	printf("|  Mimilikan                                                                                            |  Mimilikan |");
	gotoxy(0,21);	printf("|                                                                                                       |            |");
	gotoxy(0,25);	printf("|   Cisitu                                                                                              |    Dago    |");
	gotoxy(0,31);	printf("|  Terminal                                                                                             |   Bandara  |");
	gotoxy(0,32);	printf("|                                                                                                       |            |");
	gotoxy(0,37);	printf("| Setra Duta                                                                                            | Padjajaran |");
	gotoxy(0,43);	printf("|  Antapani                                                                                             |  Cicaheum  |");
	gotoxy(0,49);	printf("|                                                                                                       |            |");
	gotoxy(0,50);	printf("|   Games                                                                                               |    Coin    |");
	gotoxy(0,55);	printf("|              Cihanjuang | Parongpong |    PLN     |    %c%c%c%c    |            |  Gerlong   |  Sarijadi  |   Mulai    |",30,30,30,30);
	gotoxy(0,56);	printf("|   Penjara               |            |            |            |  Mimilikan |            |            |            |");
	gotoxy(0,59);	printf("|                         |            |            |   %c%c%c%c%c%c   |            |            |            |            |",30,30,30,30,30,30);
	int x,y,c=13,d=6,a=c*9,b=d*10;
	for(x=0;x<=a;x++){
		for(y=0;y<=b;y++){
			if(x%c==0||y%d==0){
				if((x==c&&y==d)||(x==a-c&&y==d)||(x==c&&y==b-d||(x==a-c&&y==b-d))){
					gotoxy(x,y);	printf("%c",206);
				}else if(x==0&&y==0){
					gotoxy(x,y);	printf("%c",201);
				}else if(x==a&&y==0){
					gotoxy(x,y);	printf("%c",187);
				}else if(x==0&&y==b){
					gotoxy(x,y);	printf("%c",200);
				}else if(x==a&&y==b){
					gotoxy(x,y);	printf("%c",188);
				}else if((x==0||x==a-c)&&(y==d||y==b-d||y%d==0)&&(y>=d&&y<=b-d)){
					gotoxy(x,y);	printf("%c",204);
				}else if((x==a||x==c)&&(y==d||y==b-d||y%d==0)&&(y>=d&&y<=b-d)){
					gotoxy(x,y);	printf("%c",185);	
				}else if((y==0||y==b-d)&&(x==c||x==a-c||x%c==0)){
					gotoxy(x,y);	printf("%c",203);
				}else if((y==b||y==d)&&(x==c||x==a-c||x%c==0)){
					gotoxy(x,y);	printf("%c",202);
				}else if(x==0||x==c||x==a-c||x==a){
					gotoxy(x,y);	printf("%c",186);
				}else if(y==0||y==d||y==b-d||y==b){
					gotoxy(x,y);	printf("%c",205);
				}else if(y<=d||y>=b-d){
					gotoxy(x,y);	printf("%c",186);
				}else if(x<=c||x>=a-c){
					gotoxy(x,y);	printf("%c",205);
				}
			}
		}
	}
}

void clear(){
	for(int y=8;y<=42;y++){
		gotoxy(15,y);	printf("                                                                                        ");
	}
}
void chance(){
	gotoxy(16,44);	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	for(int y=45;y<=51;y++){
		gotoxy(16,y);	printf("%c                                   %c",186,186);
	}
	gotoxy(16,52);	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void chance2(){
	gotoxy(17,46);	printf(" **  *   *    *    *   *   **  ****");
	gotoxy(17,47);	printf("*    *   *   * *   **  *  *    *   ");
	gotoxy(17,48);	printf("*    *****  *****  * * *  *    *** ");
	gotoxy(17,49);	printf("*    *   *  *   *  *  **  *    *   ");
	gotoxy(17,50);	printf(" **  *   *  *   *  *   *   **  ****");
}

struct PEMAIN{
	char nama[10];
	int karakter,uang,gerak,penjara_roll,penjara_roll2,putaran;
	bool penjara,bebas_penjara;
}pemain[4];

struct PETAK{
	char nama[20];
	int harga_jual,harga_beli,harga_sewa,upgrade,no_pemilik,no_tanah;
	bool pemilik;
}tanah[16],tanah2[4];

int jum_pem;

void deklarasi(){
	int i;
	for(i=0;i<jum_pem;i++){
		pemain[i].gerak=0;
		pemain[i].penjara=false;
		pemain[i].bebas_penjara=false;
		pemain[i].penjara_roll=0;
		pemain[i].penjara_roll2=3;
		pemain[i].putaran=0;
	}
	for(i=0;i<4;i++){
		tanah2[i].harga_beli=200;
		tanah2[i].harga_sewa=50;
		tanah2[i].pemilik=false;
		tanah2[i].upgrade=0;
		tanah2[i].no_pemilik=-1;
	}
	for(i=0;i<16;i++){
		tanah[i].pemilik=false;
		tanah[i].upgrade=0;
		tanah[i].no_pemilik=-1;
	}
	
	tanah[0].no_tanah=1;
	strcpy(tanah[0].nama,"Sarijadi");
	tanah[0].harga_beli=50;
	tanah[0].harga_jual=25;
	tanah[0].harga_sewa=27;
	
	tanah[1].no_tanah=2;
	strcpy(tanah[1].nama,"Gerlong");
	tanah[1].harga_beli=62;
	tanah[1].harga_jual=32;
	tanah[1].harga_sewa=40;
	
	tanah[2].no_tanah=6;
	strcpy(tanah[2].nama,"Parongpong");
	tanah[2].harga_beli=92;
	tanah[2].harga_jual=45;
	tanah[2].harga_sewa=70;
	
	tanah[3].no_tanah=7;
	strcpy(tanah[3].nama,"Cihanjuang");
	tanah[3].harga_beli=100;
	tanah[3].harga_jual=50;
	tanah[3].harga_sewa=77;
	
	tanah[4].no_tanah=10;
	strcpy(tanah[4].nama,"Antapani");
	tanah[4].harga_beli=107;
	tanah[4].harga_jual=52;
	tanah[4].harga_sewa=80;
	
	tanah[5].no_tanah=11;
	strcpy(tanah[5].nama,"Setra Duta");
	tanah[5].harga_beli=122;
	tanah[5].harga_jual=60;
	tanah[5].harga_sewa=90;
	
	tanah[6].no_tanah=13;
	strcpy(tanah[6].nama,"Cisitu");
	tanah[6].harga_beli=137;
	tanah[6].harga_jual=72;
	tanah[6].harga_sewa=97;
	
	tanah[7].no_tanah=15;
	strcpy(tanah[7].nama,"Ciumbuleuit");
	tanah[7].harga_beli=150;
	tanah[7].harga_jual=72;
	tanah[7].harga_sewa=117;
	
	tanah[8].no_tanah=18;
	strcpy(tanah[8].nama,"Setiabudhi");
	tanah[8].harga_beli=162;
	tanah[8].harga_jual=82;
	tanah[8].harga_sewa=127;
	
	tanah[9].no_tanah=19;
	strcpy(tanah[9].nama,"Ledeng");
	tanah[9].harga_beli=177;
	tanah[9].harga_jual=90;
	tanah[9].harga_sewa=132;
	
	tanah[10].no_tanah=23;
	strcpy(tanah[10].nama,"Sukajadi");
	tanah[10].harga_beli=185;
	tanah[10].harga_jual=92;
	tanah[10].harga_sewa=140;
	
	tanah[11].no_tanah=24;
	strcpy(tanah[11].nama,"Cipaganti");
	tanah[11].harga_beli=200;
	tanah[11].harga_jual=102;
	tanah[11].harga_sewa=147;
	
	tanah[12].no_tanah=27;
	strcpy(tanah[12].nama,"Cibodas");
	tanah[12].harga_beli=207;
	tanah[12].harga_jual=115;
	tanah[12].harga_sewa=157;
	
	tanah[13].no_tanah=29;
	strcpy(tanah[13].nama,"Dago");
	tanah[13].harga_beli=222;
	tanah[13].harga_jual=127;
	tanah[13].harga_sewa=165;
	
	tanah[14].no_tanah=31;
	strcpy(tanah[14].nama,"Padjajaran");
	tanah[14].harga_beli=235;
	tanah[14].harga_jual=132;
	tanah[14].harga_sewa=172;
	
	tanah[15].no_tanah=32;
	strcpy(tanah[15].nama,"Cicaheum");
	tanah[15].harga_beli=250;
	tanah[15].harga_jual=150;
	tanah[15].harga_sewa=188;
}

void tamp_dadu(int dadu,int jarak){
	switch(dadu){
		case 1:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c     %c",179,179);
			gotoxy(51+jarak,30);	printf("%c  *  %c",179,179);
			gotoxy(51+jarak,31);	printf("%c     %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
		case 2:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c     %c",179,179);
			gotoxy(51+jarak,30);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,31);	printf("%c     %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
		case 3:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c   * %c",179,179);
			gotoxy(51+jarak,30);	printf("%c  *  %c",179,179);
			gotoxy(51+jarak,31);	printf("%c *   %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
		case 4:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,30);	printf("%c     %c",179,179);
			gotoxy(51+jarak,31);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
		case 5:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,30);	printf("%c  *  %c",179,179);
			gotoxy(51+jarak,31);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
		case 6:
			gotoxy(51+jarak,28);	printf("%c%c%c%c%c%c%c",218,196,196,196,196,196,191);
			gotoxy(51+jarak,29);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,30);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,31);	printf("%c * * %c",179,179);
			gotoxy(51+jarak,32);	printf("%c%c%c%c%c%c%c",192,196,196,196,196,196,217);
			break;
	}
}

void tamp_pemain(int pindah,int urutan,int bidak,int cord_y){
	int warna=urutan;
	if(urutan>=4&&urutan<8){
		warna=urutan-4;
		urutan-=3;
	}else if(urutan>=8){
		warna=urutan-8;
		urutan-=9;
	}
	setcolor(warna+9);
	switch(pindah){
		case 0:
			gotoxy(urutan-2+111,57+cord_y);		printf("%c",bidak);
			break;
		case 1:
			gotoxy(urutan-2+98,57+cord_y);		printf("%c",bidak);
			break;
		case 2:
			gotoxy(urutan-2+85,57+cord_y);		printf("%c",bidak);
			break;
		case 3:
			gotoxy(urutan-2+72,57+cord_y);		printf("%c",bidak);
			break;
		case 4:
			gotoxy(urutan-2+59,57+cord_y);		printf("%c",bidak);
			break;
		case 5:
			gotoxy(urutan-2+46,57+cord_y);		printf("%c",bidak);
			break;
		case 6:
			gotoxy(urutan-2+33,57+cord_y);		printf("%c",bidak);
			break;
		case 7:
			gotoxy(urutan-2+20,57+cord_y);		printf("%c",bidak);
			break;
		case 8:
			gotoxy(urutan-2+7,57+cord_y);		printf("%c",bidak);
			break;
		case 9:
			gotoxy(urutan-2+7,51+cord_y);		printf("%c",bidak);
			break;
		case 10:
			gotoxy(urutan-2+7,45+cord_y);		printf("%c",bidak);
			break;
		case 11:
			gotoxy(urutan-2+7,39+cord_y);		printf("%c",bidak);
			break;
		case 12:
			gotoxy(urutan-2+7,33+cord_y);		printf("%c",bidak);
			break;
		case 13:
			gotoxy(urutan-2+7,27+cord_y);		printf("%c",bidak);
			break;
		case 14:
			gotoxy(urutan-2+7,21+cord_y);		printf("%c",bidak);
			break;
		case 15:
			gotoxy(urutan-2+7,15+cord_y);		printf("%c",bidak);
			break;
		case 16:
			gotoxy(urutan-2+7,9+cord_y);		printf("%c",bidak);
			break;
		case 17:
			gotoxy(urutan-2+7,3+cord_y);		printf("%c",bidak);
			break;
		case 18:
			gotoxy(urutan-2+20,3+cord_y);		printf("%c",bidak);
			break;
		case 19:
			gotoxy(urutan-2+33,3+cord_y);		printf("%c",bidak);
			break;
		case 20:
			gotoxy(urutan-2+46,3+cord_y);		printf("%c",bidak);
			break;
		case 21:
			gotoxy(urutan-2+59,3+cord_y);		printf("%c",bidak);
			break;
		case 22:
			gotoxy(urutan-2+72,3+cord_y);		printf("%c",bidak);
			break;
		case 23:
			gotoxy(urutan-2+85,3+cord_y);		printf("%c",bidak);
			break;
		case 24:
			gotoxy(urutan-2+98,3+cord_y);		printf("%c",bidak);
			break;
		case 25:
			gotoxy(urutan-2+111,3+cord_y);		printf("%c",bidak);
			break;
		case 26:
			gotoxy(urutan-2+111,9+cord_y);		printf("%c",bidak);
			break;
		case 27:
			gotoxy(urutan-2+111,15+cord_y);		printf("%c",bidak);
			break;
		case 28:
			gotoxy(urutan-2+111,21+cord_y);		printf("%c",bidak);
			break;
		case 29:
			gotoxy(urutan-2+111,27+cord_y);		printf("%c",bidak);
			break;
		case 30:
			gotoxy(urutan-2+111,33+cord_y);		printf("%c",bidak);
			break;
		case 31:
			gotoxy(urutan-2+111,39+cord_y);		printf("%c",bidak);
			break;
		case 32:
			gotoxy(urutan-2+111,45+cord_y);		printf("%c",bidak);
			break;
		case 33:
			gotoxy(urutan-2+111,51+cord_y);		printf("%c",bidak);
			break;	
	}
}
//======================================================================
void kocok_dadu(int urutan,int *dadu1,int *dadu2){
	clear();
	int i,pindah;
	pindah=pemain[urutan].gerak;
	gotoxy(42,25);	printf("            Pemain %d%c%c          ",urutan+1,179,urutan+3);
	gotoxy(42,26);	printf("           Kocok dadu !          ");
	gotoxy(42,27);	printf("        Tekan tombol spasi      ");
	getch();
	srand(time(NULL));
	for(i=0;i<10;i++){
		*dadu1=rand()%6+1;
		*dadu2=rand()%6+1;
		tamp_dadu(*dadu1,0);
		tamp_dadu(*dadu2,9);
		/*=======================================================================================================
		*dadu1=1;
		*dadu2=1;	//		 */
		Sleep(100);
	}
	pemain[urutan].gerak=*dadu1+*dadu2+pindah;
	gotoxy(42,33);	printf("Anda bergerak sebanyak %d langkah",*dadu1+*dadu2);
	while(pindah<=pemain[urutan].gerak){
		tamp_pemain(pindah-1,urutan,0,0);
		if(pindah>=34){
			pindah-=34;
			pemain[urutan].gerak-=34;
			pemain[urutan].putaran++;
			gotoxy(42,34);	printf("Melewati Mulai");
			gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
			Sleep(30);
			pemain[urutan].uang+=200;
			gotoxy(17,7);
			for(int i=0;i<jum_pem;i++){
				setcolor(i+9);
				printf("   Pemain %d%c%c  $%4d",i+1,179,i+3,pemain[i].uang);
			}
		}
		tamp_pemain(pindah,urutan,urutan+3,0);
		Sleep(300);
		pindah++;
	}
}
//======================================================================
void portal(int urutan){
	clear();
	setcolor(urutan+9);
	int y;
	if(pemain[urutan].gerak==4){
		for(y=53;y>=9;y--){
			gotoxy(57,y-1);	printf(" %c%c ",30,30);
			gotoxy(57,y);	printf("[��]");
			Sleep(35);
			gotoxy(57,y-1);	printf("    ");
			gotoxy(57,y);	printf("    ");
		}
	}else{
		for(y=8;y<=52;y++){
			gotoxy(57,y);	printf("[��]");
			gotoxy(57,y+1);	printf(" %c%c ",31,31);
			Sleep(35);
			gotoxy(57,y);	printf("    ");
			gotoxy(57,y+1);	printf("    ");
		}
	}
}
//======================================================================
void petak(int urutan);

void penjara(int urutan){
	clear();
	pemain[urutan].penjara_roll=0;
	int i,dadu1,dadu2;
	bool keluar=true;
	for(i=0;i<7;i++){
		gotoxy(1,55);	printf(" %c%c%c%c%c%c%c%c%c%c",31,31,31,31,31,31,31,31,31,31);
		gotoxy(1,56);	printf("%c",16);
		gotoxy(1,57);	printf("%c",16);
		gotoxy(1,58);	printf("%c",16);
		gotoxy(1,59);	printf(" %c%c%c%c%c%c%c%c%c%c",30,30,30,30,30,30,30,30,30,30);
		gotoxy(12,56);	printf("%c",17);
		gotoxy(12,57);	printf("%c",17);
		gotoxy(12,58);	printf("%c",17);
		Sleep(100);
		gotoxy(1,55);	printf("           ");
		gotoxy(1,56);	printf(" ");
		gotoxy(1,57);	printf(" ");
		gotoxy(1,58);	printf(" ");
		gotoxy(1,59);	printf("           ");
		gotoxy(12,56);	printf(" ");
		gotoxy(12,57);	printf(" ");
		gotoxy(12,58);	printf(" ");
		Sleep(80);
	}
	if(pemain[urutan].penjara_roll2<=0||(pemain[urutan].putaran==0&&pemain[urutan].penjara_roll2==2)){
		clear();
		gotoxy(42,25);	printf("Anda beruntung");
		gotoxy(42,26);	printf("Anda bebas dari penjara");
		getch();
		pemain[urutan].penjara=false;
		keluar=false;
		pemain[urutan].penjara_roll2=3;
		kocok_dadu(urutan,&dadu1,&dadu2);
		petak(urutan);
	}else if(pemain[urutan].penjara_roll2==3){
		gotoxy(42,25);	printf("Anda masuk penjara");
		gotoxy(42,26);	printf("Hahaha");
	}else if(pemain[urutan].bebas_penjara&&pemain[urutan].penjara_roll2==2){
		pemain[urutan].bebas_penjara=false;
		pemain[urutan].penjara=false;
		clear();
		gotoxy(42,25);	printf("Anda mempunyai kartu bebas penjara");
		gotoxy(42,26);	printf("Anda bebas dari penjara");
	}else{
		if(pemain[urutan].uang>200){
			char pilih;
			do{
				gotoxy(42,26);	printf("1. Bayar $200");
				gotoxy(42,27);	printf("2. Keberuntungan");
				gotoxy(42,25);	printf("Pilih cara kabur : ");
				pilih=getch();
			}while(pilih!='1'&&pilih!='2');
			clear();
			if(pilih=='1'){
				pemain[urutan].penjara=false;
				pemain[urutan].uang-=200;
				gotoxy(42,25);	printf("Uang anda berkurang $200");
				gotoxy(42,26);	printf("Anda bebas dari penjara");
				getch();
				gotoxy(17,7);
				for(int i=0;i<jum_pem;i++){
					setcolor(i+9);
					printf("   Pemain %d%c%c  $%4d",i+1,179,i+3,pemain[i].uang);
				}
				setcolor(urutan+9);
			}else{
				gotoxy(42,26);	printf("           Kocok dadu !          ");
				gotoxy(42,27);	printf("        Tekan tombol spasi      ");
				getch();
				srand(time(NULL));
				for(i=0;i<10;i++){
					dadu1=rand()%6+1;
					dadu2=rand()%6+1;
					tamp_dadu(dadu1,0);
					tamp_dadu(dadu2,9);
					Sleep(100);
				}
				if(dadu1==dadu2){
					pemain[urutan].penjara=false;
					gotoxy(42,33);	printf("Anda beruntung");
					gotoxy(42,34);	printf("Anda bebas dari penjara");
				}else{
					gotoxy(42,33);	printf("Maaf");
					gotoxy(42,34);	printf("Anda belum beruntung");
				}
				getch();
			}
		}else{
			gotoxy(42,26);	printf("           Kocok dadu !          ");
			gotoxy(42,27);	printf("        Tekan tombol spasi      ");
			getch();
			srand(time(NULL));
			for(i=0;i<10;i++){
				dadu1=rand()%6+1;
				dadu2=rand()%6+1;
				tamp_dadu(dadu1,0);
				tamp_dadu(dadu2,9);
				Sleep(100);
			}
			if(dadu1==dadu2){
				pemain[urutan].penjara=false;
				gotoxy(42,33);	printf("Anda beruntung");
				gotoxy(42,34);	printf("Anda bebas dari penjara");
			}else{
				gotoxy(42,33);	printf("Maaf");
				gotoxy(42,34);	printf("Anda belum beruntung");
			}
			getch();
		}
	}
	if(pemain[urutan].penjara==false&&keluar){
		pemain[urutan].penjara_roll2=3;
		kocok_dadu(urutan,&dadu1,&dadu2);
		petak(urutan);
	}else{
		pemain[urutan].penjara_roll2--;
	}
	getch();
}
//======================================================================
void head_or_tail(int hasil){
	if(hasil==1){
		gotoxy(53,25);	printf("   %C%C%C%C%C%C%C   ",220,220,220,220,220,220,220);
		gotoxy(53,26);	printf("  ���������  ");
		gotoxy(53,27);	printf(" ����������� ");
		gotoxy(53,28);	printf("������T������");
		gotoxy(53,29);	printf("������A������");
		gotoxy(53,30);	printf("������I������");
		gotoxy(53,31);	printf("������L������");
		gotoxy(53,32);	printf(" ����������� ");
		gotoxy(53,33);	printf("  ���������  ");
		gotoxy(53,34);	printf("   %C%C%C%C%C%C%C   ",223,223,223,223,223,223,223);
	}else if(hasil==2||hasil==6||hasil==4||hasil==8){
		gotoxy(53,25);	printf("     %C%C%c     ",220,220,220);
		gotoxy(53,26);	printf("    �����    ");
		gotoxy(53,27);	printf("   �������   ");
		gotoxy(53,28);	printf("  ���������  ");
		gotoxy(53,29);	printf("  ���������  ");
		gotoxy(53,30);	printf("  ���������  ");
		gotoxy(53,31);	printf("  ���������  ");
		gotoxy(53,32);	printf("   �������   ");
		gotoxy(53,33);	printf("    �����    ");
		gotoxy(53,34);	printf("     %C%C%C     ",223,223,223);
	}else if(hasil==3||hasil==7){
		gotoxy(53,25);	printf("      %C      ",220);
		gotoxy(53,26);	printf("      �      ");
		gotoxy(53,27);	printf("      �      ");
		gotoxy(53,28);	printf("      �      ");
		gotoxy(53,29);	printf("      �      ");
		gotoxy(53,30);	printf("      �      ");
		gotoxy(53,31);	printf("      �      ");
		gotoxy(53,32);	printf("      �      ");
		gotoxy(53,33);	printf("      �      ");
		gotoxy(53,34);	printf("      %C      ",223);
	}else if(hasil==5){
		gotoxy(53,25);	printf("   %C%C%C%C%C%C%C   ",220,220,220,220,220,220,220);
		gotoxy(53,26);	printf("  ���������  ");
		gotoxy(53,27);	printf(" ����������� ");
		gotoxy(53,28);	printf("������H������");
		gotoxy(53,29);	printf("������E������");
		gotoxy(53,30);	printf("������A������");
		gotoxy(53,31);	printf("������D������");
		gotoxy(53,32);	printf(" ����������� ");
		gotoxy(53,33);	printf("  ���������  ");
		gotoxy(53,34);	printf("   %C%C%C%C%C%C%C   ",223,223,223,223,223,223,223);
	}
}
//======================================================================
void mimilikan(int urutan,int giliran){
	chance();
	gotoxy(17,47);
	switch(giliran){
		case 0:
							printf("              SELAMAT              ");
			gotoxy(17,49);	printf("          PERGI KE MULAI!          ");
			getch();
			while(pemain[urutan].gerak!=0){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			break;
		case 1:
							printf("           URUS LISTRIK!           ");
			gotoxy(17,49);	printf("           PERGI KE PLN!           ");
			getch();
			while(pemain[urutan].gerak!=5){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 2:
							printf("          DASAR KRIMINAL!          ");
			gotoxy(17,49);	printf("         PERGI KE PENJARA!         ");
			getch();
			for(int i=0;i<=10;i++){
				tamp_pemain(pemain[urutan].gerak,urutan,0,0);
				tamp_pemain(8,urutan,0,0);
				tamp_pemain(8,urutan,0,1);
				tamp_pemain(8,urutan+4,0,1);
				tamp_pemain(8,urutan+8,0,1);
				Sleep(70);
				if(i!=10){
					tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
					tamp_pemain(8,urutan,urutan+3,0);
					tamp_pemain(8,urutan,241,1);
					tamp_pemain(8,urutan+4,241,1);
					tamp_pemain(8,urutan+8,241,1);
				}
				Sleep(70);
			}
			pemain[urutan].penjara_roll=0;
			pemain[urutan].gerak=8;
			tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
			pemain[urutan].penjara=true;
			petak(urutan);
			break;
		case 3:
							printf("           AYO REFRESING           ");
			gotoxy(17,49);	printf("          PERGI KE GAMES!          ");
			getch();
			while(pemain[urutan].gerak!=9){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 4:
							printf("             AYO MUDIK             ");
			gotoxy(17,49);	printf("         PERGI KE TERMINAL         ");
			getch();
			while(pemain[urutan].gerak!=12){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 5:
							printf("        TES KEBERUNTUNGANMU        ");
			gotoxy(17,49);	printf("           PERGI KE COIN           ");
			getch();
			while(pemain[urutan].gerak!=16){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 6:
							printf("          JALAN-JALAN MEN          ");
			gotoxy(17,49);	printf("       PERGI KE BEBAS PARKIR       ");
			getch();
			while(pemain[urutan].gerak!=17){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 7:
							printf("             URUS AIR!             ");
			gotoxy(17,49);	printf("           PERGI KE PDAM           ");
			getch();
			while(pemain[urutan].gerak!=22){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 8:
							printf("          DASAR KRIMINAL!          ");
			gotoxy(17,49);	printf("        PERGI KE PENGADILAN        ");
			getch();
			while(pemain[urutan].gerak!=25){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 9:
							printf("           AYO REFRESING           ");
			gotoxy(17,49);	printf("          PERGI KE GAMES!          ");
			getch();
			while(pemain[urutan].gerak!=26){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 10:
							printf("         SILAHKAN TERBANG!         ");
			gotoxy(17,49);	printf("         PERGI KE BANDARA!         ");
			getch();
			while(pemain[urutan].gerak!=30){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 11:
							printf("        TES KEBERUNTUNGANMU        ");
			gotoxy(17,49);	printf("           PERGI KE COIN           ");
			getch();
			while(pemain[urutan].gerak!=33){
				pemain[urutan].gerak++;
				if(pemain[urutan].gerak>33){
					pemain[urutan].putaran++;
					pemain[urutan].gerak=0;
					tamp_pemain(33,urutan,0,0);
					gotoxy(42,34);	printf("Uang bertambah sebanyak $200");
					pemain[urutan].uang+=200;
				}
				tamp_pemain(pemain[urutan].gerak-1,urutan,0,0);
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				Sleep(200);
			}
			petak(urutan);
			break;
		case 12:
							printf("              SELAMAT             ");
			gotoxy(17,49);	printf("         DAPAT KOMISI $300        ");
			getch();
			pemain[urutan].uang+=300;
			break;
		case 13:
							printf("         DASAR KRIMINAL!          ");
			gotoxy(17,49);	printf("           BAYAR PAJAK            ");
			getch();
			pemain[urutan].uang-=pemain[urutan].uang/3;
			break;
		case 14:
							printf("              SELAMAT             ");
			gotoxy(17,49);	printf("    AMBIL UANG SETIAP PEMAIN!     ");
			getch();
			for(int i=0;i<jum_pem;i++){
				pemain[i].uang-=30;
				pemain[urutan].uang+=30;
			}
			break;
		case 15:
							printf("               ASIK!              ");
			gotoxy(17,49);	printf("   HANCURKAN TANAH PEMAIN LAWAN   ");
			getch();
			
			break;
		case 16:
							printf("              SELAMAT             ");
			gotoxy(17,49);	printf("    DAPAT KARTU BEBAS PENJARA!    ");
			getch();
			pemain[urutan].bebas_penjara=true;
			break;
	/*	case 17:
			
			break;
		case 18:
			
			break;
		case 19:
			
			break;
		case 20:
			
			break;
		case 21:
			
			break;
		case 22:
			
			break;	//	*/
		default:
							printf("               ASIK!              ");
			gotoxy(17,49);	printf("   HANCURKAN TANAH PEMAIN LAWAN   ");
			getch();
			int y,i,pilihan[16];
			clear();
			y=1;
			for(i=0;i<16;i++){
				if(tanah[i].no_pemilik!=urutan&&tanah[i].no_pemilik!=-1){
					gotoxy(42,25+y);	printf("%d. %s",y,tanah[i].nama);
					pilihan[y]=i;
					y++;
				}
			}
			if(y>1){
				int jawab;
				do{
					gotoxy(42,25);	printf("                                      ");
					gotoxy(42,25);	printf("Pilih tanah yang mau dihancurkan: ");
					scanf("%d",&jawab);
				}while(jawab>y-1||jawab<1);
				for(i=0;i<8;i++){
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik,15,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+4,15,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+8,15,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik,15,2);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+4,15,2);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+8,15,2);
					Sleep(80);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik,0,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+4,0,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+8,0,1);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik,0,2);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+4,0,2);
					tamp_pemain(tanah[pilihan[jawab]].no_tanah,tanah[pilihan[jawab]].no_pemilik+8,0,2);
					Sleep(80);
				}
				tanah[pilihan[jawab]].no_pemilik=-1;
				tanah[pilihan[jawab]].pemilik=false;
			}else{
				gotoxy(42,25);	printf("Tidak ada tanah yang bisa dihancurkan");
			}
			getch();
			break;
	}
	getch();
	chance2();
}
//======================================================================
void bebas_parkir(){
	
}
//----------------------------------------------------------------------
bool kemenangan=false;
//======================================================================
void rumah(int urutan,int nomor){
	clear();
	char pilih;
	if(tanah[nomor].pemilik==false){
		gotoxy(42,25);	printf("Tanah belum ada pemilik");
		do{
			gotoxy(42,27);	printf("Harga tanah : $%d",tanah[nomor].harga_beli/2);
			gotoxy(42,26);	printf("Apakah anda ingin membeli? (Y/T)");
			pilih=getch();
		}while(pilih!='y'&&pilih!='Y'&&pilih!='T'&&pilih!='t');
		if(pilih=='y'||pilih=='Y'){
			if(pemain[urutan].uang<tanah[nomor].harga_beli/2){
				clear();
				gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
			}else{
				clear();
				pemain[urutan].uang-=tanah[nomor].harga_beli/2;
				tanah[nomor].pemilik=true;
				tanah[nomor].no_pemilik=urutan;
				tamp_pemain(pemain[urutan].gerak,urutan,193,1);
				gotoxy(42,25);	printf("Tanah ini menjadi milik anda");
				tanah[nomor].upgrade=1;
				gotoxy(17,7);
				for(int i=0;i<jum_pem;i++){
					setcolor(i+9);
					printf("   Pemain %d%c%c  $%4d",i+1,179,i+3,pemain[i].uang);
				}
				setcolor(urutan+9);
				if(pemain[urutan].putaran>0){
					do{
						gotoxy(42,27);	printf("A. 1 Rumah : $%d",tanah[nomor].harga_beli);
						gotoxy(42,28);	printf("B. 2 Rumah : $%d",tanah[nomor].harga_beli*2);
						gotoxy(42,29);	printf("C. Hotel   : $%d",tanah[nomor].harga_beli*3);
						gotoxy(42,26);	printf("Masukkan tambahan yang di inginkan");
						pilih=getch();
					}while(pilih!='a'&&pilih!='A'&&pilih!='b'&&pilih!='B'&&pilih!='c'&&pilih!='C');
					if(pilih=='a'||pilih=='A'){
						if(pemain[urutan].uang<tanah[nomor].harga_beli){
							clear();
							gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
						}else{
							pemain[urutan].uang-=tanah[nomor].harga_beli;
							tanah[nomor].upgrade+=2;
							tamp_pemain(pemain[urutan].gerak,urutan,30,1);
							tamp_pemain(pemain[urutan].gerak,urutan,223,2);
							clear();
							gotoxy(42,25);	printf("Terima kasih");
						}
					}else if(pilih=='b'||pilih=='B'){
						if(pemain[urutan].uang<tanah[nomor].harga_beli*2){
							clear();
							gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
						}else{
							pemain[urutan].uang-=tanah[nomor].harga_beli*2;
							tanah[nomor].upgrade+=3;
							tamp_pemain(pemain[urutan].gerak,urutan,30,1);
							tamp_pemain(pemain[urutan].gerak,urutan,223,2);
							tamp_pemain(pemain[urutan].gerak,urutan+4,30,1);
							tamp_pemain(pemain[urutan].gerak,urutan+4,223,2);
							clear();
							gotoxy(42,25);	printf("Terima kasih");
						}
					}else{
						if(pemain[urutan].uang<tanah[nomor].harga_beli*3){
							clear();
							gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
						}else{
							pemain[urutan].uang-=tanah[nomor].harga_beli*3;
							tanah[nomor].upgrade+=4;
							tamp_pemain(pemain[urutan].gerak,urutan,204,1);
							tamp_pemain(pemain[urutan].gerak,urutan+4,185,1);
							tamp_pemain(pemain[urutan].gerak,urutan,204,2);
							tamp_pemain(pemain[urutan].gerak,urutan+4,185,2);
							clear();
							gotoxy(42,25);	printf("Terima kasih");
						}
					}
				}	
			}
		}
	}else if(tanah[nomor].no_pemilik!=urutan){
		gotoxy(42,25);	printf("Tanah sudah dimiliki Pemain %d%c%c",tanah[nomor].no_pemilik+1,179,tanah[nomor].no_pemilik+3);
		gotoxy(42,26);	printf("Anda harus membayar sebanyak $%d",tanah[nomor].harga_sewa/2*tanah[nomor].upgrade);
		getch();
		if(pemain[urutan].uang<tanah[nomor].harga_sewa/2*tanah[nomor].upgrade){
			clear();
			do{
				gotoxy(42,25);	printf("Uang anda tidak cukup");
				gotoxy(42,26);	printf("1. Jual tanah");
				gotoxy(42,27);	printf("2. Minta ke Pengadilan");
				gotoxy(42,28);	printf("3. Menyerah");
				gotoxy(42,29);	printf("Masukkan pilihan ");
				pilih=getch();
			}while(pilih!='1'&&pilih!='2'&&pilih!='3');
			if(pilih=='2'){
				clear();
				int setuju;
				setuju=rand()%3;
				if(setuju==1){
					gotoxy(42,25);	printf("Anda beruntung");
					gotoxy(42,26);	printf("Berhasil membujuk Pengadilan");
					pemain[urutan].uang=46;
					pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
				}else{
					pilih='1';
					gotoxy(42,25);	printf("Anda belum beruntung");
					gotoxy(42,26);	printf("Tidak bisa membujuk Pengadilan");
					gotoxy(42,28);	printf("Jual tanah!");
				}
				getch();
			}
			if(pilih=='1'){
				bool lagi=true;
				int y,i,pilihan[16];
				do{
					clear();
					y=1;
					for(i=0;i<16;i++){
						if(tanah[i].no_pemilik==urutan){
							gotoxy(42,25+y);	printf("%d. %s",y,tanah[i].nama);
							pilihan[y]=i;
							y++;
						}
					}
					if(y>1){
						int jawab;
						do{
							gotoxy(42,25);	printf("                                ");
							gotoxy(42,25);	printf("Pilih tanah yang mau dijual: ");
							scanf("%d",&jawab);
						}while(jawab>y-1||jawab<1);
						pemain[urutan].uang+=tanah[pilihan[jawab]].harga_jual/2*tanah[pilihan[jawab]].upgrade;
						tanah[pilihan[jawab]].no_pemilik=-1;
						tanah[pilihan[jawab]].pemilik=false;
						for(i=0;i<8;i++){
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,15,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,15,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,15,2);
							Sleep(80);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,0,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,0,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,0,2);
							Sleep(80);
						}
						if(pemain[urutan].uang>tanah[nomor].harga_sewa/2*tanah[nomor].upgrade){
							lagi=false;
							pemain[urutan].uang-=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
							pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
							gotoxy(42,26+y);	printf("Jual tanah cukup");
						}
						if(lagi){
							gotoxy(42,26+y);	printf("Uang anda masih kurang");
						}
					}else{
						gotoxy(42,25);	printf("Tidak ada tanah yang bisa dijual");
						gotoxy(42,26);	printf("Anda bangkrut!");
						kemenangan=true;
					}
					getch();
					clear();
				}while(kemenangan==false&&lagi);
			}else if(pilih=='3'){
				kemenangan=true;
			}
		}else{
			pemain[urutan].uang-=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
			pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
		}
		if(pemain[urutan].uang<0){
			kemenangan=true;
		}
	}else{
		gotoxy(42,25);	printf("Tanah ini milik anda");
		if(tanah[nomor].upgrade<2){
			do{
				gotoxy(42,26);	printf("Anda ingin upgrade? (Y/T)");
				pilih=getch();
			}while(pilih!='y'&&pilih!='Y'&&pilih!='T'&&pilih!='t');
			if(pilih=='y'||pilih=='Y'){
				do{
					gotoxy(42,27);	printf("A. 1 Rumah : $%d",tanah[nomor].harga_beli);
					gotoxy(42,28);	printf("B. 2 Rumah : $%d",tanah[nomor].harga_beli*2);
					gotoxy(42,29);	printf("C. Hotel   : $%d",tanah[nomor].harga_beli*3);
					gotoxy(42,26);	printf("Masukkan tambahan yang di inginkan");
					pilih=getch();
				}while(pilih!='a'&&pilih!='A'&&pilih!='b'&&pilih!='B'&&pilih!='c'&&pilih!='C');
				if(pilih=='a'||pilih=='A'){
					if(pemain[urutan].uang<tanah[nomor].harga_beli){
						clear();
						gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
					}else{
						pemain[urutan].uang-=tanah[nomor].harga_beli;
						tanah[nomor].upgrade+=2;
						tamp_pemain(pemain[urutan].gerak,urutan,30,1);
						tamp_pemain(pemain[urutan].gerak,urutan,223,2);
						clear();
						gotoxy(42,25);	printf("Terima kasih");
					}
				}else if(pilih=='b'||pilih=='B'){
					if(pemain[urutan].uang<tanah[nomor].harga_beli*2){
						clear();
						gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
					}else{
						pemain[urutan].uang-=tanah[nomor].harga_beli*2;
						tanah[nomor].upgrade+=3;
						tamp_pemain(pemain[urutan].gerak,urutan,30,1);
						tamp_pemain(pemain[urutan].gerak,urutan,223,2);
						tamp_pemain(pemain[urutan].gerak,urutan+4,30,1);
						tamp_pemain(pemain[urutan].gerak,urutan+4,223,2);
						clear();
						gotoxy(42,25);	printf("Terima kasih");
					}
				}else{
					if(pemain[urutan].uang<tanah[nomor].harga_beli*3){
						clear();
						gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
					}else{
						pemain[urutan].uang-=tanah[nomor].harga_beli*3;
						tanah[nomor].upgrade+=4;
						tamp_pemain(pemain[urutan].gerak,urutan,204,1);
						tamp_pemain(pemain[urutan].gerak,urutan+4,185,1);
						tamp_pemain(pemain[urutan].gerak,urutan,204,2);
						tamp_pemain(pemain[urutan].gerak,urutan+4,185,2);
						clear();
						gotoxy(42,25);	printf("Terima kasih");
					}
				}
			}
		}
	}
	gotoxy(42,30);	printf("Tekan spasi untuk lanjut");
	getch();
}
//======================================================================
void rumah2(int urutan,int nomor){
	clear();
	char pilih;
	if(tanah2[nomor].pemilik==false){
		gotoxy(42,25);	printf("Tanah belum ada pemilik");
		do{
			gotoxy(42,27);	printf("Harga tanah : $%d",tanah2[nomor].harga_beli);
			gotoxy(42,26);	printf("Apakah anda ingin membeli? (Y/T)");
			pilih=getch();
		}while(pilih!='y'&&pilih!='Y'&&pilih!='T'&&pilih!='t');
		if(pilih=='y'||pilih=='Y'){
			if(pemain[urutan].uang<tanah2[nomor].harga_beli){
				clear();
				gotoxy(42,25);	printf("Uang anda tidak cukup membeli ini");
			}else{
				clear();
				pemain[urutan].uang-=tanah2[nomor].harga_beli;
				tanah2[nomor].pemilik=true;
				tanah2[nomor].no_pemilik=urutan;
				tamp_pemain(pemain[urutan].gerak,urutan,203,1);
				tamp_pemain(pemain[urutan].gerak,urutan,202,2);
				gotoxy(42,25);	printf("Tanah ini menjadi milik anda");
				tanah2[nomor].upgrade=1;
				gotoxy(17,7);
				for(int i=0;i<jum_pem;i++){
					setcolor(i+9);
					printf("   Pemain %d%c%c  $%4d",i+1,179,i+3,pemain[i].uang);
				}
				setcolor(urutan+9);
			}
		}
	}else if(tanah2[nomor].no_pemilik!=urutan){
		gotoxy(42,25);	printf("Tanah sudah dimiliki Pemain %d%c%c",tanah2[nomor].no_pemilik+1,179,tanah2[nomor].no_pemilik+3);
		gotoxy(42,26);	printf("Anda harus membayar sebanyak $%d",tanah2[nomor].harga_sewa*tanah2[nomor].upgrade);
		getch();
		if(pemain[urutan].uang<tanah2[nomor].harga_sewa/2*tanah2[nomor].upgrade){
			clear();
			do{
				gotoxy(42,25);	printf("Uang anda tidak cukup");
				gotoxy(42,26);	printf("1. Jual tanah");
				gotoxy(42,27);	printf("2. Minta ke Pengadilan");
				gotoxy(42,28);	printf("3. Menyerah");
				gotoxy(42,29);	printf("Masukkan pilihan ");
				pilih=getch();
			}while(pilih!='1'&&pilih!='2'&&pilih!='3');
			if(pilih=='2'){
				clear();
				int setuju;
				setuju=rand()%3;
				if(setuju==1){
					gotoxy(42,25);	printf("Anda beruntung");
					gotoxy(42,26);	printf("Berhasil membujuk Pengadilan");
					pemain[urutan].uang=46;
					pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
				}else{
					pilih='1';
					gotoxy(42,25);	printf("Anda belum beruntung");
					gotoxy(42,26);	printf("Tidak bisa membujuk Pengadilan");
					gotoxy(42,28);	printf("Jual tanah!");
				}
				getch();
			}
			if(pilih=='1'){
				bool lagi=true;
				int y,i,pilihan[16];
				do{
					clear();
					y=1;
					for(i=0;i<16;i++){
						if(tanah[i].no_pemilik==urutan){
							gotoxy(42,25+y);	printf("%d. %s",y,tanah[i].nama);
							pilihan[y]=i;
							y++;
						}
					}
					if(y>1){
						int jawab;
						do{
							gotoxy(42,25);	printf("                                ");
							gotoxy(42,25);	printf("Pilih tanah yang mau dijual: ");
							scanf("%d",&jawab);
						}while(jawab>y-1||jawab<1);
						pemain[urutan].uang+=tanah[pilihan[jawab]].harga_jual/2*tanah[pilihan[jawab]].upgrade;
						tanah[pilihan[jawab]].no_pemilik=-1;
						tanah[pilihan[jawab]].pemilik=false;
						for(i=0;i<8;i++){
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,15,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,15,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,15,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,15,2);
							Sleep(80);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,0,1);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan,0,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+4,0,2);
							tamp_pemain(tanah[pilihan[jawab]].no_tanah,urutan+8,0,2);
							Sleep(80);
						}
						if(pemain[urutan].uang>tanah[nomor].harga_sewa/2*tanah[nomor].upgrade){
							lagi=false;
							pemain[urutan].uang-=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
							pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
							gotoxy(42,26+y);	printf("Jual tanah cukup");
						}
						if(lagi){
							gotoxy(42,26+y);	printf("Uang anda masih kurang");
						}
					}else{
						gotoxy(42,25);	printf("Tidak ada tanah yang bisa dijual");
						gotoxy(42,26);	printf("Anda bangkrut!");
						kemenangan=true;
					}
					getch();
					clear();
				}while(kemenangan==false&&lagi);
			}else if(pilih=='3'){
				kemenangan=true;
			}
		}else{
			pemain[urutan].uang-=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
			pemain[tanah[nomor].no_pemilik].uang+=tanah[nomor].harga_sewa/2*tanah[nomor].upgrade;
		}
		if(pemain[urutan].uang<0){
			kemenangan=true;
		}	
	}else{
		gotoxy(42,25);	printf("Tanah ini milik anda");
		if(tanah2[nomor].upgrade<3){
			tanah2[nomor].upgrade++;
		}
		if(tanah2[nomor].upgrade==3){
			tamp_pemain(pemain[urutan].gerak,urutan+8,203,1);
			tamp_pemain(pemain[urutan].gerak,urutan+8,202,2);
		}
		tamp_pemain(pemain[urutan].gerak,urutan+4,203,1);
		tamp_pemain(pemain[urutan].gerak,urutan+4,202,2);
		gotoxy(42,26);	printf("Harga sewa $%d",tanah2[nomor].harga_sewa*tanah2[nomor].upgrade);
	}
	gotoxy(42,30);	printf("Tekan spasi untuk lanjut");
	getch();
}
//======================================================================
bool kartu[27];
void deklarasi_kartu(){
	for(int i=0;i<27;i++){
		kartu[i]=false;
	}
}
//======================================================================
void petak(int urutan){
	if(pemain[urutan].gerak==4||pemain[urutan].gerak==21){
		//portal-----------------------------------------------------------------------------------------------------
		int i;
		for(i=0;i<=10;i++){
			tamp_pemain(pemain[urutan].gerak,urutan,0,0);
			tamp_pemain(pemain[urutan].gerak,urutan,0,1);
			tamp_pemain(pemain[urutan].gerak,urutan,0,-1);
			Sleep(50);
			if(i!=10){
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				tamp_pemain(pemain[urutan].gerak,urutan,31,1);
				tamp_pemain(pemain[urutan].gerak,urutan,30,-1);
			}
			Sleep(50);
		}
		portal(urutan);
		if(pemain[urutan].gerak==21)
			pemain[urutan].gerak-=17;
			else pemain[urutan].gerak+=17;
		tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
	}else if(pemain[urutan].gerak==8){
		//penjara-----------------------------------------------------------------------------------------------------
		clear();
		pemain[urutan].penjara=true;
		penjara(urutan);
	}else if(pemain[urutan].gerak==16||pemain[urutan].gerak==33){
		clear();
		int hasil,i;
		char pilih;
		if(pemain[urutan].uang>200){
			do{
				gotoxy(42,23);	printf("1. Head");
				gotoxy(42,24);	printf("2. Tail");
				gotoxy(42,22);	printf("Masukkan tebakan anda ");
				pilih=getch();
			}while(pilih!='1'&&pilih!='2');
			srand(time(NULL));
			hasil=rand()%2;
			if(hasil==0)
				hasil=5;
			for(i=0;i<44;i++){
				if(hasil>=8)
					hasil-=8;
				hasil++;
				head_or_tail(hasil);
				Sleep(50);
			}
			if((pilih=='1'&&hasil==5)||(pilih=='2'&&hasil==1)){
				gotoxy(42,36);	printf("Hore!! Kamu memenangkan uang sebesar $200");
				pemain[urutan].uang+=200;
			}else{
				gotoxy(42,36);	printf("Maaf anda kehilangan uang sebesar $200");
				pemain[urutan].uang-=200;
			}
		}else{
			gotoxy(42,25);	printf("Uang anda tidak cukup untuk menebak");
		}
		getch();
	}else if(pemain[urutan].gerak==9||pemain[urutan].gerak==26){
		clear();
		//games-----------------------------------------------------------------------------------------------------
		int hasil,i;
		char pilih;
		if(pemain[urutan].uang>100){
			do{
				gotoxy(42,22);	printf("Menebak angka dadu yang akan tampil");
				gotoxy(42,23);	printf("Masukkan tebakan anda : (1-6)");
				pilih=getch();
			}while(pilih!='1'&&pilih!='2'&&pilih!='3'&&pilih!='4'&&pilih!='5'&&pilih!='6');
			srand(time(NULL));
			for(i=0;i<=10;i++){
				hasil=rand()%6+1;
				tamp_dadu(hasil,4);
				Sleep(100);
			}
			if((pilih=='1'&&hasil==1)||(pilih=='2'&&hasil==2)||(pilih=='3'&&hasil==3)||(pilih=='4'&&hasil==4)||(pilih=='5'&&hasil==5)||(pilih=='6'&&hasil==6)){
				gotoxy(42,36);	printf("Hore!! Kamu memenangkan uang sebesar $300");
				pemain[urutan].uang+=300;
			}else{
				gotoxy(42,36);	printf("Maaf anda kehilangan uang sebesar $100");
				pemain[urutan].uang-=100;
			}
		}else{
			gotoxy(42,25);	printf("Uang anda tidak cukup untuk bermain");
		}
		getch();
	}else if(pemain[urutan].gerak==3||pemain[urutan].gerak==14||pemain[urutan].gerak==20||pemain[urutan].gerak==28){
		//kartu-----------------------------------------------------------------------------------------------------
		int giliran,i=0;
		gotoxy(42,29);
		do{
			giliran=rand()%27;
			i++;
			if(i>25){
				deklarasi_kartu();
			}
		}while(kartu[giliran]);
		kartu[giliran]=true;
		mimilikan(urutan,giliran);
	}else if(pemain[urutan].gerak==17){
		//bebas parkirxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	}else if(pemain[urutan].gerak==25){
		//pengadilan-----------------------------------------------------------------------------------------------------
		clear();
		if(pemain[urutan].uang>2000){
			gotoxy(42,22);	printf("Uang berlebih");
			gotoxy(42,23);	printf("Anda harus bayar denda");
			gotoxy(42,24);	printf("Uang berkurang $200");
			pemain[urutan].uang-=200;
		}else{
			gotoxy(42,22);	printf("Terlalu miskin");
			gotoxy(42,23);	printf("Anda harus diberikan bantuan");
			gotoxy(42,24);	printf("Uang bertambah $100");
			pemain[urutan].uang+=100;
		}
		getch();
	}else if(pemain[urutan].gerak==5||pemain[urutan].gerak==12||pemain[urutan].gerak==22||pemain[urutan].gerak==30){
		//PLN PDAM dll-----------------------------------------------------------------------------------------------------
		int no_tanah;
		switch(pemain[urutan].gerak){
			case 5:		no_tanah=0;		break;
			case 12:	no_tanah=1;		break;
			case 22:	no_tanah=2;		break;
			case 30:	no_tanah=3;		break;
		}
		rumah2(urutan,no_tanah);
	}else{
		//tanah-----------------------------------------------------------------------------------------------------
		int nomor;
		switch(pemain[urutan].gerak){
			case 1:		nomor=0;	break;
			case 2:		nomor=1;	break;
			case 6:		nomor=2;	break;
			case 7:		nomor=3;	break;
			case 10:	nomor=4;	break;
			case 11:	nomor=5;	break;
			case 13:	nomor=6;	break;
			case 15:	nomor=7;	break;
			case 18:	nomor=8;	break;
			case 19:	nomor=9;	break;
			case 23:	nomor=10;	break;
			case 24:	nomor=11;	break;
			case 27:	nomor=12;	break;
			case 29:	nomor=13;	break;
			case 31:	nomor=14;	break;
			case 32:	nomor=15;	break;
		}
		rumah(urutan,nomor);
	}
	gotoxy(17,7);
	for(int i=0;i<jum_pem;i++){
		setcolor(i+9);
		printf("   Pemain %d%c%c  $%4d",i+1,179,i+3,pemain[i].uang);
	}
}
//======================================================================
void menang(){
	int urutan,max;
	max=0;
	for(urutan=1;urutan<jum_pem;urutan++){
		if(pemain[urutan].uang>pemain[max].uang)
			max=urutan;
	}
	clear();
	setcolor(max+9);
	gotoxy(42,25);	printf("              Hore!            ");
	gotoxy(42,26);	printf("        Pemain %d%c%c menang   ",max+1,179,max+3);
	gotoxy(42,27);	printf("      Dengan uang terbanyak    ");
	getch();
}
//======================================================================
int main(){
	system("MODE 118,62");
	int urutan,dadu1,dadu2,jum_uang;
	char jawab;
	do{
		gotoxy(1,1);	printf("Masukkan jumlah pemain (2-4) : ");
		jawab=getch();
	}while(jawab!='2'&&jawab!='3'&&jawab!='4');
	if(jawab=='2')
		jum_pem=2;
		else if(jawab=='3')
			jum_pem=3;
			else	jum_pem=4;
	printf("%d",jum_pem);
	do{
		gotoxy(1,4);	printf("1. $1000");
		gotoxy(1,5);	printf("2. $2000");
		gotoxy(1,6);	printf("3. $3000");
		gotoxy(1,7);	printf("4. $4000");
		gotoxy(1,3);	printf("Masukkan jumlah uang : ");
		jawab=getch();
	}while(jawab!='1'&&jawab!='2'&&jawab!='3'&&jawab!='4');
	if(jawab=='1')
		jum_uang=1000;
		else if(jawab=='2')
			jum_uang=2000;
			else if(jawab=='3')
				jum_uang=3000;
				else	jum_uang=4000;
	printf("$%d",jum_uang);
	gotoxy(1,9);	printf("Tekan Enter untuk mulai!");
	getch();
	system("cls");
	deklarasi();
	arena();
	chance();
	chance2();
	deklarasi_kartu();
	for(urutan=0;urutan<jum_pem;urutan++){
		setcolor(urutan+9);
		tamp_pemain(0,urutan,urutan+3,0);
		pemain[urutan].uang=jum_uang;
	}
	gotoxy(17,7);
	for(urutan=0;urutan<jum_pem;urutan++){
		setcolor(urutan+9);
		printf("   Pemain %d%c%c  $%4d",urutan+1,179,urutan+3,pemain[urutan].uang);
	}
	urutan=0;
	do{
		setcolor(urutan+9);
		if(pemain[urutan].penjara==false)
			kocok_dadu(urutan,&dadu1,&dadu2);
		if(dadu1==dadu2&&pemain[urutan].penjara==false){
			pemain[urutan].penjara_roll++;
			if(pemain[urutan].penjara_roll>=3){
				for(int i=0;i<=10;i++){
					tamp_pemain(pemain[urutan].gerak,urutan,0,0);
					tamp_pemain(8,urutan,0,0);
					tamp_pemain(8,urutan,0,1);
					tamp_pemain(8,urutan+4,0,1);
					tamp_pemain(8,urutan+8,0,1);
					Sleep(70);
					if(i!=10){
						tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
						tamp_pemain(8,urutan,urutan+3,0);
						tamp_pemain(8,urutan,241,1);
						tamp_pemain(8,urutan+4,241,1);
						tamp_pemain(8,urutan+8,241,1);
					}
					Sleep(70);
				}
				pemain[urutan].penjara_roll=0;
				pemain[urutan].gerak=8;
				tamp_pemain(pemain[urutan].gerak,urutan,urutan+3,0);
				pemain[urutan].penjara=true;
			}
		}else{
			pemain[urutan].penjara_roll=0;
		}
		if(pemain[urutan].gerak!=0)
			petak(urutan);
		if(pemain[urutan].penjara_roll==0||pemain[urutan].penjara)
			urutan++;
		if(urutan>=jum_pem)
			urutan-=jum_pem;
		
	}while(pemain[urutan].uang>=0&&pemain[urutan].uang<jum_uang*3&&!kemenangan);
	
	menang();
	
	
	getch();
	return 0;
}
