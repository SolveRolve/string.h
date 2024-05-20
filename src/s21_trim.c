#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src == s21_NULL) return s21_NULL;
  s21_size_t len_src = s21_strlen(src);
  s21_size_t lenght = len_src + 1;
  s21_size_t i = 0;
  res = (char *)calloc(lenght, sizeof(char));
  s21_strcpy(res, src);
  if (trim_chars == s21_NULL) {
    for (i = 0; i < lenght; i++) {
      res[i] = src[i];
    }
  } else if (src != s21_NULL && trim_chars != s21_NULL) {
    while (i < lenght && s21_strchr(trim_chars, res[i]) != s21_NULL) {
      i++;
    }
    if (i > 0) {
      s21_memcpy(res, res + i, lenght - i + 1);
      lenght -= i;
    }
    i = lenght;
    while (i > 0 && s21_strchr(trim_chars, res[i - 1]) != s21_NULL) {
      i--;
    }
    if (i < lenght - 1) res[i] = '\0';
  }
  return res;
}