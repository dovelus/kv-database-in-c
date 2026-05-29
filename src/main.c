#include <stdio.h>
#include <assert.h>
#include "kv.h"


int main() {
  int ret = 0;
  
  kv_t *table = kv_init(16);

  printf("%p\n", table);
  printf("DB Capacity: %ld\n", table->capacity);
  
  ret = kv_put(table, "HEHE", "HAHA");
  if (ret == -1 || ret == -2) {
    printf("ret = %d\n",ret);
  } else {
    printf("ret = %d\n", ret);
  }

  ret = kv_put(table, "HEHE2", "HAHA");
  if (ret == -1 || ret == -2) {
    printf("ret = %d\n",ret);
  } else {
    printf("ret = %d\n", ret);
  }
  
  ret = kv_put(table, "HEHE3", "HAHA");
  if (ret == -1 || ret == -2) {
    printf("ret = %d\n",ret);
  } else {
    printf("ret = %d\n", ret);
  }
  
  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key) {
      printf("%s:%s\n",
        table->entries[i].key,
        table->entries[i].value);
    }
  }

  printf("COUNT: %ld\n", table->count);
}
 
