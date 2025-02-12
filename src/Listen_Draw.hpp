#pragma once

#include <iostream>
#include <tuple>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include "Field.hpp"

#ifdef draw
#error "draw is already defined or declared before this file"
#endif


// --------------- Listen --------------- //

[[nodiscard]] static char key_listener() {
    char buf = 0;
    struct termios old = {0}, newt = {0};

    if (tcgetattr(STDIN_FILENO, &old) < 0) {
        perror("tcgetattr");
        return '\0';
    }

    newt = old;

    newt.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0) {
        perror("tcsetattr");
        return '\0';
    }

    int old_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    if (fcntl(STDIN_FILENO, F_SETFL, old_flags | O_NONBLOCK) < 0) {
        perror("fcntl");
        tcsetattr(STDIN_FILENO, TCSANOW, &old); 
        return '\0';
    }

    if (read(STDIN_FILENO, &buf, 1) < 0) {
        buf = '\0'; 
    }

    if (fcntl(STDIN_FILENO, F_SETFL, old_flags) < 0) {
        perror("fcntl");
    }
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) {
        perror("tcsetattr");
    }

    return buf;
}

// --------------- Draw --------------- //

const std::string GREEN = "\033[42m";
const std::string WHITE = "\033[47m";
const std::string YELLOW = "\033[43m";
const std::string RED = "\033[41m";
const std::string GRAY = "\033[100m";
const std::string RESET = "\033[0m";

static void clear_lines(const int n) noexcept{
    for (int i = 0; i < n; ++i) {
        std::cout << "\033[A";  
        std::cout << "\033[K";
    }
}

static void draw(const Field& field, const bool alive) noexcept{
    std::vector<std::tuple<int, int>> snake_pos = field.get_snake().order();
    int snake_pos_pointer = 0;
    std::tuple<int, int> apple_pos = field.get_apple();

    clear_lines(field[1]+3);

    for(int j=0; j<field[0]+2; j++){ std::cout << WHITE << "  " << RESET; }
    std::cout << std::endl;

    for(int i=0; i<field[1]; i++){
        std::cout << WHITE << "  " << RESET;
        for(int j=0; j<field[0]; j++){
            if(std::get<0>(snake_pos[snake_pos_pointer]) == j && std::get<1>(snake_pos[snake_pos_pointer]) == i){
                std::cout << ((alive) ?  GREEN: RED) << "  " << RESET;
                snake_pos_pointer++;
            }
            else if(std::get<0>(apple_pos) == j && std::get<1>(apple_pos) == i){
                std::cout << YELLOW << "  " << RESET;
            }
            else{
                std::cout << GRAY << "  " << RESET;
            }
        }
        std::cout << WHITE << "  " << RESET << std::endl;
    }

    for(int j=0; j<field[0]+2; j++){ std::cout << WHITE << "  " << RESET; }
    std::cout << std::endl;
}