#ifndef CH_LOGS_H
#define CH_LOGS_H

//-----------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "./debug_utils/error_control.h"
#include "./ch_piece/ch_piece.h" //not neccessary


//-----------------------------------------------------------------------------------------

namespace ch_logs {
    int log_init   (const char* name_of_log_file);
    int log_destr  ();
    template <class... Args> int write_logs (Args... log_text);

    //#include "ch_logs.tpp"
}



#endif
