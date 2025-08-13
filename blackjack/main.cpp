

#include<stdio.h>
#include"blackjack.h"

int main(){
	//variabel=
	int i,j,n;
	address deck=NULL;
	address banker=NULL;
	
	menu();	//tampilan awal
	player(&n);	//n : jumlah pemain
	address pemain[n];
	for(i=0;i<n;i++){
		pemain[i]=NULL;	//inisialisasi setiap pemain
	}
	
	shuffle(&deck,52);	//mengocok kartu berjumlah 52
	printf("");
	for(j=0;j<2;j++){	//pembagian kartu. 2kartu/pemain
		bagiKartu(&deck,&banker);	//pop deck & push ke banker
		if(j>0){
			lihat(banker,0,j,true);
		}else{
			lihat(banker,0,j,false);
		}
		for(i=0;i<n;i++){
			bagiKartu(&deck,&pemain[i]);	//pop deck & push ke pemain
			lihat(pemain[i],i+1,j,false);
		}
	}
	
	for(i=0;i<n;i++){
		bool tambah=true;
		j=1;
		while(Count(pemain[i])<21&&tambah){
			j++;
			turn(&deck,&pemain[i],&tambah,i);
			lihat(pemain[i],i+1,j,false);
		}
	}
	Banker(&deck,&banker);
	for(i=0;i<n;i++){
		Winner(pemain[i],banker,i);
	}
	return 0;
}
