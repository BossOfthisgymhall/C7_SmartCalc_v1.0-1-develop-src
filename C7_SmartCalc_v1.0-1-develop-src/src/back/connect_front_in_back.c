#include "../s21_smart_calc.h"

double connect_front_in_back(char* string, double* result, double x) {
  stack_node* snp = {0};
  stack_node* output = NULL;
  int err_flag = OK;
  if (string != NULL) {
    err_flag = s21_parser(&snp, string, x);
    if (err_flag == ERROR) return ERROR;
    err_flag = s21_rpn_processing(&snp, &output);
    if (err_flag == ERROR) return ERROR;
    err_flag = s21_arithmetic(&output, result);
    if (err_flag == ERROR) return ERROR;
  } else {
    return ERROR;
  }
  return err_flag;
}