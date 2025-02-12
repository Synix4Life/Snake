#include "Snake.hpp"

#include <algorithm>
#include <tuple>
#include <vector>
#include <set>

void Snake::update(const bool is_new) noexcept{
    int x = (direction == RIGHT) ? std::get<0>(parts[0]) +1 : ( (direction == LEFT) ? std::get<0>(parts[0])-1 : std::get<0>(parts[0]) ); 
    int y = (direction == UP) ? std::get<1>(parts[0])-1 : ( (direction == DOWN) ? std::get<1>(parts[0])+1 : std::get<1>(parts[0]) ); 
    parts.emplace(parts.begin(), x, y);
    if(!is_new){
        parts.pop_back();
    }
}

[[nodiscard]] std::vector<std::tuple<int, int>> Snake::order(){           
    std::vector<std::tuple<int, int>> res;
    std::set<std::tuple<int, int>> seen;
    for (const std::tuple<int, int>& element : parts) {
            if (seen.find(element) != seen.end()) {
                continue;
            }
            seen.insert(element);                    
            bool inserted = false;

            for (size_t i = 0; i < res.size(); ++i) {
                if (std::get<1>(element) < std::get<1>(res[i])) {
                    res.insert(res.begin() + (int)i, element);
                    inserted = true;
                    break;
                }
                else if (std::get<1>(element) == std::get<1>(res[i])) {
                    if (std::get<0>(element) < std::get<0>(res[i])) {
                        res.insert(res.begin() + (int)i, element);
                        inserted = true;
                        break;
                    }
                    else if (i + 1 == res.size() || std::get<0>(element) < std::get<0>(res[i + 1])) {
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
    int x = (direction == RIGHT) ? std::get<0>(parts[0]) +1 : ( (direction == LEFT) ? std::get<0>(parts[0])-1 : std::get<0>(parts[0]) ); 
    int y = (direction == UP) ? std::get<1>(parts[0])-1 : ( (direction == DOWN) ? std::get<1>(parts[0])+1 : std::get<1>(parts[0]) ); 
    return (parts.end() != std::find(parts.begin(), parts.end(), std::make_tuple(x,y)));
}