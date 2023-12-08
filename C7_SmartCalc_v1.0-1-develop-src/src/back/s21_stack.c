#include "../s21_smart_calc.h"

int s21_push(stack_node** stack_node_ptr, double data, int type, int priority) {
  stack_node* new_elem = (stack_node*)calloc(1, sizeof(stack_node));
  if (new_elem == NULL) {
    return ERROR;
  }
  new_elem->number = data;
  new_elem->type = type;
  new_elem->priority = priority;
  new_elem->next = *stack_node_ptr;  // seg
  *stack_node_ptr = new_elem;
  return OK;
}

int s21_pop(stack_node** stack_node_ptr) {
  if (*stack_node_ptr == NULL) return ERROR;
  stack_node* tmp_ptr = *stack_node_ptr;
  *stack_node_ptr = tmp_ptr->next;
  free(tmp_ptr);
  return OK;
}

int s21_count(stack_node* stack) {
  int count = 0;
  stack_node* current = stack;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}