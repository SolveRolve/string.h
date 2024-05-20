#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define p_int(x) printf(" %d", x);
#define p_str(x) printf("%s\n", x);
#define p_char(x) printf("|%c|", x);
#define er_char "!@$^&(_=)?/}{|`~><,abkmMqrtyvzABKCDIFOSUPNQRTYVZwWHjJ;:'"

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
typedef struct spec {
  int minus;
  int plus;
  int space;
  int zero;
  int mesh;
  int wight;
  int point;
  int star;
  int lenght;
  int percent;
  int accuracy;
  char type;
  char alf;
} value;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcpy(char *a, const char *b);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

char *decimal_to_string(char *str, long long dec);
char *parser_spec(char *format, value *spec, va_list arguments);
char *accuracy_wight(char *p_format, value *spec, int lenum, va_list arguments);
char *from_str_to_format(char *str, value *spec, char *format,
                         va_list arguments);
int condition(const char *format, int n);
char *dec_to_str(long long dec, char **str, value *spec);
char *char_to_str(char ch, char **str, value *spec);
char *string_to_str(char *ch, char **str, value *spec);
s21_size_t s21_strcspn_n(int n, const char *str1, const char *str2);
char *float_to_str(long double flt, char **str, value *spec);
char *flt_to_str(long double flt, char *str, value *spec);
s21_size_t s21_strpbrk_n(const char *str1, const char *str2, int n);
void print_specwight(char **str, value *spec, char **format);
char *float_to_str_e(long double flt, char **str, value *spec);
double bringing_numbers(double flt, int *exp);
char *exp_prefix(char **str, value *spec, int znak, int exp);
int kolichestvo_cifr(long double flt, value spec);