#include<stdio.h> /* untuk operasi input-output */
#include<string.h> /*Untuk memanipulasi beberapa jenis string*/
#include<stdlib.h> /*Alokasi Memori*/
#include<conio.h> /*Untuk getch()*/

struct login{                    /*login-> Nama Struct nya*/
    char username[100],password[100],nama[100],gmail[100];  /*Isi structnya (Variabel- Variabel)*/
    int  telp;
}akun_user;                      /*akun_user -> Variabel yang dideklarasikan*/

char username2[100],password2[100];     /*variabel Global, ini dipakenya buat login user*/

//FILE
FILE*f_akun_user;

//FUNGSI-FUNGSI yang ada di program kita
void login_admin();
void menu_admin();
void melihat_akun();
void user();
void register_user();
int login_user();
void milih_kamar();
void admin_premium();
void admin_biasa();
void user_premium();
void user_biasa();
void input_harga();
void menu_user();
void ulasan();
void lihat_ulasan();
void cari_user();
void pemesanan();
void lihat_pemesanan();
void pembayaran();
void cek_harga();
void tipe_kos();


/*Fungsi main, program awal/utama yang akan dijalanin sama program*/
int main(){
    int admin_or_user;
    system("cls"); /*system (“cls”); buat ngebersihin layar program. Adanya dari library stdlib.h*/
    printf("=======================================================\n");
    printf("====================  MASUK SEBAGAI ===================\n");
    printf("====== (1)               ADMIN               (1)  =====\n");
    printf("====== (2)               USER                (2)  =====\n");
    printf("====== (3)           LIHAT ULASAN            (3)  =====\n");
    printf("====== (4)               EXIT                (4)  =====\n");
    printf("=======================================================\n");
    printf("=======================================================\n");
    printf("Anda Masuk Sebagai:\n");scanf("%d",&admin_or_user);
    switch(admin_or_user){          /*Operasi switch case*/
        case 1:
                login_admin(); break;
        case 2:
                user(); break;
        case 3:
                lihat_ulasan(); break;
        case 4:
                system("Exit"); break;
        default:                    /*Kalo yg di input selain 1,2 atau 3*/
                main(); break;

    }
    
}


void login_admin(){            /*Isi Fungsi login admin*/
    char username[100],password[100];   /*Variabel Lokal*/
    int percobaan=0,i;
    char ch;
     while (percobaan< 3){          /*Buat percobaan login, dikasih 3 kali kesempatan*/
        printf("MASUKAN USERNAME ADMIN : ");
        scanf("%s", username);
        printf("MASUKAN PASSWORD ADMIN : ");
        while((ch=_getch())!=13){ /*Buat ngesamarin Password*/
                password[i]=ch;
                i++;
                printf("*");
            }

        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0){ /*Kalo username sama password bener, lanjut ke menu admin*/
            menu_admin(); /*Manggil fungsi menu admin, buat dijalanin*/
            break;
        }
        else{
            printf("Username atau password salah. Silakan coba lagi.\n");/*Kalo username atau password salah*/
            percobaan;
        }
    }

    if (percobaan== 3){ /*Kalo 3 kali gagal, kembali ke menu admin*/
        main(); /*Manggil fungsi main, buat dijalanin*/
    }

}

void menu_admin(){
    int C;
    printf("*\n"); /*\n buat ngasih space dari program sebelumnya ke program ini*/
    printf("* (1) MELIHAT AKUN TERDAFTAR            (1) *\n");
    printf("* (2) LIST PEMESANAN KAMAR              (2) *\n");
    printf("* (3) ATUR WAKTU REMINDER PEMBAYARAN    (3) *\n");
    printf("* (4) INPUT HARGA                       (4) *\n");
    printf("* (5) BACK                              (5) *\n");
    printf("*\n");
    printf("Pilih:");scanf("%d",&C);getchar();  /*Fungsi getchar*/
    switch(C){
        case 1:
                melihat_akun(); break;
        case 2:
                lihat_pemesanan(); break;
        case 3:
                cari_user(); break;

        case 4:
                input_harga(); break;

        case 5:
                main(); break;   

        default :
                main(); break;
        
    }
}

