#include "fstream"

static std::ofstream log_file;

#include "ch_logs.h"
#include "ch_logs.tpp"

//-----------------------------------------------------------------------------------------

using namespace ch_logs;

//-----------------------------------------------------------------------------------------

int ch_logs::log_init (const char* name_of_log_file) {
    log_file.open (name_of_log_file);
    if (!log_file.is_open ()) {
        std::cerr << "I feel sorry but log file is not opened\n";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    write_logs ("Start of writing logs\n", 56);
    return 0;
}

int ch_logs::log_destr () {
    write_logs ("End of writing logs\n", 56);
    log_file.close ();
    std::cout << "close\n";

    return 0;
}
