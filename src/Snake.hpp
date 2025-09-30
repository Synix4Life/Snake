#pragma once

#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <set>

#include "Essentials.hpp"

class Snake{
        std::vector<std::tuple<int,int>> parts;
        Direction direction;
        std::tuple<int, int> head;
    
    public:
        Snake(std::tuple<int, int> start_pos, enum Direction direction){
            parts.push_back(start_pos);
            this->head = start_pos;
            this->direction = direction;
        }

        void update(const bool is_new) noexcept;

        void change_dir(const enum Direction new_dir) noexcept{
            direction = new_dir; 
        }

        [[nodiscard]] std::vector<std::tuple<int, int>> get() const noexcept{ 
            return parts; 
        }

        std::tuple<int, int> operator[](const int pos) const{
            if(pos >= parts.size()){
                throw std::runtime_error("Illegal Access");
            }
            return parts[pos];
        }
        
        [[nodiscard]] int size() const noexcept{ 
            return (int) parts.size(); 
        }

        [[nodiscard]] Direction get_direction() const noexcept{ 
            return direction; 
        }

        [[nodiscard]] std::tuple<int, int> get_head() const noexcept{
            return head;
        }
        
        [[nodiscard]] std::vector<std::tuple<int, int>> order();

        [[nodiscard]] bool snake_collision() const noexcept;
};
