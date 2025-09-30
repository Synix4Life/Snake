#pragma once

/* ----- Global variables for game speed ----- */
static int game_speed = 500;
static int dynamic_speed = false;

static void adjust_speed() noexcept{
    game_speed *= 0.98;
}