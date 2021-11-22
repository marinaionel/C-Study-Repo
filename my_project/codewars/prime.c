//
// Created by Marina Ionel on 17/03/2020.
//

#include <stdbool.h>

//q = Math.floor(Math.sqrt(value));

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0) return false;
    return true;
}