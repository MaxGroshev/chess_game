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
//#include "ch_player.h"

//-----------------------------------------------------------------------------------------

int log_init   (const char* log_file);
int write_logs (const char* log_text);
int log_destr  ();

#endif
