#include "../s21_string.h"

// 1. Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
//  байтах строки, на которую указывает аргумент str.
void* s21_memchr(const void* str, int c, s21_size_t n) {
  const unsigned char* ptr_str = str;
  int flag = 1;
  unsigned char* rt = S21_NULL;

  for (s21_size_t i = 0; i < n && flag; i++, ptr_str++) {
    if (*ptr_str == (unsigned char)c) {
      rt = (unsigned char*)ptr_str;
      flag = 0;
    }
  }

  return rt;
}

// 2. Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  unsigned char* ptr_str1 = (unsigned char*)str1;
  unsigned char* ptr_str2 = (unsigned char*)str2;
  int rt = 0;

  for (s21_size_t i = 0; i < n && rt == 0; i++, ptr_str1++, ptr_str2++) {
    if (*ptr_str1 != *ptr_str2) {
      rt = (int)*ptr_str1 - (int)*ptr_str2;
      break;
    }
  }

  return rt;
}

// 3. Копирует n символов из src в dest.
void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  if (src != S21_NULL && dest != S21_NULL && n > 0) {
    char* ptr_dest = dest;
    for (s21_size_t i = 0; i < n; i++, ptr_dest++, src++) {
      *(char*)ptr_dest = *(char*)src;
    }
  }
  return dest;
}

// 4.  Копирует символ c (беззнаковый тип) в первые n символов строки, на
// которую указывает аргумент str.
void* s21_memset(void* str, int c, s21_size_t n) {
  char* ptr_str = str;
  for (s21_size_t i = 0; i < n; i++, ptr_str++) {
    *ptr_str = c;
  }
  return str;
}

// 5. Добавляет строку, на которую указывает src, в конец строки,
//     на которую указывает dest, длиной до n символов.
char* s21_strncat(char* dest, const char* src, s21_size_t n) {
  int dest_len = s21_strlen(dest);
  char* ptr_dest = dest + dest_len;
  for (s21_size_t i = 0; i < n && *src != '\0'; i++) {
    *ptr_dest++ = *src++;
  }
  *ptr_dest = '\0';
  return dest;
}

// 6. выполняет поиск первого вхождения символа symbol в строку string.
char* s21_strchr(const char* str, int c) {
  s21_size_t length = s21_strlen(str) + 1;
  const char* rt = S21_NULL;
  for (s21_size_t i = 0; i < length && rt == S21_NULL; i++) {
    if (c == str[i]) rt = (str + i);
  }
  return (char*)rt;
}

// 7. сравнивает не более первых n байт строк str1 и str2
int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  while (*str1 == *str2 && --n && *str1) {
    str1++;
    str2++;
  }

  return (*str1 - *str2);
}

// 8. Копирует до n символов из строки, на которую указывает src, в dest.
char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
  char* ptr_dest = dest;
  int size = s21_strlen(src);
  if (n > 0) {
    for (s21_size_t i = 0; i < n && size; i++, size--) {
      *ptr_dest++ = *src++;
    }
    *ptr_dest = '\0';
  }
  return dest;
}

// 9. Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char* str1, const char* str2) {
  s21_size_t i = 0;
  while (*str1 != '\0' && !s21_strchr(str2, str1[i])) i++;

  return i;
}

// 10. Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.
char* s21_strerror(int errnum) {
  char* error = "";

#ifdef __linux__
  static char* linux_errors[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error",
      "Unknown error"};
#elif __APPLE__
  static char* macos_errors[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full",
      "Unknown error"};
#endif

//   if (errnum >= 0) {
#ifdef __linux__
  if (errnum >= 0 &&
      errnum < (int)(sizeof(linux_errors) / sizeof(linux_errors[0])) - 1) {
    error = linux_errors[errnum];
  } else {
    static char er[512] = "\0";
    // заменить функцию на s21_sprintf !!!
    s21_sprintf(er, "Unknown error %d", errnum);
    error = er;
  }

#elif __APPLE__
  if (errnum >= 0 &&
      errnum < (int)(sizeof(macos_errors) / sizeof(macos_errors[0])) - 1) {
    error = macos_errors[errnum];
  } else {
    static char er[512] = "\0";
    // заменить функцию на s21_sprintf !!!
    s21_sprintf(er, "Unknown error: %d", errnum);
    error = er;
  }
#endif
  //   }

  return error;
}

// 11. Определяет длинну строки
s21_size_t s21_strlen(const char* str) {
  s21_size_t length = 0;
  for (; *(str + length); length++) {
  }

  return length;
}

// 12.Находит первый символ в строке str1, который соответствует любому
// символу, указанному в str2
char* s21_strpbrk(const char* str1, const char* str2) {
  char* rt = S21_NULL;
  //   if (str1 != S21_NULL && str2 != S21_NULL) {
  for (int i = 0; rt == S21_NULL && str1[i] != '\0'; i++) {
    for (int j = 0; rt == S21_NULL && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) rt = (char*)&str1[i];
    }
  }
  //   }
  return rt;
}

// 13.Выполняет поиск последнего вхождения символа c (беззнаковый тип) в
// строке, на которую указывает аргумент str.
char* s21_strrchr(const char* str, int c) {
  char* rt = S21_NULL;

  for (; *str != '\0'; str++) {
    if (*str == c) {
      rt = (char*)str;
    }
  }
  if (c == 0 && rt == S21_NULL) {
    rt = (char*)str;
  }

  return rt;
}

// 14. Находит первое вхождение всей строки needle (не включая завершающий
// нулевой символ), которая появляется в строке haystack.
char* s21_strstr(const char* haystack, const char* needle) {
  char* rt = S21_NULL;
  for (int i = 0; rt == S21_NULL && haystack[i] != '\0'; i++) {
    int j = 0;
    for (; haystack[i + j] == needle[j] && needle[j] != '\0'; j++);
    if (needle[j] == '\0') rt = (char*)&haystack[i];
  }
  return rt;
}

// 15. Разбивает строку str на ряд токенов, разделенных delim.
char* s21_strtok(char* str, const char* delim) {
  static char* next_token = S21_NULL;
  char* token = S21_NULL;

  if (str) next_token = str;

  if (next_token) {
    for (; *next_token && s21_strchr(delim, *next_token); next_token++);

    if (*next_token != '\0') {
      token = next_token;
      for (; *next_token && !s21_strchr(delim, *next_token); next_token++);

      if (*next_token) {
        *next_token = '\0';
        next_token++;
      } else {
        next_token = S21_NULL;
      }
    }
  }

  return token;
}