void cari_user(){
    char username[100], password[100], nama[100], email[100];
    int no_telp;

    system("cls");

    f_akun_user = fopen("Akun User.dat","rb");
    printf("Silahkan masukkan Username ");
    scanf("%s", &akun_user.username);getchar();

    if (fread(&akun_user, sizeof (akun_user), 1, f_akun_user) == 0){ 
    printf("Menu yang dicari tidak dapat ditemukan pada daftar.\n");
    }
    else{ 
    printf("Nama: %s\n",akun_user.nama);
    printf("No Telpon: %d\n",akun_user.telp);
    printf("Alamat Email:  %s\n",akun_user.gmail);
    } 
    fclose(f_akun_user); 
    system("pause");
    atur_waktu();


}

void atur_waktu(){
    int jam=0,menit=0,detik=0,ms=0; //ms=milisecond
	char ch;
printf("Masukan Lama Counter JAM::MENIT::DETIK(Gunakan Spasi):\n");
				scanf("%d%d%d",&jam,&menit,&detik);
                printf("Sisa Waktu Kosan User:\n");
				while(1) 
				{   
					printf("      \r%d:%d:%d",jam,menit,detik);
					Sleep(1000); 
					if(detik!=0)
					{
						detik--;
					}
					if(detik==0 && menit!=0)
					{
						detik=59;
						menit--;
					}
					if(detik==0 && menit==0 && jam!=0)
					{
						jam--;
						menit=59;
						detik=59;
					}
					if(jam==0 && menit==0 && detik==0)
					{
						exit(0);
					}
				}
                menu_admin();
}

void melihat_akun(){
    struct login l;
    char nama[100],gmail[100],username[100],password[100];
    int telp;
    f_akun_user = fopen("Akun User.dat","rb");
    while (fread(&l, sizeof(l),1, f_akun_user) == 1){
        printf("Nama: %s\n",l.nama);
        printf("No Telpon: %d\n",l.telp);
        printf("Alamat Email:  %s\n",l.gmail);
        printf("Username:  %s\n",l.username);
        printf("Password:  %s\n",l.password);
    }
    fclose(f_akun_user); 
    system("pause");
    menu_admin();

}

void user(){
    int B;
    system("cls");
    printf("=======================================================\n");
    printf("====================  PILIH OPSI ======================\n");
    printf("====== (1)              REGISTER              (1) =====\n");
    printf("====== (2)               LOGIN                (2) =====\n");
    printf("====== (3)               BACK                 (3) =====\n");
    printf("=======================================================\n");
    printf("=======================================================\n");
    printf("Pilih:");scanf("%d",&B);getchar();
    switch(B){
        case 1:
                register_user(); break;
        case 2:
                login_user(3); break;
        case 3:
                main(); break;
        default :
                main(); break;
        
    }
    
}

void register_user(){
    FILE *f_akun_user;
    struct login l;
    system("cls");
    printf("=======================================================\n");
    printf("====================  REGISTRASI AKUN =================\n");
    printf("=======================================================\n");
    f_akun_user=fopen("Akun user.dat","ab");
    fflush(stdin);
    printf("Masukkan Nama Lengkap: ");gets(l.nama);
    printf("Masukkan No Telepon: ");scanf("%d",&l.telp);getchar();
    printf("Masukkan Email: ");gets(l.gmail);
    printf("Masukkan Username: ");gets(l.username);
    printf("Masukkan Password: ");gets(l.password);
    fwrite(&l,sizeof(l),1,f_akun_user);
    fclose(f_akun_user);
    printf("=======================================================\n");
    printf("REGISTRASI BERHASIL\n");
    login_user(3);
}

