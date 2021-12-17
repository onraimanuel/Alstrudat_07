// Kelompok 07 Alstrudat //

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

typedef struct pengguna{
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} pengguna;


typedef struct kota {
	char kode[100];
	char nama[100];
} kota;

typedef struct rute {
	char kbrt[100];
	char tjn[100];
	char kode[100];
	int bisnis;
	int premium;
}rute;



int delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


int login(){
    int i, j, found=0;
    pengguna s1;
    pengguna *s;
    FILE *fp;
    char email[100];
    char password[100];
    fflush(stdin);
    printf("Username : ");
    scanf("%[^\n]s",email);
    fflush(stdin);
    printf("Password : ");
    scanf("%[^\n]s",password);

    fp = fopen("pengguna.txt","r");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.email,email)==0){
            if (strcmp(s1.password,password)==0) {
       			menuPengguna();
				found = 1;
			}
        } else if (strcmp(email,"admin123")==0) {
        	if (strcmp(password,"admin123")==0) {
        		menuAdmin();
			}
		}
    }
    if(!found)
        printf("\nAkun tidak terdaftar.....\n");
    else 
		printf("\nAnda berhasil login!");	
    fclose(fp);
}



int daftar(){
        pengguna *s;
        FILE *fp;
        int n,i,j;

        s = (pengguna*)malloc(100*sizeof(pengguna));
        fp = fopen("pengguna.txt","w+");

        for(i=0;i<1;i++){
        	fflush(stdin);
            printf("Nomor KTP : ");
            scanf("%[^\n]s",s[i].ktp);
            fflush(stdin);
            printf("Nama Lengkap : ");
            scanf("%[^\n]s",s[i].nama);
            fflush(stdin);
            printf("Nomor Handphone : ");
            scanf("%[^\n]s",s[i].hp);
            fflush(stdin);
            printf("Email : ");
            scanf("%[^\n]s",s[i].email);
            fflush(stdin);
            printf("Password : ");
            scanf("%[^\n]s",s[i].password);
            fflush(stdin);
            printf("Re-Password : ");
            scanf("%[^\n]s",s[i].repassword);

            fwrite(s+i,sizeof(pengguna),1,fp);
        }
    fclose(fp);
}

// Bagian Irma
int tambahKota() {
	kota *k;
    FILE *fp;
    int n,i,j;

    k = (kota*)malloc(100*sizeof(kota));
    fp = fopen("kota.txt","a+");
    
	printf("#TAMBAH DATA KOTA#\n\n");
    for(i=0;i<1;i++){
    	printf("Tambah Kota : ");
    	fflush(stdin);
        scanf("%s %s",k[i].kode,k[i].nama);
        
        fwrite(k+i,sizeof(kota),1,fp);
    }
    
    fclose(fp);
    
}

int lihatRute() {
	rute *r;
	rute r1;
    FILE *fp;
    int n,i,j, counter=1;

	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("rute.txt","r");
	system("cls");
	printf("#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t%d\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int lihatKota() {
	kota *k;
	kota k1;
    FILE *fp;
    int n,i,j, counter=1;
    
    fp = fopen("kota.txt","r");
	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

// Bagian Jerico

// Bagian Nemi

int menuPengguna() {
	system("cls");
	printf("#MENU PENGGUNA#");
	int i, j, found=0;
    pengguna s1;
    FILE *fp;

    fp = fopen("pengguna.txt","r");
    while(fread(&s1,sizeof(pengguna),1,fp)){
		printf("\nWelcome, %s",s1.nama);
		printf("\n\n1. Booking Tiket");
		printf("\n2. Kelola Profile");
		printf("\n3. History Pembelian");
		printf("\n0. Logout");
		printf("\n\nPilihan : ");
		
		int choice;
		fflush(stdin);
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				
				break;
			case 2: 
				kelolaProfile();
				break;
			case 3:
				
				break;
			default:
				
				break;
		}
		
    }
}

int menuAdmin() {
	system("cls");
	printf("#MENU ADMIN#");
	int i, j, found=0;
    pengguna s1;
    FILE *fp;
    
	printf("\nWelcome, admin");
	printf("\n\n1. Kelola Akun");
	printf("\n2. Kelola Kota");
	printf("\n3. Kelola Rute");
	printf("\n4. Lihat Pemasukan");
	printf("\n5. Lihat Jadwal Kereta Api");
	printf("\n0. Logout");
	printf("\n\nPilihan : ");
	
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1:
			system("cls");
			kelolaPengguna();
			break;
		case 2: 
			system("cls");
			kelolaKota();
			break;
		case 3:
			system("cls");
			kelolaRute();
			break;
			
		default:
			
			break;
	}
}

