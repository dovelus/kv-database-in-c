#include <stdio.h>

#include "kv.h"


int main() {
  kv_t *table = kv_init(16);

  printf("%p\n", table);
  printf("DB Capacity: %ld\n", table->capacity);
  
  kv_put(table, "HEHE", "HAHA");
}
 
