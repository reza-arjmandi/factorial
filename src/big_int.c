#include "big_int.h"

#include <stdlib.h>

struct big_int {
    unsigned char *buffer;
    int len;
};

void* create_big_int(int number_length)
{
    struct big_int* big_int_ = malloc(sizeof(struct big_int));
    big_int_->buffer = malloc(number_length * sizeof(unsigned char));
    big_int_->len = 1; 
    return big_int_;
}

void destroy_big_int(void* big_int_)
{
    struct big_int* _big_int = big_int_;
    free(_big_int->buffer);
    free(_big_int);
}

void set_big_int_to(void* big_int_,  int number)
{
    struct big_int* _big_int = big_int_;
    _big_int->buffer[0] = number;
}

void multiply_big_int_to(void* big_int_, int number)
{
    struct big_int* _big_int = big_int_;
    int temp=0;
    for(int k=0; k < _big_int->len; ++k)
    {
        temp+=_big_int->buffer[k] * number;
        _big_int->buffer[k] = temp%10;
        temp = temp / 10;
    }
    while(temp>0)
    {
        _big_int->buffer[_big_int->len]=temp%10;
        _big_int->len++;
        temp=temp/10;
    }
}

void print_big_int(void* big_int_)
{
    struct big_int* _big_int = (struct big_int*)big_int_;
    for(int k = _big_int->len-1; k>=0; --k)
    {
        printf("%d",_big_int->buffer[k]);
    }
    printf("\n");
}