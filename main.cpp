// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>

#include "Draw.hpp"
#include "Essentials.hpp"
#include "Field.hpp"
#include "Terminal.h"


// ------------------------------------------------------ //
// --------------------- CONSTANTS ---------------------- //
// ------------------------------------------------------ //

// The constant game speed, which may be subject to change via a config file in the future
constexpr int GAME_SPEED = 500;

// ====================================================== //
// ======================== MAIN ======================== //
// ====================================================== //

int main(){
    Terminal terminal;

    Field field(10, 10, 1, 1);
    bool running = true;
    auto dir = RIGHT;

    while (running) {
        char c = key_listener();
        
        if(c == 'w'){ dir = UP; }
        else if(c == 'a'){ dir = LEFT; }
        else if(c == 's'){ dir = DOWN; }
        else if(c == 'd'){ dir = RIGHT; }
        
        if( c == 'x' || field.check_and_set(dir) ){ running = false; }
        
        draw(field, running);

        std::this_thread::sleep_for(std::chrono::milliseconds(GAME_SPEED));
    }

    return 0;
}
