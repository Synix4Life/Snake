#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>

#include "Listen_Draw.hpp"
#include "Essentials.hpp"
#include "Field.hpp"
#include "Global.h"


/**
 * Display the help message
 * @name Program name
 */
static void help(const char* name){
    std::cout << 
        "Usage: " << name << " [options]\n"
        "\n"
        "Options:\n"
        "  -h, --help           Show this message\n"
        "  --speed <slow/fast>  Adjust the game speed\n"
        "  --dynamic            Makes the game speed dynamic (independent from --speed)\n"
        "\n"
    ;
    exit(0);
}


/**
 * Main game loop
 */
void loop(){
    Field field(10, 10, 1, 1);
    bool running = true;
    auto dir = RIGHT;

    while (running) {
        char c = key_listener();
        
        if(c == 'w'){ dir = UP; }
        else if(c == 'a'){ dir = LEFT; }
        else if(c == 's'){ dir = DOWN; }
        else if(c == 'd'){ dir = RIGHT; }

        field.check_and_set(dir);
        
        if( c == 'x' || field.flag()){ running = false; }
        
        draw(field, running);

        std::this_thread::sleep_for(std::chrono::milliseconds(game_speed));
    }
}


int main(int argc, char* argv[]) {    
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "--speed") == 0){
            i++;
            game_speed = (strcmp(argv[i], "slow") == 0) ? 700 : (strcmp(argv[i], "fast") == 0) ? 300 : 500;
        }
        else if(strcmp(argv[i], "--dynamic") == 0){ dynamic_speed = true; }
        else if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0){ help(argv[0]); }
        else{
            std::cout << "Unknown command";
            exit(1);
        }
    }

    loop();

    return 0;
}