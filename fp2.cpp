#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Discount{
                char kode[255];
                double persen;
            };

double hasildiskon(char target[255], double harga){
   
    Discount discount[100];
    FILE *fp = fopen("gudang.txt", "r");
    int counter = 0;
    double hasil = 0.0;
    while(fscanf(fp, "%[^#]#%lf\n", discount[counter].kode,     
          &discount[counter].persen) != EOF){
        counter++;
    }
    for(int i=0; i<counter;i++){
        if (strcmp(target,discount[i].kode) == 0){
            hasil = harga - harga * discount[i].persen;
            return hasil;
        }else{
            return harga;
        }
    }
    fclose(fp);
}

int main() {
	char target[255];
    double harga;
    double uang;
    double kembalian;
    double total_setelah_diskon;
    

    puts("Mesin Kasir");
    puts("1. Pembayaran");
    puts("2. Keluar"); // isi apaan dah ni

    char choice;
    puts("ketik pilihan anda dibawah teks ini"); 
    scanf("%c", &choice);


    switch(choice){
        case '1':
            printf("--------------------------------\n");
            printf("Total yang harus dibayar: Rp. ");
    scanf("%lf", &harga);
    
    printf("Masukkan Kode Diskon: ");
    total_setelah_diskon = hasildiskon(target, harga);
     scanf("%s", target);
     
    

    printf("Jumlah uang yang diberikan : Rp. ");
    scanf("%lf", &uang);

    if(uang>harga) {
        kembalian = uang - total_setelah_diskon;
        printf("Uang kembalian : Rp. %.3lf", kembalian);

    }
    else if(uang<harga) {
        printf("Uang kurang\n");
    }
    else {
        printf("Uang pas\n");
    }


            break;
        
        case '2':
            printf("--------------------------------\n");
            printf("Selamat tinggal!");


            break;
        default:
            printf("--------------------------------\n");
            printf("Nomor yang anda masukkan salah");


    }







    return 0;
}
