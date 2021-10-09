#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/unity.h"
#include "../libs/Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE "77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33"
#define SECRET_CODE_INT 77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33

static char* buffer = NULL;
//static int code[] = {SECRET_CODE};

void setUp(void){
    buffer = calloc(BUFSIZ, sizeof(char));
    strncpy(buffer, TEST_ARRAY, BUFSIZ);
}

void tearDown(void){
    free(buffer);
}

void test_encoderInit(void){
    puts("Positive Test");
    Message frame = newMessage(TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(frame), strlen(TEST_ARRAY));
}

void test_encoderSecret(void)
{
  puts("Secret test");
  Message frame = NULL;
  frame = newMessage(SECRET_CODE);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(SECRET_CODE, getMessage(frame), strlen(SECRET_CODE));
}

int main(void)
{
  static char* c_code[] = {SECRET_CODE};
  static int i_code[] = {SECRET_CODE_INT};
  UNITY_BEGIN();
  RUN_TEST(test_encoderInit, __LINE__);
  RUN_TEST(test_encoderSecret, __LINE__);
  size_t size = sizeof(i_code)/sizeof(int);
  Message secret = newMessage(SECRET_CODE);
  setMessage(secret ,SECRET_CODE);
  printf("MENSAJE CODIFICADO: %s\n",secret->code);
  printf("MENSAJE DECODIFICADO: ");
  Ascii(i_code, -1, size);
  return UNITY_END();
}
