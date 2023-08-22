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
    if (my_abs (to.x - from.x) == my_abs (to.y - from.y)) {
        return true;
    }
    else if ((from.x == to.x) || (from.y == to.y)) {
        return true;
    }
    std::cout << "Wrong move queen";
    return false;
}

//-----------------------------------------------------------------------------------------
