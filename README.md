# get_next_line 📚💻

## Description 📝

Reads a line from a file descriptor (`fd`). 
The goal was to create a function called `get_next_line` that returns a line read from the file descriptor, one line at a time.
Understanding static variables was a good starting point. And global variables were not allowed.

### Details 📋:

- The `get_next_line` function should allow reading a text file pointed to by the file descriptor, one line at a time.
- It should return the line that was read.
- If there is nothing else to read or an error occurs, the function should return `NULL`.
- The returned line should include the terminating `\n` character, except when the end of the file is reached and does not end with a `\n` character.
- Ensure that your function works correctly when reading from both files and standard input.

Understanding static variables would be a good starting point.
Global variables are not allowed.

## Bonus Part 💯

Here are the additional requirements:

- Implement the `get_next_line` function using only one static variable.
- The `get_next_line` function should be able to manage multiple file descriptors simultaneously.
