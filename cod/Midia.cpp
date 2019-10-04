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

int qtdMidias = 0;

Midia::Midia()
{
    this->qtdMidias ++;

    this->produtores = new std::list<Produtor*>;
}

Midia::Midia(std::string nome, int codigo, int duracao, int anoLancamento, char tipo, Midia::Genero* genero)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->tipo = tipo;

    this->genero = genero;

    this->qtdMidias ++;

    this->produtores = new std::list<Produtor*>;
}

Midia::~Midia()
{
    this->qtdMidias --;

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

std::string Midia::getTipo()
{
    if(this->tipo == 'M')
    {
        return "Musica";
    }
    else if(this->tipo == 'P')
    {
        return "Podcast";
    }
    return "Indefinido";
}

void Midia::imprimeQtdMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Quantidade de produtos de " << this->getNome() << ":" << std::endl;
    std::cout << this->qtdMidias << std::endl;
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

void Midia::rmProdutor(Produtor* produtor)
{
    this->produtores->remove(produtor);
}