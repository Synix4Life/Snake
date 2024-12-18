#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>

#include "src/Listen_Draw.hpp"
#include "src/Essentials.hpp"
#include "src/Snake.hpp"
#include "src/Field.hpp"
#include "src/Global.h"

void loop(){
    Field field(10, 10);
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
        if(strcmp(argv[i], "--parallel") == 0){
            parallel = true;
        }
        else if(strcmp(argv[i], "--num") == 0){
            i++;
            threads = atoi(argv[i]);
        }
        else if(strcmp(argv[i], "--speed") == 0){
            i++;
            game_speed = (strcmp(argv[i], "slow") == 0) ? 700 : (strcmp(argv[i], "fast") == 0) ? 300 : 500;
        }
        else if(strcmp(argv[i], "--dynamic") == 0){
            dynamic_speed = true;
        }
        else{
            printf("Unknow command\n");
            exit(1);
        }
    }

    loop();

    return 0;
}