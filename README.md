# Pipex

Pipex is a command line tool that allows you to easily connect multiple commands together using pipes. It provides a simple and intuitive way to chain commands and manipulate the output of one command as the input of another.

## Installation

To install Pipex, clone the repository and run `make` in the root directory. This will create the `pipex` executable.

## Usage

Pipex can be used just like the regular pipe operator (`|`) in the command line. For example, the command `ls -l | grep "^d"` can be written as `pipex ls -l "grep ^d"`.

You can also use multiple pipes in a single command, for example: `pipex ls -l "grep ^d" "wc -l"`

## Options

-   `-p` : used for debug, will print the commands to be executed
-   `-e` : used for debug, will print the error messages

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

Pipex is licensed under the MIT License.
