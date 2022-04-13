/*************************************************************************
	> File Name: 4.buffer.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 13 Apr 2022 08:58:31 PM CST
 ************************************************************************/

#include "./common/head.h"

int main() {
    printf("hello world!"); //行缓冲
    fflush(stdout);
    sleep(10);
    return 0;
}
