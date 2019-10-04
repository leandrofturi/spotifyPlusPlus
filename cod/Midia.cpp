#include "../bib/Midia.hpp"

Midia::Genero::Genero()
{
    this->midias = new std::list<Midia*>;
}

Midia::Genero::Genero(std::string nome, std::string sigla)
{
    this->nome = nome;
    this->sigla = sigla;

    this->midias = new std::list<Midia*>;
}

Midia::Genero::~Genero()
{
    delete this->midias;
}

std::list<Midia*>* Midia::Genero::getMidias()
{
    return this->midias;
}

void Midia::Genero::setMidias(std::list<Midia*>* midias)
{
    this->midias = midias;
}

void Midia::Genero::addMidia(Midia* midia)
{
    this->midias->push_back(midia);
}

void Midia::Genero::rmMidia(Midia* midia)
{
    this->midias->remove(midia);
}

std::string Midia::Genero::getNome()
{
    return this->nome;
}

void Midia::Genero::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Midia::Genero::getSigla()
{
    return this->sigla;
}

void Midia::Genero::setSigla(std::string sigla)
{
    this->sigla = sigla;
}

int qtdProdutos = 0;

Midia::Midia()
{
    this->qtdProdutos ++;

    this->produtores = new std::list<Produtor*>;
}

Midia::Midia(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;

    this->genero = genero;

    this->qtdProdutos ++;

    this->produtores = new std::list<Produtor*>;
}

Midia::~Midia()
{
    this->qtdProdutos --;

    delete this->produtores;
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

void Midia::setCodigo(int codigo)
{
    this->codigo = codigo;
}

int Midia::getDuracao()
{
    return this->duracao;
}

void Midia::setDuracao(int duracao)
{
    this->duracao = duracao;
}

int Midia::getAnoLancamento()
{
    return this->anoLancamento;
}

void Midia::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

void Midia::imprimeQtdProdutos()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Quantidade de produtos de " << this->getNome() << ":" << std::endl;
    std::cout << this->qtdProdutos << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}

Midia::Genero* Midia::getGenero()
{
    return this->genero;
}

void Midia::setGenero(Midia::Genero* genero)
{
    this->genero = genero;
}

std::list<Produtor*>* Midia::getProdutores()
{
    return this->produtores;
}

void Midia::setProdutores(std::list<Produtor*>* produtores)
{
    this->produtores = produtores;
}

void Midia::addProdutor(Produtor* produtor)
{
    this->produtores->push_back(produtor);
}