#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Discount{
    char kode[255];
    double persen;
};

double hasildiskon(char target[255], double harga){
    /*
        IMPORTANT:
        1. gudang.txt with discount codes file must be saved in the same directory
        2. code format : code#percentage
        3. struct Discount{
                char kode[255];
                double persen;
            };
            Above structure must be created.
            
        How it works:
        1. This function checks if user's input 'target' exists in gudang.txt
        2. If yes:
            A. fscanf checks for paired discount percentage
            B. returns discounted price
        3. If no:
            A. returns undiscounted price
    */
    Discount discount[100];
    FILE *fp = fopen("gudang.txt", "r");
    int counter = 0;
    double hasil = 0.0;
    while(fscanf(fp, "%[^#]#%lf\n", discount[counter].kode, &discount[counter].persen) != EOF){
        counter++;
    }
    for(int i=0; i<counter;i++){
        if (strcmp(target,discount[i].kode) == 0){
            hasil = harga - harga * discount[i].persen;
            return hasil;
        }
    }
    fclose(fp);
    return harga;
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
   			scanf("%s", target);
   			
    		total_setelah_diskon = hasildiskon(target, harga);
     		
     		printf("Total Setelah Diskon: %.3lf\n", total_setelah_diskon);


    printf("Jumlah uang yang diberikan : Rp. ");
    scanf("%lf", &uang);

    if(uang>total_setelah_diskon) {
        kembalian = uang - total_setelah_diskon;
        printf("Uang kembalian : Rp. %.3lf", kembalian);

    }
    else if(uang<total_setelah_diskon) {
        printf("Uang kurang\n");
    }
    else {
        printf("Uang pas\n");
    }


            break;
	}	
}
