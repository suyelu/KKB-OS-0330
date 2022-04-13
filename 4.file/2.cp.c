/*************************************************************************
	> File Name: 2.cp.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 13 Apr 2022 08:19:25 PM CST
 ************************************************************************/

#include "./common/head.h"
#define MAX_BUFF 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s src dest!\n", argv[0]);
        return 1;
    }
    int fd_in, fd_out;

    if ((fd_in = open(argv[1], O_RDONLY)) < 0) {
        perror("open()");
        exit(1);
    }

    if ((fd_out = creat(argv[2], 0666)) < 0) {
        perror("creat()");
        exit(1);
    }
    
    ssize_t nread, nwrite;
    char buff[MAX_BUFF + 5] = {0};
    while ((nread = read(fd_in, buff, MAX_BUFF)) > 0) {
        if ((nwrite = write(fd_out, buff, strlen(buff))) != nread) {
            perror("write()");
            exit(1);
        }
        memset(buff, 0, sizeof(buff));
    }

    close(fd_in);
    close(fd_out);
    return 0;
}

