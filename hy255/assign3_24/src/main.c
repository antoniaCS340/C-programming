#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"symtable.h"


void print(const char *pcKey, void *pvValue,void *pvExtra){
    printf("AM %s:  %s\n",pcKey,(char *)pvValue);
}

int main(){
    SymTable_T table = SymTable_new();
    int i;
    char result[50];
    
    if(SymTable_put(table,"antonia","csd5104"))
        printf("Added 1 element\n");
    else 
        printf("Failure in SymTable_put\n");

    if(!SymTable_put(table,"antonia","csd5104"))
        printf("Did not add the same instance\n");
    else 
        printf("Failure in SymTable_put, dublicate entry\n");

    if(SymTable_put(table,"csd","uoc"))
        printf("Added 2nd element\n");
    else 
        printf("Failure in SymTable_put");

    if(SymTable_put(table,"math","uoc"))
        printf("Added 3rd element\n");
    else 
        printf("Failure in SymTable_put");
    
    if(SymTable_remove(table,"math"))
        printf("Removed 3rd element\n");
    else 
        printf("Failure in SymTable_remove failed\n");
        

    for(i=0;i<67;i++){
        sprintf(result, "csd%d", i);
        SymTable_put(table, result ,"ugrad");
    }
    
    if(SymTable_remove(table,"csd8"))
        printf("Removed succesfull csd8\n");
    else 
        printf("SymTable_remove failed\n");
    
    if(!SymTable_get(table,"csd8"))
        printf("Removed successfully element\n");
    else 
        printf("SymTable_remove failed\n");
    
    if(SymTable_get(table, "csd5"))
        printf("Got entry502: %s element\n",(char*)SymTable_get(table, "entry5"));
    else 
        printf("SymTable_get failed\n");

    
    SymTable_map(table,print,"");
    
    SymTable_free(table);

     return 0;

}