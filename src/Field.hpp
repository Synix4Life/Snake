#pragma once

#include <algorithm>
#include <random>
#include <tuple>
#include <vector>

#include "Essentials.hpp"
#include "Snake.hpp"
#include "Global.h"

class Field{
    private:
        std::tuple<int, int> size;
        std::tuple<int, int> apple_pos;
        Snake snake;
        bool breakFlag = false;
        std::mt19937 gen;

        void set_apple();

        bool out_of_bounds(const std::tuple<int, int> pos) noexcept{
            return (std::get<0>(pos) < 0) || (std::get<0>(pos) >= std::get<0>(size)) || (std::get<1>(pos) < 0) || (std::get<1>(pos) >= std::get<1>(size));
        }

    public:
        Field(int size_x, int size_y): 
            size(size_x, size_y), 
            snake({1, 1}, RIGHT),
            gen(std::random_device{}())
        {
            apple_pos = generate_random_position(size, gen);
        }

        void check_and_set(Direction dir);

        [[nodiscard]] std::tuple<int, int> get_apple() const noexcept{
            return apple_pos;
        }

        int operator[](const int pos) const noexcept{
            return (pos==0) ? std::get<0>(size) : std::get<1>(size);
        }

        [[nodiscard]] Snake get_snake() const noexcept{
            return snake;
        }

        [[nodiscard]] bool flag() const noexcept{
            return breakFlag;
        }
};