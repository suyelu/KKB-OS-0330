/*************************************************************************
	> File Name: 1.eof.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Fri 01 Apr 2022 08:41:00 PM CST
 ************************************************************************/

#include <stdio.h>
int main() {
    int arr[1000] = {0};
    int cnt = 0, sum = 0;
    while (scanf("%d", &arr[cnt]) != EOF) {
        sum += arr[cnt];
        cnt++;
    }
    printf("sum = %d\n", sum);
    return  0;
}
