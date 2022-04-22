/*************************************************************************
	> File Name: sem.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Fri 22 Apr 2022 05:54:31 PM CST
 ************************************************************************/

#ifndef _SEM_H
#define _SEM_H
typedef sem_t* semaphore;

semaphore make_semaphore(int value);
void P(semaphore sem);
void V(semaphore sem);
#endif
