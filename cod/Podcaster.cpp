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
    this->podcasts->push_back(podcast);
}

void Podcaster::rmPodcast(Podcast* podcast)
{
    this->podcasts->remove(podcast);
}

bool Podcaster::isPodcast(Podcast* podcast)
{
    std::list<Podcast*>::iterator it = find(this->podcasts->begin(), this->podcasts->end(), podcast);
    return it != this->podcasts->end();
}

void Podcaster::imprimeNoArquivo(std::ofstream& file)
{

}