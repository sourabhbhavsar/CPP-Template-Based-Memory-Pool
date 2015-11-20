#include <stdio.h>
#include "PoolFactory.h"
#include "MemoryPool.h"

int main(int argc, char **argv)
{
	
    int* p1[10];
    
    for (int i = 0; i < 10; i++)
    {
        p1[i] = MP::MemoryPool<int>::getNext();
        *p1[i] = 10*i;
    }
    
    
    for (int i = 0; i <10; i++)
    {
        printf("p[i] is %d \n", *p1[i]);
        
    }
    

	return 0;
}
