#pragma once



// --------- Global Game-Speed ---------- //

inline int game_speed = 500;
inline int dynamic_speed = false;

/**
 * Method to adjust the game speed
 */
inline void adjust_speed() noexcept{
    game_speed *= 0.98;
}
