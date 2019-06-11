//
// Created by Gabriel Carraro on 6/11/19.
//
#ifndef NODE_H
#define NODE_H

//descritor node
typedef struct{
    int count;
    int id;
    int *state;
    int *timestamp;
    int facility;
} t_node;
#endif