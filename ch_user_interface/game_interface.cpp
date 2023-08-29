#include "user_interface.h"

//-----------------------------------------------------------------------------------------

int get_move (piece::coordinates_t*  from, piece::coordinates_t* to) {
    ASSERT (!(is_nullptr (from) || is_nullptr (to)))

    bool correct_input = false;
    while (!correct_input) { //TODO: make end of game condition
        std::cout << "Start of input\n";
        enter_move (from, to);
        if (is_correct_input (from, to)) {
            correct_input = true;
            convert_move (from, to);
        }
    }
    return 0;
}

int enter_move (piece::coordinates_t*  from, piece::coordinates_t* to) {
    scanf ("%c%hd : %c%hd", &(from->x), &(from->y), &(to->x), &(to->y));
    std::cin.get (); //to skip '\n'
    return 0;        //c++ version?
}

bool is_correct_input (const piece::coordinates_t* from, const piece::coordinates_t* to) {
    if (!((from->x >= 'a' && from->x <= 'h') && (to->x >= 'a' && to->x <= 'h'))) {
        std::cout << "Wrong input of x coordinate\n"; //may be make 'a'+size_of_board
        skip_wrong_input ();
        return false;
    }
    if (!((from->x >= 1 && from->y <= 8) && (to->y >= 1 && to->y <= 8))) {
        std::cout << "Wrong input of y coordinate\n";
        skip_wrong_input ();
        return false;
    }
    return true;
}

int convert_move (piece::coordinates_t*  from, piece::coordinates_t* to) {
    from->x -= 'a';
    to->x   -= 'a';
    from->y -= 1;
    to->y   -= 1;
    LOG_INFO ("The move is: ", from->x, from->y, " : ", to->x, to->y, '\n');
    return 0;
}

//-----------------------------------------------------------------------------------------

int skip_wrong_input () {
    while (std::cin.get () != '\n') {
        continue;
    }
    return 0;
}
