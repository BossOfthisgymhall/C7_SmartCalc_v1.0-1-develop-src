#include "test.h"

START_TEST(GENERAL_TEST_0) {
  int error = 0;
  double result = 0, exp_result = -36.0200007, x_value = 0;
  char string[SIZE] = "13.01-1.09-6.0-((0.0000001*7)+6*(9-2.01))";

  error = connect_front_in_back(string, &result, x_value);

  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_1) {
  int error = 0;
  double exp_result = -4.99621328606, result = 0, x_value = 0;

  char string[SIZE] = "(-((0.0000001*7)+6*(9-2.01)/8.4+(0.32^(5))))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_2) {
  int error = 0;
  double exp_result = -744.5, result = 0, x_value = 0;

  char string[SIZE] = "77mod4-((3*(3^(6)))-700)/24*12-2";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_3) {
  int error = 0;
  double exp_result = -52917.0091791, result = 0, x_value = 0;

  char string[SIZE] = "(-569.0000987)*(99-6)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_4) {
  int error = 0;
  double exp_result = 63.52687747, result = 0, x_value = 0;

  char string[SIZE] = "88+(2^(2))*(-569.0000987)/(99-6)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_5) {
  int error = 0;
  double exp_result = -7.0370370, result = 0, x_value = 0;

  char string[SIZE] = "(-7.0)+(-3^(-3))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_6) {
  int error = 0;
  double exp_result = -3.8376598, result = 0, x_value = 0;

  char string[SIZE] =
      "(-cos(3))-(-cos(1))+4/2-(sin(1))*6.09/(-tan(2)/acos(-1))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_7) {
  int error = 0;
  double exp_result = -6794.53374717, result = 0, x_value = 0;

  char string[SIZE] =
      "(-6696.0009867)+1/4/2/1.3*5.0009+(-56)+(-sqrt(9.9))-99"
      "+1.4^(-6)-5+8^(2)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_8) {
  int error = 0;
  double exp_result = 3.5759962, result = 0, x_value = 0;

  char string[SIZE] =
      "(-cos(3))-(-cos(1))+4/2-(sin(1))+1^(2.0000007)*6.09/"
      "(-tan(2))/acos(-1)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_9) {
  int error = 0;
  double exp_result = -4.9, result = 0, x_value = 0;

  char string[SIZE] = "(-1)+(-1)+(-1)-1.9-(-1)-1";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_10) {
  int error = 0;
  double exp_result = 0.6663667, result = 0, x_value = 0;

  char string[SIZE] = "cos(sin(1))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_11) {
  int error = OK;
  double exp_result = 4096, result = 0, x_value = 0;

  char string[SIZE] = "8^(2^(2))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_12) {
  int error = 0;
  double exp_result = 8, result = 0, x_value = 0;

  char string[SIZE] = "((+8-(-9))-(+9))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-07);
}
END_TEST

START_TEST(GENERAL_TEST_13) {
  int error = 0;
  double exp_result = -1, result = 0, x_value = 0;

  char string[SIZE] = "(+8-9)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_14) {
  int error = 0;
  double exp_result = -13.0700007, result = 0, x_value = 0;

  char string[SIZE] =
      "3*(8.0987/8.0987)-65.02+13.01-6.0-(0.0000001*7)+6*(9"
      "-2.01)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_15) {
  int error = 0;
  double exp_result = 4, result = 0, x_value = 0;

  char string[SIZE] = "(-2)^(2)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_16) {
  int error = 0;
  double exp_result = -4, result = 0, x_value = 0;

  char string[SIZE] = "(-2)-2";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_17) {  // asin
  int error = 0;
  double exp_result = (asin(0.5) * atan(0.75)), result = 0, x_value = 0;

  char string[SIZE] = "(asin(0.5)*atan(0.75))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_18) {  // asin + log
  int error = 0;
  double exp_result = (-log10(45) + asin(0.5)), result = 0, x_value = 0;

  char string[SIZE] = "(-log(45)+asin(0.5))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_19) {  // asin + ln
  int error = 0;
  double exp_result = (-log(15) + asin(0.5)), result = 0, x_value = 0;

  char string[SIZE] = "(-ln(15)+asin(0.5))";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

START_TEST(GENERAL_TEST_20) {  // asin + ln
  int error = 0;
  double exp_result =
             (9132165498651321654984621321654984651321684984351.21654 / 2),
         result = 0, x_value = 0;

  char string[SIZE] =
      "(9132165498651321654984621321654984651321684984351.21654/2)";

  error = connect_front_in_back(string, &result, x_value);
  ck_assert_int_eq(OK, error);
  ck_assert_double_eq_tol(result, exp_result, 1e-7);
}
END_TEST

Suite *General_test(void) {
  Suite *s = suite_create("\033[45m-=GENERAL TEST=-\033[0m");
  TCase *tc1_1 = tcase_create("Gengeral test: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, GENERAL_TEST_0);
  tcase_add_test(tc1_1, GENERAL_TEST_1);
  tcase_add_test(tc1_1, GENERAL_TEST_2);
  tcase_add_test(tc1_1, GENERAL_TEST_3);
  tcase_add_test(tc1_1, GENERAL_TEST_4);
  tcase_add_test(tc1_1, GENERAL_TEST_5);
  tcase_add_test(tc1_1, GENERAL_TEST_6);
  tcase_add_test(tc1_1, GENERAL_TEST_7);
  tcase_add_test(tc1_1, GENERAL_TEST_8);
  tcase_add_test(tc1_1, GENERAL_TEST_9);
  tcase_add_test(tc1_1, GENERAL_TEST_10);
  tcase_add_test(tc1_1, GENERAL_TEST_11);
  tcase_add_test(tc1_1, GENERAL_TEST_12);
  tcase_add_test(tc1_1, GENERAL_TEST_13);
  tcase_add_test(tc1_1, GENERAL_TEST_14);
  tcase_add_test(tc1_1, GENERAL_TEST_15);
  tcase_add_test(tc1_1, GENERAL_TEST_16);
  tcase_add_test(tc1_1, GENERAL_TEST_17);
  tcase_add_test(tc1_1, GENERAL_TEST_18);
  tcase_add_test(tc1_1, GENERAL_TEST_19);
  tcase_add_test(tc1_1, GENERAL_TEST_20);

  return s;
}
