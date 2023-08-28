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

bool piece_t::is_allowed_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                      const coordinates_t from, const coordinates_t to) const {
    using namespace piece;
    if (is_empty (this)) {
        std::cout << "Impossible to make move: from is empty\n";
        return false;
    }
    if (from == to) {
        std::cout << "Wrong move: from == to\n";
        return false;
    }
    if (is_ally_attac (cells[to.y][to.x])) {
        std::cout << "Ally attac is impossible\n";
        return false;
    }
//     if (is_check) {
//         if (cells[from.y][from.x].piece.get_name == KING && //?func
//             cells[from.y][from.x].piece.get_color== walking_color) {
//
//         }
//         else return false;
//     }

    if (can_move (cells, from, to)) {//exactly this piece rule
        return false;
    }
    return true;

}

bool piece_t::is_ally_attac (const piece_t* piece) const {
    if (!is_empty (piece) && color == piece->color) return true;
    return false;
}

bool piece::is_empty (const piece_t* piece) {
    if (piece == nullptr) return true;
    return false;
}

//-----------------------------------------------------------------------------------------

int my_abs (int x) {
    if (x < 0 ) return -x;
    return x;
}
