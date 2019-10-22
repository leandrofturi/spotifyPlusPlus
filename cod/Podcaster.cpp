#include "../bib/Podcaster.hpp"

Podcaster::Podcaster() 
{
    this->podcasts = new std::list<Podcast*>;
}

Podcaster::Podcaster(std::string nome, int codigo)
    : Produtor(nome, codigo)
{
    this->podcasts = new std::list<Podcast*>;
}

Podcaster::~Podcaster()
{
    delete this->podcasts;
}

void Podcaster::addPodcast(Podcast* podcast)
{
    if(buscaPodcast(podcast->getCodigo()) == NULL)
        this->podcasts->push_back(podcast);
}

void Podcaster::rmPodcast(Podcast* podcast)
{
    this->podcasts->remove(podcast);
}

Podcast* Podcaster::buscaPodcast(int codigo)
{
    for(Podcast* aux :*this->podcasts)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Podcaster::imprimePodcast()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Podcasts de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Podcast* aux : *this->podcasts)
    {
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->formataDuracao() << std::endl;
        std::cout << "Quantidade de temporadas: " << aux->getQtdTemporadas() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}