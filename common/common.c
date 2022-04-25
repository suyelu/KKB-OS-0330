/*************************************************************************
	> File Name: ../common/common.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Fri 22 Apr 2022 06:07:52 PM CST
 ************************************************************************/

#include "head.h"
void perror_exit(const char *msg) {
    perror(msg);
    exit(1);
}

void rsleep(double secs) {
    long max = secs * 1000000;
    srand((unsigned)time(NULL));
    long value = rand();
    usleep(value % max);
}
