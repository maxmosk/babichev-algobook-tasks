#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


uint16_t numbers[500500];
uint32_t used = 0;

uint16_t *lookup(uint16_t num);
uint16_t *insert(uint16_t num);
void printarr(void);
int intcmp(const void *p_1, const void *p_2);


int main(void)
{
    uint16_t buf = 0;

    do
    {
        scanf("%hu", &buf);
        insert(buf);
    }
    while (buf != 0);
    
    do
    {
        scanf("%hu", &buf);
        uint16_t *looked = lookup(buf);
        if (looked == NULL)
        {
            insert(buf);
        }
        else
        {
            *looked = 0;
        }
    }
    while (buf != 0);

    printarr();


    return 0;
}


uint16_t *lookup(uint16_t num)
{
    for (uint32_t i = 0; i < used; i++)
    {
        if (numbers[i] == num)
        {
            return &numbers[i];
        }
    }

    return NULL;
}

uint16_t *insert(uint16_t num)
{
    if (used <= (sizeof numbers / sizeof numbers[0]))
    {
        numbers[used] = num;
        return &numbers[used++];
    }
    else
    {
        return NULL;
    }
}

void printarr(void)
{
    qsort((void*) numbers, used, sizeof numbers[0], intcmp);

    for (uint32_t i = 0; i < used; i++)
    {
        if (numbers[i] != 0)
        {
            printf("%hu ", numbers[i]);
        }
    }
    
    putchar('\n');
}

int intcmp(const void *p_1, const void *p_2)
{
    return (*((uint16_t *) p_1) - *((uint16_t *) p_2));
}
