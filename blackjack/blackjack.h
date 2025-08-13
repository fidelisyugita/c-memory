

#ifndef blackjack_H
#define blackjack_H

typedef struct kartu *address;
typedef struct kartu{
	int isi;
	address next;
}KARTU;

int Count(address Player);
void clear();
void turn(address *deck,address *pemain,bool *tambah,int pos);
void lagi(bool *tambah,int pos);
void shuffle(address *deck,int jmlKartu);
void push(address *p,int isi);
void pop(address *p,int *isi);
void insertAfter(address *p,int isi);
address alokasi(int isi);
void bagiKartu(address *deck,address *pemain);
void lihat(address p,int pos,int kartuKe,bool tutup);
void tampKartu(int posisi,int kartuKe,int nilai,bool tutup);
void tampIsi(int nilai);
void menu();
void player(int *n);
void Banker(address *deck,address *Banker);
void Winner(address Player,address Banker,int i);
void gotoxy(int x, int y);

#endif
