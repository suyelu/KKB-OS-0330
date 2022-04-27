/*************************************************************************
	> File Name: 1.reader_writer.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 27 Apr 2022 03:01:06 PM CST
 ************************************************************************/
#include "head.h"

int count = 0, reader_num = 0,  writer_num = 0,  writer_sleep = 0;
semaphore rw, mutex;

void Usage(const char *argv) {
    fprintf(stderr, "Usage : %s -w writer_num -r reader_num -W writer_sleep.\n", argv);
    exit(1);
}

void *reader(void *arg) {
    int id = *(int *)arg;
    rsleep(2 * (id + 1));
    free((int *)arg);
    DBG(GREEN"Reader "BLUE"%d"NONE" starts..\n", id);
    P(mutex);
    if (count == 0) {
        DBG(GREEN"Reader "BLUE"%d"NONE" is the "RED"first"NONE" reader...\n", id);
        P(rw);
        DBG(GREEN"Reader "BLUE"%d"NONE" got the "YELLOW"rw"NONE" lock...\n", id);
    }
    count++;
    V(mutex);
    rsleep(20);
    DBG(GREEN"Reader "BLUE"%d"GREEN" finished reading...\n", id);
    P(mutex);
    count--;
    if (count == 0) {
        DBG(GREEN"Reader "BLUE"%d"NONE" is the "RED"last one"NONE" reader...\n", id);
        V(rw);
        DBG(GREEN"Reader "BLUE"%d"NONE" released the "YELLOW"rw"NONE" lock...\n", id);
    }
    V(mutex);
    DBG(GREEN"Reader "BLUE"%d"NONE" ends..\n", id);
}


void *writer(void *arg) {
    int id = *(int *)arg;
    free((int *)arg);
    rsleep(2 * (id + 1));
    DBG(CYAN"Writer "BLUE"%d"NONE" starts..\n", id);
    P(rw);
    DBG(CYAN"Writer "BLUE"%d"NONE"got the"YELLOW" rw "NONE"lock..\n", id);
    rsleep(10);
    DBG(CYAN"Writer "BLUE"%d"NONE" ends writing..\n", id);
    V(rw);
    DBG(CYAN"Writer "BLUE"%d"NONE" released the "YELLOW"rw" NONE"lock, left...\n", id);
}


int main(int argc, char **argv) {
    if (argc == 1) {
        Usage(argv[0]);
        exit(1);
    }
    int opt;
    while ((opt = getopt(argc, argv, "w:r:W:")) != -1) {
        switch(opt) {
            case 'r':
                reader_num = atoi(optarg);
                break;
            case 'w':
                writer_num = atoi(optarg);
                break;
            case 'W':
                writer_sleep = atoi(optarg);
                break;
            default:
                Usage(argv[0]);
                exit(1);
        }
    }
    rw = make_semaphore(1);
    mutex = make_semaphore(1);
    DBG(PINK"Readers will start in "RED"%d"NONE" seconds.\n", 5);
    DBG(PINK"Writers will start in "RED"%d"NONE" seconds.\n", writer_sleep);
    for (int i = 0; i < reader_num; i++) {
        pthread_t tid;
        int *id = (int *)calloc(1, sizeof(int));
        *id = i;
        pthread_create(&tid, NULL, reader, (void *)id);
    }

    for (int i = 0; i < writer_num; i++) {
        pthread_t tid;
        int *id = (int *)calloc(1, sizeof(int));
        *id = i;
        pthread_create(&tid, NULL, writer, (void *)id);
    }

    sleep(1000);
    return 0;
}
