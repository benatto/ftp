CC     = gcc
LD     = gcc
CFLGAS = -Wall -O2 -g
OBJS   = main.o
FSHELL_OBJS = shell/fshell.o

.c.o:
	$(CC) -c $(CFLAGS) -o $*.o $<

all: ftp

ftp: $(OBJS) $(FSHELL_OBJS)
	$(LD) -o $@ $(OBJS) $(FSHELL_OBJS) $(LIBS)

clean:
	rm -f $(OBJS) $(FSHELL_OBJS) ftp
