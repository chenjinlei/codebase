#ifndef _LISTLIB_H
#define _LISTLIB_H

#include <time.h>

typedef struct data_struct {
	time_t time;
	char *string;
} data_t;

int access_data(void);
int add_data(data_t data);
int free_key(int key);
int get_data(int key, data_t *datap);

#endif
