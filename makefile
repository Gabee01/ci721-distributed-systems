all: vcube

vcube: vcube.o cisj.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic vcube.o smpl.o cisj.o rand.o -lm -v

smpl.o: smpl.c smpl.h
	$(COMPILE.c) -g smpl.c

cisj.o: cisj.c cisj.h
	$(COMPILE.c) -g cisj.c

vcube.o: vcube.c smpl.h cisj.h
	$(COMPILE.c) -g  vcube.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o vcube relat saida

