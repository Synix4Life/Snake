#pragma once

/* ----- Global variables for game speed ----- */
inline int game_speed = 500;
inline int dynamic_speed = false;

inline void adjust_speed() noexcept{
    game_speed *= 0.98;
}
