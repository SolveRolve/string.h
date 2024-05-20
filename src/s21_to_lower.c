#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str == s21_NULL) res = s21_NULL;
  s21_size_t len = s21_strlen(str);
  res = (char *)calloc(len + 1, sizeof(char));
  if (res == s21_NULL) res = s21_NULL;
  if (res) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
  }
  return res;
}