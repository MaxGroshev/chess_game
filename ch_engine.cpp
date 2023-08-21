#include "ch_engine.h"

//-----------------------------------------------------------------------------------------

int start_game (board_t board) {
    //init_of_players ();
    //...
    bool checkmate = false;
    short walking_color = piece::WHITE;
    piece::coordinates_t from = {0, 0};
    piece::coordinates_t to   = {0, 0};
    for (int num_of_move = 0; !checkmate; num_of_move) {
        if (num_of_move & 1) walking_color = piece::BLACK;
        else                 walking_color = piece::WHITE;

        //get_move ();
        if (is_allowed_move (board, from, to, walking_color)) { //? better pass classes or
                                                                //? work with whole class
            //change_figure_pos ();
        }

    }

}

bool is_allowed_move (const board_t & board, const piece::coordinates_t from,//?move struct
                      const piece::coordinates_t from, const short walking_color) {
    using namespace pieces;
    if (from == to) {
        cout << "Wrong move: from == to"
        return false;
    }
//     if (is_check) {
//         if (board.cells[from.y][from.x].piece.get_name == KING && //?func
//             board.cells[from.y][from.x].piece.get_color== walking_color) {
//
//         }
//         else return false;
//     }
    if (board.cells[to.y][to.x].is_emty || !board.cells[to.y][to.x].piece.is_allay) {
        cout << "Cell is not emty"
        return false;
    }
    if (!board.cells[from.y][from.x].pieces.can_move (from, to)) {//exactly this piece rule
        return false;
    }
    return true;
}


//-----------------------------------------------------------------------------------------
