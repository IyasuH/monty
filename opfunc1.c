#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list
 * @line_number: the number of line
 *
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
int temp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
pop(stack, line_number);
(*stack)->n += temp;
}

/**
 * nop - doesn't do anything
 * @stack: doubly linked list
 * @line_number: the number of line
 *
 * Return: nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
