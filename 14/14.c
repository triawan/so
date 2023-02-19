#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
void *fun1();
void *fun2();
int shared = 1;
sem_t s;
int main()
{
    sem_init(&s, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Nilai akhir shared adalah : %d\n", shared);
}
void *fun1()
{
    int x;
    sem_wait(&s);
    x = shared;
    printf("Thread1 membaca nilai sebagai : %d\n", x);
    x = x + 1;
    printf("Pembaruan lokal oleh Thread1 : %d\n", x);
    sleep(1);
    shared = x;
    printf("Nilai variabel shared yang diperbarui oleh Thread1 adalah : %d\n", shared);
    sem_post(&s);
}
void *fun2()
{
    int y;
    sem_wait(&s);
    y = shared;
    printf("Thread2 membaca nilai sebagai : %d\n", y);
    y = y - 1;
    printf("Pembaruan lokal oleh Thread2 : %d\n", y);
    sleep(1);
    shared = y;
    printf("Nilai variabel shared yang diperbarui oleh Thread2 adalah : %d\n", shared);
    sem_post(&s);
}