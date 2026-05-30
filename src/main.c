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

  ret = kv_put(table, "HEHE3", "HOLA");
  if (ret == -1 || ret == -2) {
    printf("ret = %d\n",ret);
  } else {
    printf("ret = %d\n", ret);
  }

  char *value = kv_get(table, "HEHE3");
  if (value != NULL) {
    printf("value for HEHE3 = %s\n", value);
  } else {
    printf("Key not found\n");
  }

  int ret2 = kv_delete(table, "HEHE3");
  if (ret2 != -1) {
    printf("value for HEHE3 deleted\n");
  } else {
    printf("Key not found\n");
  }

  char *value2 = kv_get(table, "HEHE3");
  if (value2 != NULL) {
    printf("value for HEHE3 = %s\n", value2);
  } else {
    printf("Key not found\n");
  }
  
  
  printf("COUNT: %ld\n", table->count);
}
 
