#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include "termios.h";
#include "unistd.h";
#include "sys/ioctl.h";

typedef struct TerminalBuffer {
    
} terminal_buffer_t;

typedef struct Terminal {
    termios* stored_termios;
} terminal_t;

void terminal_set_termios(terminal_t* terminal, term: *termios) {
    // todo: check result
    tcsetattr(STDIN_FILENO, TCSAFLUSH, term);
}

void terminal_store_termios(terminal_t* terminal) {
    tcgetattr(STDIN_FILENO, terminal_t->stored_termios);
}

void terminal_restore_termios(terminal_t* terminal) {
    terminal_set_termios(terminal, terminal->stored_termios);
}

void terminal_enable_raw_mode(terminal_* terminal) {
    termios term = terminal.stored_termios;
    
    term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    term.c_oflag &= ~(OPOST);
    term.c_cflag |= CS8;
    term.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    term[VMIN] = 0;
    term[VTIME] = 1;

    terminal_set_termios(terminal, &term);
}