int login_user(int x){
    struct login l;
 char username[30],password[20];
    int status=0;
    f_akun_user = fopen("Akun User.dat","rb");
    if (x==0){
        main();
        return 1;
    }
    printf("Tolong Masukkan Akun Anda dengan Benar\n");fflush(stdin);
    printf("Masukkan Username:  ");gets(username);
    printf("Masukkan Password: ");gets(password);
    while(fread(&l,sizeof(l),1,f_akun_user)){
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){   
          status = 2;
            }
        else 
            {
              status = 1;
}
}
if (status==2){
  tipe_kost();
}
else {
    printf("Login Anda Gagal. Anda memiliki %d kesempatan login lagi.\n",x-1);
    system("pause");
    return login_user(x-1);
}
}
void menu_user(){
    int C;
    system("cls");
    printf("*\n");
    printf("* (1) PEMILIHAN TIPE KAMAR              (1) *\n");
    printf("* (2) BERI ULASAN                       (2) *\n");
    printf("* (3) BACK                              (3) *\n");
    printf("*\n");
    printf("Pilih:");scanf("%d",&C);getchar();
    switch(C){
       case 1:
                milih_kamar(); break;
       case 2:
                ulasan(); break;
        case 3:
                main(); break;

        default :
                main(); break;
        
    }
}

void milih_kamar(){
     int C;
    system("cls");
    printf("*\n");
    printf("* (1) KAMAR PREMIUM                     (1) *\n");
    printf("* (2) KAMAR BIASA                       (2) *\n");
    printf("* (3) BACK                              (3) *\n");
    printf("*\n");
    printf("Pilih:");scanf("%d",&C);getchar();
    switch(C){
        case 1:
                user_premium(); 
                pemesanan(); break;
        case 2:
                user_biasa(); 
                pemesanan(); break;
        case 3:
                main(); break;

        default :
                main(); break;
        
    }
}

void input_harga(){
     int C;
    system("cls");
    printf("*\n");
    printf("* (1) KAMAR PREMIUM                     (1) *\n");
    printf("* (2) KAMAR BIASA                       (2) *\n");
    printf("* (3) BACK                              (3) *\n");
    printf("*\n");
    printf("Pilih:");scanf("%d",&C);getchar();
    switch(C){
        case 1:
                admin_premium(); break;
        case 2:
                admin_biasa(); break;
        case 3:
                main(); break;

        default :
                main(); break;
        
    }

}

void admin_premium(){
    FILE *f_premium;
    struct{
        double harga;
    }daftar;
    f_premium=fopen("daftar harga.dat","wb");//membuka file
        printf("INPUT HARGA KAMAR PREMIUM :");scanf("%lf",&daftar.harga);getchar();
        fwrite(&daftar,sizeof(daftar),1,f_premium);//proses menyimpan file
    
    fclose(f_premium);//menutup file
    menu_admin();
}

void user_premium(){
    FILE *f_premium;
    struct{
        double harga;
    }daftar;
    f_premium = fopen("daftar harga.dat","rb"); //membuka
    while(fread(&daftar, sizeof(daftar),1,f_premium)==1){ //proses
        printf("HARGA KAMAR PREMIUM : %2.f\n",daftar.harga);
    }
    fclose(f_premium); 
    //penutup
}

void admin_biasa(){
    FILE *f_biasa;
    struct{
        double harga;
    }daftar;
    f_biasa=fopen("daftar harga.dat","wb");//membuka file
        printf("INPUT HARGA KAMAR BIASA :");scanf("%lf",&daftar.harga);getchar();
        fwrite(&daftar,sizeof(daftar),1,f_biasa);//proses menyimpan file
    
    fclose(f_biasa);//menutup file
    menu_admin();
}

