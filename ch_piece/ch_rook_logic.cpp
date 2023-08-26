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

bool rook_t::can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    if (((from.x == to.x) || (from.y == to.y)) && !is_jump (cells, from, to)) {
        return true;
    }
    std::cout << "wrong move for rook\n";
    return false;
}

bool rook_t::is_jump (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                      const coordinates_t from, const coordinates_t to) const {
    if (from.x == to.x) {
        if (from.y - to.y > 0) {
            for (int i = from.y - 1; i > to.y; i--) {
                if (cells[i][from.x] != nullptr) return true;
            }
        }
        else {
            for (int i = from.y + 1; i < to.y; i++) {
                if (cells[i][from.x] != nullptr) return true;
            }
        }
    }
    else if (from.y == to.y) {
        if (from.x - to.x > 0) {
            for (int i = from.x - 1; i > to.x; i--) {
                if (cells[from.y][i] != nullptr) return true;
            }
        }
        else {
            for (int i = from.x + 1; i < to.x; i++) {
                if (cells[from.y][i] != nullptr) return true;
            }
        }
    }
    return false;
}

//-----------------------------------------------------------------------------------------
