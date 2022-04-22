/*************************************************************************
	> File Name: sem.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Fri 22 Apr 2022 05:48:27 PM CST
 ************************************************************************/
#include "head.h"

semaphore make_semaphore(int value) {
  semaphore sem = malloc(sizeof(semaphore));
  int n = sem_init(sem, 0, value);
  if (n != 0) perror_exit("sem_init failed");
  return sem;
}


void P(semaphore sem) {
  int n = sem_wait(sem);
  if (n != 0) perror_exit("sem_wait failed");
}


void V(semaphore sem){
  int n = sem_post(sem);
  if (n != 0) perror_exit("sem_post failed");
}

