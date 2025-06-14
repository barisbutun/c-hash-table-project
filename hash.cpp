#include<stdio.h>

#define tablo_boyutu 10


typedef struct musteri{

    int musteri_no;
    char ad[20],soyad[20];
}musteri;

typedef struct tablo{

    musteri musteriler[tablo_boyutu];

}tablo;

tablo hash_table;

void initialize_Table(){

    int i;

    for(i=0;i<tablo_boyutu;++i){

        //hash_table.musteriler[i].ad[20]=NULL;
        hash_table.musteriler[i].musteri_no=-1;
    }
}

int  hash(int no){
       
       return (3*no+2)%tablo_boyutu;
   }

void ekle(char *add,int musterino,char soyadd[]){

    int index;
     int j=0;
     int yerlestirme_sayisi=0;
	     	
            index=hash(musterino);
        if(hash_table.musteriler[index].musteri_no==-1){
    	   
			hash_table.musteriler[index].musteri_no=musterino;
            for(int i=0;i<20;i++){

    hash_table.musteriler[index].ad[i]=add[i];
}
            for(int i=0;i<20;i++){

    hash_table.musteriler[index].soyad[i]=soyadd[i];
}
			yerlestirme_sayisi++;		
		}
		else{
			while(hash_table.musteriler[index].musteri_no!=-1){
		j+=1;
		index=(3*musterino+2+j*(7*musterino+2))%tablo_boyutu;
			}
			if(hash_table.musteriler[index].musteri_no==-1){
				
			hash_table.musteriler[index].musteri_no=musterino;
			//hash_table.musteriler[index].ad[20]=add;
			for(int i=0;i<20;i++){

    hash_table.musteriler[index].ad[i]=add[i];
}
			//hash_table.musteriler[index].soyad[20]=soyadd[20];
			for(int i=0;i<20;i++){

    hash_table.musteriler[index].soyad[i]=soyadd[i];
}
			yerlestirme_sayisi++;
			}
	}
        if(yerlestirme_sayisi>10){
	
	printf("tablo doldu");
    
	}

}
int ara(int no){
	int adim_sayisi=0;
	int a=0;
	int hash_index;
	hash_index=hash(no);
printf("\n");
	
	if(hash_table.musteriler[hash_index].musteri_no==no){
		adim_sayisi++;
		printf("%d adimda bulundu\n",adim_sayisi);
		return hash_table.musteriler[hash_index].musteri_no;
		
	}
	else{
	while(hash_table.musteriler[hash_index].musteri_no!=no){
		a++;		
	hash_index=(3*no+2+a*(7*no+2))%tablo_boyutu;	
		adim_sayisi++;
	}	
	
	if(hash_table.musteriler[hash_index].musteri_no==no){
		
		printf("%d adimda bulundu\n",adim_sayisi);
		return hash_table.musteriler[hash_index].musteri_no;
		
	}
	else{
		return -1;
	}
	
	}
	
	}
	void listele(){
		
		int i;
		for(i=0;i<tablo_boyutu;++i){
			if(hash_table.musteriler[i].musteri_no!=-1){
				printf("%d %s %s\n",hash_table.musteriler[i].musteri_no,hash_table.musteriler[i].ad,hash_table.musteriler[i].soyad);
			}
			
			
		}
		
		
		
		
	}





int main(){
FILE *dosya;
int musterino;
char add[20];
char soyadd[20];
int i=0;
int musterino2;
char add2[20];
char soyadd2[20];

dosya=fopen("ver2i.txt","r+");
int secim=0;
initialize_Table();
if(dosya==NULL){
    printf("dosya acilamadi");

}
for(int i=0;i<7;i++){
	fscanf(dosya,"%d %s %s",&musterino,&add,&soyadd);
	ekle(add,musterino,soyadd);
	}
	printf("\n");
	
int dongu=1;
printf("\n");
while(dongu==1){
printf("secim 1/ekleme 2/arama 3/listeleme 4/cikis:\n");
scanf("%d",&secim);
	switch(secim){
	
	
	case 1:
   scanf("%d %s %s",&musterino2,&add2,&soyadd2);
   
   ekle(add2,musterino2,soyadd2);
   printf("\n");
   printf("eklendi\n");
   listele();
   continue;		
	case 2:
  printf("arama yapin:");
  int ara1;
  scanf("%d",&ara1);
    ara(ara1);
    continue;
    case 3:
    	listele();
    continue;
    case 4:
    	dongu=0;
    printf("cikis");
	continue;	
    default:
    	printf("yanlis islem girdiniz");

}
}
    return 0;
}
