#include "ch_logs.h"

//-----------------------------------------------------------------------------------------

static std::ofstream out_file;

//-----------------------------------------------------------------------------------------

int log_init (const char* log_file) {
    out_file.open (log_file);
    if (!out_file.is_open ()) {
        std::cout << "I feel sorry but out file is not opened";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    return 0;
}

int write_logs (const char* log_text) {
    if (!out_file.is_open ()) {
        std::cout << "I feel sorry but out file is not opened";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    out_file << log_text;

    return 0;
}

int log_destr () {
    out_file << "End of writing logs\n";
    out_file.close ();
}
