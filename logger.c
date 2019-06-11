#include "logger.h"
#include "node.h"

void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult){
    printf("%d tested %d -> result = %d, ", tester_node, tested_node, testResult);

    print_node_state(nodes, n, tester_node);
}

void print_cis(node_set *nodes, int node, int cluster){
    printf("cis (%d, %d): {", node, cluster);
    for (int i=0; i < nodes->size; i++)
        printf(" %d", nodes->nodes[i]);
    puts("}");
}

void print_node_state(t_node *nodes, int n, int node){
    printf("node %d state: (node, status): {", node);
    for (int i=0; i < n; i++){
        printf("(%d, %d)", i, nodes[node].state[i]);
    }
    printf("}\n");
    // puts("----\n");
}

void print_node_ts(t_node *nodes, int n, int node){
    printf("node %d timestamp: (node, ts): {", node);
    for (int i=0; i < n; i++){
        printf("(%d, %d)", i, nodes[node].timestamp [i]);
    }
    printf("}\n");
    // puts("----\n");
}

void log_messages(t_node node, int token) {
    printf("node %d inbox (%d messages): {", token, node.inbox->count);
    for (int i = 0; i < node.inbox->count; i++){
        printf("(%d: %s - received from cluster = %d),",
               i, node.inbox->messages[i].content, node.inbox->messages->from_cluster);
    }
    printf("}\n");
}