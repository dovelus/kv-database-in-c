#include <stdio.h>

#include "kv.h"


int main() {
  kv_t *table = kv_init(16);

  printf("%p\n", table);
  printf("DB Capacity: %ld\n", table->capacity);
  
  int ret = kv_put(table, "HEHE", "HAHA");
  if (ret == -1 || ret == -2) {
    printf("%d\n",ret);
  }

  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key) {
      printf("%s:%s\n",
        table->entries[i].key,
        table->entries[i].value);
    }
  }
}
 
