# Simple Shell README

## Description
The Simple Shell is a UNIX command line interpreter written in C. It allows users to execute basic commands and handles simple command lines without arguments.

## Usage
- Compile the shell program using a C compiler (e.g., `gcc shell.c -o simple_shell`).
- Run the shell by executing the compiled binary (e.g., `./simple_shell`).

## Features
1. Prompt Display:
   - The shell displays a prompt "#cisfun$" to indicate that it is ready to accept commands.

2. Command Execution:
   - The shell waits for the user to input a command and executes it.
   - Commands should be a single word (no arguments or special characters).

3. Error Handling:
   - If an executable command cannot be found, the shell prints an error message and continues to display the prompt.

4. End of File (EOF) Handling:
   - The shell handles the "end of file" condition (Ctrl+D) gracefully and exits the shell.

5. Simple Shell 0.2:
   - Allows command lines with arguments.
   - Example: `ls -l`

6. Simple Shell 0.3:
   - Handles the PATH environment variable.
   - Does not call `fork` if the command doesn't exist.

7. Simple Shell 0.4:
   - Implements the `exit` built-in command to exit the shell.
   - Usage: `exit`
   - No need to handle arguments for the built-in `exit`.

8. Simple Shell 1.0:
   - Implements the `env` built-in command to print the current environment.

## Known Issues
- The shell does not handle complex commands with pipes, redirection, or other advanced features.
- It does not support special characters like ", ', `, \, *, &, #.
- The shell does not provide cursor movement capabilities.

## Contributions
Contributions to the Simple Shell project are welcome! If you find any issues or have ideas for improvements, feel free to open a pull request on the GitHub repository.
