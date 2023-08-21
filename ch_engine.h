#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "./debug_utils/error_control.h"
#include "./ch_piece/ch_piece.h" //not neccessary
#include "ch_player.h" //probably init of players should be there
#include "ch_board.h"

//-----------------------------------------------------------------------------------------

int start_game (board_t board);

#endif
