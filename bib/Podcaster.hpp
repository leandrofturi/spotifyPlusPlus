#ifndef _PODCASTER_HPP_
#define _PODCASTER_HPP_

#include <iostream>
#include <list>
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

    std::list<Podcast*>* getPodcasts();
    void setPodcasts(std::list<Podcast*>* podcasts);
    void addPodcast(Podcast* podcast);
    void rmPodcast(Podcast* podcast);
};

#endif