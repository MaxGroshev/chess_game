#include "ch_logs.h"

//-----------------------------------------------------------------------------------------

static std::ofstream log_file;
using namespace ch_logs;

//-----------------------------------------------------------------------------------------

int ch_logs::log_init (const char* name_of_log_file) {
    log_file.open (name_of_log_file);
    ASSERT (log_file.is_open ());
    write_logs ("Start of writing logs\n\n");
    return 0;
}

int ch_logs::put_in_file (std::string log_str) { //std::string - bed descision
    ASSERT (log_file.is_open ());
    log_file << log_str;
    return 0;
}

int ch_logs::log_destr () {
    write_logs ("\nEnd of writing logs\n");
    log_file.close ();
    return 0;
}
