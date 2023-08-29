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
                               const coordinates_t from, const coordinates_t to,
                               const piece_t* w_king,    const piece_t* b_king,
                               const int walk_color) const {//make struct move
    using namespace piece;
    if (is_empty (this)) {
        std::cout << "Impossible to make move: from is empty\n";
        return false;
    }
    if (walk_color != color) {
        std::cout << "Wrong color of piece to move\n";
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

    if (!can_move (cells, from, to)) {//exactly this piece rule
        return false;
    }
    if (is_check_set (cells, w_king, b_king, to)) {
        std::cout << "Check is set\n";
    }

    return true;

}

bool piece_t::is_check_set (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                            const piece_t* w_king, const piece_t* b_king,
                            const coordinates_t to)  const {
    const piece_t* def_king = w_king;
    if (color == WHITE) def_king = b_king;

    if (can_move (cells, to, def_king->coordinates)) {
        return true;
    }
    return false;
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
