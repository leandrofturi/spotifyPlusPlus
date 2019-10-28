#include "../bib/Album.hpp"

Album::Album()
{
    this->musicas = new std::list<Musica*>;
    this->qtdMusicas = 0;
}

Album::Album(std::string nome, int codigo, int duracao, int anoLancamento)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->qtdMusicas = 0;

    this->musicas = new std::list<Musica*>;
}

Album::~Album()
{
    for(Musica* aux : *this->musicas) delete aux;
    //RELACAO DE COMPOSICAO
    delete this->musicas;

    this->qtdMusicas = 0;
}

std::string Album::getNome()
{
    return this->nome;
}

void Album::setNome(std::string nome)
{
    this->nome = nome;
}

int Album::getCodigo()
{
    return this->codigo;
}

int Album::getDuracao()
{
    return this->duracao;
}

void Album::setDuracao(int duracao)
{
    this->duracao = duracao;
}

int Album::getAnoLancamento()
{
    return this->anoLancamento;
}

void Album::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

int Album::getQtdMusicas()
{
    return this->qtdMusicas;
}

void Album::addMusica(Musica* musica)
{
    if(this->buscaMusica(musica->getCodigo()) == NULL)
    {
        musica->setAlbum(this->nome);
        this->musicas->push_back(musica);
        this->qtdMusicas ++;
    }
}

void Album::rmMusica(Musica* musica)
{
    musica->setAlbum("");
    this->musicas->remove(musica);
    this->qtdMusicas --;
}

Musica* Album::buscaMusica(int codigo)
{
    for(Musica* aux :*this->musicas)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Album::imprimeMusicas()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Musicas de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Midia* aux : *this->musicas)
    {
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->formataDuracao() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}