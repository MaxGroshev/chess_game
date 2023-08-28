#include "ch_piece.h"

//-----------------------------------------------------------------------------------------

using namespace piece;

//-----------------------------------------------------------------------------------------

pawn_t::pawn_t (short color_, coordinates_t coord_) : piece_t  (color_, coord_) {
    name = PAWN;
}

pawn_t::~pawn_t () {

}

//-----------------------------------------------------------------------------------------

bool pawn_t::can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    //if (is_jump (cells, from, to)) return false; //move down others checks

    if ((from.x == to.x) && (color == WHITE) && (to.y - from.y == 1)) {
        return true;                  // because move to greater numbers
    }
    else if ((from.x == to.x) && (color == BLACK) && (from.y - to.y == 1)) {
        return true;                  // because move to less numbers
    }
    else if ((from.x == to.x) && (color == WHITE) && (to.y - from.y == 2) &&
             (from.y == 1) && !(is_jump (cells, from, to))) { //TODO: array with init positions
        return true;
    }
    else if ((from.x == to.x) && (color == BLACK) && (from.y - to.y == 2) &&
             (from.y == 6) && !(is_jump (cells, from, to))) {
        return true;
    }
    std::cout << "Wrong pawn move\n";
    return false;
}

bool pawn_t::is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                       const coordinates_t from, const coordinates_t to) const {
    if (color == WHITE && cells[from.y + 1][from.x] != nullptr) {
        return true;
    }
    else if (color == BLACK && cells[from.y - 1][from.x] != nullptr) {
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------------------
