greet-with-errors:
	gcc -o ~/bin/greet-with-errors src/greet-with-errors.c

copy:
	gcc -o ~/bin/copy src/copy.c

clean:
	rm foo bar ~/bin/*
