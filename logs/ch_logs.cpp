#include "ch_logs.h"

//-----------------------------------------------------------------------------------------

static std::ofstream log_file;
using namespace ch_logs;

//-----------------------------------------------------------------------------------------

int ch_logs::log_init (const char* name_of_log_file) {
    log_file.open (name_of_log_file);
    ASSERT (log_file.is_open ());
    write_logs (timestamp (), "Start of writing logs\n\n");
    return 0;
}

int ch_logs::put_in_file (const char* log_text) {
    ASSERT (log_file.is_open ());
    log_file << log_text;
    return 0;
}

int ch_logs::log_destr () {
    write_logs ('\n', timestamp (), "End of writing logs\n");
    log_file.close ();
    return 0;
}
