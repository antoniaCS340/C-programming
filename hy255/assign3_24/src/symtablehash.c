#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"symtable.h"

#define HASH_MULTIPLIER 65599

#define INIT_BUCKETS  509
#define MAX_BUCKETS  65521

struct  SymTable{
    unsigned int size;
    unsigned int buckets;
    binding_n ** hashTable;
};
static unsigned int SymTable_hash(const char *pcKey, unsigned int buckets){

	size_t ui;
    unsigned int uiHash = 0U;

	for (ui = 0U; pcKey[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];

	return uiHash % buckets;

}

void extension(SymTable_T oSymTable, unsigned int size){
    unsigned int num_buck, new_size;
    binding_n *temp_list, *cur, *next;
    int i;

    new_size = size;
    num_buck = oSymTable->buckets;
    /*create a temp list for all the bindings*/
    temp_list = NULL;
    for (i = 0; i < num_buck; i++){
        cur = oSymTable->hashTable[i];
        while (cur){
            next = cur->next;
            cur->next = temp_list;
            temp_list = cur;
            cur = next;
        }
         
    }

    /*reallocate more space for symtable*/
    oSymTable->buckets = new_size;
    oSymTable->hashTable = realloc(oSymTable->hashTable, new_size * sizeof(binding_n*));
    if (oSymTable->hashTable == NULL){
        SymTable_free(oSymTable);
        return;
    }

    /*put all the bindings back by the new hash position*/
    cur = temp_list;
    while (cur){
        next = cur->next;
        i = SymTable_hash(cur->key,oSymTable->buckets);
        cur->next = oSymTable->hashTable[i];
        oSymTable->hashTable[i] = cur;
        cur = next;
    }

}

void new_size_table(SymTable_T oSymTable){
    unsigned int num_buck, new_size;
    new_size = 0;

    if (oSymTable->buckets == MAX_BUCKETS)
        return;
    
    num_buck = oSymTable->size;
    switch (num_buck){
    case 509:
        new_size = 1021;
        break;
    case 1021:
        new_size = 2053;
        break;
    case 2053:
        new_size = 4093;
        break;
    case 4093:
        new_size = 8191;
        break;
    case 8191:
        new_size = 16381;
        break;
    case 16381:
        new_size = 32771;
        break;
    case 32771:
        new_size = MAX_BUCKETS;
        break;
    }
    if (new_size)
        extension(oSymTable, new_size);
}

SymTable_T SymTable_new(void){
    SymTable_T new_symTable = malloc(sizeof(SymTable_T*));
    assert(new_symTable);

    new_symTable->hashTable = malloc(INIT_BUCKETS * sizeof(binding_n*));
    if (new_symTable->hashTable == NULL){
        free(new_symTable);
        return NULL;
    }
    
    new_symTable->buckets = INIT_BUCKETS;
    new_symTable->size = 0;
    
    return new_symTable;
}

void SymTable_free(SymTable_T oSymTable){

    binding_n *curr, *next;
    int i;
    assert(oSymTable);

    for (i = 0; i < oSymTable->buckets; i++){
        curr = oSymTable->hashTable[i];
        while (curr){
            next = curr->next;
            free(curr->key);
            free(curr);
            curr = next;
        }
    }
    free(oSymTable->hashTable);
    /*free(oSymTable);*/
}

unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);
    return oSymTable->size;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){
    binding_n * newBind;
    int p;
    assert(oSymTable && pcKey);
    if (!SymTable_contains(oSymTable,pcKey)){   /*if the key doesn't exist*/
        newBind = (binding_n*)malloc(sizeof(binding_n));
        assert(newBind);
        newBind->key = malloc((strlen(pcKey) + 1)*sizeof(char));
        assert(newBind->key);
        strcpy(newBind->key,pcKey);
        newBind->value = (void*)pvValue;

        p = SymTable_hash(pcKey,oSymTable->buckets);
        newBind->next = oSymTable->hashTable[p];
        oSymTable->hashTable[p] = newBind;
        oSymTable->size++;

        new_size_table(oSymTable);
        assert(oSymTable);
        return 1;
    }
    return 0;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr, *prev;
    int p;
    assert(oSymTable && pcKey);
    p = SymTable_hash(pcKey,oSymTable->buckets);
    curr = oSymTable->hashTable[p];
    prev = NULL;

    while (curr && strcmp(curr->key, pcKey)){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        return 0; /*key doesn't exist*/

    if(prev){
        prev->next = curr->next;
    } else {
        oSymTable->hashTable[p] = curr->next;
    }

    free(curr->key);
    free(curr);
    oSymTable->size--;
    return 1;
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr;
    assert(oSymTable && pcKey);

    curr = oSymTable->hashTable[SymTable_hash(pcKey,oSymTable->buckets)];
    while (curr){
        if (strcmp(curr->key, pcKey)==0)
            return 1;
        curr = curr->next;
    }
    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr;
    assert(oSymTable && pcKey);
    curr = oSymTable->hashTable[SymTable_hash(pcKey,oSymTable->buckets)];

    while (curr && strcmp(curr->key, pcKey))
        curr = curr->next;
    
    if(!curr)
        return NULL; /*key doesn't exist*/

    return curr->value;
}

void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){
    binding_n * curr;
    int i;
    assert(oSymTable && pfApply);
    for( i = 0; i < oSymTable->buckets; i++){
        curr = oSymTable->hashTable[i];
        while (curr){
            pfApply(curr->key,curr->value, (void*)pvExtra);
            curr = curr->next;
        }
    }
}
    