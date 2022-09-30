#include "search.h"

/**
   Métodos e funções utilizados para fazer a busca.
 **/
void swap(Wine **list, int currentIndex, int newIndex);
int binarySearch(Wine **list, const double key, int begin, int end, const int property);
Wine** wineSort (Wine **list, const int size, const int property);

/**
   Ver quantos vinhos iguais foram encontrados na busca
   e printar na tela além do primeiro vinho da lista
   também quantos vinhos foram os resultados.
**/
void search(Wine **list, double key, int property, int size){

    wineSort(list, size, property);

    int index = binarySearch(list, key, 0, size - 1, property);

    if(index == -1){
        printf("Nenhum vinho encontrado\n");
        return;
    }

    Wine *searchedWine = list[index];
    
    double prop = getProperty(list[index], property);
    int count = index + 1;
    while(prop == getProperty(list[count], property)) count++;
    count = count - index;
    printWine(searchedWine);
    printf("Total de vinhos encontrados: %d\n", count);
}

/**
   Retorno: primeira ocorrência da chave procurada, caso exista, se não, -1.

   Faz a busca binária pela chave definida e quando encontra uma chave faz uma busca pela
   primeira ocorrência dela, ou seja, percorre a lista para esquerda até que encontra um
   valor diferente da chave encontrada.
 **/
int binarySearch(Wine **list, const double key, int begin, int end, const int property){
    int center;
    int result = - 1;

    while(begin <= end){

        center = (int) ((begin + end) / 2.0);
        double value = getProperty(list[center], property);
        
        if(value == key){
            /**
               Assegura de que a busca continuará sendo feita para todos os 
               elementos à esquerda na lista.
            **/
            result = center;
            end = center - 1;
        }
        if(value > key)
            end = center - 1;
        if(value < key)
            begin = center + 1;

    }
    return result;
}
/**
   Ordenação descrita nas especificações do trabalho.
   
   Parametros:
   Wine **list: lista de structs Wine. 
   int size: Tamanho da lista de structs.
   int property: Atributo do struct Wine que queremos ordenar.
           1 - citric_acid
           2 - residual_sugar
           3 - density
           4 - ph
           Other - alcohol
 **/
Wine** wineSort (Wine **list, const int size, const int property){
    if(size == 1) return list;

    // All starts fixed at 0.
    int index = 0;
    int idBegin = getId(list[0]);
    double propertyBegin = getProperty(list[0], property);

    for(int i = 1; i < size; i++){
        int idCurrent = getId(list[i]);
        double propertyCurrent = getProperty(list[i], property);
        // Checa qual termo é maior e também a condição de desempate pelo ID.
        if(propertyCurrent > propertyBegin || (propertyBegin == propertyCurrent && idCurrent > idBegin)){
            /**
               Muda essas variáveis sempre que essa condição for satisfeita, 
               Os valores delas são usados apenas para executar as comparações.
            **/
            index = i;
            propertyBegin = propertyCurrent;
            idBegin = idCurrent;
        }
    }
    swap(list, index, size - 1);
    return wineSort(list, size - 1, property);
}
void swap(Wine **list, int currentIndex, int newIndex){
    Wine *aux = list[currentIndex];
    list[currentIndex] = list[newIndex];
    list[newIndex] = aux;
}
