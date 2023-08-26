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

bool queen_t::can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                        const coordinates_t from, const coordinates_t to) const {
    if (is_jump (cells, from, to)) return false;
    if (my_abs (to.x - from.x) == my_abs (to.y - from.y)) {
        return true;
    }
    else if ((from.x == to.x) || (from.y == to.y)) {
        return true;
    }
    std::cout << "Wrong move queen";
    return false;
}

bool queen_t::is_jump (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                        const coordinates_t from, const coordinates_t to) const {
    // bishop_t tmp_bishop ();
    // rook_t   tmp_rook ();
    // if (tmp_bishop.is_jump (cells, from, to) || tmp_rook.rook_t::is_jump (cells, from, to)) {
    //     return true;
    // }
    return false;
}

//-----------------------------------------------------------------------------------------
