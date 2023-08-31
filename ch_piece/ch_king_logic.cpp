#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

king_t::king_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = KING;
    is_checked = false;
}

king_t::~king_t () {

}

//-----------------------------------------------------------------------------------------

bool king_t::can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    if (!((my_abs (to.x - from.x)) == 1)  || !((my_abs (to.y - from.y)) == 1)) {
        std::cout << "Wrong move for king\n";
        return false;
    }
    return true;
}

bool king_t::is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    return false;
}

//-----------------------------------------------------------------------------------------
