APP = gts

CFLAGS = -lreadline

*.o:
		gcc -c *.c

$(APP): *.o
		gcc -o $@ *.o $(CFLAGS)

all:  $(APP)

clean:
		rm $(APP) *.o
	
