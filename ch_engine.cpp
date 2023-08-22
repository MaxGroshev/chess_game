#include "ch_engine.h"

//-----------------------------------------------------------------------------------------

int start_game (board_t  & board) {
    std::cerr << "Game is started\n";
    //init_of_players ();
    //...
    bool checkmate = false;
    short walking_color = piece::WHITE;
    piece::coordinates_t from = {0, 0};
    piece::coordinates_t to   = {0, 0};
    for (int num_of_move = 0; !checkmate; num_of_move) {
        if (num_of_move & 1) walking_color = piece::BLACK;
        else                 walking_color = piece::WHITE;

        std::cerr << "Go for move\n";
        get_move (&from, &to);
        if (board.is_allowed_move (from, to, walking_color)) {
            //? better pass classes or work with whole class
            board.change_piece_pos (&from, &to);
        }
        board.display_pos (std::cout);
        return 0;
    }
    return 0;
}

bool board_t::is_allowed_move ( const piece::coordinates_t from,
                const piece::coordinates_t to, const short walking_color) {//?move struct
    using namespace piece;
    if ((from.x == to.x) && (from.y == to.y)) {
        std::cout << "Wrong move: from == to";
        return false;
    }
//     if (is_check) {
//         if (cells[from.y][from.x].piece.get_name == KING && //?func
//             cells[from.y][from.x].piece.get_color== walking_color) {
//
//         }
//         else return false;
//     }
    // if (cells[to.y][to.x].is_empty || !cells[to.y][to.x].piece->is_ally ()) {
    //     std::cout << "Cell is not emty";
    //     return false;
    // }
    if (!cells[from.y][from.x].piece->can_move (from, to)) {//exactly this piece rule
        return false;
    }
    return true;
}

int board_t::change_piece_pos (const piece::coordinates_t* from,
                               const piece::coordinates_t* to) {
    cells[from->y][from->x].is_empty = true;
    cells[to->y][to->x].piece        = cells[from->y][from->x].piece;
    cells[from->y][from->x].piece    = nullptr;
    cells[to->y][to->x].is_empty     = false;

    return 0;
}

//-----------------------------------------------------------------------------------------

int get_move (piece::coordinates_t*  from, piece::coordinates_t* to) {
    if (is_nullptr (from) || is_nullptr (to)) {
        std::cout << "ERROR: nullptr\n";
        print_error_message (CUR_POS_IN_PROG);
    }

    bool correct_input = false;
    char x_from = '\0';
    char x_to   = '\0';
    short y_from= 0;
    short y_to  = 0;
    while (!correct_input) { //TODO: make end of game condition
        std::cout << "Start of input\n";
        scanf ("%c%hd : %c%hd", &x_from, &y_from, &x_to, &y_to);
        if (!((x_from >= 'a' && x_from <= 'h') && (x_to >= 'a' && x_to <= 'h'))) {
            std::cout << "Wrong input of x coordinate\n";
            continue;
        }
        if (!((y_from >= 1 && y_from <= 8) && (y_to >= 1 && y_to <= 8))) {
            std::cout << "Wrong input of y coordinate\n";
            continue;
        }
        correct_input = true;
        std::cout << x_from << y_from << " " << x_to << y_to << std::endl;
        from->x = short (x_from - 'a');
        from->y = y_from - 1;
        to->x   = short (x_to   - 'a');
        to->y   = y_to - 1;
        std::cout << from->x << from->y << " " << to->x << to->y << std::endl;
    }
    return 0;
} // 34 : 58