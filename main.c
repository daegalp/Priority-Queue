#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct antrian queue;
typedef char itemType;
struct antrian{
    itemType data;
    int prioritas;
    queue *next;
};
void inisialisasi(queue *);
void enqueue(queue *);
void dequeue(queue *);
void free_queue(queue *);
void tampil(queue *);
void insert_awal();
void insert_akhir();
void insert_before();
void alokasi();
queue *front=NULL, *rear=NULL, *p, *hapus, *cari, *pbef;
int main()
{
    int menu;
    queue antrian;
    printf("Queue Prioritas\n");
    do
    {
        printf("\nMenu Queue\n");
        printf("\nPilihan Menu : 1. Mengisi Queue (Enqueue)");
        printf("\n               2. Mengambil isi Queue (Dequeue)");
        printf("\n               3. Menampilkan isi Queue (FIFO)");
        printf("\n               4. Keluar");
        printf("\nSilahkan pilih menu : ");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1 : alokasi();
                     enqueue(&antrian);
                     break;
            case 2 : dequeue(&antrian);
                     break;
            case 3 : tampil(&antrian);
                     break;
            case 4 : exit(0);
            default : printf("Maaf menu tidak tersedia\n");
                      break;
        }
    }while(menu!=4);
    return 0;
}
void alokasi()
{
    p = (queue *)malloc(sizeof(queue));
    if(p == NULL)
        exit(0);
    fflush(stdin);
    printf("Masukkan data : ");
    scanf("%c", &p->data);
    fflush(stdin);
    printf("Masukkan prioritas : ");
    scanf("%d", &p->prioritas);
    p->next = NULL;
    fflush(stdin);
}
void enqueue(queue *q)
{
    cari = front;
    if(front == NULL)
        front = p;
    else
    {
        while(cari->prioritas <= p->prioritas)
        {
            if(cari->next == NULL)
                break;
            else{
                pbef = cari;
                cari = cari->next;
            }
        }
        if(cari->next == NULL && cari->prioritas <= p->prioritas)
            insert_akhir();
        else
            insert_before();
    }
}
void dequeue(queue *q)
{
    hapus = front;
    if(hapus==NULL)
        printf("Queue Kosong !\n");
    else{
        front = hapus->next;
        printf("Data %c telah dihapus\n", hapus->data);
        free_queue(hapus);
    }
}
void free_queue(queue *x)
{
    free(x);
    x = NULL;
}
void tampil(queue *q)
{
    queue *baca;
    baca = front;
    if(baca==NULL)
        printf("Queue Kosong !\n");
    else
    {
        puts("\nIsi dari Queue");
        puts("Data\tPrioritas");
        while(baca != NULL)
        {
            printf("%c\t%d\n", baca->data, baca->prioritas);
            baca = baca->next;
        }
    }
}
void insert_awal()
{
    p->next = front;
    front = p;
}
void insert_akhir()
{
    cari->next = p ;
    rear = p;
}
void insert_before()
{
    if(cari == front)
        insert_awal();
    else{
        p->next = cari;
        pbef->next = p;
    }
}
