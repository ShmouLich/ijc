CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
OBJS = htab_bucket_count.o htab_find.o htab_lookup_add.o htab_clear.o htab_for_each.o htab_hash_function.o htab_move.o htab_erase.o htab_free.o htab_init.o htab_size.o
EXEC = tail wordcount wordcount-dynamic

all: $(EXEC)

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -o wordcount wordcount.o io.o -L . libhtab.a
	
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o io.o libhtab.so

#static
libhtab.a: $(OBJS)
	ar -rcs libhtab.a $(OBJS)
	
#dynamic
libhtab.so:	$(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o libhtab.so $(OBJS)

io.o: io.c
	$(CC) $(CFLAGS) -c io.c
	
wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c wordcount.c

htab_hash_function.o: htab_hash_function.c
	$(CC) $(CFLAGS) -fPIC -c htab_hash_function.c

htab_init.o: htab_init.c
	$(CC) $(CFLAGS) -fPIC -c htab_init.c
	
htab_move.o: htab_move.c htab_lookup_add.o htab_find.o htab_clear.o
	$(CC) $(CFLAGS) -fPIC -c htab_move.c

htab_size.o: htab_size.c
	$(CC) $(CFLAGS) -fPIC -c htab_size.c

htab_bucket_count.o: htab_bucket_count.c
	$(CC) $(CFLAGS) -fPIC -c htab_bucket_count.c
	
htab_lookup_add.o: htab_lookup_add.c htab_hash_function.o htab_find.o
	$(CC) $(CFLAGS) -fPIC -c htab_lookup_add.c
	
htab_find.o: htab_find.c htab_hash_function.o
	$(CC) $(CFLAGS) -fPIC -c htab_find.c

htab_foreach.o: htab_foreach.c
	$(CC) $(CFLAGS) -fPIC -c htab_foreach.c

htab_remove.o: htab_remove.c htab_hash_function.o
	$(CC) $(CFLAGS) -fPIC -c htab_remove.c
	
htab_clear.o: htab_clear.c htab_bucket_count.o
	$(CC) $(CFLAGS) -fPIC -c htab_clear.c
	
htab_free.o: htab_free.c htab_clear.o
	$(CC) $(CFLAGS) -fPIC -c htab_free.c

###########

clean:
	rm -f *.o
	rm -f $(EXEC)
	rm -f libhtab.so libhtab.a

pack:
	zip xkrizo05.zip *.c *.h Makefile
