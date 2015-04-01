backtrace: main.c backtrace.c
	$(CC) $^ -o $@
clean:
	-rm backstrace -f
