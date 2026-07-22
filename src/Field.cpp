#include "Field.hpp"

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <algorithm>
#include <tuple>

#include "Essentials.hpp"


// ------------------------------------------------------ //
// ---------------------- METHODS ----------------------- //
// ------------------------------------------------------ //

void Field::set_apple(){
    bool touch;
    do{
        touch = false;
        apple_pos = generate_random_position(size, gen);

        auto it = std::find(snake.get().begin(), snake.get().end(), apple_pos);
        if(
            it != snake.get().end() 
            || apple_pos == next_head_pos(snake.get_direction(), snake.get_head())
        ){
            touch = true;
        }
    }while(touch);
}

int Field::check_and_set(Direction dir){
    bool got_apple = false;
    for(int i=0; i<snake.size(); i++){
        point current = snake[i];
        if(current == apple_pos){
            got_apple = true;
            set_apple();
            break;
        }
    }
    if(out_of_bounds(snake[0])) return 1;
    if(valid_dir(snake.get_direction(), dir)) snake.change_dir(dir);
    if(snake.snake_collision()){ return 1; }
    snake.update(got_apple);
    return 0;
}