#include <stdio.h>
#include <string.h>

int hitung_jumlah_kata(char *kalimat) {
    int jumlah_kata = 0;
    int di_tengah_kata = 0;
    
    for (int i = 0; kalimat[i] != '\0'; i++) {
        if (kalimat[i] == ' ') {
            di_tengah_kata = 0;
        } else if (di_tengah_kata == 0) {
            di_tengah_kata = 1;
            jumlah_kata++;
        }
    }
    return jumlah_kata;
}

int validasi_email(char *email) {
    char *tanda_kaidah = "@";
    char *domain_email = ".ac.id";
    return (strstr(email, tanda_kaidah) != NULL && strstr(email, domain_email) != NULL);
}

void format_jurnal(char *judul_jurnal, char *nama_penulis, char *afiliasi_penulis, char *email_penulis, char *abstrak_jurnal, char *kata_kunci_jurnal, char *hasil_jurnal) {
    sprintf(hasil_jurnal, 
            "\n%s\n\n" //judul
            "%s\n" //penulis
            "%s\n" // afiliasi
            "Email : %s\n" //email
            "Abstrak.%s\n" // abstrak
            "Katakunci:%s\n", //katakucni
            judul_jurnal, nama_penulis, afiliasi_penulis, email_penulis, abstrak_jurnal, kata_kunci_jurnal);
}

int main() {
    char judul_jurnal[100];
    char nama_penulis[100];
    char email_penulis[100];
    char afiliasi_penulis[100];
    char abstrak_jurnal[300];
    char kata_kunci_jurnal[100];
    char hasil_jurnal[1000];
    
    while (1) {
        printf("Masukkan Judul Jurnal (5-14 kata): ");
        fgets(judul_jurnal, sizeof(judul_jurnal), stdin);
        judul_jurnal[strcspn(judul_jurnal, "\n")] = '\0'; 

        if (strlen(judul_jurnal) > 0 && hitung_jumlah_kata(judul_jurnal) >= 5 && hitung_jumlah_kata(judul_jurnal) <= 14) {
            break;
        } else {
            printf("Judul harus diisi dan terdiri dari 5-14 kata. Coba lagi.\n");
        }
    }
    
    while (1) {
        printf("Masukkan Nama Penulis (maksimal 3 penulis, dipisahkan koma): ");
        fgets(nama_penulis, sizeof(nama_penulis), stdin);
        nama_penulis[strcspn(nama_penulis, "\n")] = '\0'; 

        int jumlah_koma = 0;
        for (int i = 0; nama_penulis[i] != '\0'; i++) {
            if (nama_penulis[i] == ',') {
                jumlah_koma++;
            }
        }

        if (strlen(nama_penulis) > 0 && jumlah_koma <= 2 && nama_penulis[0] != ',') { 
            break;
        } else {
            printf("Penulis harus diisi dan maksimal 3 penulis, dipisahkan dengan koma. Coba lagi.\n");
        }
    }
    
    while (1) {
        printf("Masukkan Afiliasi Penulis: ");
        fgets(afiliasi_penulis, sizeof(afiliasi_penulis), stdin);
        afiliasi_penulis[strcspn(afiliasi_penulis, "\n")] = '\0';

        if (strlen(afiliasi_penulis) > 0) {
            break;
        } else {
            printf("Afiliasi tidak boleh kosong. Coba lagi.\n");
        }
    }
    
    while (1) {
        printf("Masukkan Email Penulis (harus memakai '@' dan berdomain '.ac.id'): ");
        fgets(email_penulis, sizeof(email_penulis), stdin);
        email_penulis[strcspn(email_penulis, "\n")] = '\0';

        if (strlen(email_penulis) > 0 && validasi_email(email_penulis)) {
            break;
        } else {
            printf("Email harus memakai '@' dan berdomain .ac.id. Coba lagi.\n");
        }
    }
    
    while (1) {
        printf("Masukkan Abstrak Jurnal (maksimal 200 kata): ");
        fgets(abstrak_jurnal, sizeof(abstrak_jurnal), stdin);
        abstrak_jurnal[strcspn(abstrak_jurnal, "\n")] = '\0';

        if (strlen(abstrak_jurnal) > 0 && hitung_jumlah_kata(abstrak_jurnal) <= 200) {
            break;
        } else {
            printf("Abstrak harus diisi dan maksimal memiliki 200 kata. Coba lagi.\n");
        }
    }
    
    while (1) {
        printf("Masukkan Kata Kunci (3-5 kata, dipisahkan koma): ");
        fgets(kata_kunci_jurnal, sizeof(kata_kunci_jurnal), stdin);
        kata_kunci_jurnal[strcspn(kata_kunci_jurnal, "\n")] = '\0';

        int jumlah_koma = 0;
        for (int i = 0; kata_kunci_jurnal[i] != '\0'; i++) {
            if (kata_kunci_jurnal[i] == ',') {
                jumlah_koma++;
            }
        }

        if (strlen(kata_kunci_jurnal) > 0 && jumlah_koma >= 2 && jumlah_koma <= 4 && kata_kunci_jurnal[0] != ',') { 
            break;
        } else {
            printf("Kata kunci harus terdiri dari 3-5 kata dipisahkan koma. Coba lagi.\n");
        }
    }

    system ("cls");

    format_jurnal(judul_jurnal, nama_penulis, afiliasi_penulis, email_penulis, abstrak_jurnal, kata_kunci_jurnal, hasil_jurnal);
    
    printf("%s", hasil_jurnal);

    return 0;
}
