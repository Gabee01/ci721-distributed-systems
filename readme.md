# Sistemas distribuídos e tolerandtes a falhas (CI721), 2019/1
## Prof. Elias P. Duarte 
----
### Trabalho 1: Vcube
1. *Especificação:*  
   > Implemente o algoritmo VCube no ambiente de simulação SMPL, e mostre resultados para diversos valores de N e diversos eventos - um evento de cada vez, um evento só ocorre depois do evento anterior ser diagnosticado. Para cada evento mostre claramente o número de testes executados e a latência para completar o diagnóstico do evento. Cada nodo mantém o vetor STATE[0..N-1] de contadores de eventos, inicializado em -1 (estado unknown). 
   > Assume-se que os nodos são inicializados sem-falha, a entrada correspondente ao nodo no vetor STATE[] do testador é setada para zero. Ao descobrir um novo evento em um nodo testado, o testador incrementa a entrada correspondente no vetor STATE[].
1. *Rodando o código:*
   * Os arquivos desenvolvidos estão todos neste repósitório. Para compilar o vcube, use o comando `make vcube`.
2. *Relatório:*
   * 

### Trabalho 2: Best-effort broadcast
1. *Especificação:*  
   > Implemente o algoritmo de best-effort broadcast sobre o VCube no ambiente de simulação SMPL. No algoritmo qualquer nodo pode ser a origem do broadcast. A origem envia (no máximo) logN mensagens, uma para o primeiro nodo sem falha de cada cluster. Nas mensagens o transmissor informa ao receptor qual o índice do seu cluster ("s"). Os nodos que recebem a mensagem estando no cluster de índice s=1 são folhas e não tem que retransmitir. Por outro lado, um nodo em um cluster de índice s>1 transmite s-1 mensagens, para o primeiro nodo sem falha de seus clusters 1, 2,..., s-1.
   > Mostre as mensagens transmitidas para diversos nodos funcionando como origens. Em cada execução nodos distintos do sistema estarão falhos/sem-falhas. 
   > Mostre as mensagens transmitidas para diversos nodos funcionando como origens. Em cada execução nodos distintos do sistema estarão falhos/sem-falhas.
2. *Relatório:*
   * 