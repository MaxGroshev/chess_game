#include "user_interface.h"

//-----------------------------------------------------------------------------------------

int get_move (piece::coordinates_t*  from, piece::coordinates_t* to) {
    ASSERT (!(is_nullptr (from) || is_nullptr (to)))

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
        ch_logs::write_logs ("The move is: ", x_from, y_from, " : ", x_to, y_to, '\n');
    }
    return 0;
}
