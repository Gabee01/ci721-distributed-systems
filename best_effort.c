//
// Created by Gabriel Carraro on 6/11/19.
//

#include "best_effort.h"

int get_cluster(int token, t_node *nodes);

void broadcast(int token, t_node *nodes, t_message message){
//    node_set *cluster = cis(token, cluster_index);
    for (int cluster = 1; cluster <= log2(nodes->count); cluster++) {
        // puts("Finding first ok");
        node_set *cjs = cis(token, cluster);
        int first_ok = -1;
        int node_test;
        for (int i = 0; i < cjs->size && first_ok == -1; i++) {
            node_test = nodes[token].state[nodes[cjs->nodes[i]].id];
            if (node_test == 0) {
                first_ok = cjs->nodes[i];
                printf("node %d sending message(%s), received from cluster %d, to node %d (first ok node in s = %d)\n",
                       token, message.content, message.from_cluster, first_ok, cluster);
                message.from_cluster = cluster;
                enqueue_message(nodes[first_ok].inbox, message);
                log_messages(nodes[first_ok], first_ok);
            } else {
                printf("node %d FAULTY (status = %d)\n", cjs->nodes[i], node_test);
            }
        }
    }

//    for (int i = 0; i < cluster->size; i++){
//        if (nodes[token].state[cluster->nodes[i]] == 0){
//            printf("node %d sending message(%s) from %d to %d\n", token, message.content, message.from_cluster, cluster->nodes[i]);
//            enqueue_message(nodes[cluster->nodes[i]].inbox, message);
//        }else{
//            printf("%d not sending message: node %d is faulty\n", token, cluster->nodes[i]);
//        }
//    }
}

void enqueue_message(t_inbox *inbox, t_message message){
    if (inbox->count == 0){
        inbox->messages = (t_message *) malloc(sizeof(t_message));
    }else{
        inbox->messages = (t_message *) realloc(inbox->messages, inbox->count * sizeof(t_message));
    }
    inbox->messages[inbox->count] = message;
    inbox->count++;
}

t_message dequeue_message(t_inbox *inbox){
    inbox->count--;
    return inbox->messages[0];
}

void deliver(int token, t_node *nodes) {
    if (nodes[token].inbox->count == 0) {
        printf("no messages on inbox\n");
        return;
    }

    int my_cluster = get_cluster(token, nodes);
    t_message message = dequeue_message(nodes[token].inbox);
    printf("node %d delivered message (\"%s\") from cluster %d\n",
           token, nodes[token].inbox->messages[0].content, nodes[token].inbox->messages->from_cluster);

    log_messages(nodes[token], token);

    if (my_cluster > 1) {
        broadcast(token, nodes, message);
    }
}

int get_cluster(int token, t_node *nodes) {
    int my_cluster = -1;
    for (int cluster = 1; cluster <= log2(nodes->count) && my_cluster == -1; cluster++) {
        // puts("Finding first ok");
        node_set *cjs = cis(token, cluster);
        int first_ok = -1;
        int node_test;
        for (int i = 0; i < cjs->size && first_ok == -1; i++) {
            node_test = nodes[token].state[nodes[cjs->nodes[i]].id];
            if (node_test == 0) {
                first_ok = cjs->nodes[i];
            }
            if (first_ok == token)
                my_cluster = cluster;
        }
    }
}