#include "Snake.hpp"

#include <algorithm>
#include <tuple>
#include <vector>
#include <set>


// --------------- METHODS --------------- //

void Snake::update(const bool is_new) noexcept{
    int x = (direction == RIGHT) ? parts[0].x +1 : ( (direction == LEFT) ? parts[0].x-1 : parts[0].x ); 
    int y = (direction == UP) ? parts[0].y-1 : ( (direction == DOWN) ? parts[0].y+1 : parts[0].y ); 
    parts.emplace(parts.begin(), x, y);
    this->head = point(x,y);
    if(!is_new){
        parts.pop_back();
    }
}

[[nodiscard]] std::vector<point> Snake::order(){           
    std::vector<point> res;
    std::set<point> seen;
    for (const point& element : parts) {
            if (seen.find(element) != seen.end()) {
                continue;
            }
            seen.insert(element);                    
            bool inserted = false;

            for (size_t i = 0; i < res.size(); ++i) {
                if (element.y < res[i].y) {
                    res.insert(res.begin() + (int)i, element);
                    inserted = true;
                    break;
                }
                else if (element.y == res[i].y) {
                    if (element.x < res[i].x) {
                        res.insert(res.begin() + (int)i, element);
                        inserted = true;
                        break;
                    }
                    else if (i + 1 == res.size() || element.x < res[i + 1].x) {
                        res.insert(res.begin() + (int)i + 1, element);
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

[[nodiscard]] bool Snake::snake_collision() const noexcept{
    int x = (direction == RIGHT) ? parts[0].x +1 : ( (direction == LEFT) ? parts[0].x-1 : parts[0].x ); 
    int y = (direction == UP) ? parts[0].y-1 : ( (direction == DOWN) ? parts[0].y+1 : parts[0].y ); 
    return (parts.end() != std::find(parts.begin(), parts.end(), point(x,y)));
}