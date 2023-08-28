#include "./ch_piece/ch_piece.h"
#include "./logs/ch_logs.h"
#include "ch_board.h"
#include "ch_engine.h"

int main () {
    ch_logs::log_init ("./logs/board_logs");
    board_t test_board = board_t ();
    test_board.dump ();
    start_game (test_board);
    ch_logs::log_destr ();
    test_board.dump ();
    return 0;
}
