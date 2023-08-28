#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "../debug_utils/error_control.h"
#include "../ch_piece/ch_piece.h"
#include "../logs/ch_logs.h"

//-----------------------------------------------------------------------------------------

int get_move (piece::coordinates_t*  from, piece::coordinates_t* to);

//-----------------------------------------------------------------------------------------

#endif
