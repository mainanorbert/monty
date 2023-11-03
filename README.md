# C - Stacks, Queues - LIFO, FIFO
The goal of the project was to create an interpreter for `Monty ByteCodes files`. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
`Monty ByteCode Files:` are files associated with Monty. It is often used as a teaching tool to help beginners understand the fundamental concepts of programming and computer science.
## Monty Programs
- They are plan text files written with `.m` extension
- When the Monty interpreter reads the source code, it generates bytecode instructions that represent the operations specified in the code. These bytecode instructions are typically stored in a binary file with a .m extension, known as a Monty Bytecode file.
- The interpreter is implemented using this Queues and Stacks
## Monty ByteCode Files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
- Below is example of Monty bytecode that can be interpreted:
	- `PUSH 42`
	- `PUSH             7`
	- `ADD`
	- `PRINT`
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

## How Install and Run
1. Clone the project with command:
- ```git clone https://github.com/mainanorbert/monty.git```
2. Change directory to the project with command:
- `cd monty`
3. Compile using compiler:
- `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
## The monty program usage
- Usage: `monty file`
where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument error message `USAGE: monty file`, is printed followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, error message Error: `Can't open file <file>` is printed  followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
- If the file contains an invalid instruction, error message `L<line_number>: unknown instruction <opcode>` is printed followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
- Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured
- If malloc fails error message Error: `malloc failed`, is printed followed by a new line and exit with status EXIT_FAILURE.
- Program uses malloc and free and it is not allowed to use any other function from man malloc (realloc, calloc, …)
