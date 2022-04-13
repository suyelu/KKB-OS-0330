/*************************************************************************
	> File Name: 3.nonblock.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 13 Apr 2022 08:50:40 PM CST
 ************************************************************************/

#include "./common/head.h"
int make_nonblock(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) return -1;
    flags |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flags);
}

int main() {
    char buff[512] = {0};
    make_nonblock(0);
    int ret = scanf("%s", buff);
    if (ret < 0) perror("scanf");
    printf("<ret = %d> buff : %s <end>", ret, buff);
    return 0;
}
