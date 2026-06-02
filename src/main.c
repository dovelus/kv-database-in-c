#include <stdio.h>
#include <assert.h>
#include "kv.h"


int main() {
  int ret = 0;
  
  kv_t *table = kv_init(16);

  printf("%p\n", table);
  printf("DB Capacity: %ld\n", table->capacity);
  
  kv_put(table, "HEHE", "Miao");
  kv_put(table, "HEHE", "Woof");
  kv_put(table, "HEHE2", "Rawr");
  
  char *value = kv_get(table, "HEHE");
  if (value != NULL) {
    printf("value for HEHE3 = %s\n", value);
  } else {
    printf("Key not found\n");
  }

  ret = kv_delete(table, "HEHE2");
  if (ret != -1) {
    printf("value for HEHE3 deleted\n");
  } else {
    printf("Key not found\n");
  }

  value = kv_get(table, "HEHE");
  if (value != NULL) {
    printf("value for HEHE3 = %s\n", value);
  } else {
    printf("Key not found\n");
  }

  printf("ALL ENTRIES:\n");
  for (int i = 0; i < table->capacity; i++) {
    if (table->entries[i].key && table->entries[i].key != TOMBSTONE) {
      printf("%s:%s\n",
        table->entries[i].key,
        table->entries[i].value);
    }
  }  
  printf("COUNT: %ld\n", table->count);
  
  ret = kv_free(table);
  table = NULL;
  printf("DB FREE: %d\n", ret);

  value = kv_get(table, "HEHE");
  if (value != NULL) {
    printf("value for HEHE = %s\n", value);
  } else {
    printf("Key not found\n");
  }
  
}
 
