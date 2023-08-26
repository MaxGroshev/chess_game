#include "ch_board.h"

//-----------------------------------------------------------------------------------------

using namespace piece;
using std::cout;
using std::endl;

//-----------------------------------------------------------------------------------------

board_t::board_t () {
    for (short i = 0; i < SIZE_OF_BOARD; i++) {
        if (i > 1 && i < 6) {
            for (int j = 0; j < SIZE_OF_BOARD; j++) {
                cells[i][j].is_empty = true;
                cells[i][j].piece    = nullptr;
            }
        }
        else if (i == 6 || i == 1) { //TODO:make funcs
            short color = piece::WHITE;
            if (i == 6) color = piece::BLACK;
            coordinates_t coord = {0, 0};
            for (short j = 0; j < SIZE_OF_BOARD; j++) {
                coord = {i, j};
                cells[i][j].is_empty = false;
                cells[i][j].piece = new pawn_t (color, coord);
            }
        }
        else if (i >= 6 || i <= 1) {//Probably make variable naum of lines
            short color = piece::WHITE;
            if (i > 6) color = piece::BLACK;
            coordinates_t coord = {0, 0};
            for (short j = 0; j < SIZE_OF_BOARD; j++) {
                coord = {i, j};
                cells[i][j].is_empty = false;
                switch (j) { //TODO: make func
                    case 0:
                        cells[i][j].piece = new rook_t   (color, coord); break;
                    case 1:
                        cells[i][j].piece = new knight_t (color, coord); break;
                    case 2:
                        cells[i][j].piece = new bishop_t (color, coord); break;
                    case 3:
                        cells[i][j].piece = new king_t   (color, coord); break;
                    case 4:
                        cells[i][j].piece = new queen_t  (color, coord); break;
                    case 5:
                        cells[i][j].piece = new bishop_t (color, coord); break;
                    case 6:
                        cells[i][j].piece = new knight_t (color, coord); break;
                    case 7:
                        cells[i][j].piece = new rook_t   (color, coord); break;
                }
            }
        }
    }
}

board_t::~board_t () {
    cout << "want_to clear\n";
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            delete cells[i][j].piece;
        }
    }
}

//-----------------------------------------------------------------------------------------

int board_t::dump (const char* dump_file) {
    std::ofstream out_file;
    out_file.open (dump_file, std::ios_base::app);
    ASSERT (out_file.is_open ())

    out_file << std::endl << "----------Here is dump of board---------\n"
    << "print_time: "  << timestamp ()
    << "# - ERROR\n"
    << "----------------------------------------\n";
    display_pos (out_file); //didn't work but now work

    out_file.close ();
    return 0;
}
