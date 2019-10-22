#ifndef _PODCASTER_HPP_
#define _PODCASTER_HPP_

#include <iostream>
#include <list>
#include <algorithm>
#include "Produtor.hpp"
#include "Podcast.hpp"

class Podcaster : public Produtor
{
private:
    std::list<Podcast*>* podcasts;

public:
    Podcaster();
    Podcaster(std::string nome, int codigo);
    ~Podcaster();

    void addPodcast(Podcast* podcast);
    void rmPodcast(Podcast* podcast);
    Podcast* buscaPodcast(int codigo);
    void imprimePodcast();

    //void imprimeNoArquivo(std::ofstream& file);
};

#endif