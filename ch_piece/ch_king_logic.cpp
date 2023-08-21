#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

king_t::king_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = KING;
}

king_t::~king_t () {

}

//-----------------------------------------------------------------------------------------

bool king_t::can_move (const coordinates_t from,
                       const coordinates_t to) const {
    if (!((my_abs (to.x - from.x)) == 1)  || !((my_abs (to.y - from.y)) == 1)) {
        cout << "Wrong move for king";
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------------------
