#include "ch_engine.h"

//-----------------------------------------------------------------------------------------

int start_game (board_t & board) {
    ch_logs::write_logs ("Game is started\n");
    //init_of_players ();
    //...
    bool checkmate = false;
    short walking_color = piece::WHITE;
    piece::coordinates_t from = {0, 0};
    piece::coordinates_t to   = {0, 0};
    for (int num_of_move = 0; !checkmate; num_of_move) {
        if (num_of_move & 1) walking_color = piece::BLACK;
        else                 walking_color = piece::WHITE;

        get_move (&from, &to);
        if (board.cells[from.y][from.x]->is_allowed_move (board.cells, from, to)) {
            board.change_piece_pos (&from, &to);
        }
        board.display_pos (std::cout);
        return 0;
    }
    return 0;
}

//-----------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------

int board_t::change_piece_pos (const piece::coordinates_t* from,
                               const piece::coordinates_t* to) {
    if (board_t::is_empty (cells, to->y, to->x)) delete cells[to->y][to->x];
    cells[to->y][to->x]     = cells[from->y][from->x];
    cells[from->y][from->x] = nullptr;
    ch_logs::write_logs ("Positions are changed after move\n");

    return 0;
}

//-----------------------------------------------------------------------------------------


