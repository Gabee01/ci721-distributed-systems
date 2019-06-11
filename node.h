//
// Created by Gabriel Carraro on 6/11/19.
//
#ifndef NODE_H
#define NODE_H

typedef struct{
    char *content;
    int from_cluster;
} t_message;

typedef struct{
    t_message *messages;
    int count;
} t_inbox;

typedef struct{
    int count;
    int id;
    int *state;
    int *timestamp;
    int facility;
    t_inbox *inbox;
} t_node;
#endif