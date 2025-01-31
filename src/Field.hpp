#pragma once

#include <algorithm>
#include <tuple>
#include <vector>

#include <omp.h>

#include "Essentials.hpp"
#include "Listen_Draw.hpp"
#include "Snake.hpp"
#include "Global.h"

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
                auto it = std::find(snake.get().begin(), snake.get().end(), apple_pos);
                if(it == snake.get().end()){
                    break;
                }
                #pragma omp parallel for num_threads(threads) if(parallel)
                for(int i=0; i<snake.size(); i++){
                    if(snake[i] == apple_pos){
                        #pragma omp critical
                        touch = true;
                }
            }
            }while(touch);
        }
        bool out_of_bounds(const std::tuple<int, int> pos) noexcept{
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
            if(snake.snake_collision()){ breakFlag = true; }
            snake.update(got_apple);
            if(got_apple && dynamic_speed){ adjust_speed(); }
        }
        [[nodiscard]] std::tuple<int, int> get_apple() const noexcept{
            return apple_pos;
        }
        int operator[](int pos) const noexcept{
            return (pos==0) ? std::get<0>(size) : std::get<1>(size);
        }
        [[nodiscard]] Snake get_snake() const noexcept{
            return snake;
        }
        [[nodiscard]] bool flag() const noexcept{
            return breakFlag;
        }
};