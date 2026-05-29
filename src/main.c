#include <stdio.h>

#include "kv.h"


int main() {
  kv_t *db = kv_init(16);

  printf("%p\n", db);

  printf("DB Capacity: %ld\n", db->capacity);
}
 
