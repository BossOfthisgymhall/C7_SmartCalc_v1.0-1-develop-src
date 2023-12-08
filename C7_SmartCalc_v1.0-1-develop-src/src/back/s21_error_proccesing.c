#include "../s21_smart_calc.h"

int s21_error_proccesing(char* string) {
  int dot_use = 0, status = 0, prev_status = 0;
  if (string == NULL) return ERROR;
  if (s21_split_func(string) == ERROR) return ERROR;
  while (*string != '\0') {
    if (isdigit(*string)) {
      while (isdigit(*string) || *string == '.') {
        status = NUM;
        dot_use = s21_dot_use_error(string, dot_use);
        if (dot_use == ERROR) return ERROR;
        string += 1;
      }
      dot_use = 0;
    } else {
      while (!isdigit(*string) && *string != '\0') {
        int word_lenth = 1;
        int type = s21_find_true_operator(string, &word_lenth);
        if (type == ERROR) return ERROR;
        prev_status = status;
        if (word_lenth > 1 && type != MOD) {
          status = TRIG;
        } else if (type == NUM) {
          status = NUM;
        } else {
          status = (type == OP_BRAC)
                       ? OP_BRAC
                       : ((type == CLOSE_BRAC) ? CLOSE_BRAC : OPERATOR);
        }
        if (((status == OPERATOR && prev_status == OPERATOR)) ||
            (status == TRIG && prev_status == TRIG))
          return ERROR;
        if (type == OP_BRAC &&
            (string[word_lenth] == '*' || string[word_lenth] == '/' ||
             string[word_lenth] == 'm' || string[word_lenth] == '^')) {
          return ERROR;
        }
        if (type == CLOSE_BRAC && prev_status == OPERATOR) return ERROR;
        if (prev_status == NUM && status == TRIG) return ERROR;
        if (prev_status == CLOSE_BRAC && status == TRIG) return ERROR;
        if (status == OP_BRAC && prev_status == NUM) return ERROR;
        if (status == NUM && prev_status == NUM) return ERROR;
        string += word_lenth;
      }
    }
  }
  return OK;
}

int s21_dot_use_error(char* string, int dot_use) {
  if (*string == '.') {
    if (dot_use) {
      return ERROR;
    } else {
      dot_use++;
    }
    string++;
    if (!isdigit(*string)) {
      return ERROR;
    }
  }
  return dot_use;
}

int s21_bracket_controller(const char* string) {
  int open_brackets = 0, close_brackets = 0, start_flag = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '(') {
      open_brackets++;
      start_flag = 1;
      if (string[i + 1] == ')') return ERROR;
    } else if (string[i] == ')') {
      close_brackets++;
      if (string[i + 1] == '(' || start_flag == 0) return ERROR;
      start_flag = 2;
    }
  }
  if (start_flag == 1) return ERROR;
  if (open_brackets != close_brackets) return ERROR;
  return OK;
}
int s21_type_proccesing(char* string) {
  int len = 0;
  int err_flag = OK;
  if (string != NULL) {
    len = strlen(string);
    if (len > 0) {
      if (string[0] == '*' || string[0] == '/' || string[0] == '^' ||
          string[0] == ')' || string[0] == 'm') {
        err_flag = ERROR;
      }
      if (string[len - 1] == '*' || string[len - 1] == '/' ||
          string[len - 1] == '+' || string[len - 1] == '-' ||
          string[len - 1] == '(' || string[len - 1] == '^' ||
          string[len - 1] == 'd') {
        err_flag = ERROR;
      }
    }
  }
  return err_flag;
}

int s21_trig_controller(char* string) {
  int prev_status = OK, status = OK;
  while (*string != '\0') {
    int word_lenth = 1;
    prev_status = status;
    int type = s21_find_true_operator(string, &word_lenth);
    if (word_lenth > 1 && type != MOD) {
      status = TRIG;
    } else {
      status = OK;
    }
    if (prev_status == TRIG && type != OP_BRAC) {
      return ERROR;
    }
    string += word_lenth;
  }
  return OK;
}

int s21_pow_controller(const char* string) {
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    if (string[i] == '^' && (i + 1 < len) && string[i + 1] != '(') {
      return ERROR;
    }
  }
  return OK;
}

int s21_split_func(char* string) {
  int len = strlen(string);
  int bracket = OK;
  if (len > 255 || len == 0) return ERROR;
  bracket = s21_bracket_controller(string);
  if (bracket == ERROR) return ERROR;
  if (s21_trig_controller(string) == ERROR) return ERROR;
  if (s21_type_proccesing(string) == ERROR) return ERROR;
  if (s21_pow_controller(string) == ERROR) return ERROR;
  return OK;
}