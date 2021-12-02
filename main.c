#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: int
 */

universal_t args;

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
    printf("USAGE: monty file\n");
    exit(EXIT_FAILURE);
    }
  args.count = 0;
  args.stack = NULL;
  open_file(*argv);
  free_dlistint(args.stack);
  return(0);
}
void free_dlistint(stack_t *head)
{
  stack_t *temp = head;
  while(head != NULL)
    {
      free(temp);
      head = head->next;
      temp = head;
    }
}
