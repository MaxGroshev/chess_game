#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

pawn_t::pawn_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = PAWN;
}

pawn_t::~pawn_t () {

}

//-----------------------------------------------------------------------------------------

bool pawn_t::can_move (const coordinates_t from,
                       const coordinates_t to) const {
    if (!((from.y == to.y))){ // not finished
        cout << "Wrong move for pawn";
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------------------
