#pragma once

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <algorithm>
#include <random>
#include <tuple>
#include <vector>

#include "Essentials.hpp"
#include "Snake.hpp"


// ------------------------------------------------------ //
// ---------------------- CLASSES ----------------------- //
// ------------------------------------------------------ //

class Field{
    public:
        // --------------- CONSTRUCTOR --------------- //

        /**
         * Constructor
         * @param size_x Board width
         * @param size_y Board height
         * @param pos_x Start x value
         * @param pos_y Start y value
         */
        Field(int size_x, int size_y, int pos_x, int pos_y): 
            size(size_x, size_y), 
            snake(pos_x, pos_y, RIGHT),
            gen(std::random_device{}())
        {
            apple_pos = generate_random_position(size, gen);
        }

        // --------------- METHODS --------------- //

        /**
         * The global checker and setter, which processes new positions, apple positions...
         * @param dir New direction
         */
        int check_and_set(Direction dir);

        // --------------- MEMBER GETTER --------------- //

        [[nodiscard]] point get_apple() const noexcept{ return apple_pos; }

        int operator[](const int pos) const noexcept{
            return (pos==0) ? std::get<0>(size) : std::get<1>(size);
        }

        [[nodiscard]] Snake get_snake() const noexcept{ return snake; }
    
    protected:
        // --------------- MEMBER VARIABLES --------------- //

        Snake snake;
        std::tuple<int, int> size;
        point apple_pos;
        std::mt19937 gen;

    private:
        // --------------- METHODS --------------- //

        /**
         * Set the apple
         */
        void set_apple();

        /**
         * Check if the position is out of bounds
         * @param pos The point
         * @return If it is out of bounds
         */
        bool out_of_bounds(const point pos) noexcept{
            return (pos.x < 0) || (pos.x >= std::get<0>(size)) || (pos.y < 0) || (pos.y >= std::get<1>(size));
        }

};