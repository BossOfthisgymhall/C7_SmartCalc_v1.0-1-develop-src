#include "test.h"

START_TEST(WHOLE_VALID_0) {
  int error = OK;
  char mass[SIZE] = "11-";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_1) {
  int error = OK;
  char mass[SIZE] = "(--1+1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_2) {
  int error = OK;
  char mass[SIZE] = "1-1+9*((-1)+(-cos(1-0.5)))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_3) {
  int error = OK;
  char mass[SIZE] = "1--1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_4) {
  int error = OK;
  char mass[SIZE] = "1-1-";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_5) {
  int error = OK;
  char mass[SIZE] = "(-11)-+";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_6) {
  int error = OK;
  char mass[SIZE] = "(11)/(cos(7+))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_7) {
  int error = OK;
  char mass[SIZE] = "11^2-";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_8) {
  int error = OK;
  char mass[SIZE] = "11^^2";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_9) {
  int error = OK;
  char mass[SIZE] = "11^(^2)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_10) {
  int error = OK;
  char mass[SIZE] = "11^(-^2)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_11) {
  int error = OK;
  char mass[SIZE] = "11^(2mod)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_12) {
  int error = OK;
  char mass[SIZE] = "1mod(-1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(OK, error);
}
END_TEST

START_TEST(WHOLE_VALID_13) {
  int error = OK;
  char mass[SIZE] = "cos(1)cos(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_14) {
  int error = OK;
  char mass[SIZE] = "1mod2mod";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_15) {
  int error = OK;
  char mass[SIZE] = "cos(1)+cos(1)modtan(1)-acos(-1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_16) {
  int error = OK;
  char mass[SIZE] = "1-1+9(-1+(-cos(1-)))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_17) {
  int error = OK;
  char mass[SIZE] = "1^(-1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(OK, error);
}
END_TEST

START_TEST(WHOLE_VALID_18) {
  int error = OK;
  char mass[SIZE] = "1-mod2mod";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_19) {
  int error = OK;
  char mass[SIZE] = "-(-1)+tan(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(OK, error);
}
END_TEST

