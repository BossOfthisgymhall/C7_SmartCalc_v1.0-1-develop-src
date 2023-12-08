#ifndef S21_SMART_CALC
#define S21_SMART_CALC

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1

#define OPERATOR -2
#define NUM -3
#define BRACKET -4
#define TRIG -5

#define SIZE 256

#define NUMBER 1
#define OP_BRAC 2
#define CLOSE_BRAC 3
#define ADD 4
#define SUB 5
#define MULT 6
#define DIV 7
#define POW 8
#define SQRT 9
#define MOD 10
#define UN_ADD 11
#define UN_SUB 12
#define COS 13
#define SIN 14
#define TAN 15
#define ACOS 16
#define ASIN 17
#define ATAN 18
#define LN 19
#define LOG 20

typedef struct stack_node stack_node;

struct stack_node {
  double number;
  int type;
  int priority;
  stack_node* next;
};

/*
STACK
*/
int s21_push(stack_node** stack_node_ptr, double data, int type, int priority);
int s21_pop(stack_node** stack_node_ptr);
int s21_count(stack_node* s);
/*
PARSER
*/
int s21_parser(stack_node** stack_node_ptr, char* string, double x);
int s21_parser_digit(stack_node** stack_node_ptr, char* string, double x);
int s21_parser_operators(stack_node** stack_node_ptr, char* string);
int s21_find_true_operator(char* oper, int* word_lenth);
int s21_trigonometry_parser(stack_node** stack_node_ptr, char* string);
int s21_priority(char* string, int* word_lenth);  // suda
void analyze_expression(char* string);
/*
VALIDATE
*/
int s21_error_proccesing(char* string);
int s21_dot_use_error(char* string, int dot_use);
int s21_operator_controll(char* string);
int s21_bracket_controller(const char* string);
int s21_type_proccesing(char* string);
int s21_trig_controller(char* string);
int s21_split_func(char* string);
int s21_pow_controller(const char* string);
/*
RPN PROCESSING
*/
stack_node* reverse_stack(stack_node** snp, stack_node* rev);
int s21_rpn_processing(stack_node** snp, stack_node** output);
int op_priority(stack_node** stack_node_ptr, stack_node** op,
                stack_node** output);
/*
ARITHMETIC
*/
double s21_arithmetic(stack_node** snp, double* result);
double perform_operation(double op1, double op2, double operat,
                         stack_node** number, double* result);
double pick_number(stack_node** num);
double type_check(double operat);
double perfom_trig(double op1, double operat, stack_node** num, double* result);
/*
CONNECT
*/
double connect_front_in_back(char* string, double* result, double x);
#endif
