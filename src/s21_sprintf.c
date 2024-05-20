#include "s21_string.h"
int s21_sprintf(char *str, const char *format, ...) {
  char er[57] = "!@$^&(_=)?/}{|`~><,abkmMqrtyvzABKCDIFOSUPNQRTYVZwWHjJ;:'";
  char *src = str, *p_format = (char *)format;
  va_list arguments;
  va_start(arguments, format);  //инициализация va_list
  for (; *p_format != 0;) {
    if (*p_format == '%') {
      p_format++;
      value spec = {0};
      p_format = parser_spec(p_format, &spec, arguments);
      str = from_str_to_format(str, &spec, p_format, arguments);
      if (s21_strchr(er, *p_format) == s21_NULL)
        p_format++;
      else {
        print_specwight(&str, &spec, &p_format);
      }
    } else {
      *str = *p_format;
      str++;
      p_format++;
    }
  }
  for (int i = 0; i < 2; i++) {
    *str = '\0';
    str++;
  }
  va_end(arguments);
  return (str - src - 2);
}
//флот в строку
char *flt_to_str(long double flt, char *str, value *spec) {
  if (flt < 0.0) flt = flt * -1, *str = '-', str = str + 1;
  unsigned long long rem = 1;
  int k = 0, flag = 0;

  if (flt < 1.0 && spec->accuracy > 0) {
    flag = 1, *str = '0';
    str = str + 1, *str = '.';
    str = str + 1, flt *= 10.0;
    spec->accuracy--;
    while (flt < 0.1 && spec->accuracy > 0) {
      *str = '0', str = str + 1, flt *= 10.0;
      spec->accuracy--;
    }
  }

  if (flt < 1.0 && spec->accuracy == 0) flag = 1, *str = '0', str = str + 1;

  flt = flt * pow(10, spec->accuracy);

  while (rem <= flt) rem *= 10, k++;

  if (((long long)(flt * 10) % 10) > 4) flt++;

  int dot = k - spec->accuracy;
  rem /= 10;

  while (k > 0) {
    if (!dot && flag == 0) *str = '.', str = str + 1;
    *str = (long long)(flt / rem) % 10 + 48;
    str = str + 1, rem = rem / 10, k--, dot--;
  }

  if (flt == 0) str = str + 1;
  return str;
}
//переводит из десятичного в строчку
char *decimal_to_string(char *str, long long dec) {
  if (dec < 0) {
    dec *= -1;
    *str = '-';
    str += 1;
  }
  long long rem = 1;
  int k = 0;
  while (rem <= dec) {
    rem *= 10;
    k++;
  }
  rem /= 10;
  while (k > 0) {
    *str = ((long long)dec / rem) % 10 + 48;
    str = str + 1;
    rem = rem / 10;
    k--;
  }
  *str = dec % 10 + 48;
  if (dec == 0) str = str + 1;
  return str;
}
//парсер для флажочков
char *parser_spec(char *format, value *spec, va_list arguments) {
  char *p_format = (char *)format;
  spec->accuracy = 6;
  char specs[18] = "cdieEfgGosuxXpn%\0\0", numbers[13] = "123456789*.\0\0";
  int len = (int)s21_strcspn(p_format, specs);
  int len_num = (int)s21_strcspn_n(len, p_format, numbers);
  int lenum = len - len_num * (len_num <= len);
  if (len == 0) len_num = 0;
  char er[59] = "!@$^&(_=)?/}{|`~><,abkmMqrtyvzABKCDIFOSUPNQRTYVZwWHjJ;:'\0\0";
  while (len_num > 0 && (s21_strchr(er, *(p_format)) == s21_NULL)) {
    if (*p_format == ' ') spec->space = 1;
    if (*p_format == '-') spec->minus = 1;
    if (*p_format == '0') spec->zero = 1;
    if (*p_format == '+') spec->plus = 1;
    if (*p_format == '#') spec->mesh = 1;
    if (*p_format == '%') spec->percent = 1;
    if (*p_format == '*') spec->star = 1;
    p_format += 1;
    len_num--;
  }
  if (spec->plus || spec->zero) spec->space = 0;
  if (spec->minus) spec->zero = 0;
  if (len_num >= 0) p_format = accuracy_wight(p_format, spec, lenum, arguments);
  return p_format;
}
//ширина и точность
char *accuracy_wight(char *p_format, value *spec, int lenum,
                     va_list arguments) {
  int flag = 0;
  spec->type = ' ';
  char er[57] = "!@$^&(_=)?/}{|`~><,abkmMqrtyvzABKCDIFOSUPNQRTYVZwWHjJ;:'";
  char numbers[11] = "1234567890*";
  while (lenum-- > 0 && (s21_strchr(er, *(p_format)) == s21_NULL)) {
    if (*p_format == 'l' || *p_format == 'h' || *p_format == 'L') {
      if (spec->type == ' ' || spec->type == 'h') spec->type = *p_format;
    } else {
      if (*p_format == '.') {
        spec->accuracy = 0;
        flag = 1;
        p_format += 1;
        if ((s21_strchr(numbers, *(p_format)) == s21_NULL)) break;
        spec->point = 1;
        lenum--;
      }
      if (flag == 0 && *p_format != '.') {
        if (*p_format == '*') {
          spec->wight = va_arg(arguments, int);
        } else {
          spec->wight *= 10;
          spec->wight += *p_format - 48;
        }
      }
      if (flag == 1 && *p_format != '.') {
        if (*p_format == '*') {
          spec->accuracy = va_arg(arguments, int);
          break;
        } else {
          spec->accuracy *= 10;
          spec->accuracy += *p_format - 48;
        }
      }
    }
    p_format += 1;
  }
  return p_format;
}
//проход по аргументам
char *from_str_to_format(char *str, value *spec, char *format,
                         va_list arguments) {
  // if (*format == 'G' || *format == 'g') {
  //   double flt = va_arg(arguments, double), buf = 0;
  //   int exp = 0;
  //   buf = bringing_numbers(fabs(flt), &exp);
  //   if (fabs(flt) <= 1000000.0 && fabs(flt) >= 0.00001) {
  //     str = float_to_str(flt, &str, spec);
  //   } else {
  //     if (*format == 'G')
  //       spec->alf = 'E';
  //     else
  //       spec->alf = 'e';
  //     str = float_to_str_e(flt, &str, spec);
  //   }
  // }
  if (*format == 'd' || *format == 'u') {
    long long dec = 0;  //получаем число из аргументов
    if (spec->type == 'l')
      dec = va_arg(arguments, long long);
    else if (spec->type == 'h') {
      dec = va_arg(arguments, int);
      dec = (short)dec;
    } else
      dec = va_arg(arguments, int);
    if (dec < 0 && *format == 'u') dec = 4294967296 - dec;
    str = dec_to_str(dec, &str, spec);
  }
  if (*format == 'c' || *format == '%') {
    int ch = 0;
    if (*format != '%')
      ch = va_arg(arguments, int);  //получаем число из аргументов
    else
      ch = '%';
    str = char_to_str(ch, &str, spec);
  }
  if (*format == 's') {
    char string[10000] = {0};
    char *p_string = string;
    p_string = va_arg(arguments, char *);
    str = string_to_str(p_string, &str, spec);
  }
  if (*format == 'f') {
    double flt = va_arg(arguments, double);  //получаем число из аргументов
    str = float_to_str(flt, &str, spec);
  }
  if (*format == 'e' || *format == 'E') {
    spec->alf = *format;
    double flt = va_arg(arguments, double);
    str = float_to_str_e(flt, &str, spec);
  }
  return str;
}

