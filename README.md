# Text Editor with Undo/Redo Functionalities

This program implements a simple text editor with undo/redo functionalities. It allows users to enter statements of up to 100 characters per line and perform various operations such as undo, redo, print, save, and quit.

## Special Commands

- `undo`: Remove the last entered statement.
- `redo`: Re-add the last removed statement.
- `print`: Print the entire stored input text.
- `save`: Save the text to a file called `output.txt`.
- `quit`: Exit the program and save all results to `output.txt`.

## Implementation Details

- Each statement is stored in a separate node.
- Undo/redo functionalities are implemented using stacks.
- When printing all statements, they are printed in the sequence they were entered.

## Usage

1. Clone the repository.
2. Compile the program.
3. Execute the compiled program.
4. Enter statements or special commands as required.

## Contributing
Contributions to the development of this project are welcome. If you encounter any bugs, issues, or have suggestions for improvements, please open an issue or submit a pull request.

