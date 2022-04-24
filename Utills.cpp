#include "Utills.h"
std::vector<std::string>split(std::string frase, std::string delimitador)
{
    std::stringstream ss(frase);
    std::string tok;
    char* pdelim = &delimitador[0];
    char delim = *pdelim;
    std::vector<std::string> palavra;
    while (getline(ss, tok, delim))
    {
        if (!tok.empty()) palavra.push_back(tok);
    }
    return palavra;
}
//implementaçãoes da Classes Grafo
Grafo::Grafo(std::vector<std::vector<int> >& arestas_, std::vector<std::string>& vertices_)
{
    vertices = vertices_;
    arestas = arestas_;
}
Grafo::Grafo()
{

}
void Grafo::setValues(Grafo grafo_)
{
    arestas = grafo_.getArestas();
    vertices = grafo_.getVertices();
}
std::vector<std::string>Grafo::getVertices()
{
    return vertices;
}
std::string Grafo::getVerticesValue(int op)
{
    return vertices[op];
}
std::vector<std::vector<int>> Grafo::getArestas()
{
    return arestas;
}
int Grafo::getArestasValue(int i, int j)
{
    return arestas[i][j];
}
void Grafo::showArestasValue()
{
    for (int i = 0; i < this->getArestas().size(); i++)
        for (int j = 0; j < this->getArestas()[i].size(); j++)
            std::cout << this->getArestasValue(i, j) << std::endl;
}
void Grafo::showArestasValueByIndex(int index)
{
    for (int j = 0; j < this->getArestas()[index].size(); j++)
        std::cout << this->getArestasValue(index, j) << std::endl;
}
int Grafo::getVerticesSize()
{
    return this->getVertices().size();
}
int Grafo::getArestasSize()
{
    return this->getArestas().size();
}
//fim das implementações da Classe Grafo

Grafo lerDat(std::string nome)
{
    std::ifstream arquivo;
    arquivo.open(nome);
    std::vector<std::vector<int>>arestas;
    std::vector<std::string> vertices;
    int c = 0;
    int t = 0;
    while (!arquivo.eof())
    {
        std::string linha;
        getline(arquivo, linha);
        std::vector<std::string> conteudo = split(linha, " ");
        if (c == 0) c = std::stoi(conteudo[0]);
        else
        {
            std::vector<int> a;
            for (auto i : conteudo)
            {
                if (i == "-1") break;
                a.push_back(std::stoi(i));
            }
            if (!a.empty()) arestas.push_back(a);
        }
    }
    for (int i = 1; i < c + 1; i++)
    {
        vertices.push_back(std::to_string(i));
    }
    Grafo grafo = Grafo(arestas, vertices);
    return grafo;
}
