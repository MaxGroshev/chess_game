#ifndef PLAYER_H
#define PLAYER_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "./debug_utils/error_control.h"
#include "./ch_piece/ch_piece.h"

//-----------------------------------------------------------------------------------------

//namespace piece {

enum color_of_player {
    WHITE = 0,
    BLACK = 1,
};

class player_t {
    private:
        std::string player_name;
        short num_of_pieces;
        short num_of_pawns;
        short num_of_knights;
        short num_of_bishops;
        short num_of_rooks;
        short num_of_queen;
        short color;
        piece::piece_t* pieces; //probably it will be array of basic class
                                //and different pieces are differrent legacy classes
    public:
        //constructor & destructor
        player_t  (short color_, std::string player_name_ = "Player");
        ~player_t ();
        //others methods
        int player_dump (const char* dump_file = "./logs/dump_file");

};


//}

//-----------------------------------------------------------------------------------------

#endif
