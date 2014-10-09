#include "CMINU.h"
// Notice we are including the actual C code not the header
// We could then replace any external calls with dummy functions
// To isolate a single unit from the file
#include "sum.c"

void test_my_sum_ones()
{
    int my_array[] = {1,1,1,1,1,1,1,1};
    //my_sum is part of sum.c
    int result = my_sum(my_array, 8);
    int expected_result = 8;
    CMINU_ASSERT_EQUAL_INT("my_sum with array of one's", result, expected_result);
}

void test_my_sum_incr()
{
    int my_array[] = {1,2,3,4,5,6,7,8};
    //my_sum is part of sum.c
    int result = my_sum(my_array, 8);
    int expected_result = 36;
    CMINU_ASSERT_EQUAL_INT("my_sum with array of incrementing values",
        result, expected_result);
}

int main()
{
    CMINU_SETUP();

    //Add the tests to CMINU
    CMINU_ADD_TEST("test_my_sum_ones", &test_my_sum_ones);
    CMINU_ADD_TEST("test_my_sum_incr", &test_my_sum_incr);

    // Run the tests
    // This will cause the program to exit with 0 for success or 1 for fail
    CMINU_RUN_TESTS();
}
