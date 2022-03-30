array_calc: array_calc.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf array_calc 

all: array_calc 