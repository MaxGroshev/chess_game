#ifndef BOARD_H
#define BOARD_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "./debug_utils/error_control.h"
#include "ch_piece.h" //not neccessary
#include "ch_player.h"

//-----------------------------------------------------------------------------------------

//namespace piece {

static const short SIZE_OF_BOARD = 8;
static const short NUM_OF_CELLS = SIZE_OF_BOARD * SIZE_OF_BOARD;

// enum color_of_ {
//     WHITE = 0,
//     BLACK = 1,
// };

class board_t {
    private:
        struct cell_t {
            bool is_empty;
            piece::piece_t* piece;
        };
        cell_t cells[SIZE_OF_BOARD][SIZE_OF_BOARD]; //don't know: array or pointer

    public:
        //constructor & destructor
        explicit board_t ();
        virtual ~board_t ();
        int init_pawns   (); //TODO:
        //others methods
        int dump (const char* dump_file = "./logs/board_dump");
};


//}

//-----------------------------------------------------------------------------------------

#endif
