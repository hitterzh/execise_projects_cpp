//
// Created by zhang on 2021/6/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leptjson.h"

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;                                    \
        if (equality)                                    \
            test_pass++;                                 \
        else {                                           \
            fprintf(stderr, "%s:%d: expect:" formait "actual:" format "\n",__FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
                                                         \
        }    \
                                                         \
    }

