#include "../bib/Assinante.hpp"

Assinante::Assinante()
{
    this->favoritas = new std::list<Midia*>;
}

Assinante::Assinante(std::string nome, int codigo)
    : Usuario(nome, codigo)
{
    this->favoritas = new std::list<Midia*>;
}

Assinante::~Assinante()
{
    delete this->favoritas;
}

void Assinante::addFavorita(Midia* favorita)
{
    if(this->buscaFavorita(favorita->getCodigo()) == NULL)
        this->favoritas->push_back(favorita);
}

Midia* Assinante::buscaFavorita(int codigo)
{
    for(Midia* aux :*this->favoritas)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Assinante::rmFavorita(Midia* favorita)
{
    this->favoritas->remove(favorita);
}

void Assinante::imprimeFavoritas()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias favoritas de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Midia* aux : *this->favoritas)
    {
        std::cout << aux->getTipo() << std::endl;
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->formataDuracao() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

void Assinante::escreveMidiaNoArquivo(std::ofstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    for(Midia* auxMid : *this->favoritas)
    {
        file << this->codigo;
        file << ";";
        file << auxMid->getTipo();
        file << ";";
        file << auxMid->getCodigo();
        file << ";";
        file << auxMid->getGenero()->getNome();
        file << ";";
        file << auxMid->formataDuracao();
        file << std::endl;
    }
}