void user_biasa(){
    FILE *f_biasa;
    struct{
        double harga;
    }daftar;
    f_biasa = fopen("daftar harga.dat","rb"); //membuka
    while(fread(&daftar, sizeof(daftar),1,f_biasa)==1){ //proses
        printf("HARGA KAMAR BIASA : %2.f\n",daftar.harga);
    }
    fclose(f_biasa); //penutup
}

void ulasan(){
    FILE *f_ulasan;
    struct{
        char ulasan[99];
    }daftar;
    f_ulasan=fopen("daftar ulasan.dat","ab");//membuka file
        printf("MASUKKAN ULASAN ANDA : ");gets(daftar.ulasan);
        fwrite(&daftar,sizeof(daftar),1,f_ulasan);//proses menyimpan file
    
    fclose(f_ulasan);//menutup file
}

void lihat_ulasan(){
    FILE *f_ulasan;
    struct{
        char ulasan[99];
    }daftar;
    f_ulasan = fopen("daftar ulasan.dat","rb"); //membuka
    while(fread(&daftar, sizeof(daftar),1,f_ulasan)==1){ //proses
        printf("ULASAN : %s\n",daftar.ulasan);
    }
    fclose(f_ulasan); //penutup
}


void tipe_kost(){
     int C;
    system("cls");
    printf("*\n");
    printf("* (1) KOST CAMPUR                       (1) *\n");
    printf("* (2) KOST LAKI-LAKI                    (2) *\n");
    printf("* (3) KOST PEREMPUAN                    (3) *\n");
    printf("* (4) BACK                              (4) *\n");
    printf("*\n");
    printf("Pilih:");scanf("%d",&C);getchar();
    switch(C){
       case 1:
                menu_user(); break;
       case 2:
                menu_user(); break;
       case 3:
                menu_user(); break;
       case 4:
                main(); break;

        default :
                main(); break;

}
}

void pemesanan(){
    FILE *f_pemesanan;
    struct{
        char nama[30], email[30], tipe[30], dry[30], jaminan[30];
        int telpon;
    }b;
    f_pemesanan=fopen("b pemesanan.dat","ab");//membuka file
        printf("Nama Lengkap\t: ");gets(b.nama);
        printf("No Telpon\t:");scanf("%d",&b.telpon);getchar();
        printf("Alamat2 Email\t: ");gets(b.email);
        printf("Tipe Kamar (Premium/Biasa)\t: ");gets(b.tipe);
        printf("Laundry (Iya/Tidak)\t: ");gets(b.dry);
        printf("Jaminan (KTP, KK, PASPOR)\t: ");gets(b.jaminan);

        fwrite(&b,sizeof(b),1,f_pemesanan);//proses menyimpan file
    
    fclose(f_pemesanan);//menutup file
    menu_akhir();
}

void lihat_pemesanan(){
   FILE *f_pemesanan;
    struct{
        char nama[30], email[30], tipe[30], dry[30], jaminan[30];
        int telpon;
    }b;
    f_pemesanan = fopen("b pemesanan.dat","rb"); //membuka
    while(fread(&b, sizeof(b),1,f_pemesanan)==1){ //proses
        printf("Nama Lengkap: %s\n",b.nama);
        printf("No Telepon : %d\n",b.telpon);
        printf("Alamat Email: %s\n",b.email);
        printf("Tipe Kamar: %s\n",b.tipe);
        printf("Laundry: %s\n",b.dry);
        printf("Jaminan: %s\n",b.jaminan);
        printf("\n");
    }
    fclose(f_pemesanan); //penutup
    menu_admin();
}

void menu_akhir(){
    int opsi;
    printf("***********************************************\n");
    printf("* (1) Cek Total Biaya                   (1) *\n");
    printf("* (2) Opsi Pembayaran                   (2) *\n");
    printf("Pilih:");scanf("%d",&opsi);
    switch(opsi){
        case 1:
                cek_harga();break;
        case 2:
                pembayaran();break;
        default: 
                menu_akhir();break;
    }
}

