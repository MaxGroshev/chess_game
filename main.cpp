#include "./ch_piece/ch_piece.h"
#include "./logs/ch_logs.h"
#include "ch_board.h"
#include "ch_engine.h"

int main () {
    ch_logs::log_init ("./logs/board_logs");
    //if (!ch_logs::log_file.is_open ()) {std::cout << "erroe\n";}
    board_t test_board = board_t();
    test_board.dump ();
    start_game (test_board);
    ch_logs::log_destr ();

    return 0;
}
