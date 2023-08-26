#ifndef CH_LOGS_TPP
#define CH_LOGS_TPP

//-----------------------------------------------------------------------------------------

template <class... Args>
int ch_logs::write_logs (Args... log_text) {
    std::ostringstream log_data;
    (log_data << ... << log_text);
    ch_logs::put_in_file (log_data.str ());
    return 0;
}

#endif
