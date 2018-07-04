//
//  main.cpp
//  Huffman
//
//  Created by mateus gomes on 7/5/17.
//  Copyright © 2017 mateus gomes. All rights reserved.
//
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <cstdio>

using namespace std;

class NovaString
{
public:
    
    char* vetorChar;
    
    int quantidadeElementos;
    
    int elementoAtual;
    
    NovaString()
    {
        inicializa();
    }
    
    void inicializa()
    {
        quantidadeElementos = 1000;
        
        vetorChar = (char*)malloc(sizeof(char)* quantidadeElementos);
        
        elementoAtual = 0;
    }
    
    int lenght()
    {
        return elementoAtual;
    }
    
    void append()
    {
        
    }
};

typedef NovaString String;

//Lista de inteiros onde o texto traduzido para os bits é salvo
class ListaInteiro
{
public:
    
    //vetor de inteiro onde os bits são salvos
    int *vetorInteiro;
    
    //controle da quantidade de elementos
    int quantidadeElementos;
   
    //controla o ultimo elemento
    int ultimoElemento;

    ListaInteiro()
    {
        inicializaLista();
    }
    
    void inicializaLista()
    {
        quantidadeElementos = 1000;
        
        vetorInteiro = (int*)malloc(sizeof(int)*1000);
        
        ultimoElemento = 0;
        
        int i;
        
        //atribui 0 para todas as casas do vetor
        for (i = 0; i < quantidadeElementos; i++)  vetorInteiro[i] = 0;
    }

    //adiciona novo elemento
    void append(int elemento)
    {
        
        //verifica se é necessário fazer
        if(ultimoElemento >= quantidadeElementos)
        {
            //adiciona mais elementos
            quantidadeElementos += 1000;
            
            //adiciona mais posicoes no vetor
            vetorInteiro =  (int *)realloc(vetorInteiro, quantidadeElementos*sizeof(int) );
        }
        
        //adiciona o novo elemento
        vetorInteiro[ultimoElemento] = elemento;
        
        //seta o ultimo elemento para a proxima casa
        ultimoElemento++;
    
    }
    
    //limpa lista
    void clear()
    {
        free(vetorInteiro);
        
        quantidadeElementos = 0;
        
        ultimoElemento = 0;
    }
    
    //imprime vetor
    void print()
    {
        cout << "\n\nIMPRIMINDO LISTA BINARIA\n\n";
        
        int i;
        
        for (i = 0; i < ultimoElemento; i++)
        {
            if(i%8==0)
            {
                cout << " ";
            }
            
            cout << vetorInteiro[i];
        }
        
         cout << "\n\nLISTA BINARIA IMPRESSA\n";
    }
};


//Struct onde são salvos cada elemento da lista encadeada de caracter
struct Caracter
{
    char caracter;
    
    int quantidade;
    
    string  binario;
    
    Caracter *proximoElemento;
    
    Caracter *elementoAnterior;
    
};
//Lista onde salva o primeiro elemento da lista de caracter
class ListaCaracter
{
public:
    
    Caracter * primeiroElemento = nullptr;
    
    
    //METODOS
    
    //verifica se existe o caracter
    Caracter* verificaExistencia(char caracter)
    {
        Caracter *aux = primeiroElemento;
        
        while(aux != nullptr)
        {
            if(aux->caracter == caracter)
            {
                return aux;
            }
            
            aux= aux->proximoElemento;
        }
    
        return nullptr;
    }

    //adiciona novo elemento
    void adicionaNovoElemento(Caracter* caracter)
    {
        if(primeiroElemento == nullptr)
        {
            primeiroElemento = caracter;
            
            return;
        }
        
        Caracter* aux = primeiroElemento;
        
        while(aux->proximoElemento != nullptr)
        {
            aux = aux->proximoElemento;
        }
        
        //adiciona a referencia ao elemento anterior
        caracter->elementoAnterior = aux;
        
        //adiciona o novo elemento ao final da lista
        aux->proximoElemento = caracter;
        
    }
    
    void imprimirElementos()
    {
        
        cout << "\n\nIMPRIMINDO LISTA DE CARACTERES\n";
        
        Caracter* aux = primeiroElemento;
        
        int i = 0;

        while (aux != nullptr)
        {
            
            cout << i << "  " << aux->caracter << "   " << aux->quantidade << "   " << aux->binario << endl;
            
            i++;
            
            aux = aux->proximoElemento;
        }
        cout << "\nLISTA IMPRESSA\n";
    }
    