//%d and %u
char *dec_to_str(long long dec, char **str, value *spec) {
  int len = 0;
  long long dec_rem = dec;  // len длина числа со знаком вместе
  if (dec < 0) {
    dec *= -1, len++;
  }
  if (dec == 0) len = 1;
  while (dec > 0) {
    dec = dec / 10, len++;
  }
  if (spec->space) {
    **str = ' ', *str = *str + 1, len++;
  }
  if (spec->zero && dec_rem < 0) **str = '-', *str = *str + 1, dec_rem *= -1;
  if (spec->minus) {
    if (spec->plus && dec_rem >= 0) **str = '+', *str = *str + 1, spec->wight--;
    *str = decimal_to_string(*str, dec_rem);
    int s = spec->wight - len;
    while (s > 0) **str = ' ', *str = *str + 1, s--;
  } else {
    int s = spec->wight - len;
    if (spec->plus && dec_rem >= 0 && !spec->zero) {
      s--;
    }
    while (s > 0) {
      if (spec->zero)
        **str = '0';
      else
        **str = ' ';
      *str = *str + 1, s--;
    }
    if (spec->plus && dec_rem >= 0 && !spec->zero) **str = '+', *str = *str + 1;
    *str = decimal_to_string(*str, dec_rem);
  }
  return *str;
}
//%c
char *char_to_str(char ch, char **str, value *spec) {
  if (spec->minus) {
    **str = ch, *str = *str + 1;
    int s = spec->wight - 1;
    while (s > 0) {
      **str = ' ', *str = *str + 1, s--;
    }
  } else {
    int s = spec->wight - 1;
    while (s > 0) {
      if (spec->zero)
        **str = '0';
      else
        **str = ' ';
      *str = *str + 1, s--;
    }
    **str = ch, *str = *str + 1;
  }
  return *str;
}
//%s
char *string_to_str(char *ch, char **str, value *spec) {
  int s = spec->wight - (int)s21_strlen(ch);
  if (spec->minus) {
    while (*ch != 0) {
      **str = *ch, *str = *str + 1, ch = ch + 1;
    }
    while (s > 0) {
      **str = ' ', *str = *str + 1, s--;
    }
  } else {
    while (s > 0) {
      if (spec->zero) {
        **str = '0';
      } else
        **str = ' ';
      *str = *str + 1, s--;
    }
    while (*ch != 0) {
      **str = *ch, *str = *str + 1, ch = ch + 1;
    }
  }
  return *str;
}
//%f
int kolichestvo_cifr(long double flt, value spec) {
  int len = 0;
  if (flt == 0.0) len = 1;
  if (flt == 1 && spec.plus && !spec.minus) len++;
  flt < 0.0 ? flt *= -1, len++ : flt;  //+ 1 за минус
  len += spec.accuracy + 1 * (spec.accuracy > 0) -
         (flt == 1.0 && spec.accuracy > 0) + 1 * (flt < 1.0) +
         1 * (flt == 1.0 && spec.accuracy > 0);
  while (flt >= 0.1999999999) {
    len++, flt /= 10;
  }

  return len;
}

