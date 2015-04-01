#include <stdio.h>
#include <stdlib.h>

extern void debug_trace_init(void);

int main(void)
{
	debug_trace_init();
	while(1);

	return 0;
}
