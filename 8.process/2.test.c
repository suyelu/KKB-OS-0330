/*************************************************************************
	> File Name: 2.test.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Mon 25 Apr 2022 03:14:23 PM CST
 ************************************************************************/
#include "head.h"
int *buff;
int opt, p_num = 1, c_num = 1, buffsize = 100, now = 0, buff_now = 0;
void *producer_work(void *arg);
void *consumer_work(void *arg);
semaphore mutex, full, empty; //定义信号量

void usage(char *arg0){
    fprintf(stderr, "Usage : %s -p num -c num\n", arg0);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 7) usage(argv[0]);
   // 0 1 2
    while ((opt = getopt(argc, argv, "p:c:b:")) != -1) {
        switch (opt) {
            case 'p':
                p_num = atoi(optarg); // option arg
                break;
            case 'c':
                c_num = atoi(optarg);
                break;
            case 'b':
                buffsize = atoi(optarg);
                break;
            default:
                usage(argv[0]);
        }
    }

    mutex = make_semaphore(1);
    full = make_semaphore(0);
    empty = make_semaphore(buffsize);


    buff = (int *)calloc(buffsize, sizeof(int));

    for (int i = 0; i < p_num; i++) {
        pthread_t tid; //pcb -> pid // tcb -> tid 
        pthread_create(&tid, NULL, producer_work, NULL);
    }


    for (int i = 0; i < c_num; i++) {
        pthread_t tid;
        pthread_create(&tid, NULL, consumer_work, NULL);
    }


    sleep(2000);

    return 0;
}



void *producer_work(void *arg) {
    while (1) {
        rsleep(0.5);
        DBG(YELLOW"生产了一个商品"NONE);
        P(empty);
        P(mutex);
        buff[buff_now++] = now++;
        DBG(RED"Producer ->"NONE"%d ,  %d nums in buff\n", now - 1, buff_now);
        V(mutex);
        V(full);
    }
    return NULL;
}

void *consumer_work(void *arg) {
    while (1) {
        P(full);
        P(mutex);
        DBG(GREEN"Consumer ->"NONE"%d, %d nums in buff\n", buff[buff_now - 1], buff_now - 1);
        buff[--buff_now] = 0;
        V(mutex);
        V(empty);
        rsleep(0.7);
    }
    return NULL;
}
