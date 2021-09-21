#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdio.h>

#define DEF_CAP 8

#define Deque_DEFINE(t)                                                        
  struct Deque_##t##_Iterator;                                                 
  struct Deque_##t;                                                            
  struct Deque_##t##_Iterator {                                                
    unsigned int index;                                                        
    Deque_##t *deq;                                                            
    void (*inc)(Deque_##t##_Iterator *);                                       
    void (*dec)(Deque_##t##_Iterator *);                                       
    t &(*deref)(Deque_##t##_Iterator *);                                       
  };                                                                           
  struct Deque_##t {                                                           
    unsigned int cap;                                                          
    unsigned int start_i;                                                      
    unsigned int offset;                                                       
    char type_name[sizeof(#t) + sizeof("Deque_") - 1];                         
    t *data;                                                                   
    bool (*comp)(const t &, const t &);                                        
    int (*compar)(const void *, const void *, void *);                         
    unsigned int (*size)(Deque_##t *);                                         
    bool (*empty)(Deque_##t *);                                                
    void (*resize)(Deque_##t *);                                               
    void (*push_front)(Deque_##t *, t);                                        
    void (*push_back)(Deque_##t *, t);                                         
    void (*pop_front)(Deque_##t *);                                            
    void (*pop_back)(Deque_##t *);                                             
    t &(*at)(Deque_##t *, unsigned int);                                       
    t &(*front)(Deque_##t *);                                                  
    t &(*back)(Deque_##t *);                                                   
    Deque_##t##_Iterator (*begin)(Deque_##t *);                                
    Deque_##t##_Iterator (*end)(Deque_##t *);                                  
    void (*clear)(Deque_##t *);                                                
    void (*dtor)(Deque_##t *);                                                 
    void (*sort)(Deque_##t *, Deque_##t##_Iterator, Deque_##t##_Iterator);     
  };  
