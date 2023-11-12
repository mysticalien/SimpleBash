# Grep and Cat in C

This project is a C implementation of the ```cat``` and ```grep``` commands, two fundamental Unix utilities. The cat command is used to read and concatenate files, while grep is used to search for lines in a file that match a specified pattern.

![image](IMAGES/cat.png)

## Features

 - Command-line argument parsing: The program supports a variety of command-line options and arguments, similar to the actual grep and cat commands.
 - Regular expression matching: The program uses the POSIX regular expression library to match patterns in the input.
 - File processing: The program can process multiple files and print matching lines.
 - Error handling: The program includes error handling code to deal with potential errors, such as file not found.

## Installation
To install the program, clone the repository:

```
git clone git@github.com:mysticalien/SimpleBash.git
cd SimpleBash
cd src
```

and compile the C source code for cat using Makefile:

```
cd cat
make
```

or compile the C source code for grep:

```
cd grep
make
```
## Usage

To run the program, use the following command for cat:

```
./cat [options] [file ...]
```

and this command for grep:

```
./grep [options] [pattern] [file ...]
```

To test the code for leaks use this command:

```
make leaks
```

To run the tests, use this command:

```
make test
```

## Options

### cat:

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

### grep:

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase.  |
| 3 | -v | Invert match. |
| 4 | -c | Output count of matching lines only. |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. |
| 7 | -h | Output matching lines without preceding them by file names. |
| 8 | -s | Suppress error messages about nonexistent or unreadable files. |
| 9 | -f file | Take regexes from a file. |
| 10 | -o | Output the matched parts of a matching line. |

## How it really works:

![catt](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExYzFub3FpbXR5a3oyNHBzajZkaHI3a3VxMTc3eWZmZHZyOXprZnN5NCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/7NoNw4pMNTvgc/giphy.gif)