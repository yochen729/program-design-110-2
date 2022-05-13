justify: justify.o word.o line.o
	clang -o justify justify.o word.o line.o
	 
justify.o: justify.c word.h line.h
	clang -c justify.c
	 
word.o: word.c word.h
	clang -c word.c
	 
line.o: line.c line.h
	clang -c line.c
