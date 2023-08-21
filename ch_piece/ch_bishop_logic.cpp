#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

bishop_t::bishop_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = BISHOP;
}

bishop_t::~bishop_t () {

}

//-----------------------------------------------------------------------------------------

bool bishop_t::can_move (const coordinates_t from,
                         const coordinates_t to) const {
    if (!(my_abs (to.x - from.x) == my_abs (to.y - from.y)) {
        cout << "Wrong move for bishop"
        return false;
    }
    return false;
}

//-----------------------------------------------------------------------------------------
