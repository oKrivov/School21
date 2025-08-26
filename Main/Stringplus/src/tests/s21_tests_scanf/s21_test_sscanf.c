#include "../s21_tests_main_runner.h"

// Тестируем успешное считывание целого числа
START_TEST(test_s21_sscanf_int) {
  const char *input = "123";
  const char *format = "%d";

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value,
                   expected_value);  // Проверяем, что считанное значение верно
}
END_TEST

// Тестируем считывание строки
START_TEST(test_s21_sscanf_string) {
  const char *input = "Hello, world!";
  const char *format = "%s";

  char my_value[50];
  int my_result = s21_sscanf(input, format, &my_value);

  char expected_value[50];
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_str_eq(my_value,
                   expected_value);  // Проверяем, что считанное значение верно
}
END_TEST

// Тестируем считывание числа с плавающей точкой
START_TEST(test_s21_sscanf_float) {
  const char *input = "3.1415";
  const char *format = "%f";

  float my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  float expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_double_eq_tol(my_value, expected_value,
                          0.0001);  // Проверяем, что значение равно 3.1415
}
END_TEST

// Тестируем считывание символа
START_TEST(test_s21_sscanf_char) {
  const char *input = "A";
  const char *format = "%c";

  char my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  char expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value,
                   expected_value);  // Проверяем, что считанный символ верен
}
END_TEST

// Тестируем считывание указателя
START_TEST(test_s21_sscanf_pointer) {
  const char *input = "0x7f8c72e1";
  const char *format = "%p";

  void *my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  void *expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_ptr_eq(
      my_value, expected_value);  // Проверяем, что указатель правильно считан
}
END_TEST

// Тестируем неудачное считывание
START_TEST(test_s21_sscanf_fail) {
  const char *input = "Hello";
  const char *format = "%d";

  int my_value = 0;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value = 0;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value,
                   expected_value);  // Проверяем, что считанное значение верно
}
END_TEST

// Тестируем считывание пустой строки
START_TEST(test_s21_sscanf_empty_string) {
  const char *input = "";
  const char *format = "%d";

  int my_value = 0;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value = 0;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что не будет считано значений
  ck_assert_int_eq(my_value,
                   expected_value);  // Проверяем, что значение остается нулевым
}
END_TEST

// Тестируем считывание нескольких значений
START_TEST(test_s21_sscanf_multiple_values) {
  const char *input = "42 3.14 Hello";
  const char *format = "%d %f %s";

  int my_int_value;
  float my_float_value;
  char my_string_value[50];

  int my_result = s21_sscanf(input, format, &my_int_value, &my_float_value,
                             my_string_value);

  int expected_int_value;
  float expected_float_value;
  char expected_string_value[50];

  int expected_result = sscanf(input, format, &expected_int_value,
                               &expected_float_value, expected_string_value);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значения
  ck_assert_int_eq(
      my_int_value,
      expected_int_value);  // Проверяем, что целое число считано правильно
  ck_assert_double_eq_tol(my_float_value, expected_float_value,
                          0.0001);  // Проверяем число с плавающей точкой
  ck_assert_str_eq(my_string_value, expected_string_value);  // Проверяем строку
}
END_TEST

