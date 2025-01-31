#pragma once

#include <random>
#include <tuple>
#include <time.h>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

[[nodiscard]] static bool valid_dir(Direction direction, Direction new_direction) noexcept{
    return !(
            (direction == UP && new_direction == DOWN) ||
            (direction == DOWN && new_direction == UP) ||
            (direction == LEFT && new_direction == RIGHT) ||
            (direction == RIGHT && new_direction == LEFT)
    );
}

[[nodiscard]] static std::tuple<int, int> generate_random_position(const std::tuple<int, int>& size) noexcept{
    srand(time(0));

    int max_x = std::get<0>(size);
    int max_y = std::get<1>(size);

    int rand_x = rand() % max_x;
    int rand_y = rand() % max_y;

    return {rand_x, rand_y};
}
