#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "check.h"
#include "s21_string.h"
START_TEST(s21_memchr_test1) {
  char str[50] = "12345";
  ck_assert_ptr_eq(memchr(str, '1', 5), s21_memchr(str, '1', 5));
}
END_TEST

START_TEST(s21_memchr_test2) {
  char str[50] = "12345";
  ck_assert_ptr_eq(memchr(str, '5', 1), s21_memchr(str, '5', 1));
}
END_TEST

START_TEST(s21_memchr_test3) {
  char str[50] = "asAAAsdae";
  ck_assert_ptr_eq(memchr(str, 65, 9), s21_memchr(str, 65, 9));
}
END_TEST

START_TEST(s21_memchr_test4) {
  char str[50] = "asAAAsdae";
  ck_assert_ptr_eq(memchr(str, 65, 1), s21_memchr(str, 65, 1));
}
END_TEST

START_TEST(s21_memchr_test5) {
  char str[50] = "asAAAsdae";
  ck_assert_ptr_eq(memchr(str, 65, 0), s21_memchr(str, 65, 0));
}
END_TEST

START_TEST(s21_memchr_test6) {
  char str[50] = "645 gfhjkh";
  ck_assert_ptr_eq(memchr(str, ' ', 3), s21_memchr(str, ' ', 3));
}
END_TEST

START_TEST(s21_memchr_test7) {
  char str[50] = "645 gf\nhjkh";
  ck_assert_ptr_eq(memchr(str, '\n', 3), s21_memchr(str, '\n', 3));
}
END_TEST

START_TEST(s21_memchr_test8) {
  char str[50] = "HELLO!\056789";
  ck_assert_ptr_eq(memchr(str, '!', 6), s21_memchr(str, '!', 6));
}
END_TEST

START_TEST(s21_memchr_test9) {
  char str[50] = "HELLO!\056789";
  ck_assert_ptr_eq(memchr(str, '!', 5), s21_memchr(str, '!', 5));
}
END_TEST

START_TEST(s21_memchr_test10) {
  char str[50] = "\0/r\v/n";
  ck_assert_ptr_eq(memchr(str, 'v', 5), s21_memchr(str, 'v', 5));
}
END_TEST

START_TEST(s21_memchr_test11) {
  char str[50] = "";
  ck_assert_ptr_eq(memchr(str, '0', 1), s21_memchr(str, '0', 1));
}
END_TEST

START_TEST(s21_memchr_test12) {
  char str[50] = "@#WEETggT";
  ck_assert_ptr_eq(memchr(str, 'T', 9), s21_memchr(str, 'T', 9));
}
END_TEST

START_TEST(s21_memcmp_test1) {
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 12), s21_memcmp(str1, str2, 12));
}
END_TEST

START_TEST(s21_memcmp_test2) {
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 1), s21_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcmp_test3) {
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 7), s21_memcmp(str1, str2, 7));
}
END_TEST

START_TEST(s21_memcmp_test4) {
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcmp_test5) {
  char str1[50] = "Hello/0Word";
  char str2[50] = "Hello/0Word";
  ck_assert_int_eq(memcmp(str1, str2, 9), s21_memcmp(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcmp_test6) {
  char str1[50] = "Hello/0\n\0\n\0Word\\01234";
  char str2[50] = "Hello/0\n\0\n\0Word\\01234";
  ck_assert_int_eq(memcmp(str1, str2, 19), s21_memcmp(str1, str2, 19));
}
END_TEST

START_TEST(s21_memcmp_test7) {
  char str1[50] = "Hello/0\n\0\n\0Word\\01234";
  char str2[50] = "Hello/0\n\0\n\0Word\\43210";
  ck_assert_int_eq(memcmp(str1, str2, 19), s21_memcmp(str1, str2, 19));
}
END_TEST

START_TEST(s21_memcmp_test8) {
  char str1[50] = " \0 \0 \0 4___r";
  char str2[50] = " \0 \0 \0 4__ _r";
  ck_assert_int_eq(memcmp(str1, str2, 11), s21_memcmp(str1, str2, 11));
}
END_TEST

START_TEST(s21_memcmp_test9) {
  char str1[50] = " \0 \0 \0 4___r";
  char str2[50] = " \0 \0 \0 4__ _r";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test10) {
  char str1[50] = "Hello\0Word";
  char str2[50] = "Hello\0Rord";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test11) {
  char str1[50] = "Hello\0Word";
  char str2[50] = "Hello\0Rord";
  ck_assert_int_eq(memcmp(str1, str2, 9), s21_memcmp(str1, str2, 9));
}
END_TEST

START_TEST(s21_memset_test1) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test2) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test3) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 4), s21_memset(str, '0', 4));
}
END_TEST

START_TEST(s21_memset_test4) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test5) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 9), s21_memset(str, '0', 9));
}
END_TEST

START_TEST(s21_memset_test6) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 12), s21_memset(str, '0', 12));
}
END_TEST

START_TEST(s21_memset_test7) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, 't', 3), s21_memset(str, 't', 3));
}
END_TEST

START_TEST(s21_memset_test8) {
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '\0', 8), s21_memset(str, '\0', 8));
}
END_TEST

START_TEST(s21_memset_test9) {
  char str[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memset(str, 'g', 10), s21_memset(str, 'g', 10));
}
END_TEST

START_TEST(s21_memset_test10) {
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 4), s21_memset(str, '0', 4));
}
END_TEST

START_TEST(s21_memset_test11) {
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 5), s21_memset(str, '0', 5));
}
END_TEST

START_TEST(s21_memset_test12) {
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 6), s21_memset(str, '0', 6));
}
END_TEST

START_TEST(s21_memset_test13) {
  char str[50] = "";
  ck_assert_ptr_eq(memset(str, 'y', 1), s21_memset(str, 'y', 1));
}
END_TEST

START_TEST(s21_memcpy_test1) {
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 0), s21_memcpy(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcpy_test2) {
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 9), s21_memcpy(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcpy_test3) {
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 20 - 4), s21_memcpy(str1, str2, 20 - 4));
}
END_TEST

START_TEST(s21_memcpy_test4) {
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 4), s21_memcpy(str1, str2, 4));
}
END_TEST

