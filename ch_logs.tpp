#ifndef CH_LOGS_TPP
#define CH_LOGS_TPP

//-----------------------------------------------------------------------------------------

template <class... Args>
int ch_logs::write_logs (Args... log_text) {
    if (!log_file.is_open ()) {
        std::cerr << "I feel sorry but log file is not opened\n";
        print_error_message (CUR_POS_IN_PROG);
        return -1;
    }
    (log_file << ... << log_text);
    return 0;
}

#endif
