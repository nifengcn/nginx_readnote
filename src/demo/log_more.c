#include <stdio.h>
#include <stdarg.h>

/*
#define REC_WARNING(fmt, arg...) do {\
	ul_writelog(UL_LOG_WARNING, "[%s:%s:%d:qid[%lx]:" fmt, __FILE__,__FUNCTION__, __LINE__,thread_queryid, ##arg);\
} while (0)
*/

void ngx_log_error_core(FILE *log, int err,
    const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf("\n");
}

#define ngx_log_debug(log, ...)                                        \
        ngx_log_error_core(log, __VA_ARGS__)

int main() {
	printf("hello world\n");
	ngx_log_error_core(stdout, 0, "%s#%s", "hello", "haha");
	ngx_log_debug(stdout, 0, "%s#%s", "hello", "haha");
	return 0;
}
