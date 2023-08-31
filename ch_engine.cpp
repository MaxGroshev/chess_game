#include "ch_engine.h"

//-----------------------------------------------------------------------------------------

int start_game (board_t & board) {
    LOG_INFO ("Game is started\n");
    //init_of_players ();
    //...
    bool checkmate   = false;
    short walk_color = piece::WHITE;
    piece::coordinates_t from = {0, 0};
    piece::coordinates_t to   = {0, 0};
    for (int num_of_move = 0; !checkmate; num_of_move) {
        walk_color = def_walk_color (num_of_move);
        get_move (&from, &to);
        if (board.cells[from.y][from.x]->is_allowed_move (board.cells, from,
                                                          to, board.w_king, board.b_king,
                                                          walk_color)) {
            board.cells[from.y][from.x]->change_piece_pos (board.cells, &from, &to);
            num_of_move++;
        }
        board.display_pos (std::cout);
        return 0;
    }
    return 0;
}

//-----------------------------------------------------------------------------------------

int def_walk_color (int num_of_move) {
    if (num_of_move & 1) return piece::BLACK;
    return piece::WHITE;
}

//-----------------------------------------------------------------------------------------

int piece::piece_t::change_piece_pos (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                    const piece::coordinates_t* from, const piece::coordinates_t* to) {
    if (!piece::is_empty (cells[to->y][to->x])) delete cells[to->y][to->x];//prob segfault
    cells[to->y][to->x] = this;
    cells[to->y][to->x]->coordinates = *to;
    cells[from->y][from->x] = nullptr;
    LOG_DEBUG ("Positions are changed after move\n");

    return 0;
}

//-----------------------------------------------------------------------------------------


