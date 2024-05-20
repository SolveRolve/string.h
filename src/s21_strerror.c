#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char error[100] = {'\0'};
  if (errnum < 0 || errnum > MAX_ERROR_NUM) {
    s21_sprintf(error, "%s %d", TEXT_ERROR, errnum);
  } else
    s21_strncpy(error, (char *)errors_text[errnum], 99);
  return error;
}