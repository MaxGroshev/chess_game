#include "./ch_piece/ch_piece.h"
#include "ch_logs.h"
#include "ch_board.h"
#include "ch_engine.h"

int main () {
    //log_init ("./logs/board_dump");

    board_t test_board = board_t();
    test_board.dump ();
    start_game (test_board);
    //log_destr ();

    return 0;
}
