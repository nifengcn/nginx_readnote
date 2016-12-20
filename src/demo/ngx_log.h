#ifndef DEMO_NGX_LOG_H
#define DEMO_NGX_LOG_H

typedef struct ngx_log_s ngx_log_t;

typedef struct ngx_open_file_s ngx_open_file_t;

typedef struct {
	size_t len;
	u_char *data;
} ngx_str_t;

struct ngx_open_file_s {
	int fd;
	ngx_str_t name;

	void (*flush)(ngx_open_file_t *file, ngx_log_t *log);
	void *data;
};

typedef u_char *(*ngx_log_handler_pt) (ngx_log_t *log, u_char *buf, size_t len);
typedef void (*ngx_log_writer_pt) (ngx_log_t *log, ngx_uint_t level, u_char *buf, size_t len);

struct ngx_log_s {
	intptr_t log_level;
	ngx_open_file_t *file;

	ngx_atomic_uint_t connection; /*原子操作*/

	time_t disk_full_time;

	ngx_log_handler_pt handler;
	void *data;

	ngx_log_writer_pt writer;
	void *wdata;
	
	char *action;
	ngx_log_t *next;
};

#endif
