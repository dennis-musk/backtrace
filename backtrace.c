#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>

#define TRACE_SIZE 1024

static void trace_print(int signal_type)
{
	int trace_id = -1;
	int i = 0;
	void *buffer[100];
	char **info = NULL;
	char trace_buff[TRACE_SIZE];

	trace_id = backtrace(buffer, TRACE_SIZE);

	info = backtrace_symbols(buffer, trace_id);
	if (NULL == info){
		return;
	}

	for (i = 0; i < trace_id; i++) {
		sprintf(trace_buff, "echo \"%s\" >> ./trace_info_%d.txt", info[i], signal_type);
		system(trace_buff);
	}

	sprintf(trace_buff, "echo \"###################################\" >> ./trace_info_%d.txt", signal_type);
	system(trace_buff);
}

static void signal_hadle_fun(int signal_type)
{
	switch(signal_type) {
	case SIGHUP:
	case SIGINT:
	case SIGQUIT:
	case SIGILL:
	case SIGTRAP:

	case SIGABRT:
	case SIGBUS:
	case SIGFPE:
	case SIGKILL:
	case SIGSEGV:

	case SIGPIPE:
	case SIGTERM:
		trace_print(signal_type);
		exit(0);
		break;
	}
}

void debug_trace_init(void)
{
	signal(SIGHUP, signal_hadle_fun);
	signal(SIGINT, signal_hadle_fun);
	signal(SIGQUIT, signal_hadle_fun);
	signal(SIGILL, signal_hadle_fun);
	signal(SIGTRAP, signal_hadle_fun);

	signal(SIGABRT, signal_hadle_fun);
	signal(SIGBUS, signal_hadle_fun);
	signal(SIGFPE, signal_hadle_fun);
	signal(SIGKILL, signal_hadle_fun);
	signal(SIGSEGV, signal_hadle_fun);

	signal(SIGPIPE, signal_hadle_fun);
	signal(SIGTERM, signal_hadle_fun);
}

