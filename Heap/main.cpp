#include <iostream>

using namespace std;
const int MAX = 100;

struct TElemento {
    int chave;
    string dado;
};

struct THeap {
    TElemento elementos[MAX];
    int quantidade;
};

int posicaoPai(int pos){
  return (pos-1)/2;
}

int posicaoFilhoEsquerda(int pos){
  return (2*pos)+1;
}

int posicaoFilhoDireita(int pos){
  return (2*pos)+2;
}

TElemento retornaVazio(){
    TElemento vazio;
    vazio.chave = 0;
    vazio.dado = "";
}

void inicializaHeap(THeap &heap){
    heap.quantidade = 0;

    for (int i = 0; i < MAX; i++){
        heap.elementos[i] = retornaVazio();
    }
}

void acomodaElemento(THeap &heap, int posicaoDoElemento) {
        TElemento auxiliaTroca;

        //compara o elemento com o "atual pai"
        while (posicaoDoElemento > 0 && heap.elementos[posicaoPai(posicaoDoElemento)].chave <= heap.elementos[posicaoDoElemento].chave)
        {
            //troca o pai pelo filho
            auxiliaTroca = heap.elementos[posicaoDoElemento];
            heap.elementos[posicaoDoElemento] = heap.elementos[posicaoPai(posicaoDoElemento)];
            heap.elementos[posicaoPai(posicaoDoElemento)] = auxiliaTroca;
            posicaoDoElemento = posicaoPai(posicaoDoElemento);
        }
}

//insere o elemento da árvore
bool inserirElemento(THeap &heap, TElemento dado) {
    if (dado.chave > 0 && heap.quantidade < MAX){
        //insere o novo elemento no final da estrutura
        heap.elementos[heap.quantidade] = dado;
        //move o elemento para a posição certa
        acomodaElemento(heap, heap.quantidade);
        heap.quantidade++;

        return true;
    } else {
        return false;
    }
}

void reorganizaAoRemover(THeap &heap, int posicaoDoElemento){
    TElemento auxiliaTroca;
    int filho = posicaoFilhoEsquerda(posicaoDoElemento);

    while (filho < heap.quantidade){
        if (filho < heap.quantidade-1){
            if (heap.elementos[filho].chave < heap.elementos[filho + 1].chave){
                filho++;
            }
        }

        if (heap.elementos[posicaoDoElemento].chave >= heap.elementos[filho].chave){
            break;
        }

        auxiliaTroca = heap.elementos[posicaoDoElemento];
        heap.elementos[posicaoDoElemento] = heap.elementos[filho];
        heap.elementos[filho] = auxiliaTroca;
    }
}

bool removerElemento(THeap &heap){
    if (heap.quantidade > 0){
        heap.quantidade--;
        //o primeiro elemento recebe o último
        heap.elementos[0] = heap.elementos[heap.quantidade];
        //passa a raiz
        reorganizaAoRemover(heap, 0);
        return true;
    } else {
        return false;
    }
}

void imprimirHeap(THeap heap){
    cout<<"Heap Binario\n\n";
    for (int i = 0; i < heap.quantidade; i++){
        cout<<heap.elementos[i].chave<<"\t";
    }
}

void imprimirTopo(THeap heap){
        cout<<"\n\nTopo";
        cout<<"\nChave: "<<heap.elementos[0].chave;
        cout<<"\nDado: "<<heap.elementos[0].dado;
}

void atualizarChavePeloDado(THeap &heap, string dado, int chave){
    for (int i = 0; i < heap.quantidade; i++){
        if (heap.elementos[i].dado == dado){
            heap.elementos[i].chave = chave;
            reorganizaAoRemover(heap, i);
        }
    }
}

int main()
{
    THeap heap;
    inicializaHeap(heap);

    TElemento elemento1;
    TElemento elemento2;
    TElemento elemento3;
    TElemento elemento4;
    TElemento elemento5;
    TElemento elemento6;
    TElemento elemento7;
    TElemento elemento8;
    TElemento elemento9;
    TElemento elemento10;
    TElemento elemento11;
    TElemento elemento12;
    TElemento elemento13;

    elemento1.chave = 17;
    elemento1.dado = "A";
    elemento2.chave = 24;
    elemento2.dado = "B";
    elemento3.chave = 3;
    elemento3.dado = "C";
    elemento4.chave = 4;
    elemento4.dado = "D";
    elemento5.chave = 5;
    elemento5.dado = "E";
    elemento6.chave = 2;
    elemento6.dado = "F";
    elemento7.chave = 19;
    elemento7.dado = "G";
    elemento8.chave = 80;
    elemento8.dado = "H";
    elemento9.chave = 9;
    elemento9.dado = "I";
    elemento10.chave = 10;
    elemento10.dado = "J";
    elemento11.chave = 11;
    elemento11.dado = "K";
    elemento12.chave = 12;
    elemento12.dado = "L";
    elemento13.chave = 13;
    elemento13.dado = "M";

    inserirElemento(heap, elemento1);
    inserirElemento(heap, elemento2);
    inserirElemento(heap, elemento3);
    inserirElemento(heap, elemento4);
    inserirElemento(heap, elemento5);
    inserirElemento(heap, elemento6);
    inserirElemento(heap, elemento7);
    inserirElemento(heap, elemento8);
    inserirElemento(heap, elemento9);
    inserirElemento(heap, elemento10);
    inserirElemento(heap, elemento11);
    inserirElemento(heap, elemento12);
    inserirElemento(heap, elemento13);

    atualizarChavePeloDado(heap, "H", 1);

    removerElemento(heap);
    imprimirHeap(heap);
    imprimirTopo(heap);

    cout<<"\n\n";
}
