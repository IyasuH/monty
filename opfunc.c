#include "monty.h"

/**
 * push - pushes an element to the top of stack
 * @stack: doubly linked lists
 * @line_number: the number line
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
int val;
int i = 0;
char *value = strtok(NULL, "\n");
struct stack_s *new = malloc(sizeof(stack_t));
val = 0;
if (new == NULL)
{
printf("Erorr: malloc failed\n");
exit(EXIT_FAILURE);
}
for (i = 0; value[i] != '\0'; i++)
{
/* to check if val is not integer*/
if (!(isdigit(value[i])))
{
printf("L%u: usage: push integer\n", line_number);
free_dlistint(args.stack);
exit(EXIT_FAILURE);
}
}
val = atoi(value);
new->n = val;
new->prev = NULL;
new->next = NULL;
if (*stack == NULL)
(*stack) = new;
else
{
(*stack)->prev = new;
new->next = (*stack);
(*stack) = new;
}
}

/**
 * pint - prints the value at the top of stack followed by newline
 * @stack: doubly linked list
 * @line_number: the number line
 */

void pint(stack_t **stack, unsigned int line_number)
{
  if(!*stack)
    {
      printf("L%u: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  printf("%d\n", (*stack)->n);
}

/**
 * pall - print all the values on the stack starting from the top of stack
 * @stack: doubly linked lists
 * @line_number: the number line
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
(void) line_number;
if (stack == NULL)
{
free_dlistint(args.stack);
exit(EXIT_FAILURE);
}
while (stack != NULL)
{
printf("%d\n", (*stack)->n);
(*stack) = (*stack)->next;
}
}
