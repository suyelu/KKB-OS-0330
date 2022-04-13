/*************************************************************************
	> File Name: 1.open.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 13 Apr 2022 07:11:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd;
    char message[1024] = {0};
    fd = open("./1.txt", O_CREAT | O_RDWR, 0777);
    printf("fd = %d\n", fd);
    strcpy(message, "This is message to be write!\n");
    ssize_t wsize = write(fd, message, strlen(message));
    printf("%ld chars write success!\n", wsize);

    sleep(2);

    lseek(fd, 0, SEEK_SET);

    memset(message, 0, sizeof(message));
    ssize_t nread = read(fd, message, sizeof(message));
    printf("<%ld> %s", nread, message);
    close(fd);
    return 0;
}
