#CMINU

A simple C unit test framework

#Quick start guide

Here is a quick example of a unit test

```C
#include <CMINU.h>
// Notice we are including the actual C code not the header
// We could then replace any external calls with dummy functions
// To isolate a single unit from the file
#include "MyCode.c"

void test_my_sum_ones()
{
    int my_array[] = {1,1,1,1,1,1,1,1};
    //my_sum is part of MyCode.c
    int result = my_sum(my_array);
    int expected_result = 8;
    CMINU_ASSERT_EQUAL_INT("my_sum with array of one's", result, expected_result);
}

void test_my_sum_incr()
{
    int my_array[] = {1,2,3,4,5,6,7,8};
    //my_sum is part of MyCode.c
    int result = my_sum(my_array);
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

```

You can then compile and run the unit test with gcc like so:

```bash
gcc my_unit_test.c CMINU.c -o unit_test
./unit_test
```

This will (hopefully) then give the output below

```
Testing "test_my_sum_ones":
    [PASS]   my_sum with array of one's

Testing "test_my_sum_incr":
    [PASS]   my_sum with array of incrementing values

Test complete:
    Success:   2/2
    Failures:  0/0
```

