Simple Shell
============

Description
-----------

The Simple Shell project is an implementation of a basic command-line interpreter. This shell replicates the behavior of the standard Unix shell, providing an interface for users to execute commands and manage processes.

Features
--------

*   **Command execution**: Executes commands with arguments.
*   **Built-in commands**: Supports built-in commands like `cd`, `exit`, and `env`.
*   **Path handling**: Searches for executable files in the directories listed in the `PATH` environment variable.
*   **Error handling**: Displays appropriate error messages for invalid commands or arguments.
*   **Interactive and non-interactive modes**: Operates in both interactive mode (user input) and non-interactive mode (script execution).

Getting Started
---------------

### Prerequisites

*   A Unix-like operating system (Linux, macOS)
*   GCC compiler

### Installation

1.  Clone the repository:git clone https://github.com/petrushimself/simple_shell.git
    
2.  Navigate to the project directory:cd simple_shell
    
3.  Compile the source files:gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
    

### Usage

*   **Interactive mode**:
    
    ./hsh
    
    Type commands and press Enter to execute.
    
*   **Non-interactive mode**:
    
    echo "command" | ./hsh
    
    or
    
    ./hsh < script
    

Built-in Commands
-----------------

*   `cd [directory]`: Change the current directory.
*   `exit [status]`: Exit the shell with a given status.
*   `env`: Print the environment variables.

Example
-------

$ ./hsh
    $ ls -l
    total 8
    -rw-r--r-- 1 user user  0 Jul 31 09:47 file1
    -rw-r--r-- 1 user user  0 Jul 31 09:47 file2
    $ cd ..
    $ exit

Authors
-------

*   **Petrus Tlhomedi** - petrushimself


License
-------

This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
---------------

*   ALX Africa for the project guidelines and resources.
*   The creators of the original Unix shell for inspiration.

* * *
