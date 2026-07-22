#pragma once

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <random>
#include <tuple>
#include <ctime>


// ------------------------------------------------------ //
// ----------------------- ENUMS ------------------------ //
// ------------------------------------------------------ //

/**
 * Enum for the direction the snake is faceing
 */
enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};


// ------------------------------------------------------ //
// --------------------- STRUCTURES --------------------- //
// ------------------------------------------------------ //

/**
 * Defines a point in the grid
 */
struct point{
    int x;
    int y;

    point(): x(-1), y(-1) {}
    point(int x, int y): x(x), y(y) {}

    bool operator<(const point& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
    
    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }
};


// ------------------------------------------------------ //
// ---------------------- METHODS ----------------------- //
// ------------------------------------------------------ //

/**
 * Check if the new direction is valid
 * @param direction The original direction
 * @param new_direction If the new direction is valid regarding the old direction
 * @return If it is valid
 */
[[nodiscard]] static bool valid_dir(const enum Direction direction, const enum Direction new_direction) noexcept{
    return !(
            (direction == UP && new_direction == DOWN) ||
            (direction == DOWN && new_direction == UP) ||
            (direction == LEFT && new_direction == RIGHT) ||
            (direction == RIGHT && new_direction == LEFT)
    );
}


/**
 * Calculate the next head position
 * @param direction The direction the snake is facing
 * @param head The current head of the snake
 * @return The new head
 */
[[nodiscard]] static point next_head_pos(Direction direction, point head){
    int x = (direction == RIGHT) ? head.x+1 : ( (direction == LEFT) ? head.x-1 : head.x );
    int y = (direction == UP) ? head.y-1 : ( (direction == DOWN) ? head.y+1 : head.y );
    return point(x,y);
}


/**
 * Generate a random apple position
 * @param size Board size
 * @param gen The random number generator
 * @return The new apple position
 */
[[nodiscard]] static point generate_random_position(const std::tuple<int, int>& size, std::mt19937& gen) noexcept{
    srand(time(nullptr));

    int max_x = std::get<0>(size);
    int max_y = std::get<1>(size);

    std::uniform_int_distribution<> dist_x(0, max_x-1);
    std::uniform_int_distribution<> dist_y(0, max_y-1);

    return point(dist_x(gen), dist_y(gen));
}
