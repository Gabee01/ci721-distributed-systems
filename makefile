CC=gcc
CFLAGS=-I.
FD_DEPS = vcube.h failure_detector.h cisj.h smpl.h rand.h logger.h
FD_OBJ = vcube.o failure_detector.o cisj.o smpl.o rand.o logger.o
BEB_DEPS = best_effort.h failure_detector.h smpl.h cisj.h logger.h
BEB_OBJ = best_effort.o failure_detector.o vcube.o cisj.o smpl.o rand.o logger.o

%.o: %.c $(FD_DEPS) $(BEB_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vcube: $(FD_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

best_effort: $(BEB_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) *.o vcube best_effort relat logs/*
