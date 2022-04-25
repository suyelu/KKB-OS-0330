/*************************************************************************
	> File Name: head.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Wed 13 Apr 2022 08:20:06 PM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include "color.h"
#include "common.h"
#include "sem.h"
#ifdef _D
#define DBG(fmt, args...) printf(fmt, ##args)
#else
#define DBG(fmt, args...)
#endif
#endif
