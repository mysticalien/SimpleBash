# SimpleBash
Grep and Cat in C
This project is a C implementation of the cat and grep commands, two fundamental Unix utilities. The cat command is used to read and concatenate files, while grep is used to search for lines in a file that match a specified pattern.

Features
Command-line argument parsing: The program supports a variety of command-line options and arguments, similar to the actual grep and cat commands.
Regular expression matching: The program uses the POSIX regular expression library to match patterns in the input.
File processing: The program can process multiple files and print matching lines.
Error handling: The program includes error handling code to deal with potential errors, such as file not found or memory allocation failure.
Installation
To install the program, clone the repository and compile the C source code:

git clone https://github.com/your_username_/grep_and_cat_in_c.git
cd grep_and_cat_in_c
gcc -o grep_and_cat main.c
Usage
To run the program, use the following command:

./grep_and_cat [options] [pattern] [file ...]
The program supports a variety of command-line options and arguments. For example, the -i option makes the pattern matching case-insensitive, and the -v option inverts the matching, so only lines that do not match the pattern are printed.
