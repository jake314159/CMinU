
void CMINU_SETUP();
void CMINU_ADD_TEST(char *name, void(*test_function)());
void CMINU_RUN_TESTS();

void CMINU_SET_SHOW_SUCCESS(char show_success);

void CMINU_ASSERT_TRUE(char *name, char value);
void CMINU_ASSERT_FALSE(char *name, char value);
void CMINU_ASSERT_EQUAL_INT(char *name, int v1, int v2);
void CMINU_ASSERT_EQUAL_FLOAT(char *name, float v1, float v2);
void CMINU_ASSERT_EQUAL_DOUBLE(char *name, double v1, double v2);
void CMINU_ASSERT_EQUAL_STRINGS(char *name, char *v1, char *v2);

