CC=gcc
CFLAGS=-I.
FD_DEPS = vcube.h failure_detector.h cisj.h smpl.h rand.h logger.h
FD_OBJ = vcube.o failure_detector.o cisj.o smpl.o rand.o logger.o
BC_DEPS = broadcast.h best_effort.h failure_detector.h cisj.h smpl.h logger.h
BC_OBJ = broadcast.o best_effort.o failure_detector.o cisj.o smpl.o rand.o logger.o

%.o: %.c $(FD_DEPS) $(BC_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vcube: $(FD_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

broadcast: $(BC_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) *.o vcube best_effort relat logs/* 
	$(RM) -r cmake-build-debug
