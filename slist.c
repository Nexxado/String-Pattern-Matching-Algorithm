#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.H"


void slist_init(slist_t* list) {
  printf("slist_init() \n");
  
  memset(list, 0, sizeof(list));
  slist_head(list) = NULL;
  slist_tail(list) = NULL;
  
  slist_size(list) = 0;
  
}


void slist_destroy(slist_t* list,slist_destroy_t freeData) {
    printf("slist_destroy() \n");
    
    slist_node_t* p, *q;
    int i;
    
    for(p = slist_head(list); p != NULL; p = q) {
        
        q = slist_next(p);
        
        if(freeData)
            free(slist_data(p));
            
        
        free(p);
    }
    
}


void* slist_pop_first(slist_t* list) {
    printf("slist_pop_first() \n");
    
    if(slist_size(list) == 0) {
        return NULL;
    
    }
     
     
    void* data = slist_data(slist_head(list));
    
    if(slist_size(list) == 1) {
        
        free(slist_head(list));
        slist_head(list) = NULL;
        
    } else {
        
        slist_node_t* p = slist_head(list);
        slist_head(list) = slist_next(p);
        free(p);
        
    }
    
    slist_size(list)--;
    return data;
}


int slist_append(slist_t* list, void* newData) {
    printf("slist_append() \n");
    
    slist_node_t* node = (slist_node_t*)malloc(sizeof(slist_node_t));
    if(node == NULL)
        return -1;
    
    slist_data(node) = newData;
    slist_next(node) = NULL;
    
    slist_size(list)++;
    
    if(slist_head(list) == NULL) {
        printf("head == NULL \n");
        
        slist_head(list) = node;
        slist_tail(list) = node;
        return 0;
    
    }
    
    printf("adding after tail \n");
    slist_next(slist_tail(list)) = node;
    
    return 0;
}

