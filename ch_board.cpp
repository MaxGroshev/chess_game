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
                cells[i][j].piece = new piece_t (color, PAWN, coord);
            }
        }
        else if (i >= 6 || i <= 1) {//Probably make variable naum of lines
            short color = piece::WHITE;
            if (i > 6) color = piece::BLACK;
            coordinates_t coord = {0, 0};
            for (short j = 0; j < SIZE_OF_BOARD; j++) {
                    coord = {i, j};
                    cells[i][j].is_empty = false;
                    switch (j) { //TODO: improve
                        case 0:
                            cells[i][j].piece = new piece_t (color, ROOK, coord); break;
                        case 1:
                            cells[i][j].piece = new piece_t (color, KNIGHT, coord); break;
                        case 2:
                            cells[i][j].piece = new piece_t (color, BISHOP, coord); break;
                        case 3:
                            cells[i][j].piece = new piece_t (color, KING, coord); break;
                        case 4:
                            cells[i][j].piece = new piece_t (color, QUEEN, coord); break;
                        case 5:
                            cells[i][j].piece = new piece_t (color, BISHOP, coord); break;
                        case 6:
                            cells[i][j].piece = new piece_t (color, KNIGHT, coord); break;
                        case 7:
                            cells[i][j].piece = new piece_t (color, ROOK, coord); break;
                    }
                }
        }
    }
}

board_t::~board_t () {
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
    if (!out_file.is_open ()) {
        std::cout << "I feel sorry but out file is not opened";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }

    clock_t now = time (NULL);
    char* current_time = ctime (&now);

    out_file << std::endl << "----------Here is dump of board---------\n"
    << "print_time: "  << current_time
    << "# - ERROR\n"
    << "----------------------------------------\n";
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            if (cells[i][j].is_empty) out_file << " 0 ";
            else {
                switch (cells[i][j].piece->get_name ()) { //TODO: improve
                    case PAWN:
                        out_file << " * "; break;
                    case KNIGHT:
                        out_file << " % "; break;
                    case ROOK:
                        out_file << " ! "; break;
                    case BISHOP:
                        out_file << " @ "; break;
                    case KING:
                        out_file << " & "; break;
                    case QUEEN:
                        out_file << " $ "; break;
                    default:
                        out_file << " # "; break;
                }
            }
        }
        out_file << endl;
    }

    out_file.close ();
    return 0;
}
