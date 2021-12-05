# Monty Project

## Monty language
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
* Example:

```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

###### Pall
The `pall` opcode prints all the values on the stack , starting from the top of the stack.
* Usage: `pall`
* if stack is empty it prints does not anything.

###### Pint
The `pint` opcode prints the value at the top of the stack, followed by new line
* Usage: `pint`
* if the stack is empty print error message `L<line_number>: can not pint, stack empty` followed by exit with the status `EXIT_FAILURE`
* Example:

```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```

###### Pop
The `pop` opcode removes the top element of the stack.
* Usage: `pop`
* If the stack is empty, print the error message `L<line_number>: can not pop an empty stack` followed by exit with the status `EXIT_FAILURE`
* Example:

```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```

###### Swap
The opcode `swap` swaps the top two elements of the stack.
* Usage: `swap`
* If the stack contains less than two elements, print the error message `L<line_number>: can not swap, stack too short` followed by exit with the status `EXIT_FAILURE`
* Example:

```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```

###### Add
The opcode `add` adds the top two elements of the stack.
* Usage: `add`
* If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short` followed by exit with the status `EXIT_FAILURE`.
* Example:

```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```

###### Nop
The opcode `nop` does not do anything.
* Usage: `nop`
