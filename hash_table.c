#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char *key;
    char *value;
};

struct HashTable {
    int size;
    int count;
    struct Item** items;
};

struct Item *create_item(const char *key, const char *value) {
    struct Item *item = malloc(sizeof(struct Item));
    item->key = strdup(key);
    item->value = strdup(value);

    return item;
}

void destroy_item(struct Item *item) {
    free(item->key);
    free(item->value);
    free(item);
}

int main() {
    struct Item *item = create_item("key", "value");
    printf("%s\n", item->key);
    printf("%s\n", item->value);
    destroy_item(item);
}