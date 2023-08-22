#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "../debug_utils/error_control.h"

//-----------------------------------------------------------------------------------------

namespace piece {

static const short INIT_NUM_OF_PIECES = 16;
static const short INIT_NUM_OF_PAWNS  = 8;
static const short INIT_NUM_OF_KNIGHTS= 2;
static const short INIT_NUM_OF_BISHOPS= 2;
static const short INIT_NUM_OF_ROOKS  = 2;
static const short INIT_NUM_OF_QUEENS = 1;
static const short INIT_NUM_OF_KING   = 1;

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
    short x;        //TODO: later make letters for x axis
    short y;
};

class piece_t {
    protected:
        bool  is_alive;
        short color;
        short name;
        coordinates_t coordinates;
    public:
        //constructor & destructor
        explicit piece_t (short color_, coordinates_t coord_);
        virtual ~piece_t ();
        //get_piece_data methods
        inline short         get_color () const {return color;};
        inline short         get_name  () const {return name;};
        inline coordinates_t get_pos   () const {return coordinates;};
        inline short         get_x     () const {return coordinates.x;};
        inline short         get_y     () const {return coordinates.y;};
        //condition methods
        bool                 is_ally   (const piece_t & piece) const;
        //virtual methods
        virtual bool can_move (const coordinates_t from,
                               const coordinates_t to) const = 0;

        //others methods
};


#include "ch_piece_logic.h"

}

//-----------------------------------------------------------------------------------------

int my_abs (int x); //make polymorf

//-----------------------------------------------------------------------------------------

#endif
