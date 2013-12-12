FLAGS = -O3 -std=c99
PROGDIR = progs

all : bf

bf : bf.c
	gcc $(FLAGS) -o bf bf.c

run : bf
	./bf $(PROGDIR)/hello.b

%.b : bf
	./bf $(PROGDIR)/$@

bftoc : bftoc.c
	gcc $(FLAGS) -o bftoc bftoc.c

clean :
	rm -rf *.o bf bftoc

