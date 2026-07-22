#pragma once

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


// ------------------------------------------------------ //
// ---------------------- CLASSES ----------------------- //
// ------------------------------------------------------ //

/**
 * Class to construct a non-blocking terminal for a directional key-input
 */
class Terminal {
    public:
        /**
         * Constructor for the Terminal class to save the old terminal and create a new 
         */
        Terminal() {
            tcgetattr(STDIN_FILENO, &old_);

            termios newt = old_;
            newt.c_lflag &= ~(ICANON | ECHO);

            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
        }

        /**
         * Restore the original terminal
         */
        ~Terminal() {
            tcsetattr(STDIN_FILENO, TCSANOW, &old_);
        }

    private:
        termios old_{};
};


// ------------------------------------------------------ //
// ---------------------- METHODS ----------------------- //
// ------------------------------------------------------ //

/**
 * Provide an option to read the terminal direction as a buffered reader
 */
[[nodiscard]] char key_listener(){
    char buf{};
    if (read(STDIN_FILENO, &buf, 1) > 0)
        return buf;

    return '\0';
}