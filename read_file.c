#include "monty.h"

/**
 * open_file - open file
 * @file_name: location of file
 *
 * Return: nothing
 */

void open_file(char *file_name)
{
  FILE *fptr;
  /* to check if file is empty and check if file exist */
  if (file_name == NULL || access(file_name, R_OK) == -1)
    {
      printf("Error: Can't open file %s\n", file_name);
      exit(EXIT_FAILURE);
    }
  fptr = fopen(file_name, "r");
  if (fptr == NULL)
    {
      printf("Error: can't open file %s\n", file_name);
      exit(EXIT_FAILURE);
    }
  read_file(fptr);
  fclose(fptr);
}

/**
 * read_file - read the content of file
 * @fptr: pointer to open fiel
 *
 * Return: nothing
 */

void read_file(FILE *fptr)
{
  char *buff = NULL;
  size_t size = 256;
  for (; getline(&buff, &size, fptr) != '\0';)
    tokenizer(buff);
}

/**
* tokenizer - make tokens from each line
* @buff: line in file
* Return: nothing
*/
void tokenizer(char *buff)
{
  char *op = NULL;
  op = strtok(buff, "\n ");
  if (op[0] == '#')
    return;
  func_call(op);
}

/**
 * func_call - to find the correct function for opcode
 * @op: the opcode
 * Return: nothing
 */

void func_call(char *op)
{
  int i = 0;
  instruction_t ins[] = {{"push", push}, {"pall", pall}};
  while (ins[i].opcode && op)
    {
      if (strcmp(op, ins[1].opcode) == 0)
	{
	  ins[i].f(&(args.stack), args.count);
	  return;
	}
      i++;
    }
}
