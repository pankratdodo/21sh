# 21sh

# About
You’ll have to start from your minishell and make it stronger to get little by littler closer to a real functionnal shell. You’ll add couple of features such as multi-commande management, redirections as well as line edition that will allow you to use arrows for example.

## Installation
1. Download/Clone this repo
```
git clone https://github.com/pankratdodo/21sh.git
```
2. Run
```
cd 21sh && make && ./21sh
```

## Main project instructions
#### General Instructions
- Project must be written in C in accordance with [the Norm](https://github.com/R4meau/minishell/blob/master/norme.en.pdf).
- Program cannot have memory leaks.
- No Segmentation fault, bus error, double free, etc.
- Within the mandatory part, you are allowed to use only the following libc functions:
    - *malloc, free*
    - *access*
    - *open, close, read, write*
    - *opendir, readdir, closedir*
    - *getcwd, chdir*
    - *stat, lstat, fstat*
    - *fork, execve*
    - *wait, waitpid, wait3, wait4*
    - *signal, kill*
    - *exit*
    - *pipe*
    - *dup, dup2*
    - *isatty, ttyname, ttyslot*
    - *ioctl*
    - *getenv*
    - *tcsetattr, tcgetattr*
    - *tgetent*
    - *tgetflag*
    - *tgetnum*
    - *tgetstr*
    - *tgoto*
    - *tputs*
- A line edition feature using the termcaps library. Check the following description below.
- The `CTRL+D` et `CTRL+C` keys combination features for line edition and process execution.
- The “;” command line separator
- Pipes “|”
- The 4 following redirections `<`, `>`, `<<`, `>>`
- File descriptor aggregation
- Move the cursor left and right to be able to edit the line at a specific location. Obviously new characters have to be inserted between the existing ones similarly to a classic shell.
- Use `UP` and `DOWN` arrows to navigate through the command history
- Cut, and paste all line using the `Ctrl-U` `Crtl-Y` keys
- Go directly to the beginning or the end of a line by pressing `home` and `end`
- Completely manage quotes and double quotes, even on several lines
- Write AND edit a command over a few lines. `SHIFT+UP` and `SHIFT+DOWN` allow to go from one line to another in the command while remaining in the same column or otherwise the most appropriate column.

#### Bonus Part

- Search through history using `CTRL+R`
- Implement a hash table for binary files
- Simple or advanced completion using `tab`
- POSIX for built-in's
- Syntactic shell coloration freely activable or deactivable.
