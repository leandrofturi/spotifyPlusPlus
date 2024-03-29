#include "../bib/Midia.hpp"

Midia::Genero::Genero() {}

Midia::Genero::Genero(std::string nome, std::string sigla)
{
    this->nome = nome;
    this->sigla = sigla;
}

Midia::Genero::~Genero() {}

std::string Midia::Genero::getNome()
{
    return this->nome;
}

std::string Midia::Genero::getSigla()
{
    return this->sigla;
}

int qtdMidias = 0;

Midia::Midia()
{
    this->qtdMidias ++;
}

Midia::Midia(std::string nome, int codigo, double duracao, int anoLancamento, Midia::Genero* genero)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;

    this->genero = genero;

    this->qtdMidias ++;
}

Midia::~Midia()
{
    this->qtdMidias --;
}

std::string Midia::getNome()
{
    return this->nome;
}

void Midia::setNome(std::string nome)
{
    this->nome = nome;
}

int Midia::getCodigo()
{
    return this->codigo;
}

double Midia::getDuracao()
{
    return this->duracao;
}

void Midia::setDuracao(double duracao)
{
    this->duracao = duracao;
}

std::string Midia::formataDuracao()
{
    return cpp_util::formatsHours(60*this->duracao);
}

int Midia::getAnoLancamento()
{
    return this->anoLancamento;
}

void Midia::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

std::string Midia::getTipo()
{
    if(this->tipo == "MUSICA")
    {
        return "Musica";
    }
    else if(this->tipo == "PODCAST")
    {
        return "Podcast";
    }
    return "Indefinido";
}

Midia::Genero* Midia::getGenero()
{
    return this->genero;
}

std::string Midia::getProdutores()
{
    std::string produtores;
    for(std::string aux : this->produtores)
    {
        produtores.append(aux);
        produtores.append(",");
    }
    return produtores.substr(0, produtores.size()-1);
}

void Midia::addProdutor(std::string produtor)
{
    for(std::string aux : this->produtores)
        if(aux == produtor) return;
    this->produtores.push_back(produtor);
}

void Midia::rmProdutor(std::string produtor)
{
    this->produtores.remove(produtor);
}

void Midia::imprimeQtdMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Quantidade de produtos de " << this->getNome() << ":" << std::endl;
    std::cout << this->qtdMidias << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}