#include "ch_piece.h"
using namespace piece;

//-----------------------------------------------------------------------------------------

bool coordinates_t::operator== (const coordinates_t & coord) const {
    if (x == coord.x && y == coord.y) return true;
    return false;
}
