#include <stdio.h>
int main()
{
    int page[50], i, n, f, ps, off, pno;
    printf("\nMasukkan nomor halaman memori : ");
    scanf("%d", &n);
    printf("\nMasukkan ukuran halaman : ");
    scanf("%d", &ps);
    printf("\nMasukkan nomor frames : ");
    scanf("%d", &f);
    for (i = 0; i < n; i++)
    {
        page[i] = -1;
    }
    printf("\nMasukkan tabel halaman");
    printf("(Masukkan nomor frame = -1 jika halaman itu tidak ada di frame mana pun) \n");
    printf("\nNomor Halaman :\tNomor Frame :");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t", i);
        scanf("%d", &page[i]);
    }
    printf("\nAlamat Logikal (nomor halaman & offset) : ");
    scanf("%d%d", &pno, &off);
    if (page[pno] == -1)
    {
        printf("\nHalaman yang diperlukan tidak tersedia di frame mana pun");
    }
    else
    {
        printf("\nAlamat fisikal (nomor frame & offset) : %d, %d\n", page[pno], off);
    }
    return 0;
}
