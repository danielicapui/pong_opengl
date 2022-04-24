#pragma once
#ifndef UTILLS_H
#define UTILLS_H
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
//uma classe que representa um grafo composto vertices e arestas
class Grafo
{
private:
    std::vector<std::string> vertices;
    std::vector<std::vector<int>> arestas;
public:
    Grafo(void);
    Grafo(std::vector<std::vector<int> >& arestas_, std::vector<std::string>& vertices_);//constructor que recebe dois vetores
    std::vector<std::string>  getVertices();//retorna um vetor de string corresponde ao nome dos vértices
    std::string getVerticesValue(int); //retorna uma string do vértice correspondente ao index
    std::vector<std::vector<int>> getArestas();//retorna uma int corresponde ao peso da aresta
    int getArestasValue(int, int);//retorna uma int corresponde ao peso da aresta
    void showArestasValue();//método para mostrar todas arestas e seus valores
    void showArestasValueByIndex(int index);//mostra arestas por um index
    int getVerticesSize();
    int getArestasSize();
    void setValues(Grafo);
};
std::vector<std::string> split(std::string frase, std::string delimitador = " ");//serve para dividir um string em vetor dividida por um delimitador

Grafo lerDat(std::string nome);//método para ler um arquivo dat e retorna um grafo


class Utills
{
};

#endif