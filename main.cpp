#include <iostream>
#include <thread>
#include <chrono>

#include "src/Listen_Draw.hpp"
#include "src/Essentials.hpp"
#include "src/Snake.hpp"
#include "src/Field.hpp"

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

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    loop();

    return 0;
}