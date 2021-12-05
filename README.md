# Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
## Usage
The code is compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```
And to run the program:
```
./monty bytecodes/
```
## Opcodes description

###### Push
The `push` opcode pushes element to the stack.
* Usage: `push <int>`
  * where `<int>` is an integer

###### Pall
The `pall` opcode prints all the values on the stack , starting from the top of the stack.
* Usage: `pall`
* if stack is empty it prints does not anything.

###### Pint
The `pint` opcode prints the value at the top of the stack, followed by new line
* Usage: `pint`
* if the stack is empty print error message `L<line_number>: can not pint, stack empty` followed by exit with the status `EXIT_FAILURE`

###### Pop
The `pop` opcode removes the top element of the stack.
* Usage: `pop`
* If the stack is empty, print the error message `L<line_number>: can not pop an empty stack` followed by exit with the status `EXIT_FAILURE`

###### Swap
The opcode `swap` swaps the top two elements of the stack.
* Usage: `swap`
* If the stack contains less than two elements, print the error message `L<line_number>: can not swap, stack too short` followed by exit with the status `EXIT_FAILURE`

###### Add
The opcode `add` adds the top two elements of the stack.
* Usage: `add`
* If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short` followed by exit with the status `EXIT_FAILURE`.

###### Nop
The opcode `nop` does not do anything.
* Usage: `nop`
