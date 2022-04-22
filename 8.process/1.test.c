/*************************************************************************
	> File Name: 1.test.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Fri 22 Apr 2022 05:57:19 PM CST
 ************************************************************************/
#include "head.h"

int main(){
    semaphore mutex = make_semaphore(1);
    P(mutex);
    printf("in\n");
    V(mutex);
}