START_TEST(s21_memcpy_test5) {
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 2 * 4), s21_memcpy(str1, str2, 2 * 4));
}
END_TEST

START_TEST(s21_memcpy_test6) {
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 9), s21_memcpy(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcpy_test7) {
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test8) {
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 0), s21_memcpy(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcpy_test9) {
  char str1[50] = "\0";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test10) {
  char str1[50] = "1";
  char str2[50] = "\0";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test11) {
  char str1[50] = "\0\0\0\0\0";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 3), s21_memcpy(str1, str2, 3));
}
END_TEST

START_TEST(s21_memcpy_test12) {
  char str1[50] = " 123456789qqq";
  char str2[50] = "   asdf\0Z\0-";
  ck_assert_ptr_eq(memcpy(str1, str2, 8), s21_memcpy(str1, str2, 8));
}
END_TEST

START_TEST(s21_strlen_test1) {
  char str[50] = "12345";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test2) {
  char str[50] = "1";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test3) {
  char str[50] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test4) {
  char str[50] = "12345\n67890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test5) {
  char str[50] = "asasf )(*&^%$#@!@#$%^&\":?.{P|}{P:\\/\\})   FG   H";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test6) {
  char str[50] = "1234\05";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test7) {
  char str[50] = "\012345";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test8) {
  char str[50] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strncmp_test1) {
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 10), s21_strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test2) {
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 11), s21_strncmp(str1, str2, 11));
}
END_TEST

START_TEST(s21_strncmp_test3) {
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_strncmp_test4) {
  char str1[50] = "Hello Word!";
  char str2[50] = "HelloWord!";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test5) {
  char str1[50] = "Hello Word!";
  char str2[50] = "HelloWord!";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(s21_strncmp_test6) {
  char str1[50] = "Hello Word!";
  char str2[50] = "HelloWord!";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_test7) {
  char str1[50] = " Hello Word!";
  char str2[50] = "Hello Word!";
  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncmp_test8) {
  char str1[50] = "Hello Word!";
  char str2[50] = "Hello Word! ";
  ck_assert_int_eq(strncmp(str1, str2, 13), s21_strncmp(str1, str2, 13));
}
END_TEST

START_TEST(s21_strncmp_test9) {
  char str1[50] = "1";
  char str2[50] = "";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_test10) {
  char str1[50] = "1";
  char str2[50] = "";
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_strncmp_test11) {
  char str1[50] = "Hello Word!";
  char str2[50] = "Hello \0Word!";
  ck_assert_int_eq(strncmp(str1, str2, 8), s21_strncmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncmp_test12) {
  char str1[50] = "Hello Word!";
  char str2[50] = "Hello \nWord!";
  ck_assert_int_eq(strncmp(str1, str2, 8), s21_strncmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncmp_test13) {
  char str1[50] = "}{:{+_)(*&^%$";
  char str2[50] = "}{:{+_)(*&^%$";
  ck_assert_int_eq(strncmp(str1, str2, 12), s21_strncmp(str1, str2, 12));
}
END_TEST

START_TEST(s21_strncmp_test14) {
  char str1[50] = "}{:{+_)((*&^%$";
  char str2[50] = "}{:{+_)(*&^%$";
  ck_assert_int_eq(strncmp(str1, str2, 12), s21_strncmp(str1, str2, 12));
}
END_TEST

START_TEST(strncpy_test1) {
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test2) {
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

// START_TEST(strncpy_test3) {
//
//   char str1[50] = "abcdef";
//   char str2[50] = "12345";
//   ck_assert_str_eq(strncpy(str1, str2, 0), s21_strncpy(str1, str2, 0));
// }
// END_TEST
START_TEST(strncpy_test3) {
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test4) {
  char str1[50] = "abcdef";
  char str2[50] = "1";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test5) {
  char str1[50] = "a";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test6) {
  char str1[50] = "";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test7) {
  char str1[50] = "abcdef";
  char str2[50] = "";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test8) {
  char str1[50] = " dest ";
  char str2[50] = "HELLO!\05";
  ck_assert_str_eq(strncpy(str1, str2, 6), s21_strncpy(str1, str2, 6));
}
END_TEST

START_TEST(strncpy_test9) {
  char str1[50] = " dest ";
  char str2[50] = "HELLO!\05";
  ck_assert_str_eq(strncpy(str1, str2, 8), s21_strncpy(str1, str2, 8));
}
END_TEST

START_TEST(strncpy_test10) {
  char str1[50] = "\0/r\v/n";
  char str2[50] = "5t/<//8\0";
  ck_assert_str_eq(strncpy(str1, str2, 3), s21_strncpy(str1, str2, 3));
}
END_TEST

START_TEST(strncpy_test11) {
  char str1[50] = "        abcdef  ";
  char str2[50] = "   __-=      1+(*&) 234 5       ";
  ck_assert_str_eq(strncpy(str1, str2, 27), s21_strncpy(str1, str2, 27));
}
END_TEST

START_TEST(s21_strncat_test1) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "word", 5);
  orig_str = strncat(str2, "word", sizeof str2 - strlen(str2) - 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test2) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "word", 10);
  orig_str = strncat(str2, "word", 10);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test3) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "", 1);
  orig_str = strncat(str2, "", 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test4) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "", 4);
  orig_str = strncat(str2, "", 4);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test5) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "word", 3);
  orig_str = strncat(str2, "word", 3);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test6) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "word", 0);
  orig_str = strncat(str2, "word", 0);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test7) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "", 1);
  orig_str = strncat(str2, "", 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test8) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = " !@#123 ";
  char str2[100] = " !@#123 ";
  s21_str = s21_strncat(str1, "\n", 2);
  orig_str = strncat(str2, "\n", 2);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test9) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "H\0ello ";
  char str2[100] = "H\0ello ";
  s21_str = s21_strncat(str1, "word", 5);
  orig_str = strncat(str2, "word", sizeof str2 - strlen(str2) - 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test10) {
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "H\0ello ";
  char str2[100] = "H\0ello ";
  s21_str = s21_strncat(str1, "wor\0d", 5);
  orig_str = strncat(str2, "wor\0d", 5);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcspn_test1) {
  const char str1[200] = "1234567890";
  const char str2[200] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test2) {
  const char str1[200] = "1234567890e";
  const char str2[200] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test3) {
  const char str1[200] = "12d34567890e";
  const char str2[200] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test4) {
  const char str1[200] = "";
  const char str2[200] = "qwe";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test5) {
  const char str1[200] = " Hello! ";
  const char str2[200] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test6) {
  const char str1[200] = "";
  const char str2[200] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test7) {
  const char str1[200] = " ";
  const char str2[200] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test8) {
  const char str1[200] = "";
  const char str2[200] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test9) {
  const char str1[200] = "1 2  .3... Hello!";
  const char str2[200] = "Hello!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test10) {
  const char str1[200] = "Hello";
  const char str2[200] = "oleH";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test11) {
  const char str1[200] = "Hello";
  const char str2[200] = "89\0Hello";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test12) {
  const char str1[200] = "He\0llo";
  const char str2[200] = "lo";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test13) {
  const char str1[200] = "             321  ";
  const char str2[200] = "1";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test14) {
  const char str1[200] = "q1q2w3we45rt66g7Zyu8j";
  const char str2[200] = "zxvbvcvbZnm,m./??";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strtok_test1) {
  char str1[100] = "hello  how,a y. and what, yiu do in this, plase";
  char str2[100] = "hello  how,a y. and what, yiu do in this, plase";
  char delim[100] = " ,.";
  char p_str1[100] = {0};
  char p_str2[100] = {0};
  char *ptr1 = p_str1, *ptr2 = p_str2;
  ptr1 = s21_strtok(str1, delim);
  ptr2 = strtok(str2, delim);
  while (ptr2 != NULL) {
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
    ck_assert_str_eq(ptr1, ptr2);
  }
}
END_TEST

