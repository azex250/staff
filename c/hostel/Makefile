UNTY_PATH=./unity

all: db_api.o
	gcc -o manage manage.c db_api.o

db_api:
	gcc -c db_api.c
clean:
	rm -rf *.o manage