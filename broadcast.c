//
// Created by Gabriel Carraro on 6/11/19.
//

#include "broadcast.h"
#include "node.h"
#include "failure_detector.h"

int main(int argc, char * argv[]){
    static int n,
            token,
            event;

    float roundTime = 5.0;
    if (argc != 2){
        puts("Uso correto: ./tempo <num_nodes>");
        exit(1);
    }
    n = atoi(argv[1]);
    init(n);

    scheduleEvents(n);
    t_message message;

    while (time() < SIMULATION_TIME){
        cause(&event, &token);
        printf("\n> TEMPO: %f, node: %d, event: %d >> ", time(), token, event);

        switch(event) {

            case TEST:
                if(status(nodes[token].id) != 0){
                    break;
                }
                printf("> TEST: ");
                testNode(token, nodes, n, SHOULD_LOG_TEST);
                schedule(TEST, roundTime, token);
                // printf("status node %d = %d", token, status(token));
                break;

            case FAULT:
                if (request(nodes[token].id, token, 0) != 0) {
                    printf("ERRO: Não foi possivel falhar o nodo %d\n",token);
                    exit(1);
                }
                printf("> FAULT: ");
                //Deu certo a falha
                printf("Falha bem sucessedida para nodo %d - status %d\n", token, status(nodes[token].id));
                break;

            case REPAIR:
                release(nodes[token].id, token);
                schedule(TEST, roundTime, token);
                printf("REPAIR: Nodo %d recuperou\n", token);
                break;

            case SEND:
                if(status(nodes[token].id) != 0){
                    break;
                }
                printf("> SEND: ");
                message.from_cluster = get_cluster(token, nodes);
                char *content = (char*)malloc(150 * sizeof(char));
                sprintf(content, "Node %d says hi!", token);
                message.content = content;
                broadcast(token, nodes, message);

            case RECEIVE:
                printf("> RECEIVE: ");
                if(status(nodes[token].id) != 0){
                    break;
                }
                deliver(token, nodes);


            default:
                break;
        }
        // printStates(nodes, n);
    }
}

void init(int n){
    static char fa_name[5]; // fa : facility
    smpl( 0, "Simulação ilustrando algoritmo vcube");
    reset();
    stream(1);

    // Inicialização
    nodes = (t_node *) malloc(sizeof(t_node) * n);
    for (int i=0; i<n; i++){
        memset(fa_name, '\0', 5);
        printf(fa_name, "%d", i);
        nodes[i].count = n;
        nodes[i].id = facility(fa_name, 1);

        nodes[i].state = (int *) malloc(sizeof(int) * n);
        nodes[i].timestamp = (int *) malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++){
            nodes[i].state[j] = -1;
            nodes[i].timestamp[j] = 0;
        }

        nodes[i].inbox = (t_inbox *) malloc(sizeof(t_inbox));
        nodes[i].inbox->count = 0;
        nodes[i].inbox->messages = NULL;
    }
}

void scheduleEvents(int n){
    //Set tests rounds
    for (int i=0; i < n; i++){
        schedule(TEST, 1, i);
    }
//    for (int i=0; i < n/2; i++){
//        schedule(FAULT, 12.0, i);
//    }
//
//    for (int i=0; i < n/4; i++){
//        schedule(REPAIR, 30.0, i);
//    }

    schedule(SEND, 35, 0);

    for (int i = 0; i < n; i++){
//        float time_send = (13 * i) % SIMULATION_TIME;
//
//        float time_receive = time_send + 5;

//        schedule(SEND, 10 + i, i);
        schedule(RECEIVE, 40, i);
    }
}