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

bool bishop_t::can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                         const coordinates_t from, const coordinates_t to) const {
    if (!(my_abs (to.x - from.x) == my_abs (to.y - from.y))) {
        std::cout << "Wrong move for bishop\n";
        return false;
    }
    if (is_jump (cells, from, to)) return false;
    return true;
}

bool bishop_t::is_jump (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    if (from.x - to.x > 0) {
        if (to.y - from.y < 0) {
            for (int i = 1; i < from.x - to.x; i++) {
                if (cells[from.y + i][from.x - i] != nullptr) return true;
            }
        }
        else {
            for (int i = 1; i < from.x - to.x; i++) {
                if (cells[from.y - i][from.x - i] != nullptr) return true;
            }
        }
    }
    else if (from.x - to.x < 0) {
        if (to.y - from.y < 0) {
            for (int i = 1; i < from.x - to.x; i++) {
                if (cells[from.y + i][from.x + i] != nullptr) return true;
            }
        }
        else {
            for (int i = 1; i < from.x - to.x; i++) {
                if (cells[from.y - i][from.x + i] != nullptr) return true;
            }
        }
    }
    return false;
}

//-----------------------------------------------------------------------------------------
