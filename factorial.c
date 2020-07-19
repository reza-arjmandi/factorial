#include <stdio.h>

#include "big_int.h"

void calculate_factorial(unsigned int number, void* result)
{
    set_big_int_to(result, 1);
    for(int i=2; i <= number; ++i)
    {
        multiply_big_int_to(result, i);
    }
}

int main()
{
    int number;
    scanf("%d",&number);
    void* fact = create_big_int(200);
    calculate_factorial(number, fact);
    print_big_int(fact);
    destroy_big_int(fact);
    return 0;
}