int tambahRute() {
	rute *r;
	kota k1;
    FILE *fp,*fp1;
    int n,i,j;

    r = (rute*)malloc(100*sizeof(rute));
    fp = fopen("rute.txt","a+");
    fp1 = fopen("kota.txt","r");
    
	printf("#TAMBAH DATA RUTE#\n\n");
	char kode1[100], kode2[100], kode3[100];
    for(i=0;i<1;i++){
    	printf("Tambah Data Rute : ");
    	fflush(stdin);
        scanf("%s %s %d %d",r[i].kbrt,r[i].tjn,&r[i].bisnis,&r[i].premium);
        while(fread(&k1,sizeof(kota),1,fp1)) {
            if(strcmp(r[i].kbrt,k1.nama)==0) {
            	strcpy(kode1,k1.kode);
			} 
			
			if (strcmp(r[i].tjn,k1.nama)==0) {
				strcpy(kode2,k1.kode);
			}
			
			strcpy(kode3,strcat(kode1,"-"));
			strcpy(r[i].kode,(strcat(kode3,kode2)));
        }
        
        fwrite(r+i,sizeof(rute),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaRute();
}




int kelolaPengguna() {
    int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf("#KELOLA AKUN BY ADMIN#");
    
    fflush(stdin);
    printf("Masukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
            found = 1;
            printf("--Data Pengguna--");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			
   			printf("\n\n--Ubah Data Pengguna--");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("pengguna.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&s1,sizeof(pengguna),1,fp1)){
            fwrite(&s1,sizeof(pengguna),1,fp);
            printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);

			}  
        }
        fclose(fp);
        fclose(fp1);
    }




int kelolaProfile() {
	int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf("#KELOLA AKUN BY PENUMPANG#");
    fflush(stdin);
    printf("\n\nMasukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
        	
            found = 1;
            printf("--Data Pengguna--");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			
   			printf("\n\n--Ubah Data Pengguna--");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("pengguna.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&s1,sizeof(pengguna),1,fp1)){
            fwrite(&s1,sizeof(pengguna),1,fp);
            printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
			
			// MENU ADMIN
			system("cls");
			printf("#MENU ADMIN#");
			int i, j, found=0;
		    pengguna s1;
		    FILE *fp;
		
		    
			printf("\nWelcome, admin");
			printf("\n\n1. Kelola Akun");
			printf("\n2. Kelola Kota");
			printf("\n3. Kelola Rute");
			printf("\n4. Lihat Pemasukan");
			printf("\n5. Lihat Jadwal Kereta Api");
			printf("\n0. Logout");
			printf("\n\nPilihan : ");
			
			int choice;
			fflush(stdin);
			scanf("%d",&choice);
			
			switch(choice) {
				case 1:
					system("cls");
					kelolaPengguna();
					break;
				case 2: 
					system("cls");
					kelolaKota();
					break;
				case 3:
					
					break;
				default:
					
					break;
			}  
        }
        fclose(fp);
        fclose(fp1);
    }
}

tambahJadwal() {
	jadwal *j;
	jadwal j1;
	rute r1;
    FILE *fp,*fp1;
    int n,i;

    j = (jadwal*)malloc(100*sizeof(jadwal));
    fp = fopen("jadwal.txt","a+");
    fp1 = fopen("rute.txt","r");
    
	printf("#TAMBAH DATA JADWAL#\n\n");
	
    for(i=0;i<1;i++){
    	printf("Tambah Data Jadwal : ");
    	printf("\n\nKode Jadwal : ");
    	fflush(stdin);
        scanf("%s",j[i].kode);
        printf("\nTanggal : ");
    	fflush(stdin);
        scanf("%s",j[i].tanggal);
        printf("\nWaktu Keberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].waktuKbrt);
        printf("\nKeberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].kbrt);
        printf("\nTujuan : ");
    	fflush(stdin);
        scanf("%s",j[i].tjn);
        printf("\nKAI : ");
    	fflush(stdin);
        scanf("%s",j[i].kai);
        printf("\nJumlah sisa kursi : ");
    	fflush(stdin);
        scanf("%d",&j[i].sisa);
        
        
        
        while(fread(&r1,sizeof(rute),1,fp1)) {
            if(strcmp(j[i].kbrt,r1.kbrt)!=0) {
            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j[i].kbrt);
			} 
			
			if (strcmp(j[i].tjn,r1.tjn)!=0) {
				printf("\n\nTujuan %s tidak ada pada daftar !",j[i].tjn);
			}
		
        }
        
        fwrite(j+i,sizeof(jadwal),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaJadwal();
}


int lihatJadwal() {
	jadwal *j;
	jadwal j1;
    FILE *fp;
    int n,i;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("jadwal.txt","r");
	system("cls");
	printf("#LIHAT DATA JADWAL#");
	printf("\nData Lengkap Jadwal Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("Kode Jadwal\tTanggal\tWaktu Keberangkatan\t\tKeberangkatan\tTujuan\t\tKAI\t\tStatus\n");
	while(fread(&j1,sizeof(jadwal),1,fp)) { 
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tKAI %s\t\tSisa %d Kursi\n",j1.kode,j1.tanggal, j1.waktuKbrt, j1.kbrt, j1.tjn, j1.kai, j1.sisa);
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int editJadwal() {
	jadwal *j;
	int i=0;
	int found=0, counter=1;
    jadwal j1;
    rute r1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihatJadwal();


    fflush(stdin);
    
	fp = fopen("rute.txt","r");
    fp1 = fopen("jadwal.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Jadwal : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&j1,sizeof(jadwal),1,fp1)){
    	if(strcmp(j1.kode,kode)==0){
				found = 1;
		    	printf("\n\nKode Jadwal : ");
	    	fflush(stdin);
	        scanf("%s",j1.kode);
	        printf("\nTanggal : ");
	    	fflush(stdin);
	        scanf("%s",j1.tanggal);
	        printf("\nWaktu Keberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.waktuKbrt);
	        printf("\nKeberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.kbrt);
	        printf("\nTujuan : ");
	    	fflush(stdin);
	        scanf("%s",j1.tjn);
	        printf("\nKAI : ");
	    	fflush(stdin);
	        scanf("%s",j1.kai);
	        printf("\nJumlah sisa kursi : ");
	    	fflush(stdin);
	        scanf("%d",&j1.sisa);   	

			while(fread(&r1,sizeof(rute),1,fp1)) {
	            if(strcmp(j1.kbrt,r1.kbrt)!=0) {
	            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j1.kbrt);
				} 
				
				if (strcmp(j1.tjn,r1.tjn)!=0) {
					printf("\n\nTujuan %s tidak ada pada daftar !",j1.tjn);
				}
			
	        }
	        
	        
	    	
        } 
        
    	fwrite(&j1,sizeof(jadwal),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("jadwal.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&j1,sizeof(jadwal),1,fp1)) {
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
}


int hapusJadwal() {
	int i, found=0;
    jadwal j1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("jadwal.txt","r");
    
	system("cls");
	lihatJadwal();
    
    printf("\nDelete Jadwal : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("jadwal.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&j1,sizeof(jadwal),1,fp)){
        if(strcmp(j1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&j1,sizeof(jadwal),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("jadwal.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&j1,sizeof(jadwal),1,fp1)){
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}



int main(){
    int ch;
   
    do{
    	printf("SELAMAT DATANG");
        printf("\n1.Login");
        printf("\n2.Register");
//        printf("\n3.DISPLAY");
//        printf("\n4.NO OF RECORDS");
//        printf("\n5.SEARCH");
//        printf("\n6.UPDATE");
//        printf("\n7.DELETE");
//        printf("\n8.SORT IN FILE BY TOTAL DESC");
//        printf("\n9.SORT ON SCREEN BY TOTAL DESC");
//        printf("\n10.SORT ON SCREEN BY NAME");
        printf("\n0.EXIT");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                login();
            break;
        case 2:
                daftar();
            break;
//        case 3:
//                display();
//            break;
//        case 4:
//                count();
//        break;
//        case 5:
//                search();
//        break;
//        case 6:
//                update();
//            break;
//            case 7:
//                delete_rec();
//            break;
//            case 8:
//                sort_in_file();
//                break;
//            case 9:
//                sort_on_screen();
//            break;
//            case 10:
//                sort_by_name();
//            break;

            
        }
    }while(ch!=0);

    return 0;
}
