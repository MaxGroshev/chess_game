#ifndef CH_LOGS_H
#define CH_LOGS_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>

#include "../debug_utils/error_control.h"
//#include "../debug_utils/ASSERT.h"
#include "../ch_piece/ch_piece.h" //not neccessary

//-----------------------------------------------------------------------------------------

const int buf_size = 64;

//-----------------------------------------------------------------------------------------

namespace ch_logs {
    int log_init    (const char* name_of_log_file);
    int log_destr   ();
    int put_in_file (std::string log_str); //too slow: allocating
    template <class... Args> int write_logs (Args... log_text);

    #include "ch_logs.tpp"
}



#endif