    void ordenaSelectionSort()
    {
        
        if(primeiroElemento != nullptr)
        {
            cout << endl << endl << "ORDENANDO LISTA" << endl;
            
            Caracter* auxI, *auxJ, aux, *auxRef;
            
            auxI = primeiroElemento;
            
           while(auxI != nullptr)
           {
               auxJ = auxI->proximoElemento;
               
               while (auxJ != nullptr)
               {
                   if(auxJ->quantidade > auxI->quantidade)
                   {
                       char caracterAuxiliar;
                       
                       int quantidade;
                       
                       caracterAuxiliar = auxI->caracter;
                       quantidade = auxI->quantidade;
                       
                       auxI->caracter = auxJ->caracter;
                       auxI->quantidade = auxJ->quantidade;
                       
                       auxJ->caracter = caracterAuxiliar;
                       auxJ->quantidade = quantidade;
                       
                   }
                   
                   auxJ = auxJ->proximoElemento;
               }
            
               auxI = auxI->proximoElemento;
           }
        
        }
        
        cout << endl << endl << "LISTA ORDENADA POR SELECTION SORT" << endl;
    
    }
    
    //converte de binario para decimal
    long binaryToDecimal(long n)
    {
        
        int remainder;
        
        long decimal = 0, i=0;
        
        while(n != 0) {
           
            remainder = n%10;
            
            n = n/10;
            
            decimal = decimal + (remainder* pow(2,i));
            
            ++i;
        }
        return decimal;
    }
    
    //converte de decimal para binario
    long decimalToBinary(long n)
    {
        
        int remainder;
        
        long binary = 0, i = 1;
        
        while(n != 0) {
        
            remainder = n%2;
            
            n = n/2;
            
            binary= binary + (remainder*i);
            
            i = i*10;
        }
        return binary;
    }
    
    //método que gera o binario para cada caracter
    void gerarBinarioCadaCaracterLista()
    {
        cout << "\n\nGERANDO BINARIO PARA CADA ELEMENTO\n";
        
        Caracter* aux = primeiroElemento;
        
        int i = 0, j = 0;
        
        while (aux != nullptr)
        {
            for (j = 0; j < i ; j++)
            {
                aux->binario.append("1");
            }
            
            aux->binario.append("0");
            
            i++;
            
            aux = aux->proximoElemento;
        }
        
         cout << "\nBINARIO PARA CADA ELEMENTO GERADO";
        
    }
    
    //gera uma lista de bits consultado cada caracter do texto original e transformando através da lista binario por caracter gerada anteriormente
    void geraListaBinaria(string texto, ListaInteiro *listaInteiro)
    {
        cout << "\n\nGERANDO LISTA BINARIA" ;
        
        int i, j;
    
        for(i = 0; i < texto.length(); i ++)
        {
            Caracter * aux = primeiroElemento;
            
            while(aux != nullptr)
            {
                if(texto[i] == aux->caracter)
                {
                    for (j = 0; j < aux->binario.length(); j++)
                    {
                        //pega a diferenca entre dois chars
                        listaInteiro->append(aux->binario[j] - '0');
                    }
                    break;
                }
            
                aux = aux->proximoElemento;
            }
        }
        
         cout << "\n\nLISTA BINARIA GERADA\n";
    }
    
    //metodo que grava a lista binario no arquivo
    //utiliza chars como meio para a gravacao do binario
    

    void criptografa(ListaInteiro * listaBits)
    {
        cout << "TRANSFORMANDO LISTA BITS PARA GRAVAR NO ARQUIVO" << endl;
    
        FILE *pa;
        
        char *nome = "/Users/mateusgomes/Downloads/texto.bin";
        
        if (( pa = fopen(nome, "w+b")) == NULL)
        {
            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
            
            exit(1);
        }
        
        int i;
        
        char novoByte = 0;
        
        long byte = 0, decimal;
    
        for (i = 0; i < listaBits->ultimoElemento; i++)
        {
            if (i%8 == 0 )
            {
                if(i != 0)
                {
                    decimal = binaryToDecimal(byte);
                    
                    novoByte = binaryToDecimal(byte);
                    
                    cout << novoByte  << endl;
                    
                    fwrite(&novoByte, 1, sizeof(novoByte), pa);
                    
                    cout << " B: " << byte << " D: " << decimal << " C: " <<  novoByte << endl;

                    
                }
            
                byte =  pow(10, 7 - i%8)*listaBits->vetorInteiro[i];
                
            }
            else
            {
            
                byte = byte + pow(10, 7 - i%8)*listaBits->vetorInteiro[i];
        
            }
        
        }
        fclose(pa);
        
        cout << "ARQUIVO GRAVADO\n";
    }
    void descriptografa()
    {
        
        cout << endl << "DESCRIPTOGRAFANDO " << endl;
        
        //lê arquivo enquanto não chegar em eof
        FILE *pa;
    
        char *nome = "/Users/mateusgomes/Downloads/texto.bin";
        
        if (( pa = fopen(nome, "rb")) == NULL)
        {
            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
          
            exit(1);
        }
        unsigned byte;
        
        string binario = "", tmp;
        int i;
    
        while(!feof(pa))
        {
            fread(&byte, 1,1, pa);
            
            cout << "D: " << byte <<  " B: " << decimalToBinary((long)byte) << endl;
            
            tmp = to_string(decimalToBinary((long)byte));
            
            if(tmp.length() < 8)
            {
                for(i = 0; i < 8 - tmp.length(); i++)
                {
                    binario.append("0");
                }
            }
            
            binario += to_string( decimalToBinary((long)byte));
           
            
        }
        
        cout << "\nBINARIO GERADO\n" << binario << "\n\n\nGERANDO TEXTO ORIGINAL\n\n";
        

        int contador = 0 ;
        
        for (i = 0; i < binario.length(); i++)
        {
            if(binario[i] == '0')
            {
                Caracter *aux = primeiroElemento;
                
                int j = 0;
                
                while (aux != nullptr)
                {
                    if(j == contador)
                    {
                        cout << aux->caracter;
                        break;
                    }
                    
                    j++;
                    
                    aux = aux->proximoElemento;
                }
                contador = 0;
            }
            if(binario[i] == '1')
            {
                contador++;
            }
        }
        cout << endl << endl;
    
        fclose(pa);
        
        cout << "DESCRIPTOGRAFADO\n";
    }
    
    
    
};

