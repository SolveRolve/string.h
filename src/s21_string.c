#include "s21_string.h"

//функция возвращает длину строки
s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  while (*str != 0) lenght++, str++;
  return lenght;
}
//функция возвращает указатель на позицию на которой находиться символ
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  int flag = 0;
  if (s21_strlen(str) < n) n = s21_strlen(str);
  while (n--) {
    if (*p == c) {
      flag = 1;
      break;  //возвращает адрес первого вхождение в строку символа (с)
    }
    p++;
  }
  return flag ? (void *)p : s21_NULL;
}
// cравнение двух блоков памяти <0 >0 0
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *str_1 = str1, *str_2 = str2;
  while (n--) {
    if (*str_1 != *str_2) {
      result = *str_1 - *str_2;
      break;
    }
    str_1++, str_2++;
  }
  return result;
}
//копирует из срц в дест n  символов
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *str_in = src, *str_out = dest;
  while (n > 0) {
    *(char *)dest = *str_in;
    dest++, str_in++, n--;
  }
  return (void *)str_out;
}
//заполняем массив указанными символами н раз
void *s21_memset(void *str, int c, s21_size_t n) {
  char *p_str = str;
  int flag = 0;
  while (n > 0) {
    *(char *)str = c;
    str++, n--, flag = 1;
  }
  str = p_str;
  return flag ? (void *)str : s21_NULL;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *str_in = (char *)src, *str_rem = (char *)dest;
  while (*dest != '\0') dest++;
  while (n--) *dest = *str_in, str_in++, dest++;
  *dest = '\0';
  dest = str_rem;
  return dest;
}
char *s21_strchr(const char *str, int c) {
  char *ptr = (char *)str;
  int flag = 0;
  s21_size_t size = s21_strlen(str) + 1;
  while (size-- && !flag) {
    if (*ptr == c) {
      flag = 1;
      break;
    }
    ptr++;
  }
  return flag ? (char *)ptr : s21_NULL;
}

char *s21_strcpy(char *a, const char *b) {
  size_t i = 0;
  for (; b[i] != '\0'; i++) {
    a[i] = b[i];
  }
  a[i] = '\0';
  return a;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  const char *str_1 = str1, *str_2 = str2;
  while (n-- > 0) {
    if (*str_1 != *str_2) {
      result = *str_1 - *str_2;
      break;
    }
    str_1++, str_2++;
  }
  return result;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *src_res = (char *)src, *dest_res = dest;
  int flag = 0;
  while (n > 0) {
    if (*src_res == '\0') flag = 1;
    if (!flag)
      *dest = *src_res;
    else
      *dest = '\0';
    n--, src_res++, dest++;
  }
  return dest_res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ret = s21_NULL;
  const char *p1 = str1;
  int match = 0;
  while (*p1 != '\0' && !match) {
    const char *p2 = str2;
    while (*p2 != '\0' && !match) {
      if (*p1 == *p2) match = 1, ret = p1;
      p2++;
    }
    p1++;
  }
  return (char *)ret;
}

char *s21_strrchr(const char *str, int c) {
  const char *end = s21_NULL;
  for (; *str != 0; str++) {
    if (*str == c) end = str;
  }
  return *str == c ? (char *)str : (char *)end;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  if (needle == s21_NULL || *needle == '\0') res = (char *)haystack;
  for (int i = 0; haystack[i] != '\0' && !res; i++) {
    int k = i;
    for (int j = 0; needle[j] != '\0' && !res; j++) {
      if (haystack[k] == needle[j] && !res) {
        k++;
        if (needle[j + 1] == '\0' && !res) {
          res = (char *)(haystack + i);
        }
      } else {
        break;
      }
    }
  }
  return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *p_str = s21_strpbrk(str1, str2);
  int lenght = s21_strlen(str1);
  if (p_str != s21_NULL) lenght = s21_strlen(str1) - s21_strlen(p_str);
  return lenght;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last;
  char *string = str;

  char *p_str = s21_NULL;
  if (string == s21_NULL)  //
    string = last;

  if (string != s21_NULL) {
    p_str = s21_strpbrk(string, delim);
    //первое вхождение
    while (p_str == string) {
      string++;
      p_str = s21_strpbrk(string, delim);

      if (p_str != s21_NULL) {
        *p_str = 0;
        last = p_str + 1;
      }
    }
    if (p_str != s21_NULL) {
      *p_str = 0;
      last = p_str + 1;
    }
  }
  if (p_str == s21_NULL) {
    p_str = last;
    last = s21_NULL;
  }

  return p_str != s21_NULL ? string : s21_NULL;
}

s21_size_t s21_strcspn_n(int n, const char *str1, const char *str2) {
  char *p_str = s21_strpbrk(str1, str2);
  int lenght = s21_strlen(str1);
  if (p_str != s21_NULL) {
    lenght = s21_strlen(str1) - s21_strlen(p_str);
  }
  return n < lenght ? n : lenght;
}
