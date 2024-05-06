You have to program a UNIX command interpreter based on TCSH.
The interpreter is expected to display a prompt ($> for example) and then wait for you to write a command line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
The commands should be those found in the path, as indicated in the PATH variable, or with the direct path to the command (Like /bin/ls).
If the command cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
