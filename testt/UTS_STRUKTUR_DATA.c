#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maksimal 20

typedef struct Mahasiswa {
    char nama[50];
    char jenis_kelamin;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *pList = NULL;
Mahasiswa *lingkaran_laki_laki = NULL;
Mahasiswa *lingkaran_perempuan = NULL;
int jumlah_mahasiswa = 0;
int jumlah_mahasiswi = 0;

void tampilkan_lingkaran(Mahasiswa *pList, const char *nama_lingkaran);

Mahasiswa* node(const char *nama, char jenis_kelamin) {
    Mahasiswa *pNew = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    strcpy(pNew->nama, nama);
    pNew->jenis_kelamin = jenis_kelamin;
    pNew->next = pNew;
    return pNew;
}

void tambah_mahasiswa(const char *nama, char jenis_kelamin) {
    if (jumlah_mahasiswa + jumlah_mahasiswi >= Maksimal) {
        printf("Tidak dapat menambahkan %s, kapasitas sudah penuh.\n", nama);
        return;
    }
    Mahasiswa *pNew = node(nama, jenis_kelamin);
    if (pList == NULL) {
        pList = pNew;
    } else {
        Mahasiswa *pCur = pList;
        while (pCur->next != pList) {
            pCur = pCur->next;
        }
        pCur->next = pNew;
        pNew->next = pList;
    }
    if (jenis_kelamin == 'L') {
        jumlah_mahasiswa++;
    } else if (jenis_kelamin == 'P') {
        jumlah_mahasiswi++;
    }

    printf("%s berhasil masuk ke dalam lingkaran besar.\n", nama);
}

void hapus_mahasiswa(const char *nama) {
    if (pList == NULL) {
        printf("Lingkaran besar kosong, tidak ada yang dapat dihapus.\n");
        return;
    }

    Mahasiswa *pCur = pList;
    Mahasiswa *pPre = NULL;

    do {
        if (strcmp(pCur->nama, nama) == 0) {
            if (pCur->next == pCur) {
                pList = NULL;
            } else {
                if (pPre != NULL) {
                    pPre->next = pCur->next;
                } else {
                    Mahasiswa *last = pList;
                    while (last->next != pList) {
                        last = last->next;
                    }
                    last->next = pCur->next;
                    pList = pCur->next;
                }
            }

            if (pCur->jenis_kelamin == 'L') {
                jumlah_mahasiswa--;
            } else if (pCur->jenis_kelamin == 'P') {
                jumlah_mahasiswi--;
            }

            free(pCur);
            printf("%s berhasil dihapus dari lingkaran besar.\n", nama);
            return;
        }
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("%s tidak ditemukan dalam lingkaran besar.\n", nama);
}

void pisahkan_dan_tampilkan_lingkaran() {
    lingkaran_laki_laki = NULL;
    lingkaran_perempuan = NULL;

    if (pList == NULL) {
        printf("Lingkaran besar kosong, tidak ada yang dapat dipisahkan.\n");
        return;
    }

    Mahasiswa *pCur = pList;
    do {
        Mahasiswa *pNew = node(pCur->nama, pCur->jenis_kelamin);
        if (pCur->jenis_kelamin == 'L') {
            if (lingkaran_laki_laki == NULL) {
                lingkaran_laki_laki = pNew;
            } else {
                Mahasiswa *tempL = lingkaran_laki_laki;
                while (tempL->next != lingkaran_laki_laki) {
                    tempL = tempL->next;
                }
                tempL->next = pNew;
                pNew->next = lingkaran_laki_laki;
            }
        } else if (pCur->jenis_kelamin == 'P') {
            if (lingkaran_perempuan == NULL) {
                lingkaran_perempuan = pNew;
            } else {
                Mahasiswa *tempP = lingkaran_perempuan;
                while (tempP->next != lingkaran_perempuan) {
                    tempP = tempP->next;
                }
                tempP->next = pNew;
                pNew->next = lingkaran_perempuan;
            }
        }

        pCur = pCur->next;
    } while (pCur != pList);

    tampilkan_lingkaran(lingkaran_laki_laki, "Lingkaran Laki-Laki");
    tampilkan_lingkaran(lingkaran_perempuan, "Lingkaran Perempuan");
}

void tampilkan_lingkaran(Mahasiswa *pList, const char *nama_lingkaran) {
    if (pList == NULL) {
        printf("%s kosong.\n", nama_lingkaran);
        return;
    }

    printf("\n%s:\n", nama_lingkaran);
    Mahasiswa *pCur = pList;
    do {
        printf("-> %s (%c) ", pCur->nama, pCur->jenis_kelamin);
        pCur = pCur->next;
    } while (pCur != pList);
    printf("\n");
}

int main() {
    int pilihan;
    char nama[50];
    char jenis_kelamin;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah mahasiswa\n");
        printf("2. Tampilkan lingkaran api unggun\n");
        printf("3. Lingkaran kecil laki-laki dan perempuan\n");
        printf("4. Hapus mahasiswa dari lingkaran besar\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                tambah_mahasiswa(nama, jenis_kelamin);
                break;
            case 2:
                tampilkan_lingkaran(pList, "Lingkaran Besar");
                break;
            case 3:
                pisahkan_dan_tampilkan_lingkaran();
                break;
            case 4:
                printf("Masukkan nama yang ingin dihapus: ");
                scanf("%s", nama);
                hapus_mahasiswa(nama);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
