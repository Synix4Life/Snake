#pragma once

#include <tuple>
#include <vector>

#include "Essentials.hpp"
#include "Snake.hpp"
#include "Listen_Draw.hpp"

class Field{
    private:
        std::tuple<int, int> size;
        std::tuple<int, int> apple_pos;
        Snake snake;
        bool breakFlag = false;

        void set_apple(){
            bool touch;
            do{
                touch = false;
                apple_pos = generate_random_position(size);
                for(int i=0; i<snake.size(); i++){
                    if(snake[i] == apple_pos){
                        touch = true;
                        break;
                }
            }
            }while(touch);
        }
        bool out_of_bounds(const std::tuple<int, int> pos){
            return (std::get<0>(pos) < 0) || (std::get<0>(pos) >= std::get<0>(size)) || (std::get<1>(pos) < 0) || (std::get<1>(pos) >= std::get<1>(size));
        }

    public:
        Field(int size_x, int size_y): 
            size(size_x, size_y), 
            snake({1, 1}, RIGHT),
            apple_pos(generate_random_position({size_x, size_y})) {}

        void check_and_set(Direction dir){
            bool got_apple = false;
            for(int i=0; i<snake.size(); i++){
                std::tuple<int, int> current = snake[i];
                if(current == apple_pos){
                    got_apple = true;
                    set_apple();
                    break;
                }
            }
            if(out_of_bounds(snake[0])) breakFlag = true;
            if(valid_dir(snake.get_direction(), dir)) snake.change_dir(dir);
            snake.update(got_apple);
        }
        [[nodiscard]] std::tuple<int, int> get_apple(){
            return apple_pos;
        }
        int operator[](int pos){
            return (pos==0) ? std::get<0>(size) : std::get<1>(size);
        }
        Snake get_snake(){
            return snake;
        }
        [[nodiscard]] bool flag() noexcept{
            return breakFlag;
        }
};