void cek_harga(){
    int opsi,opsi1,opsi2;
    printf("***********************************************\n");
    printf("************* CEK HARGA       *****************\n");
    printf("***********************************************\n");
    printf("*************** Kamar yang Dipesan ************\n");
    printf("* (1) Premium                   (1) *\n");
    printf("* (2) Biasa                     (2) *\n");
    printf("SEGALA BENTUK TRANSFER YANG TIDAK SESUAI NOMINAL\n");
    printf("TIDAK AKAN DIPROSES!!\n");
    printf("Pilih:");scanf("%d",&opsi);
    switch(opsi){
        case 1:
                printf("*************** Kamar yang Dipesan ************\n");
                printf("* (1) Beralangganan Laundry                   (1) *\n");
                printf("* (2) Tidak Berlangganan Laundry              (2) *\n");
                printf("Pilih:");scanf("%d",&opsi1);
                if(opsi1==1){
                        user_premium();
                        printf("Harga Berlangganan Laundry:500.0000\n");
                        printf("Total Harga: Harga Kos + 500.000\n");
                        pembayaran(); }
                else{
                        user_premium();
                        pembayaran();
                } //HARUSNYA PAKE BREAK, KARENA GK PAKE BREAK SETELAH CASE 1 LANGSUNG CASE 2
        case 2:
                printf("*************** Kamar yang Dipesan ************\n");
                printf("* (1) Beralangganan Laundry                   (1) *\n");
                printf("* (2) Tidak Berlangganan Laundry              (2) *\n");
                printf("Pilih:");scanf("%d",&opsi2);
                if(opsi2==1){
                        user_biasa();
                        printf("Harga Berlangganan Laundry:500.0000\n");
                        printf("Total Harga: Harga Kos + 500.000\n");
                        pembayaran();
                }
                else{
                        user_biasa();
                        pembayaran();
                }
    }

}


void pembayaran(){
    int opsi;
    printf("***********************************************\n");
    printf("************* OPSI PEMBAYARAN *****************\n");
    printf("***********************************************\n");
    printf("* (1) BCA                               (1) *\n");
    printf("* (2) BRI                               (2) *\n");
    printf("* (3) QRIS                              (3) *\n");
    printf("SEGALA BENTUK TRANSFER YANG TIDAK SESUAI NOMINAL\n");
    printf("TIDAK AKAN DIPROSES!!\n");
    printf("Pilih:");scanf("%d",&opsi);
    switch(opsi){
        case 1:
                printf("Anda Memilih BCA Sebagai Opsi Pembayaran\n");
                printf("Silahkan Transfer ke No Rekening Berikut: 0001-01-011822-53-4 (An. Roy)\n");
                printf("Kwitansi Kos akan Diberikan Oleh Admin Kepada Gmail yang User Berikan\n");
                printf("Silahkan Menunggu dalam Waktu 1x24 jam\n");
                printf("TERIMA KASIH");
                break;
        case 2:
                printf("Anda Memilih BRI Sebagai Opsi Pembayaran\n");
                printf("Silahkan Transfer ke No Rekening Berikut: 070-00-018555-5 (An. Roy)\n");
                printf("Kwitansi Kos akan Diberikan Oleh Admin Kepada Gmail yang User Berikan\n");
                printf("Silahkan Menunggu dalam Waktu 1x24 jam\n");
                printf("TERIMA KASIH");
                break;
        case 3:
                printf("Anda Memilih QRIS Sebagai Opsi Pembayaran\n");
                printf("Silahkan Transfer ke No Rekening Berikut: 0867-5635-3429 (An. Kiyoshi)\n");
                printf("Kwitansi Kos akan Diberikan Oleh Admin Kepada Gmail yang User Berikan\n");
                printf("Silahkan Menunggu dalam Waktu 1x24 jam\n");
                printf("TERIMA KASIH");
                break;
        default: pembayaran();
    }
}