// Тестируем корректное считывание символов после пробела
START_TEST(test_s21_sscanf_whitespace) {
  const char *input = "  123";
  const char *format = "%d";

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

// Тестируем считывание целого числа с шириной
START_TEST(test_s21_sscanf_int_width) {
  const char *input = "12345";
  const char *format = "%5d";  // Ожидаем считать только первые 5 символов

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

// Тестируем считывание строки с ограничением ширины
START_TEST(test_s21_sscanf_string_width) {
  const char *input = "Hello, world!";
  const char *format =
      "%5s";  // Ожидаем считать только первые 5 символов строки

  char my_value[50];
  int my_result = s21_sscanf(input, format, &my_value);

  char expected_value[50];
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_str_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

// Тестируем считывание числа с плавающей точкой в научной записи
START_TEST(test_s21_sscanf_float_scientific) {
  const char *input = "1.23e4";
  const char *format = "%f";  // Число в научной записи

  float my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  float expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_double_eq_tol(my_value, expected_value,
                          0.0001);  // Проверяем, что значение правильно
}
END_TEST

// Тестируем считывание нескольких значений с разными форматами
START_TEST(test_s21_sscanf_multiple_formats) {
  const char *input = "42 Hello 3.14 A";
  const char *format = "%d %s %f %c";

  int my_int;
  char my_string[50];
  float my_float;
  char my_char;

  int my_result =
      s21_sscanf(input, format, &my_int, my_string, &my_float, &my_char);

  int expected_int;
  char expected_string[50];
  float expected_float;
  char expected_char;

  int expected_result = sscanf(input, format, &expected_int, expected_string,
                               &expected_float, &expected_char);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_int, expected_int);  // Проверяем, что значение верно
  ck_assert_str_eq(my_string, expected_string);  // Проверяем строку
  ck_assert_double_eq_tol(my_float, expected_float,
                          0.0001);  // Проверяем значение с плавающей точкой
  ck_assert_int_eq(my_char, expected_char);  // Проверяем символ
}
END_TEST

// Тестируем считывание строки с пробелами
START_TEST(test_s21_sscanf_string_with_spaces) {
  const char *input = "Hello world!";
  const char *format = "%s";  // Ожидаем считать первое слово

  char my_value[50];
  int my_result = s21_sscanf(input, format, &my_value);

  char expected_value[50];
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_str_eq(my_value,
                   expected_value);  // Проверяем, что считанное значение верно
}
END_TEST

// Тестируем считывание знака '%' (специальный символ)
START_TEST(test_s21_sscanf_percent_sign) {
  const char *input = "% 10";
  const char *format = "%% %d";  // Ожидаем считать сам символ %

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что символ верен
}
END_TEST

// Тестируем считывание целого числа, но не достаточно символов
START_TEST(test_s21_sscanf_int_not_enough_chars) {
  const char *input = "12";
  const char *format = "%10d";  // Ожидаем считать одно целое число

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

// Тестируем считывание целого числа, но не на вход подается дробное
START_TEST(test_s21_sscanf_int_with_float_input) {
  const char *input = "12.1";
  const char *format = "%d";  // Ожидаем считать одно целое число

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_with_different_count_1) {
  const char *input = "12";
  const char *format = "%d %d";  // Ожидаем считать одно целое число

  int my_value_1;
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  int expected_value_1;
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

// Тестируем считывание целого числа, но не на вход подается дробное
START_TEST(test_s21_sscanf_with_different_count_2) {
  const char *input = "12 12";
  const char *format = "%d";  // Ожидаем считать одно целое число

  int my_value;
  int my_result = s21_sscanf(input, format, &my_value);

  int expected_value;
  int expected_result = sscanf(input, format, &expected_value);

  ck_assert_int_eq(
      my_result, expected_result);  // Ожидаем, что будет считано одно значение
  ck_assert_int_eq(my_value, expected_value);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_convert_types) {
  const char *input = "12.1 12.1";
  const char *format = "%d %d";  // Ожидаем считать два целых числа

  int my_value_1;
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  int expected_value_1;
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_int) {
  const char *input = "12 12";
  const char *format = "%u %u";  // Ожидаем считать два целых числа

  int my_value_1 = 0;
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  int expected_value_1 = 0;
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_int_float) {
  const char *input = "12 12.1";
  const char *format = "%u %u";  // Ожидаем считать два целых числа

  int my_value_1 = 0;
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  int expected_value_1 = 0;
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_int_int) {
  const char *input = "12 12.1";
  const char *format = "%hu %d";  // Ожидаем считать два целых числа

  int my_value_1 = 0;
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  int expected_value_1 = 0;
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_float_int) {
  const char *input = "12.1 12.1";
  const char *format = "%lu %d";  // Ожидаем считать два целых числа

  long my_value_1 = 0;
  long my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  long expected_value_1 = 0;
  long expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_string) {
  const char *input = "12 hello";
  const char *format =
      "%u %s";  // Ожидаем считать положительное целое число и строку

  int my_value_1 = 0;
  char my_value_2[50];
  int my_result = s21_sscanf(input, format, &my_value_1, my_value_2);

  int expected_value_1 = 0;
  char expected_value_2[50];
  int expected_result =
      sscanf(input, format, &expected_value_1, expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_str_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_unsigned_string_int) {
  const char *input = "hello 12";
  const char *format = "%s %u";  // Ожидаем считать строку и целое число

  char my_value_1[50];
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, my_value_1, &my_value_2);

  char expected_value_1[50];
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_str_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_float_string) {
  const char *input = "123.1 hello";
  const char *format = "%f %s";  // Ожидаем считать вещественное число и строку

  float my_value_1 = 0;
  char my_value_2[50];
  int my_result = s21_sscanf(input, format, &my_value_1, my_value_2);

  float expected_value_1 = 0;
  char expected_value_2[50];
  int expected_result =
      sscanf(input, format, &expected_value_1, expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_str_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_string_float) {
  const char *input = "hello 123.1";
  const char *format = "%s %f";  // Ожидаем считать строку и вещественное число

  char my_value_1[50];
  float my_value_2 = 0;
  int my_result = s21_sscanf(input, format, my_value_1, &my_value_2);

  char expected_value_1[50];
  float expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_str_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_float_float) {
  const char *input = "123.1 123.1";
  const char *format = "%f %f";  // Ожидаем считать два вещественных числа

  float my_value_1 = 0;
  float my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  float expected_value_1 = 0;
  float expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_float_char) {
  const char *input = "123.1 A";
  const char *format = "%f %c";  // Ожидаем считать вещественное число и символ

  float my_value_1 = 0;
  char my_value_2;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  float expected_value_1 = 0;
  char expected_value_2;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_char_float) {
  const char *input = "A 123.1";
  const char *format = "%c %f";  // Ожидаем считать символ и вещественное число

  char my_value_1;
  float my_value_2 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1, &my_value_2);

  char expected_value_1;
  float expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, &expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано два значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_char_float_int) {
  const char *input = "A 123.1 42";
  const char *format =
      "%c %f %d";  // Ожидаем считать символ, вещественное и целое число

  char my_value_1;
  float my_value_2 = 0;
  int my_value_3 = 0;
  int my_result =
      s21_sscanf(input, format, &my_value_1, &my_value_2, &my_value_3);

  char expected_value_1;
  float expected_value_2 = 0;
  int expected_value_3 = 0;
  int expected_result = sscanf(input, format, &expected_value_1,
                               &expected_value_2, &expected_value_3);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_3,
                   expected_value_3);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_string_n) {
  const char *input = "Hello guys";
  const char *format = "%s %n";  // Ожидаем считать строку и кол-во символов

  char my_value_1[50];
  int my_value_2 = 0;
  int my_result = s21_sscanf(input, format, my_value_1, &my_value_2);

  char expected_value_1[50];
  int expected_value_2 = 0;
  int expected_result =
      sscanf(input, format, expected_value_1, &expected_value_2);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_str_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
  ck_assert_int_eq(my_value_2,
                   expected_value_2);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_i) {
  const char *input = "123456";
  const char *format = "%i";  // Ожидаем считать строку и кол-во символов

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_e) {
  const char *input = "12e-5";
  const char *format = "%e";  // Ожидаем считать строку и кол-во символов

  float my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  float expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_double_eq_tol(my_value_1, expected_value_1,
                          0.0001);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_g) {
  const char *input = "12e-5";
  const char *format = "%g";  // Ожидаем считать строку и кол-во символов

  float my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  float expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_double_eq_tol(my_value_1, expected_value_1,
                          0.0001);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_o) {
  const char *input = "077";
  const char *format = "%o";  // Ожидаем считать строку и кол-во символов

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_x) {
  const char *input = "0x1F";
  const char *format = "%x";  // Ожидаем считать строку и кол-во символов

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result,
                   expected_result);  // Ожидаем, что будет считано три значение
  ck_assert_int_eq(my_value_1,
                   expected_value_1);  // Проверяем, что значение верно
}
END_TEST

START_TEST(test_s21_sscanf_string_width_1) {
  const char *input = "hello";
  const char *format = "%3s";

  char my_value_1[50];
  int my_result = s21_sscanf(input, format, my_value_1);

  char expected_value_1[50];
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_str_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_int_width_1) {
  const char *input = "123456";
  const char *format = "%3d";

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_int_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_int_h) {
  const char *input = "123456";
  const char *format = "%hd";

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_int_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_int_l) {
  const char *input = "12345678987654321";
  const char *format = "%ld";

  long int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  long int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_int_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_float_L) {
  const char *input = "123456.123456789";
  const char *format = "%Lf";

  long double my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  long double expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_double_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_int_h_width) {
  const char *input = "123456";
  const char *format = "%3hd";

  int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_int_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_int_l_width) {
  const char *input = "12345678987654321";
  const char *format = "%7ld";

  long int my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  long int expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_int_eq(my_value_1, expected_value_1);
}
END_TEST

START_TEST(test_s21_sscanf_float_L_width) {
  const char *input = "123456.123456789";
  const char *format = "%8Lf";

  long double my_value_1 = 0;
  int my_result = s21_sscanf(input, format, &my_value_1);

  long double expected_value_1 = 0;
  int expected_result = sscanf(input, format, &expected_value_1);

  ck_assert_int_eq(my_result, expected_result);
  ck_assert_double_eq(my_value_1, expected_value_1);
}
END_TEST

// Собираем все тесты в один набор
Suite *s21_Sscanf_Suite(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sscanf_int);
  tcase_add_test(tc_core, test_s21_sscanf_string);
  tcase_add_test(tc_core, test_s21_sscanf_float);
  tcase_add_test(tc_core, test_s21_sscanf_char);
  tcase_add_test(tc_core, test_s21_sscanf_pointer);
  tcase_add_test(tc_core, test_s21_sscanf_fail);
  tcase_add_test(tc_core, test_s21_sscanf_empty_string);
  tcase_add_test(tc_core, test_s21_sscanf_multiple_values);
  tcase_add_test(tc_core, test_s21_sscanf_whitespace);
  tcase_add_test(tc_core, test_s21_sscanf_int_width);  // Новый тест для ширины
  tcase_add_test(
      tc_core,
      test_s21_sscanf_string_width);  // Новый тест для строки с шириной
  tcase_add_test(
      tc_core,
      test_s21_sscanf_float_scientific);  // Новый тест для научной записи
  tcase_add_test(
      tc_core,
      test_s21_sscanf_multiple_formats);  // Новый тест для нескольких форматов
  tcase_add_test(
      tc_core,
      test_s21_sscanf_string_with_spaces);  // Новый тест для строки с пробелами
  tcase_add_test(tc_core,
                 test_s21_sscanf_percent_sign);  // Новый тест для процента
  tcase_add_test(
      tc_core,
      test_s21_sscanf_int_not_enough_chars);  // Новый тест для
                                              // недостаточно символов
  tcase_add_test(
      tc_core, test_s21_sscanf_int_with_float_input);  // Новый тест для целого
                                                       // числа с дробным входом
  tcase_add_test(
      tc_core,
      test_s21_sscanf_with_different_count_1);  // Новый тест для разного
                                                // количества значений
  tcase_add_test(
      tc_core,
      test_s21_sscanf_with_different_count_2);  // Новый тест для разного
                                                // количества значений
  tcase_add_test(tc_core,
                 test_s21_sscanf_convert_types);  // Новый тест для конвертации
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_int);
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_int_float);
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_int_int);
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_float_int);
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_string);
  tcase_add_test(tc_core, test_s21_sscanf_unsigned_string_int);
  tcase_add_test(tc_core, test_s21_sscanf_float_string);
  tcase_add_test(tc_core, test_s21_sscanf_string_float);
  tcase_add_test(tc_core, test_s21_sscanf_float_float);
  tcase_add_test(tc_core, test_s21_sscanf_float_char);
  tcase_add_test(tc_core, test_s21_sscanf_char_float);
  tcase_add_test(tc_core, test_s21_sscanf_char_float_int);
  tcase_add_test(tc_core, test_s21_sscanf_string_n);
  tcase_add_test(tc_core, test_s21_sscanf_i);
  tcase_add_test(tc_core, test_s21_sscanf_e);
  tcase_add_test(tc_core, test_s21_sscanf_g);
  tcase_add_test(tc_core, test_s21_sscanf_o);
  tcase_add_test(tc_core, test_s21_sscanf_x);
  tcase_add_test(tc_core, test_s21_sscanf_string_width_1);
  tcase_add_test(tc_core, test_s21_sscanf_int_width_1);
  tcase_add_test(tc_core, test_s21_sscanf_int_h);
  tcase_add_test(tc_core, test_s21_sscanf_int_l);
  tcase_add_test(tc_core, test_s21_sscanf_float_L);
  tcase_add_test(tc_core, test_s21_sscanf_int_h_width);
  tcase_add_test(tc_core, test_s21_sscanf_int_l_width);
  tcase_add_test(tc_core, test_s21_sscanf_float_L_width);
  // Добавляем все тесты в набор

  suite_add_tcase(s, tc_core);
  return s;
}