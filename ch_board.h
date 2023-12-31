#ifndef BOARD_H
#define BOARD_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "./debug_utils/error_control.h"
#include "./ch_piece/ch_piece.h" //not neccessary
#include "./logs/ch_logs.h"

//-----------------------------------------------------------------------------------------

//namespace board {
class board_t {
    friend class piece::piece_t;
    private:
        piece::piece_t* cells[SIZE_OF_BOARD][SIZE_OF_BOARD];
        piece::king_t* w_king;
        piece::king_t* b_king;
    public:
        //constructor & destructor
        explicit board_t ();
        virtual ~board_t ();
        //TODO: int init_pawns   ();
        //others methods
        bool is_empty (piece::piece_t* (&cell)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       short i, short j);
        // int  change_piece_pos (const piece::coordinates_t* from,
        //                        const piece::coordinates_t* to);
        int  dump      (const char* dump_file = "./logs/board_dump");
        std::ostream & display_pos (std::ostream & os);
        //friends methods
        friend int start_game (board_t & board);
};
//}

//-----------------------------------------------------------------------------------------

#endif
