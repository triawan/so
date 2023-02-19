#include <stdio.h>
#include <dirent.h>
void print_apapun_yang_ada_di_folder(const char *directory_path);
int main(void)
{
    char directory_path[256] = {0};
    printf("[?] MASUKKAN DIRECTORY_PATH: ");
    scanf("%s", directory_path);
    printf("[!] PATH = %s\n\n", directory_path);
    print_apapun_yang_ada_di_folder(directory_path);
    return 0;
}
void print_apapun_yang_ada_di_folder(const char *directory_path)
{
    if (directory_path == NULL)
    {
        fprintf(stderr, "argumen directory_path nya null\n");
        return;
    }
    DIR *d = opendir(directory_path);
    if (d == NULL)
    {
        fprintf(stderr, "[!] Directory path tidak diketahui\n");
        return;
    }
    printf("===============================================\n");
    printf("\tPrint semua berkas dan direktori\n");
    printf("===============================================\n");
    printf("TYPE \t\t| NAME\n");
    printf("-----------------------------------------------\n");
    struct dirent *dir = NULL;
    while ((dir = readdir(d)) != NULL)
    {
        switch (dir->d_type)
        {
        case DT_REG:
            printf("FILE\t\t| %s\n", dir->d_name);
            break;

        case DT_DIR:
            printf("DIRECTORY\t| %s\n", dir->d_name);
            break;

        case DT_FIFO:
            printf("FIFO\t| %s\n", dir->d_name);
            break;
        case DT_SOCK:
            printf("SOCKET\t| %s\n", dir->d_name);
            break;

        case DT_CHR:
            printf("CHAR DEVICE\t| %s\n", dir->d_name);
            break;

        case DT_BLK:
            printf("BLOCK DEVICE\t| %s\n", dir->d_name);
            break;

        case DT_LNK:
            printf("SYMBOLIC LINK\t| %s\n", dir->d_name);
            break;

        case DT_UNKNOWN:
            printf("UNKNOWN\t| %s\n", dir->d_name);
            break;
        }
    }
    printf("\n");
    closedir(d);
}
