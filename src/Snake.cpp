#include "Snake.hpp"

// ------------------------------------------------------ //
// ---------------------- IMPORTS ----------------------- //
// ------------------------------------------------------ //

#include <algorithm>
#include <tuple>
#include <vector>
#include <set>


// ------------------------------------------------------ //
// ---------------------- METHODS ----------------------- //
// ------------------------------------------------------ //

void Snake::update(const bool is_new) noexcept{
    int x = (direction == RIGHT) ? parts[0].x +1 : ( (direction == LEFT) ? parts[0].x-1 : parts[0].x ); 
    int y = (direction == UP) ? parts[0].y-1 : ( (direction == DOWN) ? parts[0].y+1 : parts[0].y ); 
    parts.emplace(parts.begin(), x, y);
    this->head = point(x,y);
    if(!is_new){
        parts.pop_back();
    }
}

[[nodiscard]] std::vector<point> Snake::sort()
{
    std::vector<point> res = parts;

    std::sort(res.begin(), res.end(),
        [](const point& a, const point& b)
        {
            return std::tie(a.y, a.x) < std::tie(b.y, b.x);
        });

    return res;
}

[[nodiscard]] bool Snake::snake_collision() const noexcept{
    int x = (direction == RIGHT) ? parts[0].x +1 : ( (direction == LEFT) ? parts[0].x-1 : parts[0].x ); 
    int y = (direction == UP) ? parts[0].y-1 : ( (direction == DOWN) ? parts[0].y+1 : parts[0].y ); 
    return (parts.end() != std::find(parts.begin(), parts.end(), point(x,y)));
}