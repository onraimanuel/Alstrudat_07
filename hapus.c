int hapusRute() {
	int i, j, found=0;
    rute r1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("rute.txt","r");
	system("cls");
	lihatRute();
    
    printf("\nDelete Rute : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("rute.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&r1,sizeof(rute),1,fp)){
        if(strcmp(r1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&r1,sizeof(rute),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("rute.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&r1,sizeof(rute),1,fp1)){
            fwrite(&r1,sizeof(rute),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}

int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
} 


int kelolaRute() {
	int i, j, counter=1;
    rute r1;
    rute *r;
    FILE *fp;
	
	fp = fopen("rute.txt","r");

	system("cls");
	printf("#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
    
    printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Rute");
	printf("\n2. Lihat Data Rute");
	printf("\n3. Edit Data Rute");
	printf("\n4. Delete Data Rute");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahRute();
			kelolaRute();
			break;
		case 2:
			system("cls");
			lihatRute();
			kelolaRute();
			break;
		case 3:
			system("cls");
			editRute();
			kelolaRute();
			break;
		case 4:
			hapusRute();
			kelolaRute();
			system("cls");
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}


int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
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
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			kelolaKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			kelolaKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			kelolaKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
	
}