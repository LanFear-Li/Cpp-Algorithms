//
// Created by LanFear on 2021/6/21.
//

#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H

#include <assert.h>
#include <stdlib.h>

typedef char *string;
string String(char *);

typedef char bool;
#define TRUE 1;
#define FALSE 0;

void *checked_malloc(int);

#endif //COMPILER_UTIL_H
