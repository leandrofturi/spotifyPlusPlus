#ifndef _PODCASTER_HPP_
#define _PODCASTER_HPP_

// ATRIBUTOS OK

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
    bool isPodcast(Podcast* podcast);

    void imprimeNoArquivo(std::ofstream& file);
};

#endif