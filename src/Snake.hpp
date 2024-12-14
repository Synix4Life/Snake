#pragma once

#include <vector>
#include <tuple>
#include <stdexcept>

#include "Essentials.hpp"

class Snake{
        std::vector<std::tuple<int,int>> parts;
        Direction direction;
    
    public:
        Snake(std::tuple<int, int> start_pos, Direction direction){
            parts.push_back(start_pos);
            this->direction = direction;
        }

        void update(const bool is_new){
            int x = (direction == RIGHT) ? std::get<0>(parts[0]) +1 : ( (direction == LEFT) ? std::get<0>(parts[0])-1 : std::get<0>(parts[0]) ); 
            int y = (direction == UP) ? std::get<1>(parts[0])-1 : ( (direction == DOWN) ? std::get<1>(parts[0])+1 : std::get<1>(parts[0]) ); 
            parts.emplace(parts.begin(), x, y);
            if(!is_new){
                parts.pop_back();
            }
        }

        void change_dir(Direction new_dir){
            direction = new_dir;
        }

        [[nodiscard]] std::vector<std::tuple<int, int>> get(){
            return parts;
        }

        std::tuple<int, int> operator[](int pos){
            if(pos >= parts.size()){
                throw std::runtime_error("Illegal Access");
            }
            return parts[pos];
        }
        
        [[nodiscard]] int size(){
            return parts.size();
        }

        [[nodiscard]] Direction get_direction(){ return direction; }
        
        [[nodiscard]] std::vector<std::tuple<int, int>> order(){           
            std::vector<std::tuple<int, int>> res;
            for (const std::tuple<int, int>& element : parts) {
                    bool inserted = false;

                    for (size_t i = 0; i < res.size(); ++i) {
                        if (std::get<1>(element) < std::get<1>(res[i])) {
                            res.insert(res.begin() + i, element);
                            inserted = true;
                            break;
                        }
                        else if (std::get<1>(element) == std::get<1>(res[i])) {
                            if (std::get<0>(element) < std::get<0>(res[i])) {
                                res.insert(res.begin() + i, element);
                                inserted = true;
                                break;
                            }
                            else if (i + 1 == res.size() || std::get<0>(element) < std::get<0>(res[i + 1])) {
                                res.insert(res.begin() + i + 1, element);
                                inserted = true;
                                break;
                            }
                        }
                    }

                    if (!inserted) {
                        res.push_back(element);
                    }
                }

            return res;
        }
};