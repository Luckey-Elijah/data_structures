#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Fibonacci.h"

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q){
    int i;
    // allocate mem for new HugeInteger
    HugeInteger *new_int = calloc(1, sizeof(HugeInteger));

    // check for proper mem allocation
    if (new_int == NULL){
        printf("Could not properly allocate memory. Exiting..\n");
        return NULL;
    }
    
    // determine greater length of p and q
    int size_new_int; 
    if (p->length > q->length){
        size_new_int = p->length;
    }else{
        size_new_int = q->length;
    }

    // set new array size
    new_int->length = size_new_int;

    // initialize values in digits to zero
    for (i = new_int->length; i >= 0 ; i--){
        new_int->digits[i] = 0;
    }

    // add the integers together
    for (i = new_int->length; i >= 0; i--){
        new_int->digits[i] = p->digits[i] + q->digits[i];
    }

    // reduces values greater than 10
    // and appropiately moves them to the next index
    int temp;
    for (i = new_int->length; i >= 0; i--){
        if ((new_int->digits[i] / 10) > 0){
            temp = new_int->digits[i] / 10;
            new_int->digits[i] = new_int->digits[i] - (temp*10);
            new_int->digits[i+1] = new_int->digits[i + 1] + temp;
        }
    }
    
    return new_int;
}

HugeInteger *hugeDestroyer(HugeInteger *p){
    free(p->digits);
    free(p);

    return NULL;
}

HugeInteger *parseString(char *str){
    int length = (unsigned)strlen(str)-1;
    int i;
    // printf("length: %d\n", length);

    HugeInteger *new_int = calloc(1, sizeof(HugeInteger));
    new_int->length = length;
    new_int->digits = calloc(length, sizeof(new_int->digits[length]));

    if( str == NULL){
        new_int->digits[0]=0;
        return new_int;
    }

    for (i = 0; i < length; i++){
        // printf("index: %d\n", i);
        new_int->digits[i] = str[i];
    }

    free(new_int->digits);
    free(new_int);

    return new_int;
}

HugeInteger *parseInt(unsigned int n){
    HugeInteger *fib_int = malloc(sizeof(HugeInteger));
    unsigned int i, digits;
    
    // determine the number of digits being passed through "n"
    while (n != 0){
        n = n/10;
        digits++;
    }

    fib_int->length = digits;
    for (i = digits; i != 1; i--){
        fib_int->digits[i] = (digits / (pow(10, i-1)) );
    }

    return fib_int;

}

unsigned int *toUnsignedInt(HugeInteger *p){
    
    if (p == NULL){
        printf("Error: Huge int is NULL.\n");
        return 0;
    }

    int *value = malloc(sizeof(unsigned int));
    int i;

    for(i = p->length; i > 0; i--){
        *value = p->digits[i] * ( (int) pow(10, i-1));
    }

    if (value == NULL){
        printf("Error: value is NULL.\n");
        return NULL;
    }
    return value;
}

HugeInteger *fib(int n){
    HugeInteger *fib_int = calloc(1, sizeof(HugeInteger));
}

double difficultyRating(void){
    return 1.0;
};

double hoursSpent(void){
    return 1.0;
};
