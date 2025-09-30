#pragma once

#include <random>
#include <tuple>
#include <ctime>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

[[nodiscard]] static bool valid_dir(const enum Direction direction, const enum Direction new_direction) noexcept{
    return !(
            (direction == UP && new_direction == DOWN) ||
            (direction == DOWN && new_direction == UP) ||
            (direction == LEFT && new_direction == RIGHT) ||
            (direction == RIGHT && new_direction == LEFT)
    );
}

[[nodiscard]] static std::tuple<int, int> next_head_pos(Direction direction, std::tuple<int, int> head){
    int x = (direction == RIGHT) ? std::get<0>(head) +1 : ( (direction == LEFT) ? std::get<0>(head)-1 : std::get<0>(head) );
    int y = (direction == UP) ? std::get<1>(head)-1 : ( (direction == DOWN) ? std::get<1>(head)+1 : std::get<1>(head) );
    return {x,y};
}

[[nodiscard]] static std::tuple<int, int> generate_random_position(const std::tuple<int, int>& size, std::mt19937& gen) noexcept{
    srand(time(nullptr));

    int max_x = std::get<0>(size);
    int max_y = std::get<1>(size);

    std::uniform_int_distribution<> dist_x(0, max_x-1);
    std::uniform_int_distribution<> dist_y(0, max_y-1);

    return {dist_x(gen), dist_y(gen)};
}
