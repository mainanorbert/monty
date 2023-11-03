# C - Stacks, Queues - LIFO, FIFO
The goal of the project was to create an interpreter for `Monty ByteCodes files`. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
`Monty ByteCode Files:` are files associated with Monty. It is often used as a teaching tool to help beginners understand the fundamental concepts of programming and computer science.
## Monty Programs
- They are plan text files written with `.m` extension
- When the Monty interpreter reads the source code, it generates bytecode instructions that represent the operations specified in the code. These bytecode instructions are typically stored in a binary file with a .m extension, known as a Monty Bytecode file.
- The interpreter is implemented using this Queues and Stacks
- Below is example of Monty bytecode that can be interpreted:
	- `PUSH 42`
	- `PUSH 7`
	- `ADD`
	- `PRINT`
