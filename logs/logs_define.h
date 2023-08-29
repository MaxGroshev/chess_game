#if defined(DEBUG)
#define LOG_DEBUG(args...)              \
            ch_logs::write_logs (args); \

#else
#define LOG_DEBUG(args...);
#endif

//-----------------------------------------------------------------------------------------

#if defined(CH_LOG_STR)
#define LOG_STR(str)                    \
            ch_logs::put_in_file (str); \

#else
#define LOG_STR(str);
#endif

//-----------------------------------------------------------------------------------------

#if defined(CH_LOG_INFO)
#define LOG_INFO(args...)               \
            ch_logs::write_logs (args); \

#else
#define LOG_INFO(args...);
#endif

//-----------------------------------------------------------------------------------------
