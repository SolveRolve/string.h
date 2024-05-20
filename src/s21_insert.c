#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  static char *res = s21_NULL;
  int f = 1;

  if (src == s21_NULL || str == s21_NULL)
    f = 0;
  else {
    s21_size_t len_src = s21_strlen(src);
    if (len_src < start_index)
      f = 0;
    else {
      s21_size_t len_str = s21_strlen(str);
      s21_size_t len = len_str + len_src + 1;
      if ((int)start_index < 0 || start_index > len_src)
        f = 0;
      else if (len <= start_index)
        f = 0;
      else {
        res = (char *)calloc(len, sizeof(char));
        if (res == s21_NULL)
          f = 0;
        else {
          s21_strcpy(res, src);
          s21_strcpy(res + start_index, str);
          s21_strcpy(res + start_index + len_str, src + start_index);
        }
      }
    }
  }

  return (f == 1) ? res : s21_NULL;
}