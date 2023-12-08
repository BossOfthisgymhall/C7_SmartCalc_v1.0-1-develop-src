#include "../s21_smart_calc.h"

int s21_rpn_processing(stack_node** stack_node_ptr, stack_node** output) {
  stack_node* op = NULL;
  stack_node* rev = NULL;
  double value = 0;
  int err = OK;
  rev = reverse_stack(stack_node_ptr, rev);
  while (rev != NULL) {
    if ((rev)->type == NUMBER) {
      value = (rev)->number;
      s21_push(output, value, NUMBER, 0);
      s21_pop(&rev);
    } else {
      if (op == NULL || rev->type == OP_BRAC) {
        s21_push(&op, 0, (rev)->type, (rev)->priority);
        s21_pop(&rev);
      } else {
        op_priority(&rev, &op, output);
      }
    }
  }
  while (op != NULL) {
    s21_push(output, 0, op->type, op->priority);
    s21_pop(&op);
  }
  rev = reverse_stack(output, rev);
  *stack_node_ptr = reverse_stack(&rev, *stack_node_ptr);
  *output = reverse_stack(stack_node_ptr, *output);
  printf("Вышел из рпн\n");
  return err;
}

int op_priority(stack_node** snp, stack_node** op, stack_node** output) {
  if (((*snp)->priority > (*op)->priority) && (*snp)->priority != 1) {
    s21_push(op, 0, (*snp)->type, (*snp)->priority);
    s21_pop(snp);
  } else if ((*snp)->type == CLOSE_BRAC) {
    s21_pop(snp);
    while ((*op)->type != OP_BRAC) {
      s21_push(output, 0, (*op)->type, (*op)->priority);
      s21_pop(op);
    }
    if ((*op)->type == OP_BRAC) {
      s21_pop(op);
    }
  } else if (((*snp)->priority <= (*op)->priority)) {
    s21_push(output, 0, (*op)->type, (*op)->priority);
    s21_pop(op);
  }
  return OK;
}

stack_node* reverse_stack(stack_node** input, stack_node* out) {
  while (*input != NULL) {
    s21_push(&out, (*input)->number, (*input)->type, (*input)->priority);
    s21_pop(input);
  }
  return out;
}
