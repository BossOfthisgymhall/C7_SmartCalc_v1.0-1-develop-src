#include "../s21_smart_calc.h"

int s21_parser(stack_node** stack_node_ptr, char* string, double x) {
  int step = 0;
  if (s21_error_proccesing(string) == ERROR) return ERROR;
  analyze_expression(string);
  while (*string != '\0') {
    if (isdigit(*string) || *string == 'x') {
      step = s21_parser_digit(stack_node_ptr, string, x);
    }
    if (strchr("+-up*/^()", *string)) {
      step = s21_parser_operators(stack_node_ptr, string);
    }
    if (strchr("asctlm", *string)) {
      step = s21_trigonometry_parser(stack_node_ptr, string);
    }
    string += step;
  }
  return OK;
}

int s21_parser_digit(stack_node** stack_node_ptr, char* string, double x) {
  char numbers[SIZE] = {0};
  int i = 0;
  double value = 0;
  if (*string == 'x') {
    s21_push(stack_node_ptr, x, NUMBER, 0);
    i++;
  } else {
    while (isdigit(*string) || *string == '.') {
      numbers[i] = *string;
      i++;
      string += 1;
    }
    value = strtod(numbers, NULL);
    s21_push(stack_node_ptr, value, NUMBER, 0);
  }
  return i;
}

int s21_parser_operators(stack_node** stack_node_ptr, char* string) {
  int word_lenth = 1, priority = 0;
  int type = s21_find_true_operator(string, &word_lenth);
  priority = s21_priority(string, &word_lenth);
  if (priority == ERROR) return ERROR;
  s21_push(stack_node_ptr, 0, type, priority);
  return word_lenth;
}

int s21_trigonometry_parser(stack_node** stack_node_ptr, char* string) {
  int word_lenth = 1, priority = 0;
  int type = s21_find_true_operator(string, &word_lenth);
  priority = s21_priority(string, &word_lenth);
  if (priority == ERROR) return ERROR;
  s21_push(stack_node_ptr, 0, type, priority);
  return word_lenth;
}

int s21_find_true_operator(char* oper, int* word_lenth) {
  int type_flag = ERROR;
  if (*oper == '+') {
    type_flag = ADD;
  } else if (*oper == 'x') {
    type_flag = NUM;
  } else if (*oper == '-') {
    type_flag = SUB;
  } else if (*oper == '*') {
    type_flag = MULT;
  } else if (*oper == '/') {
    type_flag = DIV;
  } else if (*oper == '^') {
    type_flag = POW;
  } else if (*oper == '(') {
    type_flag = OP_BRAC;
  } else if (*oper == ')') {
    type_flag = CLOSE_BRAC;
  } else if (*oper == 'u') {
    type_flag = UN_SUB;
  } else if (*oper == 'p') {
    type_flag = UN_ADD;
  } else if (strncmp(oper, "mod", 3) == 0) {
    type_flag = MOD;
    *word_lenth = 3;
  } else if (strncmp(oper, "sin", 3) == 0) {
    type_flag = SIN;
    *word_lenth = 3;
  } else if (strncmp(oper, "ln", 2) == 0) {
    type_flag = LN;
    *word_lenth = 2;
  } else if (strncmp(oper, "log", 3) == 0) {
    type_flag = LOG;
    *word_lenth = 3;
  } else if (strncmp(oper, "tan", 3) == 0) {
    type_flag = TAN;
    *word_lenth = 3;
  } else if (strncmp(oper, "sqrt", 4) == 0) {
    type_flag = SQRT;
    *word_lenth = 4;
  } else if (strncmp(oper, "asin", 4) == 0) {
    type_flag = ASIN;
    *word_lenth = 4;
  } else if (strncmp(oper, "atan", 4) == 0) {
    type_flag = ATAN;
    *word_lenth = 4;
  } else if (strncmp(oper, "acos", 4) == 0) {
    type_flag = ACOS;
    *word_lenth = 4;
  } else if (strncmp(oper, "cos", 3) == 0) {
    type_flag = COS;
    *word_lenth = 3;
  }
  return type_flag;
}

int s21_priority(char* string, int* word_lenth) {
  int priority = 1;
  if (*word_lenth == 1) {
    if (*string == '-' || *string == '+') {
      priority = 2;
    } else if (*string == '*' || *string == '/') {
      priority = 3;
    } else if (*string == '^') {
      priority = 6;
    } else if (*string == 'u' || *string == 'p') {
      priority = 4;
    }
  } else if (strncmp(string, "mod", 3) == 0) {
    priority = 3;
  } else {
    priority = 5;
  }
  return priority;
}

void analyze_expression(char* string) {
  int i = 0;
  char prev_char = '\0';
  while (string[i] != '\0') {
    char current_char = string[i];
    if (current_char == '-' && (i == 0 || prev_char == '(')) {
      string[i] = 'u';
    } else if (current_char == '+' && (i == 0 || prev_char == '(')) {
      string[i] = 'p';
    }
    prev_char = current_char;
    i++;
  }
}
