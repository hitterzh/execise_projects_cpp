//
// Created by zhang on 2021/6/18.
//

#ifndef EXECISE_PROJECTS_CPP_LEPTJSON_H
#define EXECISE_PROJECTS_CPP_LEPTJSON_H

typedef enum {
    LEPT_NULL,
    LEPT_FALSE,
    LEPT_TRUE,
    LEPT_NUMBER,
    LEPT_STRING,
    LEPT_ARRAY,
    LEPT_OBJECT
}lept_type;

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_STINGULAR,
    };

int lept_parse(lept_value* v, const char* json);
lept_type lept_get_type(const lept_value* v);

#endif //EXECISE_PROJECTS_CPP_LEPTJSON_H
