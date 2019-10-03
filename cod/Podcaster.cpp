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

std::list<Podcast*>* Podcaster::getPodcasts()
{
    return this->podcasts;
}

void Podcaster::setPodcasts(std::list<Podcast*>* podcasts)
{
    this->podcasts = podcasts;
}

void Podcaster::addPodcast(Podcast* podcast)
{
    this->podcasts->push_back(podcast);
}