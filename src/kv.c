#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "kv.h"

size_t hash(char *val, int capacity) {
  size_t hash = 0x13371337deadbeef;
  
  while(*val) {
    hash ^= *val;
    hash = hash << 8;
    hash += *val;

    val++;
  }

  return hash % capacity;
}

// fn kv_put
// parmans:
// - db: a pointer to the db
// - key: a pointer to the key value
// - values: a pointer to the value itself
// return the index of the key, otherwise on
// error, return -1, or not found return -2
int kv_put(kv_t *db, char *key, char *value) {
  if (!db || !key || !value) return -1;

  size_t idx = hash(key, db->capacity);

  for (int i = 0; i < db->capacity - 1; i++) {

    size_t real_idx = (idx + i) % db->capacity;
    
    kv_entry_t *entry = &db->entries[real_idx];

    // the key is already set, updating
    if (entry->key && entry->key != TOMBSTONE && !strcmp(entry->key, key)) {
      char *newval = strdup(value);
      if (!newval) return -1;
      entry->value = newval;
      return 0;
    }

    // land in a slot that is "empty"
    // null or tombstone
    if (!entry->key || entry->key == TOMBSTONE) {
      char *newval = strdup(value);
      char *newkey = strdup(key);
      if (!newval || !newkey) {
        free(newval);
        free(newkey);
        return -1;
      }
      entry->value = newval;
      entry->key = newkey;
      db->count++;
      return 0;
    }
    
  }

  return -2;
}

// fn kv_get
// parmans:
// - db: a pointer to the db
// - key: a pointer to the key value
// return the a pointer to the vale, otherwise on
// error, return NULL
char *kv_get(kv_t *db, char *key) {
  if (!db || !key) return NULL;

  size_t idx = hash(key, db->capacity);

  for (int i = 0; i < db->capacity - 1; i++) {
     size_t real_idx = (idx + i) % db->capacity;

     kv_entry_t *entry = &db->entries[real_idx];
     if (entry == NULL) {
       return NULL;
     }

     if (entry->key && entry->key != TOMBSTONE && !strcmp(entry->key, key)) {
         return entry->value;
     }
   }
  return NULL;
}

// fn kv_delete
// parmans:
// - db: a pointer to the db
// - key: a pointer to the key value
// return the a 0 on success delete, otherwise on
// error, return -1
int kv_delete(kv_t *db, char *key) {
  if (!db || !key) return -1;

  size_t idx = hash(key, db->capacity);

  for (int i = 0; i < db->capacity - 1; i++) {
     size_t real_idx = (idx + i) % db->capacity;

     kv_entry_t *entry = &db->entries[real_idx];
     if (entry == NULL) {
       return -1;
     }

     if (entry->key && entry->key != TOMBSTONE && !strcmp(entry->key, key)) {
         entry->key = TOMBSTONE;
         db->capacity--;
         return 0;
     }
   }
  return -1;
}


kv_t *kv_init(size_t capacity) {
  if (capacity == 0) return NULL;

  kv_t *table = malloc(sizeof(kv_t));
  if (table == NULL) {
    return NULL;
  }

  table->capacity = capacity;
  table->count = 0;

  table->entries = calloc(sizeof(kv_entry_t), capacity);
  if (table->entries == NULL) {
    return NULL;
  }

  return table;
  
}


