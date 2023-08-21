#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

piece_t::piece_t (short color_, coordinates_t coord_) {
    color = color_;
    coordinates = coord_;
}

piece_t::~piece_t () {

}

//-----------------------------------------------------------------------------------------

bool  piece_t::is_ally (const piece_t & piece) const {
    if (this.color != piece.color) return false;
    else                           return true;
}

//-----------------------------------------------------------------------------------------

int my_abs (int x) {
    if (x < 0 ) return -x;
    return x;
}
