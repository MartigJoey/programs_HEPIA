#include <stdio.h>

typedef struct hm_t hm;

typedef struct entry_t entry;

hm *hm_create(unsigned int length);
void hm_destroy(hm **hash_map);
hm *hm_set(hm *hash_map, const char *const key, const char *const value);
char *hm_get(const hm *const hash_map, const char *const key);
char *hm_rm(hm *hash_map, const char *const key); 
char *hm_to_str(const hm *const hash_map);
void hm_print(const hm *const hash_map);
int hm_get_length(hm *hash_map);