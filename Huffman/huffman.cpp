////
////  main.cpp
////  Huffman
////
////  Created by mateus gomes on 7/5/17.
////  Copyright © 2017 mateus gomes. All rights reserved.
////
//
//
//
//
//
//
//#include <iostream>
//#include <string>
//#include <math.h>
//#include<fstream>
//#include<cstdio>
//
//using namespace std;
//class ListaInteiro
//{
//public:
//    int *vetorInteiro;
//    
//    int quantidadeElementos;
//    
//    int ultimoElemento;
//    
//    ListaInteiro()
//    {
//        inicializaLista();
//    }
//    
//    void inicializaLista()
//    {
//        quantidadeElementos = 1000;
//        
//        vetorInteiro = (int*)malloc(sizeof(int)*1000);
//        
//        ultimoElemento = 0;
//        
//        int i;
//        
//        for (i = 0; i < quantidadeElementos; i++)  vetorInteiro[i] = 0;
//    }
//    
//    //adiciona novo elemento
//    void append(int elemento)
//    {
//        //verifica se tamanho é menor
//        
//        if(ultimoElemento >= quantidadeElementos)
//        {
//            quantidadeElementos += 1000;
//            
//            //adiciona mais posicoes no vetor
//            vetorInteiro =  (int *)realloc(vetorInteiro, quantidadeElementos*sizeof(int) );
//        }
//        
//        vetorInteiro[ultimoElemento] = elemento;
//        
//        ultimoElemento++;
//        
//    }
//    
//    //limpa lista
//    void clear()
//    {
//        free(vetorInteiro);
//        quantidadeElementos = 0;
//        ultimoElemento = 0;
//    }
//    //imprime vetor
//    void print()
//    {
//        cout << endl << endl;
//        
//        int i;
//        
//        for (i = 0; i < ultimoElemento; i++)
//        {
//            if(i%8==0)
//            {
//                cout << " ";
//            }
//            
//            cout << vetorInteiro[i];
//        }
//        
//        cout << endl << endl;
//    }
//};
//
//
//
//struct Caracter
//{
//    char caracter;
//    
//    int quantidade;
//    string  binario;
//    Caracter *proximoElemento;
//    Caracter *elementoAnterior;
//    
//};
//
//class ListaCaracter
//{
//public:
//    Caracter * primeiroElemento = nullptr;
//    
//    
//    Caracter* verificaExistencia(char caracter)
//    {
//        Caracter *aux = primeiroElemento;
//        
//        
//        while(aux != nullptr)
//        {
//            if(aux->caracter == caracter)
//            {
//                return aux;
//            }
//            
//            
//            aux= aux->proximoElemento;
//        }
//        
//        
//        return nullptr;
//    }
//    
//    void adicionaNovoElemento(Caracter* caracter)
//    {
//        if(primeiroElemento == nullptr)
//        {
//            primeiroElemento = caracter;
//            
//            return;
//        }
//        
//        Caracter* aux = primeiroElemento;
//        
//        while(aux->proximoElemento != nullptr)
//        {
//            aux = aux->proximoElemento;
//        }
//        
//        caracter->elementoAnterior = aux;
//        
//        aux->proximoElemento = caracter;
//        
//    }
//    void imprimirElementos()
//    {
//        Caracter* aux = primeiroElemento;
//        
//        int i = 0;
//        
//        while (aux != nullptr)
//        {
//            
//            cout << i << "  " << aux->caracter << "   " << aux->quantidade << "   " << aux->binario << endl;
//            
//            i++;
//            aux = aux->proximoElemento;
//        }
//    }
//    void ordenaSelectionSort()
//    {
//        
//        if(primeiroElemento != nullptr)
//        {
//            cout << "Ordenando Lista" << endl;
//            
//            Caracter* auxI, *auxJ, aux, *auxRef;
//            
//            auxI = primeiroElemento;
//            
//            while(auxI != nullptr)
//            {
//                auxJ = auxI->proximoElemento;
//                
//                while (auxJ != nullptr)
//                {
//                    //cout << auxJ->quantidade << "  " <<  auxI->quantidade << endl;
//                    
//                    if(auxJ->quantidade > auxI->quantidade)
//                    {
//                        // cout << "troca" << endl;
//                        
//                        char caracterAuxiliar;
//                        int quantidade;
//                        
//                        caracterAuxiliar = auxI->caracter;
//                        quantidade = auxI->quantidade;
//                        
//                        auxI->caracter = auxJ->caracter;
//                        auxI->quantidade = auxJ->quantidade;
//                        
//                        auxJ->caracter = caracterAuxiliar;
//                        auxJ->quantidade = quantidade;
//                        
//                    }
//                    
//                    auxJ = auxJ->proximoElemento;
//                }
//                
//                auxI = auxI->proximoElemento;
//            }
//            
//        }
//        
//    }
//    
//    long binaryToDecimal(long n) {
//        int remainder;
//        long decimal = 0, i=0;
//        while(n != 0) {
//            remainder = n%10;
//            n = n/10;
//            decimal = decimal + (remainder* pow(2,i));
//            ++i;
//        }
//        return decimal;
//    }
//    
//    long decimalToBinary(long n) {
//        int remainder;
//        long binary = 0, i = 1;
//        
//        while(n != 0) {
//            remainder = n%2;
//            n = n/2;
//            binary= binary + (remainder*i);
//            i = i*10;
//        }
//        return binary;
//    }
//    void gerarBinarioCadaCaracterLista()
//    {
//        //        int i = 0, soma = 0;
//        //
//        //        Caracter* aux = primeiroElemento;
//        //
//        //        while (aux != nullptr)
//        //        {
//        //            soma = soma + pow(2, i);
//        //
//        //            aux->binario = (string)(decimalToBinary(soma) -1);
//        //            i++;
//        //            aux = aux->proximoElemento;
//        //        }
//        
//        Caracter* aux = primeiroElemento;
//        
//        int i = 0, j = 0;
//        
//        while (aux != nullptr)
//        {
//            for (j = 0; j < i ; j++)
//            {
//                aux->binario.append("1");
//            }
//            aux->binario.append("0");
//            i++;
//            aux = aux->proximoElemento;
//        }
//        
//    }
//    void gravarTextoEmBinario(string texto)
//    {
//        //para cada letra do texto verifica qual é o binario especifico e escreve no arquivo
//        
//        
//        
//        
//        //
//        //        FILE *pa;
//        //        char *nome = "/Users/mateusgomes/Downloads/texto.txt";
//        //
//        //        if (( pa = fopen(nome, "w+b")) == NULL) {
//        //            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
//        //            exit(1);
//        //        }
//        //
//        //        int bit;
//        //
//        //        Caracter* aux = primeiroElemento;
//        //        int i;
//        //        string auxiliar;
//        //        char teste;
//        //
//        //        while (aux != nullptr)
//        //        {
//        //            for (i = 0; i < aux->binario.length(); i++)
//        //            {
//        //                auxiliar = aux->binario;
//        //
//        //                teste = auxiliar[i];
//        //
//        //                fwrite(&teste, sizeof(teste), 1, pa);
//        //            }
//        //
//        //
//        //            aux = aux->proximoElemento;
//        //        }
//    }
//    
//    void gravarArquivoBytes()
//    {
//        FILE *pa;
//        char *nome = "/Users/mateusgomes/Downloads/texto.txt";
//        
//        if (( pa = fopen(nome, "w+b")) == NULL) {
//            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
//            exit(1);
//        }
//        
//        int bit;
//        
//        Caracter* aux = primeiroElemento;
//        int i;
//        string auxiliar;
//        uint8_t teste;
//        
//        //uint8_t binario;
//        char *testeChar;
//        
//        
//        while (aux != nullptr)
//        {
//            for (i = 0; i < aux->binario.length(); i++)
//            {
//                auxiliar = aux->binario;
//                
//                testeChar = &auxiliar[i];
//                
//                cout << auxiliar[i] << endl;
//                
//            }
//            
//            aux = aux->proximoElemento;
//        }
//        
//        fwrite(&testeChar, 1, sizeof(testeChar), pa);
//    }
//    
//    void gravacaoArquivoTeste2()
//    {
//        ofstream outFile;
//        outFile.open("/Users/mateusgomes/Downloads/texto.txt", ios::binary | ios::app);
//        
//        // Student obj;
//        
//        //obj.setData();
//        
//        char binario = 0;
//        int i;
//        char novoTeste[] = "01010101";
//        
//        for (i = 0; i < 1000; i++)
//        {
//            if(i%2==0)
//            {
//                binario = 1;
//            }
//            else
//            {
//                binario = 0;
//            }
//            
//            // outFile.write(&novoTeste, sizeof(novoTeste[0]));
//        }
//        outFile.write(novoTeste, sizeof(novoTeste));
//        
//        
//        outFile.close();
//    }
//    
//    void lerArquivoBytes()
//    {
//        FILE *pa;
//        char *nome = "/Users/mateusgomes/Downloads/texto.txt";
//        
//        if (( pa = fopen(nome, "w+b")) == NULL) {
//            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
//            exit(1);
//        }
//        long leitura;
//        
//        
//        fread(&leitura,1, 1, pa);
//        cout << leitura << endl;
//        
//        fread(&leitura,1, 1, pa);
//        cout << leitura << endl;
//        
//        //        fread(&leitura,1, 1, pa);
//        //        cout << leitura << endl;
//        //
//        //        fread(&leitura,1, 1, pa);
//        //        cout << leitura << endl;
//        //
//        //        fread(&leitura,1, 1, pa);
//        //        cout << leitura << endl;
//        
//        
//        
//        //        while (!feof(stdin)) {
//        //            fread(&leitura,1, 1, pa);
//        //
//        //            cout << leitura << endl;
//        //        }
//        
//        
//    }
//    void geraStringBits(string texto, ListaInteiro *listaInteiro)
//    {
//        int i, j;
//        
//        for(i = 0; i < texto.length(); i ++)
//        {
//            Caracter * aux = primeiroElemento;
//            
//            while(aux != nullptr)
//            {
//                if(texto[i] == aux->caracter)
//                {
//                    for (j = 0; j < aux->binario.length(); j++)
//                    {
//                        listaInteiro->append(aux->binario[j] - '0');
//                    }
//                    break;
//                }
//                
//                aux = aux->proximoElemento;
//            }
//        }
//        
//    }
//    char bitsToByte(int bits[]) {
//        char meuByte = 0;
//        for(int i=0; i<8; i++) {
//            meuByte += bits[i];
//            meuByte <<= 1;
//        }
//        return meuByte;
//    }
//    long long convertDecimalToBinary(int n)
//    {
//        long long binaryNumber = 0;
//        int remainder, i = 1, step = 1;
//        
//        while (n!=0)
//        {
//            remainder = n%2;
//            printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, remainder, n/2);
//            n /= 2;
//            binaryNumber += remainder*i;
//            i *= 10;
//        }
//        return binaryNumber;
//    }
//    void criptografa(ListaInteiro * listaBits)
//    {
//        FILE *pa;
//        
//        char *nome = "/Users/mateusgomes/Downloads/texto.bin";
//        
//        if (( pa = fopen(nome, "w+b")) == NULL)
//        {
//            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
//            
//            exit(1);
//        }
//        
//        int i;
//        
//        char novoByte = 0;
//        
//        long byte = 0;
//        
//        for (i = 0; i < listaBits->ultimoElemento; i++)
//        {
//            if (i%8 == 0 )
//            {
//                cout << novoByte <<  "   "  << (int)novoByte << "   " << decimalToBinary((long)novoByte) << "    " << byte <<  " " << binaryToDecimal(byte) << " ";;
//                
//                if(i != 0)
//                {
//                    novoByte = binaryToDecimal(byte);
//                    
//                    cout << novoByte  << endl;
//                    // fwrite(&novoByte, 1, sizeof(novoByte), pa);
//                    fwrite(&novoByte, 1, sizeof(novoByte), pa);
//                    
//                }
//                
//                novoByte = listaBits->vetorInteiro[i];
//                
//                byte =  pow(10, 7 - i%8)*listaBits->vetorInteiro[i];
//                
//            }
//            else
//            {
//                novoByte += listaBits->vetorInteiro[i];
//                novoByte <<= 1;
//                
//                
//                byte = byte + pow(10, 7 - i%8)*listaBits->vetorInteiro[i];
//                
//            }
//            
//        }
//        fclose(pa);
//    }
//    void descriptografa()
//    {
//        
//        cout << endl << "DESCRIPTOGRAFANDO " << endl;
//        
//        //lê arquivo enquanto não chegar em eof
//        FILE *pa;
//        
//        char *nome = "/Users/mateusgomes/Downloads/texto.bin";
//        
//        if (( pa = fopen(nome, "rb")) == NULL)
//        {
//            printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
//            
//            exit(1);
//        }
//        unsigned byte;
//        
//        string binario = "", tmp;
//        int i;
//        
//        while(!feof(pa))
//        {
//            fread(&byte, 1,1, pa);
//            
//            cout << byte <<  " " << (long) byte << "  " << decimalToBinary((long)byte) << endl;
//            
//            tmp = to_string(decimalToBinary((long)byte));
//            
//            if(tmp.length() < 8)
//            {
//                for(i = 0; i < 8 - tmp.length(); i++)
//                {
//                    binario.append("0");
//                }
//            }
//            
//            binario += to_string( decimalToBinary((long)byte));
//            
//            
//        }
//        cout << binario << endl << endl << endl;
//        
//        int contador = 0 ;
//        
//        for (i = 0; i < binario.length(); i++)
//        {
//            if(binario[i] == '0')
//            {
//                Caracter *aux = primeiroElemento;
//                
//                int j = 0;
//                
//                while (aux != nullptr)
//                {
//                    if(j == contador)
//                    {
//                        cout << aux->caracter;
//                        break;
//                    }
//                    
//                    j++;
//                    
//                    aux = aux->proximoElemento;
//                }
//                contador = 0;
//            }
//            if(binario[i] == '1')
//            {
//                contador++;
//            }
//        }
//        cout << endl << endl;
//        
//        //jogar tudo dentro de uma string
//        //pegar cada caractere e transformar seu inteiro em binarios
//        //com a lista de binarios traduzir a cada pedaço
//        fclose(pa);
//    }
//    
//};
//
//int main(int argc, const char * argv[])
//{
//    
//    //    string texto =  "sdfsdfsdfsdfsdf fdjsjdbfksbdfkab ,ndskjhiquyweuirn,sdf .kldghf8oity8734y5873grbkfbalkfga89s7tr8q9ogrkabv  a ahufdpiay9df7tyq79w8r 9qhto jnlsdnfopauysb07r yqp943hto;qhjfo; ay ip79t a879ftq9hróq[ri qfyfpq9ewho \n nh2op 0 yp9ay8fahv,bcv/lnaáj ifq[]r]-q\rqipa iag idufypia";
//    //
//    
//    string texto = " mateus pereira gomes mateus pereira gomes estela pereira gomes katia regina renata pestana ,./l;[]\" ";
//    
//    int i;
//    
//    ListaCaracter* lista = new ListaCaracter();
//    
//    for(i = 0; i  < texto.length(); i++)
//    {
//        Caracter *existente =  lista->verificaExistencia(texto[i]);
//        
//        if (existente == nullptr)
//        {
//            //cria novo elemento
//            
//            Caracter *novoElemento = new Caracter();
//            
//            novoElemento->caracter = texto[i];
//            
//            novoElemento->quantidade = 1;
//            
//            novoElemento->proximoElemento = nullptr;
//            
//            novoElemento->elementoAnterior = nullptr;
//            
//            novoElemento->binario = "";
//            
//            //adiciona novo elemento na Lista
//            
//            lista->adicionaNovoElemento(novoElemento);
//        }
//        else{
//            existente->quantidade++;
//        }
//    }
//    
//    lista->imprimirElementos();
//    
//    lista->ordenaSelectionSort();
//    
//    lista->imprimirElementos();
//    
//    
//    lista->gerarBinarioCadaCaracterLista();
//    
//    lista->imprimirElementos();
//    
//    ListaInteiro * listaBinario = new ListaInteiro();
//    
//    lista->geraStringBits(texto, listaBinario);
//    
//    listaBinario->print();
//    
//    lista->criptografa(listaBinario);
//    
//    lista->descriptografa();
//    
//    
//}
