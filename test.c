//
// Created by pc on 2021/8/26.
//
#include <stdio.h>
#include "threadpool.h"
#include <stdlib.h>
#include <unistd.h>

void *mywork( void * arg){
    printf("the thread id is : %ld, start running ...\n", pthread_self());
}

int main(){

    //传入最小线程数、最大线程数，消息队列大小。
    threadpool *pool = createThreadPool(1,2,100);
    for(int i = 0; i < 1000; i ++){
        //这里建议传入堆参数，线程函数执行完成之后会free掉这个堆。
        int *p = malloc(sizeof (int));
        *p = i;
        pollTaskAppend(pool, mywork, (void *)p);
    }
    pollDestory(pool);
    return 0;
}
