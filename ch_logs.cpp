#include "ch_logs.h"

//-----------------------------------------------------------------------------------------

static std::ofstream log_file;
using namespace ch_logs;

//-----------------------------------------------------------------------------------------

int ch_logs::log_init (const char* name_of_log_file) {
    log_file.open (name_of_log_file);
    if (!log_file.is_open ()) {
        std::cerr << "I feel sorry but log file is not opened\n";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    write_logs ("Start of writing logs\n");
    return 0;
}

int ch_logs::put_in_file (std::string log_str) { //std::string - bed descision
    if (!log_file.is_open ()) {
        std::cerr << "I feel sorry but log file is not opened\n";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    log_file << log_str;

    return 0;
}

int ch_logs::log_destr () {
    write_logs ("End of writing logs\n");
    log_file.close ();
    std::cout << "close\n";

    return 0;
}