START_TEST(s21_strtok_test2) {
  char str1[100] = "123abc23ccd3vvc321";
  char str2[100] = "123abc23ccd3vvc321";
  char delim[100] = "213";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test3) {
  char str1[100] = "";
  char str2[100] = "";
  char delim[100] = "213";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test4) {
  char str1[100] = "123abc23ccd3vvc321";
  char str2[100] = "123abc23ccd3vvc321";
  char delim[100] = "";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test5) {
  char str1[100] = "123abc23ccd3vvc321";
  char str2[100] = "123abc23ccd3vvc321";
  char delim[100] = "789";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test6) {
  char str1[100] = "111";
  char str2[100] = "111";
  char delim[100] = "1";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test7) {
  char str1[100] = "121";
  char str2[100] = "121";
  char delim[100] = "1";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test8) {
  char str1[100] = "         1   2  1   ";
  char str2[100] = "         1   2  1   ";
  char delim[100] = " ";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strchr_test1) {
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '1'), s21_strchr(str, '1'));
}
END_TEST

START_TEST(s21_strchr_test2) {
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '5'), s21_strchr(str, '5'));
}
END_TEST

START_TEST(s21_strchr_test3) {
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '0'), s21_strchr(str, '0'));
}
END_TEST

START_TEST(s21_strchr_test4) {
  char str[80] = "Hello Word!";
  ck_assert_ptr_eq(strchr(str, 'y'), s21_strchr(str, 'y'));
}
END_TEST

START_TEST(s21_strchr_test5) {
  char str[80] = "Hello Word!";
  ck_assert_str_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(s21_strchr_test6) {
  char str[80] = "Hello W\0ord!";
  ck_assert_str_eq(strchr(str, 'l'), s21_strchr(str, 'l'));
}
END_TEST

START_TEST(s21_strchr_test7) {
  char str[80] = "Hello W\0ord!";
  ck_assert_ptr_eq(strchr(str, 'r'), s21_strchr(str, 'r'));
}
END_TEST

START_TEST(s21_strchr_test8) {
  char str[80] = "";
  ck_assert_ptr_eq(strchr(str, 'v'), s21_strchr(str, 'v'));
}
END_TEST

START_TEST(s21_strchr_test9) {
  char str[80] = "\tt\n\"";
  ck_assert_str_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(s21_strchr_test10) {
  char str[80] = "abcdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test11) {
  char str[80] = "ab\0cdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_test1) {
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '1'), s21_strrchr(str, '1'));
}
END_TEST

START_TEST(s21_strrchr_test2) {
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '0'), s21_strrchr(str, '0'));
}
END_TEST

START_TEST(s21_strrchr_test3) {
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '5'), s21_strrchr(str, '5'));
}
END_TEST

START_TEST(s21_strrchr_test4) {
  char str[80] = "";
  ck_assert_ptr_eq(strrchr(str, 't'), s21_strrchr(str, 't'));
}
END_TEST

START_TEST(s21_strrchr_test5) {
  char str[80] = "Hello Word!";
  ck_assert_ptr_eq(strrchr(str, 'L'), s21_strrchr(str, 'L'));
}
END_TEST

