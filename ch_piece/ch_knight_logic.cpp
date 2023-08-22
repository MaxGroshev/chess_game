#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

knight_t::knight_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = KNIGHT;
}

knight_t::~knight_t () {

}

//-----------------------------------------------------------------------------------------

bool knight_t::can_move (const coordinates_t from,
                         const coordinates_t to) const {
        if (((my_abs (to.x - from.x) == 2) && (my_abs (to.y - from.y) == 1)) ||
            ((my_abs (to.y - from.y) == 2) && (my_abs (to.x - from.x) == 1))) {
        return true;
    }
    std::cout << "Wrong move for knight\n";
    return false;
}

//-----------------------------------------------------------------------------------------