char *float_to_str(long double flt, char **str, value *spec) {
  long double flt_rem = flt;
  int len = kolichestvo_cifr(flt, *spec);  // len длина числа со знаком вместе
  if (spec->space && flt_rem > 0.0 && spec->minus)
    **str = ' ', *str = *str + 1, spec->wight--;
  if (spec->zero && flt_rem < 0.0) **str = '-', *str = *str + 1, flt_rem *= -1;
  if (spec->minus) {
    if (spec->plus && flt_rem > 0.0)
      **str = '+', *str = *str + 1, spec->wight--;
    *str = flt_to_str(flt_rem, *str, spec);
    int s = spec->wight - len;
    while (s > 0) {
      **str = ' ', *str = *str + 1, s--;
    }
  } else {
    if (spec->plus && flt_rem > 0.1 && spec->zero)
      **str = '+', *str = *str + 1, spec->wight--;
    int s = spec->wight - len;
    if (spec->space && flt_rem > 0.0 && s <= 0) **str = ' ', *str = *str + 1;
    if (spec->plus && flt_rem > 0.0 && !spec->zero && !spec->minus) s--;
    while (s > 0) {
      if (spec->zero)
        **str = '0';
      else
        **str = ' ';
      *str = *str + 1, s--;
    }
    if (spec->plus && flt_rem > 0.0 && !spec->zero)
      **str = '+', *str = *str + 1;
    *str = flt_to_str(flt_rem, *str, spec);
  }
  return *str;
}
//
void print_specwight(char **str, value *spec, char **format) {
  int s = spec->wight - 1;
  if (spec->minus) {
    **str = **format;
    *str = *str + 1;
    *format = *format + 1;
    while (s > 0) {
      **str = ' ';
      *str = *str + 1;
      s--;
    }
  } else {
    while (s > 0) {
      if (spec->zero)
        **str = '0';
      else
        **str = ' ';
      *str = *str + 1;
      s--;
    }
    **str = **format;
    *str = *str + 1;
    *format = *format + 1;
  }
}
//%eE
char *float_to_str_e(long double flt, char **str, value *spec) {
  int len = 0, minus = -1, exp = 0, znak = -1;
  long double flt_rem = flt;
  if (flt < 0.0) {
    flt *= -1;
    len++;
    minus = 1;
  }
  if (fabs((double)flt_rem) < 1.0) znak = 1;
  if (flt == 0.0) len = 1;
  flt_rem = bringing_numbers(fabs((double)flt_rem), &exp);
  if (minus == 1) flt_rem *= -1;
  len += spec->accuracy - 1 * (spec->minus * (flt < 0.0)) -
         1 * (spec->accuracy == 0);
  if (spec->space && minus < 0) {
    **str = ' ';
    *str = *str + 1;
    len++;
  }
  if (spec->zero && flt_rem < 0.0) {
    **str = '-';
    *str = *str + 1;
    flt_rem *= -1;
  }
  if (spec->minus) {
    if (spec->plus && minus < 0) {
      **str = '+';
      *str = *str + 1;
      spec->wight--;
    }
    *str = flt_to_str(flt_rem, *str, spec);
    *str = exp_prefix(str, spec, znak, exp);
    int s = spec->wight - len - 6;
    while (s > 0) {
      **str = ' ';
      *str = *str + 1;
      s--;
    }
  } else {
    if (spec->plus && minus < 0 && spec->zero) {
      **str = '+';
      *str = *str + 1;
      spec->wight--;
    }
    int s = spec->wight - len - 6;
    if (spec->plus && flt_rem > 0 && !spec->zero) {
      s--;
    }
    while (s > 0) {
      if (spec->zero) {
        **str = '0';
      } else
        **str = ' ';
      *str = *str + 1;
      s--;
    }
    if (spec->plus && minus < 0 && !spec->zero) {
      **str = '+';
      *str = *str + 1;
    }
    *str = flt_to_str(flt_rem, *str, spec);
    *str = exp_prefix(str, spec, znak, exp);
  }
  return *str;
}
// 111.00->1.1100
double bringing_numbers(double flt, int *exp) {
  while (flt > 10.0) {
    flt = flt / 10;
    *exp += 1;
  }
  while (flt < 1.0) {
    flt = flt * 10;
    *exp += 1;
  }
  return flt;
}
// e+-00
char *exp_prefix(char **str, value *spec, int znak, int exp) {
  **str = spec->alf;
  *str = *str + 1;
  if (znak < 0) {
    **str = '+';
    *str = *str + 1;
  } else {
    **str = '-';
    *str = *str + 1;
  }
  if (exp < 10) {
    **str = '0';
    *str = *str + 1;
  }
  *str = decimal_to_string(*str, (long long)exp);
  return *str;
}