START_TEST(WHOLE_VALID_20) {
  int error = OK;
  char mass[SIZE] = "5000.0000-(-1)+tan(1)^(2)/(-2)*1+398mod3mod2";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_21) {
  int error = OK;
  char mass[SIZE] = "cos(1)^(sqrt(1))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_22) {
  int error = OK;
  char mass[SIZE] = "acos(1)ln(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_23) {
  int error = OK;
  char mass[SIZE] = "acos(1)modln(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_24) {
  int error = OK;
  char mass[SIZE] = "398mod3mod2mod";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_25) {
  int error = OK;
  char mass[SIZE] = "mod";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_26) {
  int error = OK;
  char mass[SIZE] = "cos(1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_27) {
  int error = OK;
  char mass[SIZE] = "cos(3)mod1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_28) {
  int error = OK;
  char mass[SIZE] = "";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_29) {
  int error = OK;
  char mass[SIZE] = "cos(3)mod(-1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

// validation ALL

START_TEST(WHOLE_VALID_30) {
  int error = OK;
  char mass[SIZE] = "sin(1)-(-2*x)/x-(-1)mod(x^(-2))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_33) {
  int error = OK;
  char mass[SIZE] = "x^(-1)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_34) {
  int error = OK;
  char mass[SIZE] = "(-3.00009mod2modx)^(xmodacos(x))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_35) {
  int error = OK;
  char mass[SIZE] = "9*x";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_36) {
  int error = OK;
  char mass[SIZE] = "x^(x)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_37) {
  int error = OK;
  char mass[SIZE] = "x^(xmodx)*(-2)modx";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_38) {
  int error = OK;
  char mass[SIZE] = "asin(1)^(xmodx)*(-2)modx";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_39) {
  int error = OK;
  char mass[SIZE] = "atan(1)^(log(2))modx-ln(10)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_40) {
  int error = OK;
  char mass[SIZE] = "sin(cos(tan(x)))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_41) {
  int error = OK;
  char mass[SIZE] = "4(4)-(5)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_42) {
  int error = OK;
  char mass[SIZE] = "(x^(2))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_43) {
  int error = OK;
  char mass[SIZE] = "(x)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(WHOLE_VALID_44) {
  int error = OK;
  char mass[SIZE] = "(-x^(2))";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

// 256 symbos
START_TEST(WHOLE_VALID_45) {
  int error = OK;
  char mass[SIZE * 2] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "1111111111111111111111111111111111111111";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_46) {
  int error = OK;
  char mass[SIZE] = "2^2";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_47) {
  int error = OK;
  char mass[SIZE] = "cos1";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

START_TEST(WHOLE_VALID_48) {
  int error = OK;
  char mass[SIZE] = "(/)";
  error = s21_error_proccesing(mass);
  ck_assert_int_eq(ERROR, error);
}
END_TEST

Suite *Whole_validation(void) {
  Suite *s = suite_create("\033[45m-=WHOLE VALIDATION=-\033[0m");
  TCase *tc1_1 = tcase_create("WHOLE VALIDATION: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, WHOLE_VALID_0);
  tcase_add_test(tc1_1, WHOLE_VALID_1);
  tcase_add_test(tc1_1, WHOLE_VALID_2);
  tcase_add_test(tc1_1, WHOLE_VALID_3);
  tcase_add_test(tc1_1, WHOLE_VALID_4);
  tcase_add_test(tc1_1, WHOLE_VALID_5);
  tcase_add_test(tc1_1, WHOLE_VALID_6);
  tcase_add_test(tc1_1, WHOLE_VALID_7);
  tcase_add_test(tc1_1, WHOLE_VALID_8);
  tcase_add_test(tc1_1, WHOLE_VALID_9);
  tcase_add_test(tc1_1, WHOLE_VALID_10);
  tcase_add_test(tc1_1, WHOLE_VALID_11);
  tcase_add_test(tc1_1, WHOLE_VALID_12);
  tcase_add_test(tc1_1, WHOLE_VALID_13);
  tcase_add_test(tc1_1, WHOLE_VALID_14);
  tcase_add_test(tc1_1, WHOLE_VALID_15);
  tcase_add_test(tc1_1, WHOLE_VALID_16);
  tcase_add_test(tc1_1, WHOLE_VALID_17);
  tcase_add_test(tc1_1, WHOLE_VALID_18);
  tcase_add_test(tc1_1, WHOLE_VALID_19);
  tcase_add_test(tc1_1, WHOLE_VALID_20);
  tcase_add_test(tc1_1, WHOLE_VALID_21);
  tcase_add_test(tc1_1, WHOLE_VALID_22);
  tcase_add_test(tc1_1, WHOLE_VALID_23);
  tcase_add_test(tc1_1, WHOLE_VALID_24);
  tcase_add_test(tc1_1, WHOLE_VALID_25);
  tcase_add_test(tc1_1, WHOLE_VALID_26);
  tcase_add_test(tc1_1, WHOLE_VALID_27);
  tcase_add_test(tc1_1, WHOLE_VALID_28);
  tcase_add_test(tc1_1, WHOLE_VALID_29);
  tcase_add_test(tc1_1, WHOLE_VALID_30);
  tcase_add_test(tc1_1, WHOLE_VALID_33);
  tcase_add_test(tc1_1, WHOLE_VALID_34);
  tcase_add_test(tc1_1, WHOLE_VALID_35);
  tcase_add_test(tc1_1, WHOLE_VALID_36);
  tcase_add_test(tc1_1, WHOLE_VALID_37);
  tcase_add_test(tc1_1, WHOLE_VALID_38);
  tcase_add_test(tc1_1, WHOLE_VALID_39);
  tcase_add_test(tc1_1, WHOLE_VALID_40);
  tcase_add_test(tc1_1, WHOLE_VALID_41);
  tcase_add_test(tc1_1, WHOLE_VALID_42);
  tcase_add_test(tc1_1, WHOLE_VALID_43);
  tcase_add_test(tc1_1, WHOLE_VALID_44);
  tcase_add_test(tc1_1, WHOLE_VALID_45);
  tcase_add_test(tc1_1, WHOLE_VALID_46);
  tcase_add_test(tc1_1, WHOLE_VALID_47);
  tcase_add_test(tc1_1, WHOLE_VALID_48);

  return s;
}