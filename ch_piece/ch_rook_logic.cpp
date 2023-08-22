#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

rook_t::rook_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = ROOK;
}

rook_t::~rook_t () {

}

//-----------------------------------------------------------------------------------------

bool rook_t::can_move (const coordinates_t from,
                       const coordinates_t to) const {
    if ((from.x == to.x) || (from.y == to.y)) {
        return true;
    }
    std::cout << "wrong move for rook\n";
    return false;
}

//-----------------------------------------------------------------------------------------
