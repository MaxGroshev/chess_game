#include "ch_player.h"

//-----------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------

player_t::player_t (short color_, std::string player_name_) {

    //TODO:make flag (if double color init)

    player_name = player_name_;
    color       = color_;
    num_of_pieces = INIT_NUM_OF_PIECES;
    num_of_pawns  = INIT_NUM_OF_PAWNS;
    num_of_knights= INIT_NUM_OF_KNIGHTS;
    num_of_bishops= INIT_NUM_OF_BISHOPS;
    num_of_rooks  = INIT_NUM_OF_ROOKS;
    num_of_queen  = INIT_NUM_OF_QUEENS;

    pieces = (piece::piece_t*) calloc (INIT_NUM_OF_PIECES, sizeof (piece::piece_t));
    // if (color_ == piece::WHITE) {
    //     piece::coordinates_t coord = {0,0};
    //     for (int i = 1; i <= piece::INIT_NUM_OF_PIECES; i++) {
    //         pieces[i - 1] = piece::piece_t (color_, )
    //     }
    // }
}

player_t::~player_t () {
    delete [] pieces;
}

//-----------------------------------------------------------------------------------------

int player_t::player_dump (const char* dump_file) {
    std::ofstream out_file;
    out_file.open (dump_file, std::ios_base::app);
//     if (!out_file.is_open ()) {
//         std::cout << "I feel sorry but out file is not opened";
//         print_error_message (CUR_POS_IN_PROG);
//         return -1;
//     }
//
//     clock_t now = time (NULL);
//     this->current_time = ctime (&now);
//
//     out_file << std::endl << "----------Here is dump of pieces---------\n"
//     << "color of pieces = " << color << endl
//     << "count of pieces = " << piece_color << endl
//     << "print_time: "  << this->current_time
//     << "--------------------------------------\n";


    out_file.close ();

    return 0;
}
