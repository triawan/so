#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i, shmid;
    void *shared_memory;
    char buff[100];
    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key shared memory adalah : %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Proses terlampir di : %p\n", shared_memory);
    printf("Data yang dibaca dari shared memory adalah : %s", (char *)shared_memory);
}
