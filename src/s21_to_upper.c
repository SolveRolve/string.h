#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = s21_NULL;
  if (str == s21_NULL) res = s21_NULL;
  int len = s21_strlen(str);
  res = (char *)calloc(len + 1, sizeof(char));
  if (res == s21_NULL) res = s21_NULL;
  if (res) {
    for (int i = 0; i < len + 1; i++) {
      res[i] = str[i];
      if (res[i] >= 'a' && res[i] <= 'z') res[i] -= 32;
    }
  }
  return res;
}