int main(int argc, const char * argv[])
{

//    string texto =  "sdfsdfsdfsdfsdf fdjsjdbfksbdfkab ,ndskjhiquyweuirn,sdf .kldghf8oity8734y5873grbkfbalkfga89s7tr8q9ogrkabv  a ahufdpiay9df7tyq79w8r 9qhto jnlsdnfopauysb07r yqp943hto;qhjfo; ay ip79t a879ftq9hróq[ri qfyfpq9ewho \n nh2op 0 yp9ay8fahv,bcv/lnaáj ifq[]r]-q\rqipa iag idufypia";
//    
    string texto = "Se você copiar um texto de uma página da Internet para colar em um documento do Word e usar somente os comandos Copiar e Colar, o texto será colado no Word mantendo todo o formato original da Internet; podem aparecer uma coisas estranhas como misteriosos formatos de letras e tabelas HTML.Em muitos casos, isso é indesejável e resulta em um trabalho extra para reformatar tudo como texto autêntico do Word. Para evitar esses transtornos, use o comando Colar especial, em vez do comando Colar, da seguinte maneira: Na página da Internet, selecione o texto que você quer copiar. Tecla Ctrl-C para copiar o texto selecionado para a área de transferência do Windows. Abra o Word e posicione o cursor no ponto a partir do qual será colado o novo texto. Clique no menu Editar. Clique no comando Colar especial. No campo Como\" da caixa de diálogo \"Colar Especial\", selecione a opção Texto não formatado. Clique no botão OK.";
    
    //string texto = " mateus pereira gomes mateus pereira gomes estela pereira gomes katia regina renata pestana ,./l;[]\" ";
    
    int i;
    
    ListaCaracter* lista = new ListaCaracter();
    
    for(i = 0; i  < texto.length(); i++)
    {
        Caracter *existente =  lista->verificaExistencia(texto[i]);
        
        if (existente == nullptr)
        {
            //cria novo elemento
            
            Caracter *novoElemento = new Caracter();
            
            novoElemento->caracter = texto[i];
            
            novoElemento->quantidade = 1;
            
            novoElemento->proximoElemento = nullptr;
            
            novoElemento->elementoAnterior = nullptr;
            
            novoElemento->binario = "";
            
            //adiciona novo elemento na Lista
            
            lista->adicionaNovoElemento(novoElemento);
        }
        else{
            existente->quantidade++;
        }
    }
    
    lista->imprimirElementos();
    
    lista->ordenaSelectionSort();
    
    lista->imprimirElementos();
    
    
    lista->gerarBinarioCadaCaracterLista();
    
    lista->imprimirElementos();
    
    ListaInteiro * listaBinario = new ListaInteiro();
    
    lista->geraListaBinaria(texto, listaBinario);
    
    listaBinario->print();
    
    lista->criptografa(listaBinario);
    
    lista->descriptografa();
    
    cout << "\n\nQUANTIDADE ORIGINAL \nbytes: " << texto.length() << " \nbits: " << texto.length()*8 << endl;
    
    cout << "\nQUANTIDADE CRIOPTOGRAFADO - Lista binária\nbytes: " << (listaBinario->ultimoElemento)/8 << " \nbits: " << (listaBinario->ultimoElemento) << endl;
    
}
