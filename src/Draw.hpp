#pragma once

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <iostream>
#include <vector>

#include "Field.hpp"


// ------------------------------------------------------ //
// --------------------- CONSTANTS ---------------------- //
// ------------------------------------------------------ //

inline const std::string GREEN = "\033[42m";
inline const std::string WHITE = "\033[47m";
inline const std::string YELLOW = "\033[43m";
inline const std::string RED = "\033[41m";
inline const std::string GRAY = "\033[100m";
inline const std::string RESET = "\033[0m";


// ------------------------------------------------------ //
// ---------------------- METHODS ----------------------- //
// ------------------------------------------------------ //

/**
 * Clear the lines to readraw
 * @param n Line count
 */
inline void clear_lines(const int n) noexcept{
    for (int i = 0; i < n; ++i) {
        std::cout << "\033[A";  
        std::cout << "\033[K";
    }
}


/**
 * Draw the updated board in the terminal
 * @param field The field
 * @param alive If the snake is still alive
 */
inline void draw(const Field& field, const bool alive) noexcept{
    const auto& snake_pos = field.get_snake().sort();
    int snake_pos_pointer = 0;
    point apple_pos = field.get_apple();

    clear_lines(field[1]+2);

    for(int j=0; j<field[0]+2; j++){ std::cout << WHITE << "  " << RESET; }
    std::cout << std::endl;

    for(int i=0; i<field[1]; i++){
        std::cout << WHITE << "  " << RESET;
        for(int j=0; j<field[0]; j++){
            if(snake_pos[snake_pos_pointer].x == j && snake_pos[snake_pos_pointer].y == i){
                std::cout << ((alive) ?  GREEN: RED) << "  " << RESET;
                snake_pos_pointer++;
            }
            else if(apple_pos.x == j && apple_pos.y == i){
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