#include <stdio.h>
#include <stdlib.h>
#include "CMINU.h"

#define TRUE 1
#define FALSE 0

static int success_tests;
static int failed_tests;
static char show_success = TRUE;

typedef struct TEST_ENTRY {
    char *name;
    void(*test_function)();
    struct TEST_ENTRY *next;
} TEST_ENTRY;

static TEST_ENTRY *test_list = 0;

static void success(char *name, char *explain) {
    success_tests++;
    if(show_success) {
        printf("    [PASS]   %s %s\n", name, explain);
    }
}

static void fail(char *name, char *explain) {
    failed_tests++;
    printf("    [FAIL]   %s %s\n", name, explain);
}

void CMINU_SETUP() {
    success_tests = 0;
    failed_tests = 0;
}

void CMINU_ADD_TEST(char *n, void(*f)()) {
    if(test_list == 0) {
        test_list = malloc(sizeof(TEST_ENTRY));
        test_list->next = 0;
        test_list->test_function = f;
        test_list->name = n;
    } else {
        TEST_ENTRY *t = test_list;
        while(t->next != 0) {
            t = t->next;
        }
        t->next = malloc(sizeof(TEST_ENTRY));
        t = t->next;
        t->next = 0;
        t->test_function = f;
        t->name = n;
    }
}

void CMINU_RUN_TESTS() {
    TEST_ENTRY *t = test_list;
    while(t != 0) {
        printf("Testing \"%s\":\n", t->name);
        t->test_function();
        printf("\n");
        t = t->next;
    }
    
    printf("Test complete:\n");
    printf("    Success:   %i/%i\n", success_tests, success_tests+failed_tests);
    printf("    Failures:  %i/%i\n", failed_tests, success_tests+failed_tests);

    //Exit with 0 for success and 1 if fail
    if(failed_tests == 0) {
        exit(0);
    } else {
        exit(1);
    }
}

void CMINU_SET_SHOW_SUCCESS(char s)
{
    show_success = s;
}

void CMINU_ASSERT_TRUE(char *name, char value)
{
    if(value) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

void CMINU_ASSERT_FALSE(char *name, char value)
{
    if(!value) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

void CMINU_ASSERT_EQUAL_INT(char *name, int v1, int v2)
{
    if(v1 == v2) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

void CMINU_ASSERT_EQUAL_FLOAT(char *name, float v1, float v2)
{
    if(v1 == v2) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

void CMINU_ASSERT_EQUAL_DOUBLE(char *name, double v1, double v2)
{
    if(v1 == v2) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

void CMINU_ASSERT_EQUAL_STRINGS(char *name, char *v1, char *v2)
{
    int i=0;
    while(v1[i] != '\0' && v2[i] != '\0' && v1[i]==v2[i]) {
        i++;
    }
    if(v1[i] == v2[i]) {
        success(name, "");
    } else {
        fail(name, "");
    }
}

