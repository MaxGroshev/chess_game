#include "ch_board.h"

//-----------------------------------------------------------------------------------------

using std::endl;
using std::cout;
using std::cin;

//-----------------------------------------------------------------------------------------

std::ostream & board_t::display_pos (std::ostream & os) {
    using namespace piece;
    for (int i = SIZE_OF_BOARD - 1; i >= 0; i--) {
        for (int j = 0; j < SIZE_OF_BOARD ; j++) {
            if (is_empty (cells, short (i), short (j))) os << " 0 ";
            else {
                switch (cells[i][j]->get_name ()) { //TODO: improve
                    case PAWN:
                        os << " * "; break;
                    case KNIGHT:
                        os << " % "; break;
                    case ROOK:
                        os << " ! "; break;
                    case BISHOP:
                        os << " @ "; break;
                    case KING:
                        os << " & "; break;
                    case QUEEN:
                        os << " $ "; break;
                    default:
                        os << " # "; break;
                }
            }
        }
        os << endl;
    }
    return os;
}

//-----------------------------------------------------------------------------------------
