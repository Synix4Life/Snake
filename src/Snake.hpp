#pragma once

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <set>

#include "Essentials.hpp"


// ------------------------------------------------------ //
// ---------------------- CLASSES ----------------------- //
// ------------------------------------------------------ //

class Snake{   
    public:
        // --------------- CONSTRUCTOR --------------- //
        
        /**
         * Constructor
         * @param start_X Start x value
         * @param start_y Start y value
         * @param direction Direction
         */
        Snake(int start_x, int start_y, enum Direction direction){
            auto p = point(start_x, start_y);
            parts.push_back(p);
            this->head = p;
            this->direction = direction;
        }

        // --------------- METHODS --------------- //

        /**
         * Update the snakes position
         * @param is_new If the apple has been collected in the last iteration
         */
        void update(const bool is_new) noexcept;

        /**
         * Change direction
         * @param new_dir New direction
         */
        void change_dir(const enum Direction new_dir) noexcept{
            direction = new_dir; 
        }

        /**
         * Order the set of points
         * @return The ordered point set
         */
        [[nodiscard]] std::vector<point> sort();

        /**
         * Checks if the snake collides with itself
         * @return If the snake collides
         */
        [[nodiscard]] bool snake_collision() const noexcept;

        // --------------- MEMBER GETTER --------------- //

        [[nodiscard]] std::vector<point> get() const noexcept{ 
            return parts; 
        }
        
        [[nodiscard]] int size() const noexcept{ 
            return (int) parts.size(); 
        }

        [[nodiscard]] Direction get_direction() const noexcept{ 
            return direction; 
        }

        [[nodiscard]] point get_head() const noexcept{ return head; }
        
        /**
         * Operator[] override for direct part accessing
         */
        point operator[](const int pos) const{
            if(pos >= parts.size()){
                std::cout << "Illegal snake access";
                exit(1);
            }
            return parts[pos];
        }

    protected:
        // --------------- MEMBER VARIABLES --------------- //
    
        std::vector<point> parts;
        Direction direction;
        point head;
};
