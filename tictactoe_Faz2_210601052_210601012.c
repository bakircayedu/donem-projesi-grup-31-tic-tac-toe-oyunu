#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

FILE *skorTablosu;

int x,y,sayac=1;
char masa[3][3],kazanan;

void ciz();
void hamle();
int kontrol();

struct Oyuncu
    {
        char isim[100];
        int skor;
    }Oyuncu;

int main()
{

    struct Oyuncu oyuncu1,oyuncu2;
    oyuncu1.skor = 0;
    oyuncu2.skor = 0;


    printf("Oyuncu X Isminizi Giriniz : ");
    gets(oyuncu1.isim);
    printf("Oyuncu O Isminizi Giriniz : ");
    gets(oyuncu2.isim);
   

    

    skorTablosu = fopen("Skor_Tablosu.txt","w");
    
    fprintf(skorTablosu,"%s %d",oyuncu1.isim,oyuncu1.skor);
    fprintf(skorTablosu,"\n%s %d",oyuncu2.isim,oyuncu2.skor);
    
    fclose(skorTablosu);


    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            masa[i][j] = ' ';
        }
    }
    
    printf("\n\nOynamak istediginiz karenin satirini ve sutununu giriniz! \nOrnek : 1.satir 2.sutun\n\n");

    ciz();

    while(kontrol() == 0)
    {
        hamle();
        if ((x==0||x==1||x==2)&&(y==0||y==1||y==2)&&(masa[x][y])==' ')
        {
            
        
        
        if (sayac%2==0) {
        printf("Sira O'da\n"); 
            masa[x][y] = 'X';
        }else{
            printf("Sira X'te\n");
            masa[x][y] = 'O';
        }
        ciz();
        }else{
        printf("Gecerli bir hamle giriniz!");
        --sayac;
        }
        
    }
    
    printf("\nOyun Bitti Kazanan %c",kazanan);
    
    

    (kazanan=='X') ? oyuncu1.skor++ : oyuncu2.skor++;
    
    skorTablosu = fopen("Skor_Tablosu.txt","w");
    
    fprintf(skorTablosu,"%s %d",oyuncu1.isim,oyuncu1.skor);
    fprintf(skorTablosu,"\n%s %d",oyuncu2.isim,oyuncu2.skor);
    
    fclose(skorTablosu);

    //tekrar oynamak için

   bool evet = 1;
    
    while (evet!=0)
    {
       
    

    printf("Bir Daha Oynamak Ister misiniz ? \nEvet-> 1\nHayir-> 0 ");
    scanf("%d",&evet);
    sayac = 1;
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            masa[i][j] = ' ';
        }
    }
    if (evet == 1){
        ciz();
        while(kontrol() == 0)
    {
        hamle();
        if ((x==0||x==1||x==2)&&(y==0||y==1||y==2)&&(masa[x][y])==' ')
        {
            
        
        
        if (sayac%2==0) {
        printf("Sira O'da\n"); 
            masa[x][y] = 'X';
        }else{
            printf("Sira X'te\n");
            masa[x][y] = 'O';
        }
        ciz();
        }else{
        printf("Gecerli bir hamle giriniz!");
        --sayac;
        }
        
    }
    }else
    printf("Oynadiginiz icin tesekkurler");

    (kazanan=='X') ? oyuncu1.skor++ : oyuncu2.skor++;

    skorTablosu = fopen("Skor_Tablosu.txt","w");
    
    fprintf(skorTablosu,"%s %d",oyuncu1.isim,oyuncu1.skor);
    fprintf(skorTablosu,"\n%s %d",oyuncu2.isim,oyuncu2.skor);
    
    fclose(skorTablosu);


    
    }
    
}

void ciz(){
    printf(" %c | %c | %c ", masa[0][0], masa[0][1], masa[0][2]);
        printf("\n---|---|---\n");
    printf(" %c | %c | %c ", masa[1][0], masa[1][1], masa[1][2]);
        printf("\n---|---|---\n");
    printf(" %c | %c | %c ", masa[2][0], masa[2][1], masa[2][2]);
}

void hamle(){
    printf("\nSatiri Giriniz : ");
    scanf("%d",&x);
    --x;
    printf("Sutunu Giriniz : ");
    scanf("%d",&y);
    --y;
    sayac++;
}

int kontrol(){
    //yatay kontrol
    for (int i = 0; i < 3; i++)
    {
        if(masa[i][0]==masa[i][1]&&masa[i][0]==masa[i][2]&&(masa[i][0]=='X'||masa[i][0]=='O')){
        
        kazanan = masa[i][0];
        return 1;
        }
    }
    // dikey kontrol
    for (int i = 0; i < 3; i++)
    {
        if((masa[0][i]==masa[1][i]&&masa[0][i]==masa[2][i])&&(masa[0][i]=='X'||masa[0][i]=='O')){
        
        kazanan = masa[0][i];
        return 1;
        }
    }
    //çapraz kontrol
    if((masa[0][0]==masa[1][1]&&masa[0][0]==masa[2][2])&&(masa[1][1]=='X'||masa[1][1]=='O')){
        
        kazanan = masa[0][0];
        return 1;
        }
    if((masa[0][2]==masa[1][1]&&masa[1][1]==masa[2][0])&&(masa[0][2]=='X'||masa[0][2]=='O')){
        
        kazanan = masa[0][2];
        return 1;
        }
    return 0;
}