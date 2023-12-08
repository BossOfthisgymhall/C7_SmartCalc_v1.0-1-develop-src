#include "../s21_smart_calc.h"

double s21_arithmetic(stack_node** snp, double* result) {
  stack_node* num = {0};
  double number1 = 0, number2 = 0;
  int operat = 0, err_flag = OK;
  while ((*snp) != NULL) {
    if ((*snp)->type == NUMBER) {
      s21_push(&num, (*snp)->number, NUMBER, 0);
      s21_pop(snp);
    } else if ((*snp)->type != NUMBER && s21_count(num) > 0) {
      operat = (*snp)->type;
      s21_pop(snp);
      if (operat == UN_SUB) {
        *result = pick_number(&num);
        *result *= -1;
        s21_push(&num, *result, NUMBER, 0);
        operat = 0;
      } else if (operat == UN_ADD) {
        *result = pick_number(&num);
        *result *= 1;
        s21_push(&num, *result, NUMBER, 0);
        operat = 0;
      } else {
        if (type_check(operat) == TRIG) {
          err_flag = perfom_trig(number1, operat, &num, result);
          operat = 0;
        } else {
          err_flag = perform_operation(number1, number2, operat, &num, result);
          operat = 0;
        }
      }
    }
  }
  int count = s21_count(num);
  if (count == 1) {
    *result = pick_number(&num);
  }
  return err_flag;
}

double perform_operation(double op1, double op2, double operat,
                         stack_node** num, double* result) {
  int count = 0, err_flag = OK;
  count = s21_count(*num);
  if (count == 1) {
    *result = pick_number(num);
    if (operat == UN_SUB) {
      *result *= -1;
    }
  } else if (count >= 2) {
    if (num != NULL) {
      op2 = pick_number(num);
      op1 = pick_number(num);
    }
    if (operat == ADD) {
      *result = op1 + op2;
    } else if (operat == SUB) {
      *result = op1 - op2;
    } else if (operat == MULT) {
      *result = op1 * op2;
    } else if (operat == DIV) {
      if (op2 == 0) {
        return ERROR;
      }
      *result = op1 / op2;
    } else if (operat == POW) {
      *result = powf((double)op1, (double)op2);
    } else if (operat == MOD) {
      if (op2 == 0) {
        return ERROR;
      }
      *result = fmod(op1, op2);
    }
  }
  s21_push(num, *result, NUMBER, 0);
  return err_flag;
}

double pick_number(stack_node** num) {
  double number = 0;
  number = (*num)->number;
  s21_pop(num);
  return number;
}

double perfom_trig(double op1, double operat, stack_node** num,
                   double* result) {
  op1 = pick_number(num);
  int err_flag = OK;
  if (operat == SQRT) {
    *result = sqrt(op1);
  } else if (operat == COS) {
    *result = cos(op1);
  } else if (operat == SIN) {
    *result = sin(op1);
  } else if (operat == TAN) {
    *result = tan(op1);
  } else if (operat == ACOS) {
    *result = acos(op1);
  } else if (operat == ASIN) {
    *result = asin(op1);
  } else if (operat == ATAN) {
    *result = atan(op1);
  } else if (operat == LN) {
    *result = log(op1);
  } else if (operat == LOG) {
    *result = log10(op1);
  }
  s21_push(num, *result, NUMBER, 0);
  return err_flag;
}

double type_check(double operat) {
  int type = OK;
  if (operat == COS || operat == SQRT || operat == SIN || operat == TAN ||
      operat == ACOS || operat == ASIN || operat == ATAN || operat == LN ||
      operat == LOG) {
    type = TRIG;
  }
  return type;
}
