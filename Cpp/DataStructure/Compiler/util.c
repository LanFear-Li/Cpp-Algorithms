//
// Created by LanFear on 2021/6/21.
//

#include "util.h"

void *checked_malloc(int len) {
    void *p = malloc(len);
    assert(p);
    return p;
}