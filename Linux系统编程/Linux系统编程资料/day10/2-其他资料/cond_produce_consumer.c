#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void err_thread(int ret, char *str)
{
    if (ret != 0) {
        fprintf(stderr, "%s:%s\n", str, strerror(ret));
        pthread_exit(NULL);
    }
}

struct msg {
    int num;
    struct msg *next;
};

struct msg *head;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;      // 定义/初始化一个互斥量
pthread_cond_t has_data = PTHREAD_COND_INITIALIZER;      // 定义/初始化一个条件变量

void *produser(void *arg)
{
    while (1) {
        struct msg *mp = malloc(sizeof(struct msg));

        mp->num = rand() % 1000 + 1;                        // 模拟生产一个数据`
        printf("--produce %d\n", mp->num);

        pthread_mutex_lock(&mutex);                         // 加锁 互斥量
        mp->next = head;                                    // 写公共区域
        head = mp;
        pthread_mutex_unlock(&mutex);                       // 解锁 互斥量

        pthread_cond_signal(&has_data);                     // 唤醒阻塞在条件变量 has_data上的线程.

        sleep(rand() % 3);
    }

    return NULL;
}

void *consumer(void *arg)
{
    while (1) {
        struct msg *mp;

        pthread_mutex_lock(&mutex);                         // 加锁 互斥量
        if (head == NULL) {
            pthread_cond_wait(&has_data, &mutex);           // 阻塞等待条件变量, 解锁
        }                                                   // pthread_cond_wait 返回时, 重写加锁 mutex

        mp = head;
        head = mp->next;

        pthread_mutex_unlock(&mutex);                       // 解锁 互斥量
        printf("---------consumer:%d\n", mp->num);

        free(mp);
        sleep(rand()%3);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int ret;
    pthread_t pid, cid;

    srand(time(NULL));

    ret = pthread_create(&pid, NULL, produser, NULL);           // 生产者
    if (ret != 0) 
        err_thread(ret, "pthread_create produser error");

    ret = pthread_create(&cid, NULL, consumer, NULL);           // 消费者
    if (ret != 0) 
        err_thread(ret, "pthread_create consuer error");

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
