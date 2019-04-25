#include <stdlib.h>
#include <stdio.h>
#include "smpl.h"
#include "cisj.h"

// ring.c

//descritor node
typedef struct{
	int id;
	int *state;
	int *stateCount;
} t_node;

t_node * nodes;

typedef int bool;
enum { false, true };

const int TEST = 1;
const int REPAIR = 2;
const int FAULT = 3;
const int SIMULATION_TIME = 100;

void testObservedNodes(node_set *observedNodes, t_node currentTesterNode, int nodesCount, int dimension);
void updateStatuses(t_node tester, t_node testee, int nodesCount, int dimension, node_set *observedNodes);
void printStates(t_node *nodes, t_node node, int size);

int main(int argc, char * argv[]){
	static int n, //Numero de nodes
	token, // qual node está executando em determinado momento
	event; // qq coisa que vc quer que aconteça

	static char fa_name[5]; // fa : facility
	if (argc != 2){
		puts("Uso correto: ./tempo <num_nodes>");
		exit(1);
	}
	n = atoi(argv[1]);
	smpl( 0, "Simulação ilustrando algoritmo vcube");
	reset();
	stream(1);

	// Inicialização
	nodes = (t_node *) malloc(sizeof(t_node) * n);
    int observedCount = 0;
	for (int i=0; i<n; i++){
		memset(fa_name, '\0', 5);
		printf(fa_name, "%d", i);
		nodes[i].id = facility(fa_name, 1);
		
		nodes[i].state = (int *) malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++){
			nodes[i].state[j] = -1;
		}
		nodes[i].stateCount = (int *) malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++){
			nodes[i].stateCount[j] = 0;
		}
	}

	//imprima fa_name e id para todos os nodes
	//Schedule de eventos

	float roundTime = 15.0;

	//Set tests rounds
	for (int i=0; i < n; i++){
		schedule(TEST, 0.0, i);
	}

//	for (int i = 0; i < n; i++){
//		schedule(FAULT, 0.0, i);
	schedule(FAULT, 35.0, 1);
	schedule(REPAIR, 50.0, 1);
	schedule(FAULT, 70.0, 1);
	// schedule(REPAIR, 40.0, 1);
//	}

	int isNodeOk;
	node_set* observedNodes;
	int dimension = 1;
	while (time() < SIMULATION_TIME){
		cause(&event, &token);
		t_node currentTesterNode;
        switch(event) {
            case TEST:
            	currentTesterNode = nodes[token];
            	if (currentTesterNode.id > 0){
	            	// printf("dimension = %d\n", dimension);
	                observedNodes = cis(token, dimension);
	                testObservedNodes(observedNodes, currentTesterNode, n, dimension);
	                dimension = (dimension) % ((int)log2(n)) + 1;
	                printf("dimension %d\n", dimension);
	                printStates(nodes, currentTesterNode, n);
	                schedule(TEST, roundTime, token);
	            }
                break;

            case FAULT:
                if (request(nodes[token].id, token, 0) != 0) {
                    printf("! Não foi possivel falhar o nodo %d\n",nodes[token].id);
                    exit(1);
                }
                //Deu certo a falha
                printf("EVENTO > Falha bem sucessedida para nodo %d\n", nodes[token].id);
                break;

            case REPAIR:
                release(nodes[token].id, token);
                printf("EVENTO > Nodo %d recuperou\n", nodes[token].id );
                break;
        }
	}
}

void testObservedNodes(node_set *observedNodes, t_node currentTesterNode, int nodesCount, int dimension){
	for(int toTest = 0; toTest < observedNodes->size; toTest++)
    {
    	int inTestIndex = observedNodes->nodes[toTest];
    	// printf("index = %d", inTestIndex);
        t_node inTestNode = nodes[inTestIndex];

        if (inTestNode.id > 0 && inTestNode.id != currentTesterNode.id){
        
	        int testedStatus = status(inTestNode.id);

			if (currentTesterNode.state[inTestIndex] != testedStatus){
				currentTesterNode.stateCount[inTestIndex]++;
				currentTesterNode.state[inTestIndex] = testedStatus;
			}
			// If node tested OK
	        if (testedStatus == 0){
	            printf("\n > Nodo %d testado OK pelo nodo %d\n", inTestNode.id, currentTesterNode.id);
	            // Update tester states
	            updateStatuses(currentTesterNode, inTestNode, nodesCount, dimension, observedNodes);
	    	}
	     	else if (testedStatus == 1){
	        	printf("\n > Nodo %d testado FALHO pelo nodo %d\n", inTestNode.id, currentTesterNode.id);
	    	}
	    	else{
	    		printf("\n > Nodo %d testado DESCONHECIDO pelo nodo %d\n", inTestNode.id, currentTesterNode.id);
	    	}
	    }
    }
}

void updateStatuses(t_node tester, t_node testee, int nodesCount, int dimension, node_set *observedNodes){
	for (int i = 0; i < nodesCount; i++){
    	int wasTested = 0;
		for (int observedIndex = 0; observedIndex < observedNodes->size; observedIndex ++){
			if (observedNodes->nodes[observedIndex] == i){
				wasTested = 1;
			}
		}

    	if (nodes[i].id != testee.id && tester.state[i] != testee.state[i] && !wasTested)
    	{
			tester.state[i] = testee.state[i];
			tester.stateCount[i]++;
			// if (tester.stateCount[i] > testee.stateCount[i])
			// 	tester.stateCount[i] = testee.stateCount[i];
			// else
			// 	testee.stateCount[i] = tester.stateCount[i];

			printf("nodo %d pegou info sobre nodo %d pelo nodo %d\n", tester.id, nodes[i].id, testee.id);
		}
        // }
    }
}

void printStates(t_node *nodes, t_node node, int size){
	printf("%4.1f - Estado atual (nodo %d): ",  time(), node.id);
	printf("[");
	for (int i = 0; i < size; i++){
		printf("Nodo %d: %d; ", nodes[i].id, node.state[i]);
	}
	printf("]\n");

	printf("%4.1f - Contagem de eventos (nodo %d): ",  time(), node.id);
	printf("[");
	for (int i = 0; i < size; i++){
		printf("Nodo %d: %d; ", nodes[i].id, node.stateCount[i]);
	}
	printf("]\n");
}