#include "test.h"

START_TEST(DOT_VALID_0) {
  int error = OK;
  char mass[SIZE] = "1.1-.1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_1) {
  int error = OK;
  char mass[SIZE] = "1.1-1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(OK, error);
}
END_TEST

START_TEST(DOT_VALID_2) {
  int error = OK;
  char mass[SIZE] = "11.- 1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_3) {
  int error = OK;
  char mass[SIZE] = "11-1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(DOT_VALID_4) {
  int error = OK;
  char mass[SIZE] = "11-.11";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_5) {
  int error = OK;
  char mass[SIZE] = "1.1-11.";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_6) {
  int error = OK;
  char mass[SIZE] = "1.1-11";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(DOT_VALID_7) {
  int error = OK;
  char mass[SIZE] = "1..1-11";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_8) {
  int error = OK;
  char mass[SIZE] = "1.1.-1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_9) {
  int error = OK;
  char mass[SIZE] = "11.-1.1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_10) {
  int error = OK;
  char mass[SIZE] = ".11-11";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_11) {
  int error = OK;
  char mass[SIZE] = ".cos(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_12) {
  int error = OK;
  char mass[SIZE] = "acos(1.)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_13) {
  int error = OK;
  char mass[SIZE] = "acos(1.1.)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_14) {
  int error = OK;
  char mass[SIZE] = "acos(1.1-3.3-.)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(DOT_VALID_15) {
  int error = OK;
  char mass[SIZE] = "";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

Suite *Dot_validation(void) {
  Suite *s = suite_create("\033[45m-=DOT VALIDATION=-\033[0m");
  TCase *tc1_1 = tcase_create("SmartCalc validation: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, DOT_VALID_0);
  tcase_add_test(tc1_1, DOT_VALID_1);
  tcase_add_test(tc1_1, DOT_VALID_2);
  tcase_add_test(tc1_1, DOT_VALID_3);
  tcase_add_test(tc1_1, DOT_VALID_4);
  tcase_add_test(tc1_1, DOT_VALID_5);
  tcase_add_test(tc1_1, DOT_VALID_6);
  tcase_add_test(tc1_1, DOT_VALID_7);
  tcase_add_test(tc1_1, DOT_VALID_8);
  tcase_add_test(tc1_1, DOT_VALID_9);
  tcase_add_test(tc1_1, DOT_VALID_10);
  tcase_add_test(tc1_1, DOT_VALID_11);
  tcase_add_test(tc1_1, DOT_VALID_12);
  tcase_add_test(tc1_1, DOT_VALID_13);
  tcase_add_test(tc1_1, DOT_VALID_14);
  tcase_add_test(tc1_1, DOT_VALID_15);

  return s;
}