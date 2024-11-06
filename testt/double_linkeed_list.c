#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void hapusAwal(node **head);
void hapusTengah(node **head, int bil);
void hapusAkhir(node **head);
void cariData(node *head, int bil);
int jumlahData(node *head);
int totalData(node *head);

int main() {
    node *head = NULL;
    char pilih;
    int bil;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("0. Tambah data di awal\n");
        printf("1. Tambah data di tengah list\n");
        printf("2. Tambah data di akhir list\n");
        printf("3. Cetak isi list\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Tampilkan jumlah data\n");
        printf("9. Tampilkan total penjumlahan data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        scanf(" %c", &pilih);

        switch (pilih) {
            case '0': tambahAwal(&head); break;
            case '1': tambahData(&head); break;
            case '2': tambahAkhir(&head); break;
            case '3': tranverse(head); break;
            case '4': hapusAwal(&head); break;
            case '5': 
                printf("Masukkan nilai data yang ingin dihapus: ");
                scanf("%d", &bil);
                hapusTengah(&head, bil); 
                break; 
            case '6': hapusAkhir(&head); break;
            case '7': 
                printf("Masukkan nilai yang ingin dicari: ");
                scanf("%d", &bil); 
                cariData(head, bil); 
                break; 
            case '8': 
                printf("Jumlah data: %d\n", jumlahData(head)); 
                break; 
            case '9': 
                printf("Total penjumlahan data: %d\n", totalData(head)); 
                break;
            case 'q': break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }

        if (pilih != 'q') {
            printf("Tekan Enter untuk melanjutkan...\n");
            getchar();  
            getchar();  
        }
    } while (pilih != 'q');

    while (head != NULL) {
        hapusAwal(&head);
    }

    return 0;
}

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew) {
        pNew->data = bil;
        pNew->next = *head;
        pNew->prev = NULL;
        
        if (*head != NULL) {
            (*head)->prev = pNew;
        }
        
        *head = pNew;
        printf("Data %d berhasil ditambahkan di awal.\n", bil);
    } else {
        printf("Alokasi memori gagal\n");
    }
}

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("Bilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    while (pCur && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (!pCur) {
        printf("Node tidak ditemukan\n");
    } else if (!pNew) {
        printf("Alokasi memori gagal\n");
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pNew->prev = pCur;

        if (pCur->next != NULL) {
            pCur->next->prev = pNew;
        }
        pCur->next = pNew;
        printf("Data %d berhasil ditambahkan setelah %d.\n", bil, pos);
    }
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew) {
        pNew->data = bil;
        pNew->next = NULL;

        if (!*head) {
            pNew->prev = NULL;
            *head = pNew;
            printf("Data %d berhasil ditambahkan di akhir.\n", bil);
        } else {
            pCur = *head;
            while (pCur->next) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->prev = pCur;
            printf("Data %d berhasil ditambahkan di akhir.\n", bil);
        }
    } else {
        printf("Alokasi memori gagal\n");
    }
}

void tranverse(node *head) {
    node *pWalker = head;

    if (!pWalker) {
        printf("List kosong\n");
        return;
    }

    printf("Isi list: ");
    while (pWalker) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

void hapusAwal(node **head) {
    node *pDel;

    if (!*head) {
        printf("List kosong!\n");
    } else {
        pDel = *head;
        *head = (*head)->next;

        if (*head != NULL) {
            (*head)->prev = NULL;
        }

        free(pDel);
        printf("Data di awal berhasil dihapus!\n");
    }
}

void hapusTengah(node **head, int bil) {
    node *pCur = *head;

    if (!*head) {
        printf("List kosong!\n");
    } else {
        while (pCur && pCur->data != bil) {
            pCur = pCur->next;
        }

        if (!pCur) {
            printf("Data tidak ditemukan!\n");
        } else {
            if (pCur->prev != NULL) {
                pCur->prev->next = pCur->next;
            }
            if (pCur->next != NULL) {
                pCur->next->prev = pCur->prev;
            }
            if (pCur == *head) {
                *head = pCur->next;
            }
            free(pCur);
            printf("Data %d berhasil dihapus!\n", bil);
        }
    }
}

void hapusAkhir(node **head) {
    node *pCur = *head;

    if (!*head) {
        printf("List kosong!\n");
    } else {
        while (pCur->next) {
            pCur = pCur->next;
        }

        if (pCur->prev != NULL) {
            pCur->prev->next = NULL;
        } else {
            *head = NULL;
        }

        free(pCur);
        printf("Data di akhir berhasil dihapus!\n");
    }
}

void cariData(node *head, int bil) {
    node *pCur = head;

    while (pCur) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan!\n", bil);
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan!\n", bil);
}

int jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur) {
        count++;
        pCur = pCur->next;
    }

    return count;
}

int totalData(node *head) {
    int total = 0;
    node *pCur = head;

    while (pCur) {
        total += pCur->data;
        pCur = pCur->next;
    }

    return total;
}
