# Sistemas distribuídos e tolerandtes a falhas (CI721), 2019/1
## Prof. Elias P. Duarte 
----
### Trabalho 1: [Vcube](https://ieeexplore.ieee.org/document/7016729)
1. *Especificação:*  
   > Implemente o algoritmo VCube no ambiente de simulação SMPL, e mostre resultados para diversos valores de N e diversos eventos - um evento de cada vez, um evento só ocorre depois do evento anterior ser diagnosticado. Para cada evento mostre claramente o número de testes executados e a latência para completar o diagnóstico do evento. Cada nodo mantém o vetor STATE[0..N-1] de contadores de eventos, inicializado em -1 (estado unknown). 
   > Assume-se que os nodos são inicializados sem-falha, a entrada correspondente ao nodo no vetor STATE[] do testador é setada para zero. Ao descobrir um novo evento em um nodo testado, o testador incrementa a entrada correspondente no vetor STATE[].
1. *O código:*
   * Os arquivos desenvolvidos estão todos neste repósitório. Para compilar o vcube, use o comando `make vcube`.
   * Uso do vcube: `./vcube <numero_de_nodos>`
   * Para esse trabalho, estão sendo agendados um evento de teste para cada nodo no `tempo 1`, sendo que a cada teste, um novo teste é agendado após `roundTime=5.0`
   * No início, também estão sendo agendadas `falhas para os primeiros n/2 nodos no tempo 12.0`, e também agendados o `reparo dos primeiros n/4 nodos no tempo 30.0`, onde `n=<numero_de_nodos>`.
   * Um log pode ser gerado através da saída padrão com `./vcube <numero_de_nodos> > logs/vcube.log`
   * `make clean` limpa os arquivos compilados e deleta os arquivos em `/logs`
1. *Relatório:*
   * Todos os nodos possuem um dois vetors com <numero_de_nodos> posições, sendo um o vetor de status, inicializado com `status = -1 (indefinido)`, e um vetor de timestamps, inicializado com `timestamp=0`
    * O funcionamento do vcube implementado só foi testado com *<numero_de_nodos> = potencias de 2*, (ex:[1, 2, 4, 8, 16, 32...])
   * A cada rodada de testes, o nodo *i é testado pelo primeiro nodo sem falha j do seu cluster cis(i, cluster)*
   * Após isso, j é testado pelo primeiro nodo sem falha de cada um dos seus clusters {cis(j, 0), cis(j, 1), cis(j, 2), ..., cis(j, log2(n))}
   * Sempre que j é testado ok por um nodo x:
     * se `x.timestamp % 2 == 1`, então `x.timestamp[j]++`
     * se x possui timestamp sobre algum nodo k, tal que` x.timestamp[k] > j.timestamp[k]`, o estado de k em j é atualizado para o estado de k em x, ou seja, `x.state[k] = j.state[k]`
    * Sempre que j é testado falho por um nodo x:
        * se `x.timestamp % 2 == 0`, então `x.timestamp[j]++` 
1. *Dificuldades encontradas:*
      * Entender o funcionamento do smpl, como o que eram o *tokens* e no funcionamento das *facilitys*
      * A princípio havia implementado o algoritmo de forma errada, fazendo o *nodo com o token* testar os de seu cluster, isso causou muita confusão pois os resultados não faziam sentido com os esperados
      * Após a correção do início do algoritmo, a implementação de como os status deveriam ser atualizados levou um tempo, consegui entender melhor após ler o artigo
### Trabalho 2: Best-effort broadcast
1. *Especificação:*  
   > Implemente o algoritmo de best-effort broadcast sobre o VCube no ambiente de simulação SMPL. No algoritmo qualquer nodo pode ser a origem do broadcast. A origem envia (no máximo) logN mensagens, uma para o primeiro nodo sem falha de cada cluster. Nas mensagens o transmissor informa ao receptor qual o índice do seu cluster ("s"). Os nodos que recebem a mensagem estando no cluster de índice s=1 são folhas e não tem que retransmitir. Por outro lado, um nodo em um cluster de índice s>1 transmite s-1 mensagens, para o primeiro nodo sem falha de seus clusters 1, 2,..., s-1.
   > Mostre as mensagens transmitidas para diversos nodos funcionando como origens. Em cada execução nodos distintos do sistema estarão falhos/sem-falhas. 
   > Mostre as mensagens transmitidas para diversos nodos funcionando como origens. Em cada execução nodos distintos do sistema estarão falhos/sem-falhas.
1. *O código:*
1. *Relatório:*
1. *Dificuldades encontradas:*