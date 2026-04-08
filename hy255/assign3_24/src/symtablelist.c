#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include<string.h>
#include"symtable.h"

struct  SymTable{
    unsigned int size;
    binding_n * head;
};

SymTable_T SymTable_new(void){
    SymTable_T new_symTable = malloc(sizeof(SymTable_T*));
    assert(new_symTable);
    new_symTable->size = 0;
    new_symTable->head = NULL;
    return new_symTable;
}

void SymTable_free(SymTable_T oSymTable){
    binding_n *curr, *next;
    assert(oSymTable);
    curr = oSymTable->head;

    while (curr){
        next = curr->next;
        free(curr->key);
        free(curr);
        curr = next;
    }
    free(oSymTable);
}

unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);
    return oSymTable->size;
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr;
    assert(oSymTable && pcKey);

    curr = oSymTable->head;
    while (curr){
        if (curr && strcmp(curr->key, pcKey)==0)
            return 1;
        curr = curr->next;
    }
    return 0;
    
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){
    binding_n * newBind;
    if (!SymTable_contains(oSymTable,pcKey)){   /*if the key doesn't exist*/
        newBind = (binding_n*)malloc(sizeof(binding_n));
        assert(newBind);
        newBind->key = malloc((strlen(pcKey) + 1)*sizeof(char));
        assert(newBind->key);
        strcpy(newBind->key,pcKey);
        newBind->value = (void*)pvValue;
        newBind->next = oSymTable->head;
        oSymTable->head = newBind;
        oSymTable->size++;
        return 1;
    }
    return 0;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr, *prev;
    assert(oSymTable && pcKey);
    curr = oSymTable->head;
    prev = NULL;

    while (curr && strcmp(curr->key, pcKey)){
        prev = curr;
        curr = curr->next;
    }
    if(!curr)
        return 0; /*key doesn't exist*/

    if(prev){
        prev->next = curr->next;
    } else {
        oSymTable->head = curr->next;
    }

    free(curr->key);
    free(curr);
    oSymTable->size--;
    return 1;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    binding_n *curr;
    assert(oSymTable && pcKey);
    curr = oSymTable->head;

    while (curr && strcmp(curr->key, pcKey))
        curr = curr->next;
    
    if(!curr)
        return NULL; /*key doesn't exist*/

    return curr->value;
}

void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){
    binding_n * curr;
    assert(oSymTable && pfApply);
    curr = oSymTable->head;
    while (curr){
        pfApply(curr->key,curr->value, (void*)pvExtra);
        curr = curr->next;
    }
}