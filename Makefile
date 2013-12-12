FLAGS = -O3 -std=c99
CFILES = bf.c
PROGDIR = progs

all : bf

bf : $(CFILES)
	gcc $(FLAGS) -o bf $(CFILES)

run : bf
	./bf $(PROGDIR)/hello.b

%.b : bf
	./bf $(PROGDIR)/$@

clean :
	rm -rf *.o bf

