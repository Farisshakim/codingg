#include <stdio.h>
#include <string.h>

typedef struct {
    char npm[20];
    char nama[50];
    char prodi[30];
    float ipk;
} Mahasiswa;

void swap(Mahasiswa *a, Mahasiswa *b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Mahasiswa mhs[], int n, char key[], int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int condition = 0;
            if (strcmp(key, "npm") == 0) {
                condition = ascending ? strcmp(mhs[j].npm, mhs[j + 1].npm) > 0 : strcmp(mhs[j].npm, mhs[j + 1].npm) < 0;
            } else if (strcmp(key, "nama") == 0) {
                condition = ascending ? strcmp(mhs[j].nama, mhs[j + 1].nama) > 0 : strcmp(mhs[j].nama, mhs[j + 1].nama) < 0;
            } else if (strcmp(key, "prodi") == 0) {
                condition = ascending ? strcmp(mhs[j].prodi, mhs[j + 1].prodi) > 0 : strcmp(mhs[j].prodi, mhs[j + 1].prodi) < 0;
            } else if (strcmp(key, "ipk") == 0) {
                condition = ascending ? mhs[j].ipk > mhs[j + 1].ipk : mhs[j].ipk < mhs[j + 1].ipk;
            }

            if (condition) {
                swap(&mhs[j], &mhs[j + 1]);
            }
        }
    }
}

// Menampilkan data mahasiswa
void printData(Mahasiswa mhs[], int n) {
    printf("NPM\t\tNama\t\t\tProdi\t\t\tIPK\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%-20s\t%-20s\t%.2f\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
}

int main() {
    Mahasiswa mhs[] = {
      {"23081010001", "Andi Wijaya", "Informatika", 3.75},
        {"23082010003", "Budi Santoso", "Sistem Informasi", 3.97},
        {"23083010005", "Citra Dewi", "Sains Data", 3.50},
        {"23084010002", "Dedi Pratama", "Bisnis Digital", 3.95},
        {"23081010004", "Eka Saputra", "Informatika", 3.68},
        {"23081010009", "Kukuh Sanjaya", "Informatika", 3.76},
        {"23082010002", "Rahman Nur", "Sistem Informasi", 3.95},
        {"23082010004", "Ahmad Ghroi", "Sistem Informasi", 3.51},
        {"23084010009", "Taufik Hidayah", "Informatika", 3.73},
        {"23083010012", "Wahyu Saputra", "Sains Data", 3.20},
        {"23084010015", "Angel Witjaksana", "Bisnis Digital", 4.00}
    };

    int n = sizeof(mhs) / sizeof(mhs[0]);
    int choice;

    do {
        printf("\nMenu Sorting:\n");
        printf("1. Sort by NPM (Ascending)\n");
        printf("2. Sort by NPM (Descending)\n");
        printf("3. Sort by Nama (A-Z)\n");
        printf("4. Sort by Nama (Z-A)\n");
        printf("5. Sort by Prodi (A-Z)\n");
        printf("6. Sort by Prodi (Z-A)\n");
        printf("7. Sort by IPK (Ascending)\n");
        printf("8. Sort by IPK (Descending)\n");
        printf("0. Exit\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(mhs, n, "npm", 1);
                printf("\nData setelah diurutkan berdasarkan NPM (Ascending):\n");
                printData(mhs, n);
                break;
            case 2:
                bubbleSort(mhs, n, "npm", 0);
                printf("\nData setelah diurutkan berdasarkan NPM (Descending):\n");
                printData(mhs, n);
                break;
            case 3:
                bubbleSort(mhs, n, "nama", 1);
                printf("\nData setelah diurutkan berdasarkan Nama (A-Z):\n");
                printData(mhs, n);
                break;
            case 4:
                bubbleSort(mhs, n, "nama", 0);
                printf("\nData setelah diurutkan berdasarkan Nama (Z-A):\n");
                printData(mhs, n);
                break;
            case 5:
                bubbleSort(mhs, n, "prodi", 1);
                printf("\nData setelah diurutkan berdasarkan Prodi (A-Z):\n");
                printData(mhs, n);
                break;
            case 6:
                bubbleSort(mhs, n, "prodi", 0);
                printf("\nData setelah diurutkan berdasarkan Prodi (Z-A):\n");
                printData(mhs, n);
                break;
            case 7:
                bubbleSort(mhs, n, "ipk", 1);
                printf("\nData setelah diurutkan berdasarkan IPK (Ascending):\n");
                printData(mhs, n);
                break;
            case 8:
                bubbleSort(mhs, n, "ipk", 0);
                printf("\nData setelah diurutkan berdasarkan IPK (Descending):\n");
                printData(mhs, n);
                break;
            case 0:
                printf("Keluar program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}
