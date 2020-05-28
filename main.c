#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void menu();
void tambah_siswa();
void tampil_siswa();
void edit_siswa();
void hapus_siswa();
void close();
void header();
struct DATA {
	char nama[30];
	int kelas,id;
	char jk[30];
	float nilai[5];
	int total;
	char index;
}tambah,cek,hapus,sort[100],temp;

char index[2];
struct date{
	int tgl;
	int bln;
	int thn;
};
int sign_In(char user[30], char pass[30]){
    FILE *p;
    char user2[30], pass2[30];

    p= fopen("data/users.txt", "r");


    fscanf(p,"User: %s Password: %s",user2,pass2);

    if( (strcmp(user,user2)==0) && (strcmp(pass,pass2)==0) ){
        mainn(); // masuk ke menu pilihan
    }
    else
    	{printf("masukkan ulang");
        main();} //biar balek ke main klo salah

}
int main(){
    char user[30], pass[30];

    printf("\nUser:");
    scanf("%s",user);
    printf("\nPassword:");
    scanf("%s",pass);

    sign_In(user, pass);

}
int mainn() //LOADING SYSTEM
{
	system("cls");
		printf("Tunggu Bentar");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	menu(); //habis loding masuk ke menu
	return 0;
}
void menu(){
	int pilih;
	menu:
		system("cls");
		header();
		printf("MAIN MENU :");
		printf("\n[1]. Tambah siswa Dan nilai siswa");
		printf("\n[2]. Tampil Data siswa");
		printf("\n[3]. Hapus Data siswa");
		printf("\n[4]. Edit Data siswa");
		printf("\n[5]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_siswa();
				break;
			case 2:tampil_siswa();
				break;
			case 3:hapus_siswa();
				break;
			case 4:edit_siswa();
				break;
			case 5:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}
void tambah_siswa(){ //portal tambah siswa dan nilainya
	FILE *ptr,*ptr1;
	int count=0;
	
	ptr=fopen("data/siswa.txt","a");
		system("cls");
		ptr1 =fopen("data/siswa.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.kelas,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
		{
			tambah.id++;	
		}
		cek.id = tambah.id;
		fclose(ptr1);
		printf ("masukan nama siswa : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("masukan JK siswa (L/P): ");fflush(stdin);
		scanf ("%[^\n]",tambah.jk);
		printf ("masukan kelas siswa (desimal) : ");fflush(stdin);
		scanf ("%d",&tambah.kelas); 
		printf("nilai harian\t: ");
		scanf("%f",&tambah.nilai[0]);
		printf("nilai kuis\t: ");
		scanf("%f",&tambah.nilai[1]);
		printf("nilai ulangan\t: ");
		scanf("%f",&tambah.nilai[2]);
		printf("nilai ujian\t: ");
		scanf("%f",&tambah.nilai[3]);
		tambah.nilai[4]=(tambah.nilai[0]+tambah.nilai[1]+tambah.nilai[2]+tambah.nilai[3])/4;
		tambah.total = tambah.nilai[4];
		fprintf(ptr,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		fclose(ptr);
	
		printf("\n\nData siswa Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}
void close(){
}
void tampil_siswa(){ //diplay data siswa keseluruhan
	FILE *view;
	view = fopen("data/siswa.txt","r");
	int test=0;
	system ("cls");
	printf ("No\t\tNAMA\t\tJK\t\tkelas\t\tHARIAN\t\tKUIS\t\tULANGAN\t\tUJIAN\t\tRata-Rata\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.kelas,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		test++;
	}
	printf ("\nJumlah Data siswa : %d",test);
	fclose(view);
	
	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void header(){ //cuma judul data, pake waktu biar bagus
	printf("=== DATA SISWA ===");
	time_t mytime;
	time(&mytime);
	printf("\n%s", ctime(&mytime));
	
}
void hapus_siswa(){ //portal hapus data siswa pake no absen
	FILE *lama, *baru;
	int test=0;
	lama = fopen("data/siswa.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. absen siswa yang akan di hapus : "); //hapus berdasarkan no absen
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.kelas,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);	
		}
		else{
			test++;
			printf("\nData siswa No absen : %d dengan Nama : %s\n",tambah.id,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("data/siswa.txt");
	rename("baru.txt","data/siswa.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_siswa();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
	
}
void edit_siswa(){ //portal edit siswa
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("data/siswa.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");
	
	printf ("Masukan no. absen siswa : ");
	scanf ("%d",&cek.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.kelas,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo. absen : %d dimiliki siswa dengan Nama : %s",tambah.id,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama");
				printf("\n[2]. Jenis Kelamin");
				printf("\n[3]. kelas");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cek.jk);
					strcpy(tambah.jk,cek.jk);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data kelas Baru : ");
					scanf ("%d",&cek.kelas);
					tambah.kelas = cek.kelas;
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti; //kalau salah input kembali ke atas
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.kelas,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("data/siswa.txt");
	rename("baru.txt","data/siswa.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 1 untuk mencoba lagi, 2 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
            case '1': edit_siswa();
            	break;
            case '2': menu();
            	break;
            case '0': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
