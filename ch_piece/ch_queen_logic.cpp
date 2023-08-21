#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

queen_t::queen_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = QUEEN;
}

queen_t::~queen_t () {

}

//-----------------------------------------------------------------------------------------

bool queen_t::can_move (const coordinates_t from,
                        const coordinates_t to) const {
    return true;
}

//-----------------------------------------------------------------------------------------
