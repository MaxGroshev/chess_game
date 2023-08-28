#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "../ch_game_const/game_consts.h"
#include "../debug_utils/error_control.h"

//-----------------------------------------------------------------------------------------

namespace piece {

enum name_of_piece {
    PAWN   = 0,
    KNIGHT = 1,
    BISHOP = 2,
    ROOK   = 3,
    QUEEN  = 4,
    KING   = 5,
};

enum color_of_piece {
    WHITE = 0,
    BLACK = 1,
};

struct coordinates_t {
    short x;
    short y;

    bool operator== (const coordinates_t & coord) const;
};

class piece_t {
    protected:
        bool  is_alive;
        short color;
        short name;
        coordinates_t coordinates;

    public:
        //constructor & destructor
        explicit piece_t (short color_ = -1, coordinates_t coord_ = {-1,-1});
        virtual ~piece_t ();
        //get_piece_data methods
        inline short         get_color () const {return color;};
        inline short         get_name  () const {return name;};
        inline coordinates_t get_pos   () const {return coordinates;};
        inline short         get_x     () const {return coordinates.x;};
        inline short         get_y     () const {return coordinates.y;};
        //condition methods
        bool is_ally_attac    (const piece_t* piece) const;
        bool is_allowed_move  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                               const coordinates_t from, const coordinates_t to) const;
        //virtual methods
        virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                               const coordinates_t from, const coordinates_t to) const = 0;
        virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                               const coordinates_t from, const coordinates_t to) const = 0;
        //friends methods
};

#include "ch_piece_logic.h"
    bool is_empty  (const piece_t* piece); //does not work in class
}

//-----------------------------------------------------------------------------------------


int my_abs (int x); //make polymorf

//-----------------------------------------------------------------------------------------

#endif