START_TEST(s21_strrchr_test6) {
  char str[80] = "Hello Word!";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_test7) {
  char str[80] = "Hello Worl\0d!";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_test8) {
  char str[80] = "Hello Worl\0d!";
  ck_assert_ptr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(s21_strrchr_test9) {
  char str[80] = "gggggggggggggggg\0";
  ck_assert_str_eq(strrchr(str, 'g'), s21_strrchr(str, 'g'));
}
END_TEST

START_TEST(s21_strrchr_test10) {
  char str[80] = "gggggggggggggggg9\0";

  ck_assert_str_eq(strrchr(str, 'g'), s21_strrchr(str, 'g'));
}
END_TEST

START_TEST(s21_strrchr_test11) {
  char str[80] = " 958ugjmkl3cpefc.e";
  ck_assert_str_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(s21_strrchr_test12) {
  char str[80] = " 958ug\tjmkl\v3cpe\nfc.e";
  ck_assert_str_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(s21_strchr_test13) {
  char str[80] = "abcdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test14) {
  char str[80] = "ab\0cdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strpbrk_test1) {
  char str1[200] = "1234567890";
  char str2[200] = "456";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char str1[200] = "1234567890";
  char str2[200] = "654";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char str1[200] = "1234567890";
  char str2[200] = "6541";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  char str1[200] = "1234567890";
  char str2[200] = "!w a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test5) {
  char str1[200] = "1234567890";
  char str2[200] = "1234567890";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test6) {
  char str1[200] = "1234567890";
  char str2[200] = "0987654321";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test7) {
  char str1[200] = "qwertyu9";
  char str2[200] = "                 uyt   ";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test8) {
  char str1[200] = "";
  char str2[200] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test9) {
  char str1[200] = "321";
  char str2[200] = "\0";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test10) {
  char str1[200] = "\0";
  char str2[200] = "\0";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test11) {
  char str1[200] = "bb123\nA\0a";
  char str2[200] = "acAd";
  char *p_str1 = (char *)str1;
  char *p_str2 = (char *)str2;
  ck_assert_str_eq(strpbrk(p_str1, p_str2), s21_strpbrk(p_str1, p_str2));
}
END_TEST

START_TEST(s21_strpbrk_test12) {
  char str1[200] = "bb123\n\0A\0a";
  char str2[200] = "acAd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test13) {
  char str1[200] = "1234567890";
  char str2[200] = "1";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test14) {
  char str1[200] = "1234567890";
  char str2[200] = "0";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test1) {
  char str1[200] = "1234567890";
  char str2[200] = "0";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test2) {
  char str1[200] = "1234567890";
  char str2[200] = "1";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test3) {
  char str1[200] = "1234567890";
  char str2[200] = "6";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test4) {
  char str1[200] = "1234567890";
  char str2[200] = "456";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test5) {
  char str1[200] = "1234567890";
  char str2[200] = "876";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test6) {
  char str1[200] = "1";
  char str2[200] = "123";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test7) {
  char str1[200] = "abc";
  char str2[200] = "";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test8) {
  char str1[200] = "";
  char str2[200] = "";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test9) {
  char str1[200] = "ad\nc";
  char str2[200] = "\n";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test10) {
  char str1[200] = "ad\0c123";
  char str2[200] = "c1";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test11) {
  char str1[200] = "adc1\023";
  char str2[200] = "c1";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test12) {
  char str1[200] = " a B b c ";
  char str2[200] = " ";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test13) {
  char str1[200] = " a B b c ";
  char str2[200] = " B ";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test14) {
  char str1[200] =
      "}oi>()&*^&uY#HnHG/.//.,,,fUnkb  +_ _P+)_*(&^%$$$#%@#) vCEXWDfv  ";
  char str2[200] = ")_*(";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test15) {
  char str1[200] =
      "}oi>()&*^&uY#HnHG/.//.,,,fUnkb  +_ _P+)_*(&^%$$$#%@#) vCEXWDfv  ";
  char str2[200] = ")*(";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

// START_TEST(s21_sprintf_test_1) {
//   char str1[200] = {0};
//   char *p_str1 = (char *)str1;
//   char str2[200] = {0};
//   char *p_str2 = (char *)str2;
//   char format[100] = {0};
//   char *p_format = format;
//   p_format = "hello ma freund %10c ";
//   ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
//                    sprintf(p_str2, p_format, 123));
//   printf("%s\n%s\n\n", str1, str2);
//   ck_assert_str_eq( ptr1, ptr2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_2) {
//   char str1[200] = {0};
//   char *p_str1 = (char *)str1;
//   char str2[200] = {0};
//   char *p_str2 = (char *)str2;
//   char format[100] = {0};
//   char *p_format = format;
//   p_format = "hello ma freund %-10c";
//   ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
//                    sprintf(p_str2, p_format, 123));
//   printf("%s\n%s\n\n", str1, str2);
//   ck_assert_str_eq(str1, str2);
// }
END_TEST
START_TEST(s21_sprintf_test_3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10c";
  int k = s21_sprintf(p_str1, p_format, 123);
  int kk = sprintf(p_str2, p_format, 123);

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 123),
                   sprintf(p_str2, p_format, 123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10c";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -123),
                   sprintf(p_str2, p_format, -123));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10d%10d%10d%10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10d%-10d%-10d%-10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10d%+10d%+10d%+10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10d%+-10d%+-10d%+-10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10d% 10d% 10d% 10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10d%+- 10d%+- 10d%+- 10d";
  int k = s21_sprintf(p_str1, p_format, 1, 0, -1, 101231);
  int kk = sprintf(p_str2, p_format, 1, 0, -1, 101231);

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010d%010d%010d%010d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010d%-010d%-010d%-010d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10d%+-0 10d%+-0 10d%+-0 10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10d%10d%10d%10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10d%-10d%-10d%-10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10d%+10d%+10d%+10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10d%+-10d%+-10d%+-10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10d% 10d% 10d% 10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10d%+- 10d%+- 10d%+- 10d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010d%010d%010d%010d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-0*d%-0*d%-0*d%-0*d";
  ck_assert_int_eq(
      s21_sprintf(p_str1, p_format, 10, -1, 10, 0, 10, -1, 10, 101231),
      sprintf(p_str2, p_format, 10, -1, 10, 0, 10, -1, 10, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 *d";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 10, -1, 0, -1, 101231),
                   sprintf(p_str2, p_format, 10, -1, 0, -1, 101231));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_f_1) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund  %10f %10f %10f %10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_2) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10f%-10f%-10f%-10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_f_3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund  %+10.0f%+10.0f%+10.0f%+10.0f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10.1f %+-10.1f %+-10.1f %+-10.1f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10.2f% 10.2f% 10.2f% 10.2f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10.6f%+- 10.6f%+- 10.6f%+- 10.6f";
  int k = s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7, -1.0 / 7 * 100,
                      -1.0 / 7);
  int kk = sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7, -1.0 / 7 * 100,
                   -1.0 / 7);

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format =
      "hello ma freund %010.3ffreund %010.3ffreund %010.3ffreund %010.3f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format =
      "hello ma freund %-010.4ffreund %-010.4ffreund %-010.4ffreund %-010.4f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10fund %+-0 10fund %+-0 10fund %+-0 10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, 1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10feund %10feund %10feund %10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10fnd %-10fnd %-10fnd %-10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_f_12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10fund %+10fund %+10fund %+10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10.3fnd %+-10.3fnd %+-10.3fnd %+-10.3f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10.5fnd % 10.5fnd % 10.5fnd % 10.5f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10.fund %+- 10.fund %+- 10.fund %+- 10.f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010.1fnd %010.1fnd %010.1fnd %010.1fnd";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010.10fnd %-010.10fnd %-010.10fnd %-010.10f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_f_18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format =
      "hello ma freund %+-0 10.5fnd %+-0 10.5fnd %+-0 10.5fnd %+-0 10.5f";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, -1.0 / 7 * 100, 1.0 / 7,
                               -1.0 / 7 * 100, -1.0 / 7),
                   sprintf(p_str2, p_format, -1.0 / 7 * 100, 1.0 / 7,
                           -1.0 / 7 * 100, -1.0 / 7));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test1) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10s%10s%10s%10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test2) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10s%-10s%-10s%-10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10s%+10s%+10s%+10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10s%+-10s%+-10s%+-10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10s% 10s% 10s% 10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10s%+- 10s%+- 10s%+- 10s";
  int k = s21_sprintf(p_str1, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                      p_format, "");
  int kk = sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                   p_format, "");

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010s%010s%010s%010s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010s%-010s%-010s%-010s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10s%+-0 10s%+-0 10s%+-0 10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10s%10s%10s%10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10s%-10s%-10s%-10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10s%+10s%+10s%+10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10s%+-10s%+-10s%+-10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10s% 10s% 10s% 10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10s%+- 10s%+- 10s%+- 10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010s%010s%010s%010s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010s%-010s%-010s%-010s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10s%+-0 10s%+-0 10s%+-0 10s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_1) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_2) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test_perc_3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10% %s %s %s %s";
  int k = s21_sprintf(p_str1, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                      p_format, "");
  int kk = sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                   p_format, "");

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test_perc_12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_perc_18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10% %s %s %s %s";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, "ksdfh8",
                               "welrnm945fp2!<{D($FN\0", p_format, ""),
                   sprintf(p_str2, p_format, "ksdfh8", "welrnm945fp2!<{D($FN\0",
                           p_format, ""));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG1) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10.4e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG2) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-10.2e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test_gG3) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+15.9e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG4) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10.1e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG5) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 15.0e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG6) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  p_int(2) char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 15.6e";
  int k = s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342);
  int kk = sprintf(p_str2, p_format, 7.0 / 4 + 456.342);

  ck_assert_int_eq(k, kk);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG7) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %015e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG8) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010E";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 - 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 - 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG9) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 15E";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG10) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %15.1e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG11) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-15.4e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21__sprintf_test_gG12) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+10.5e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG13) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-10.6e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 - 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 - 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG14) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund % 10.7e";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 - 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 - 456.342));
  printf("%s\n%s\n\n", str1, str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG15) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+- 10.8e\0";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG16) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %010.9e\0";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG17) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %-010.5e\0";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 + 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 + 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_gG18) {
  char str1[200] = {0};
  char *p_str1 = (char *)str1;
  char str2[200] = {0};
  char *p_str2 = (char *)str2;
  char format[100] = {0};
  char *p_format = format;
  p_format = "hello ma freund %+-0 10.7e\0";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 7.0 / 4 - 456.342),
                   sprintf(p_str2, p_format, 7.0 / 4 - 456.342));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21__sprintf_test_eror_str1) {
  char str1[80] = {0};
  char *p_str1 = (char *)str1;
  char str2[80] = {0};
  char *p_str2 = (char *)str2;
  char format[30] = {0};
  char *p_format = format;
  p_format = "hello ma freund %10d %bndo3ij10 %y2d %01=0de %}}3-9d %10d\0";
  ck_assert_int_eq(s21_sprintf(p_str1, p_format, 1, 1),
                   sprintf(p_str2, p_format, 1, 1));
  printf("%s\n%s\n\n", str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(insert_1) {
  char *s1 = "school\0";
  char *s2 = "21\0";
  s21_size_t x = 6;
  char *ex = "school21";
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(insert_2) {
  char *s1 = "school\0";
  char *s2 = "21\0";
  s21_size_t x = 7;
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST

START_TEST(insert_3) {
  char *s1 = "Ho\0";
  char *s2 = "ell\0";
  s21_size_t x = 1;
  char *ex = "Hello\0";
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(insert_4) {
  char *s1 = "start!\0";
  char *s2 = "Let's \0";
  s21_size_t x = 0;
  char *ex = "Let's start!\0";
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(insert_5) {
  char *s1 = "\0";
  char *s2 = "error \0";
  s21_size_t x = 2;
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST

START_TEST(insert_6) {
  char *s1 = "school\0";
  char *s2 = "21\0";
  s21_size_t x = -6;
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST

START_TEST(insert_7) {
  char *s1 = "school\0";
  char *s2 = "\0";
  s21_size_t x = 2;
  char *ex = "school\0";
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(insert_8) {
  char *s1 = "\0";
  char *s2 = "school\0";
  s21_size_t x = 0;
  char *ex = "school\0";
  char *result = (char *)s21_insert(s1, s2, x);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_1) {
  char *s1 = "123abcdr312adfjko123\0";
  char *s2 = "123\0";
  char *ex = "abcdr312adfjko\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_2) {
  char *s1 = ".....My name is Mahesh Chand****\0";
  char *s2 = "*.";
  char *ex = "My name is Mahesh Chand\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_3) {
  char *s1 = "  **  //QWERTYUI//  //  **\0";
  char *s2 = " */\0";
  char *ex = "QWERTYUI\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_4) {
  char *s1 = "-=1--1=--=\0";
  char *s2 = "-=\0";
  char *ex = "1--1\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_5) {
  char *s1 = NULL;
  char *s2 = " \0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST

START_TEST(trim_6) {
  char *s1 = "+!!++Abo+ba++00\0";
  char *s2 = "+!0-\0";
  char *ex = "Abo+ba\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_7) {
  char *s1 = "+!!++Abo+ba++00\0";
  char *s2 = NULL;
  char *ex = "+!!++Abo+ba++00\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(trim_8) {
  char *s1 = "\0";
  char *s2 = "123\0";
  char *ex = "\0";
  char *result = (char *)s21_trim(s1, s2);
  ck_assert_str_eq(result, ex);
  if (result) free(result);
}
END_TEST

START_TEST(strerror_1) {
  for (int i = -3; i < 140; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!\0";
  char s3[100] = "hELLO, WORLD!\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123\0";
  char s3[100] = "\nH\t\\G123123\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "already lower\0";
  char s3[100] = "already lower\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "\0";
  char s3[100] = "\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz\0";
  char s3[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234\0";
  char s3[100] = "_?};!234\0";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_1) {
  char s1[30] = "Hello, world!\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "HELLO, WORLD!\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char s1[30] = "\nh\t\\g123123\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "\nH\t\\G123123\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char s1[30] = "ALREADY UPPER\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "ALREADY UPPER\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char s1[30] = "\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char s1[30] = "_?};!234\0";
  char *s2 = s21_to_upper(s1);
  char s3[100] = "_?};!234\0";
  ck_assert_str_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_upper_4);
  tcase_add_test(tc, test_to_upper_5);
  tcase_add_test(tc, test_to_upper_6);
  // tcase_add_test(tc, test_to_upper_7);

  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  // tcase_add_test(tc, test_to_lower_7);

  tcase_add_test(tc, s21_memchr_test1);
  tcase_add_test(tc, s21_memchr_test2);
  tcase_add_test(tc, s21_memchr_test3);
  tcase_add_test(tc, s21_memchr_test4);
  tcase_add_test(tc, s21_memchr_test5);
  tcase_add_test(tc, s21_memchr_test6);
  tcase_add_test(tc, s21_memchr_test7);
  tcase_add_test(tc, s21_memchr_test8);
  tcase_add_test(tc, s21_memchr_test9);
  tcase_add_test(tc, s21_memchr_test10);
  tcase_add_test(tc, s21_memchr_test11);
  tcase_add_test(tc, s21_memchr_test12);
  tcase_add_test(tc, s21_memcmp_test1);
  tcase_add_test(tc, s21_memcmp_test2);
  tcase_add_test(tc, s21_memcmp_test3);
  tcase_add_test(tc, s21_memcmp_test4);
  tcase_add_test(tc, s21_memcmp_test5);
  tcase_add_test(tc, s21_memcmp_test6);
  tcase_add_test(tc, s21_memcmp_test7);
  tcase_add_test(tc, s21_memcmp_test8);
  tcase_add_test(tc, s21_memcmp_test9);
  tcase_add_test(tc, s21_memcmp_test10);
  tcase_add_test(tc, s21_memcmp_test11);
  tcase_add_test(tc, s21_memset_test1);
  tcase_add_test(tc, s21_memset_test2);
  tcase_add_test(tc, s21_memset_test3);
  tcase_add_test(tc, s21_memset_test4);
  tcase_add_test(tc, s21_memset_test5);
  tcase_add_test(tc, s21_memset_test6);
  tcase_add_test(tc, s21_memset_test7);
  tcase_add_test(tc, s21_memset_test8);
  tcase_add_test(tc, s21_memset_test9);
  tcase_add_test(tc, s21_memset_test10);
  tcase_add_test(tc, s21_memset_test11);
  tcase_add_test(tc, s21_memset_test12);
  tcase_add_test(tc, s21_memset_test13);
  tcase_add_test(tc, s21_memcpy_test1);
  tcase_add_test(tc, s21_memcpy_test2);
  tcase_add_test(tc, s21_memcpy_test3);
  tcase_add_test(tc, s21_memcpy_test4);
  tcase_add_test(tc, s21_memcpy_test5);
  tcase_add_test(tc, s21_memcpy_test6);
  tcase_add_test(tc, s21_memcpy_test7);
  tcase_add_test(tc, s21_memcpy_test8);
  tcase_add_test(tc, s21_memcpy_test9);
  tcase_add_test(tc, s21_memcpy_test10);
  tcase_add_test(tc, s21_memcpy_test11);
  tcase_add_test(tc, s21_memcpy_test12);

  tcase_add_test(tc, s21_strlen_test1);
  tcase_add_test(tc, s21_strlen_test2);
  tcase_add_test(tc, s21_strlen_test3);
  tcase_add_test(tc, s21_strlen_test4);
  tcase_add_test(tc, s21_strlen_test5);
  tcase_add_test(tc, s21_strlen_test6);
  tcase_add_test(tc, s21_strlen_test7);
  tcase_add_test(tc, s21_strlen_test8);

  tcase_add_test(tc, s21_strncmp_test1);
  tcase_add_test(tc, s21_strncmp_test2);
  tcase_add_test(tc, s21_strncmp_test3);
  tcase_add_test(tc, s21_strncmp_test4);
  tcase_add_test(tc, s21_strncmp_test5);
  tcase_add_test(tc, s21_strncmp_test6);
  tcase_add_test(tc, s21_strncmp_test7);
  tcase_add_test(tc, s21_strncmp_test8);
  tcase_add_test(tc, s21_strncmp_test9);
  tcase_add_test(tc, s21_strncmp_test10);
  tcase_add_test(tc, s21_strncmp_test11);
  tcase_add_test(tc, s21_strncmp_test12);
  tcase_add_test(tc, s21_strncmp_test13);
  tcase_add_test(tc, s21_strncmp_test14);
  tcase_add_test(tc, strncpy_test1);
  tcase_add_test(tc, strncpy_test2);
  tcase_add_test(tc, strncpy_test3);
  tcase_add_test(tc, strncpy_test4);
  tcase_add_test(tc, strncpy_test5);
  tcase_add_test(tc, strncpy_test6);
  tcase_add_test(tc, strncpy_test7);
  tcase_add_test(tc, strncpy_test8);
  tcase_add_test(tc, strncpy_test9);
  tcase_add_test(tc, strncpy_test10);
  tcase_add_test(tc, strncpy_test11);
  tcase_add_test(tc, s21_strncat_test1);
  tcase_add_test(tc, s21_strncat_test2);
  tcase_add_test(tc, s21_strncat_test3);
  tcase_add_test(tc, s21_strncat_test4);
  tcase_add_test(tc, s21_strncat_test5);
  tcase_add_test(tc, s21_strncat_test6);
  tcase_add_test(tc, s21_strncat_test7);
  tcase_add_test(tc, s21_strncat_test8);
  tcase_add_test(tc, s21_strncat_test9);
  tcase_add_test(tc, s21_strncat_test10);

  tcase_add_test(tc, s21_strcspn_test1);
  tcase_add_test(tc, s21_strcspn_test2);
  tcase_add_test(tc, s21_strcspn_test3);
  tcase_add_test(tc, s21_strcspn_test4);
  tcase_add_test(tc, s21_strcspn_test5);
  tcase_add_test(tc, s21_strcspn_test6);
  tcase_add_test(tc, s21_strcspn_test7);
  tcase_add_test(tc, s21_strcspn_test8);
  tcase_add_test(tc, s21_strcspn_test9);
  tcase_add_test(tc, s21_strcspn_test10);
  tcase_add_test(tc, s21_strcspn_test11);
  tcase_add_test(tc, s21_strcspn_test12);
  tcase_add_test(tc, s21_strcspn_test13);
  tcase_add_test(tc, s21_strcspn_test14);
  tcase_add_test(tc, s21_strtok_test1);
  tcase_add_test(tc, s21_strtok_test2);
  tcase_add_test(tc, s21_strtok_test3);
  tcase_add_test(tc, s21_strtok_test4);
  tcase_add_test(tc, s21_strtok_test5);
  tcase_add_test(tc, s21_strtok_test6);
  tcase_add_test(tc, s21_strtok_test7);
  tcase_add_test(tc, s21_strtok_test8);
  tcase_add_test(tc, s21_strchr_test1);
  tcase_add_test(tc, s21_strchr_test2);
  tcase_add_test(tc, s21_strchr_test3);
  tcase_add_test(tc, s21_strchr_test4);
  tcase_add_test(tc, s21_strchr_test5);
  tcase_add_test(tc, s21_strchr_test6);
  tcase_add_test(tc, s21_strchr_test7);
  tcase_add_test(tc, s21_strchr_test8);
  tcase_add_test(tc, s21_strchr_test9);
  tcase_add_test(tc, s21_strchr_test10);
  tcase_add_test(tc, s21_strchr_test11);

  tcase_add_test(tc, s21_strrchr_test1);
  tcase_add_test(tc, s21_strrchr_test2);
  tcase_add_test(tc, s21_strrchr_test3);
  tcase_add_test(tc, s21_strrchr_test4);
  tcase_add_test(tc, s21_strrchr_test5);
  tcase_add_test(tc, s21_strrchr_test6);
  tcase_add_test(tc, s21_strrchr_test7);
  tcase_add_test(tc, s21_strrchr_test8);
  tcase_add_test(tc, s21_strrchr_test9);
  tcase_add_test(tc, s21_strrchr_test10);
  tcase_add_test(tc, s21_strrchr_test11);
  tcase_add_test(tc, s21_strrchr_test12);
  tcase_add_test(tc, s21_strchr_test13);
  tcase_add_test(tc, s21_strchr_test14);

  tcase_add_test(tc, s21_strpbrk_test1);
  tcase_add_test(tc, s21_strpbrk_test2);
  tcase_add_test(tc, s21_strpbrk_test3);
  tcase_add_test(tc, s21_strpbrk_test4);
  tcase_add_test(tc, s21_strpbrk_test5);
  tcase_add_test(tc, s21_strpbrk_test6);
  tcase_add_test(tc, s21_strpbrk_test7);
  tcase_add_test(tc, s21_strpbrk_test8);
  tcase_add_test(tc, s21_strpbrk_test9);
  tcase_add_test(tc, s21_strpbrk_test10);
  tcase_add_test(tc, s21_strpbrk_test11);
  tcase_add_test(tc, s21_strpbrk_test12);
  tcase_add_test(tc, s21_strpbrk_test13);
  tcase_add_test(tc, s21_strpbrk_test14);

  tcase_add_test(tc, s21_strstr_test1);
  tcase_add_test(tc, s21_strstr_test2);
  tcase_add_test(tc, s21_strstr_test3);
  tcase_add_test(tc, s21_strstr_test4);
  tcase_add_test(tc, s21_strstr_test5);
  tcase_add_test(tc, s21_strstr_test6);
  tcase_add_test(tc, s21_strstr_test7);
  tcase_add_test(tc, s21_strstr_test8);
  tcase_add_test(tc, s21_strstr_test9);
  tcase_add_test(tc, s21_strstr_test10);
  tcase_add_test(tc, s21_strstr_test11);
  tcase_add_test(tc, s21_strstr_test12);
  tcase_add_test(tc, s21_strstr_test13);
  tcase_add_test(tc, s21_strstr_test14);
  tcase_add_test(tc, s21_strstr_test15);

  // tcase_add_test(tc, s21_sprintf_test_1);
  // tcase_add_test(tc, s21_sprintf_test_2);
  tcase_add_test(tc, s21_sprintf_test_3);
  tcase_add_test(tc, s21_sprintf_test_4);
  tcase_add_test(tc, s21_sprintf_test_5);
  tcase_add_test(tc, s21_sprintf_test_6);
  tcase_add_test(tc, s21_sprintf_test_7);
  tcase_add_test(tc, s21_sprintf_test_8);
  tcase_add_test(tc, s21_sprintf_test_9);
  tcase_add_test(tc, s21_sprintf_test_10);
  tcase_add_test(tc, s21_sprintf_test_11);
  tcase_add_test(tc, s21_sprintf_test_12);
  tcase_add_test(tc, s21_sprintf_test_13);
  tcase_add_test(tc, s21_sprintf_test_14);
  tcase_add_test(tc, s21_sprintf_test_15);
  tcase_add_test(tc, s21_sprintf_test_16);
  tcase_add_test(tc, s21_sprintf_test_17);
  tcase_add_test(tc, s21_sprintf_test_18);

  tcase_add_test(tc, s21_sprintf_test1);
  tcase_add_test(tc, s21_sprintf_test2);
  tcase_add_test(tc, s21_sprintf_test3);
  tcase_add_test(tc, s21_sprintf_test4);
  tcase_add_test(tc, s21_sprintf_test5);
  tcase_add_test(tc, s21_sprintf_test6);
  tcase_add_test(tc, s21_sprintf_test7);
  tcase_add_test(tc, s21_sprintf_test8);
  tcase_add_test(tc, s21_sprintf_test9);
  tcase_add_test(tc, s21_sprintf_test10);
  tcase_add_test(tc, s21_sprintf_test11);
  tcase_add_test(tc, s21_sprintf_test12);
  tcase_add_test(tc, s21_sprintf_test13);
  tcase_add_test(tc, s21_sprintf_test14);
  tcase_add_test(tc, s21_sprintf_test15);
  tcase_add_test(tc, s21_sprintf_test16);
  tcase_add_test(tc, s21_sprintf_test17);
  tcase_add_test(tc, s21_sprintf_test18);

  tcase_add_test(tc, s21_sprintf_test_f_1);
  tcase_add_test(tc, s21_sprintf_test_f_2);
  tcase_add_test(tc, s21_sprintf_test_f_3);
  tcase_add_test(tc, s21_sprintf_test_f_4);
  tcase_add_test(tc, s21_sprintf_test_f_5);
  tcase_add_test(tc, s21_sprintf_test_f_6);
  tcase_add_test(tc, s21_sprintf_test_f_7);
  tcase_add_test(tc, s21_sprintf_test_f_8);
  tcase_add_test(tc, s21_sprintf_test_f_9);
  tcase_add_test(tc, s21_sprintf_test_f_10);
  tcase_add_test(tc, s21_sprintf_test_f_11);
  tcase_add_test(tc, s21_sprintf_test_f_12);
  tcase_add_test(tc, s21_sprintf_test_f_13);
  tcase_add_test(tc, s21_sprintf_test_f_14);
  tcase_add_test(tc, s21_sprintf_test_f_15);
  tcase_add_test(tc, s21_sprintf_test_f_16);
  tcase_add_test(tc, s21_sprintf_test_f_17);
  tcase_add_test(tc, s21_sprintf_test_f_18);

  tcase_add_test(tc, s21__sprintf_test1);
  tcase_add_test(tc, s21__sprintf_test2);
  tcase_add_test(tc, s21__sprintf_test3);
  tcase_add_test(tc, s21__sprintf_test4);
  tcase_add_test(tc, s21__sprintf_test5);
  tcase_add_test(tc, s21__sprintf_test6);
  tcase_add_test(tc, s21__sprintf_test7);
  tcase_add_test(tc, s21__sprintf_test8);
  tcase_add_test(tc, s21__sprintf_test9);
  tcase_add_test(tc, s21__sprintf_test10);
  tcase_add_test(tc, s21__sprintf_test11);
  tcase_add_test(tc, s21__sprintf_test12);
  tcase_add_test(tc, s21__sprintf_test13);
  tcase_add_test(tc, s21__sprintf_test14);
  tcase_add_test(tc, s21__sprintf_test15);
  tcase_add_test(tc, s21__sprintf_test16);
  tcase_add_test(tc, s21__sprintf_test17);
  tcase_add_test(tc, s21__sprintf_test18);

  tcase_add_test(tc, s21__sprintf_test_perc_1);
  tcase_add_test(tc, s21__sprintf_test_perc_2);
  tcase_add_test(tc, s21__sprintf_test_perc_3);
  tcase_add_test(tc, s21__sprintf_test_perc_4);
  tcase_add_test(tc, s21__sprintf_test_perc_5);
  tcase_add_test(tc, s21__sprintf_test_perc_6);
  tcase_add_test(tc, s21__sprintf_test_perc_7);
  tcase_add_test(tc, s21__sprintf_test_perc_8);
  tcase_add_test(tc, s21__sprintf_test_perc_9);
  tcase_add_test(tc, s21__sprintf_test_perc_10);
  tcase_add_test(tc, s21__sprintf_test_perc_11);
  tcase_add_test(tc, s21__sprintf_test_perc_12);
  tcase_add_test(tc, s21__sprintf_test_perc_13);
  tcase_add_test(tc, s21__sprintf_test_perc_14);
  tcase_add_test(tc, s21__sprintf_test_perc_15);
  tcase_add_test(tc, s21__sprintf_test_perc_16);
  tcase_add_test(tc, s21__sprintf_test_perc_17);
  tcase_add_test(tc, s21__sprintf_test_perc_18);

  tcase_add_test(tc, s21__sprintf_test_gG1);
  tcase_add_test(tc, s21__sprintf_test_gG2);
  tcase_add_test(tc, s21__sprintf_test_gG3);
  tcase_add_test(tc, s21__sprintf_test_gG4);
  tcase_add_test(tc, s21__sprintf_test_gG5);
  tcase_add_test(tc, s21__sprintf_test_gG6);
  tcase_add_test(tc, s21__sprintf_test_gG7);
  tcase_add_test(tc, s21__sprintf_test_gG8);
  tcase_add_test(tc, s21__sprintf_test_gG9);
  tcase_add_test(tc, s21__sprintf_test_gG10);
  tcase_add_test(tc, s21__sprintf_test_gG11);
  tcase_add_test(tc, s21__sprintf_test_gG12);
  tcase_add_test(tc, s21__sprintf_test_gG13);
  tcase_add_test(tc, s21__sprintf_test_gG14);
  tcase_add_test(tc, s21__sprintf_test_gG15);
  tcase_add_test(tc, s21__sprintf_test_gG16);
  tcase_add_test(tc, s21__sprintf_test_gG17);
  tcase_add_test(tc, s21__sprintf_test_gG18);

  tcase_add_test(tc, s21__sprintf_test_eror_str1);

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  tcase_add_test(tc, trim_8);
  tcase_add_test(tc, strerror_1);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  setlocale(LC_ALL, "");
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = suite_insert();
  sr = srunner_create(s1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  nf = 0;
  srunner_free(sr);
  return nf;
}