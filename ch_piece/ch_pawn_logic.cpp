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
    if ((from.x == to.x) && (color == WHITE) && (to.y - from.y == 1)) {
        return true;                  // because move to greater numbers
    }
    else if ((from.x == to.x) && (color == BLACK) && (from.y - to.y == 1)) {
        return true;                  // because move to less numbers
    }
    else if ((from.x == to.x) && (color == WHITE) && (from.y - to.y == 2) &&
             (from.y == 1)) {         //TODO: array with init positions
        return true;
    }
    else if ((from.x == to.x) && (color == BLACK) && (from.y - to.y == 2) &&
             (from.y == 6)) {
        return true;
    }
    else {
        std::cout << "Wrong pawn move\n";
    }
    return false;
}

//-----------------------------------------------------------------------------------------
