#include "../bib/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital()
{
    this->assinantes = new std::list<Assinante*>;
    this->produtores = new std::list<Produtor*>;
    this->midias = new std::list<Midia*>;
    this->generos = new std::list<Midia::Genero*>;
}

PlataformaDigital::PlataformaDigital(std::string nome)
{
    this->nome = nome;

    this->assinantes = new std::list<Assinante*>;
    this->produtores = new std::list<Produtor*>;
    this->midias = new std::list<Midia*>;
    this->generos = new std::list<Midia::Genero*>;
}

PlataformaDigital::~PlataformaDigital()
{
    std::list<Assinante*>::iterator aux1;
    for(aux1 = this->assinantes->begin(); aux1 != this->assinantes->end(); aux1 ++)
    {
        delete *aux1;
    }
    std::list<Produtor*>::iterator aux2;
    for(aux2 = this->produtores->begin(); aux2 != this->produtores->end(); aux2 ++)
    {
        delete *aux2;
    }
    std::list<Midia*>::iterator aux3;
    for(aux3 = this->midias->begin(); aux3 != this->midias->end(); aux3 ++)
    {
        delete *aux3;
    }
    std::list<Midia::Genero*>::iterator aux4;
    for(aux4 = this->generos->begin(); aux4 != this->generos->end(); aux4 ++)
    {
        delete *aux4;
    }

    delete this->assinantes;
    delete this->produtores;
    delete this->midias;
    delete this->generos;
}

std::string PlataformaDigital::getNome()
{
    return this->nome;
}

void PlataformaDigital::setNome(std::string nome)
{
    this->nome = nome;
}

void PlataformaDigital::imprimeMidiasPorGenero(Midia::Genero* genero)
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias do genero " << genero->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Musicas" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    
    std::list<Midia*>::iterator aux1;
    for(aux1 = this->midias->begin(); aux1 != this->midias->end(); aux1 ++)
    {
        if(((*aux1)->getGenero()->getNome() == genero->getNome()) && ((*aux1)->getGenero()->getSigla() == genero->getSigla()))
        {
            if ((*aux1)->getTipo() == "Musica")
            {
                std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
                std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
                std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
                std::cout << std::endl;
            }
        }
    }
    std::cout << "################################" << std::endl << std::endl;
    std::cout << "Podcasts" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    for(aux1 = this->midias->begin(); aux1 != this->midias->end(); aux1 ++)
    {
        if(((*aux1)->getGenero()->getNome() == genero->getNome()) && ((*aux1)->getGenero()->getSigla() == genero->getSigla()))
        {
            if ((*aux1)->getTipo() == "Podcast")
            {
                std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
                std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
                std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

std::list<Assinante*>* PlataformaDigital::getAssinantes()
{
    return this->assinantes;
}

void PlataformaDigital::setAssinantes(std::list<Assinante*>* assinantes)
{
    this->assinantes = assinantes;
}

void PlataformaDigital::addAssinante(Assinante* assinante)
{
    this->assinantes->push_back(assinante);
}

void PlataformaDigital::rmAssinante(Assinante* assinante)
{
    this->assinantes->remove(assinante);
}

void PlataformaDigital::imprimeAssinantes()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Assinantes de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    std::list<Assinante*>::iterator aux1;
    for(aux1 = this->assinantes->begin(); aux1 != this->assinantes->end(); aux1 ++)
    {
        std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

std::list<Produtor*>* PlataformaDigital::getProdutores()
{
    return this->produtores;
}

void PlataformaDigital::setProdutores(std::list<Produtor*>* produtores)
{
    this->produtores = produtores;
}

void PlataformaDigital::addProdutor(Produtor* produtor)
{
    this->produtores->push_back(produtor);
}

void PlataformaDigital::rmProdutor(Produtor* produtor)
{
    this->produtores->remove(produtor);
}

std::list<Midia*>* PlataformaDigital::getMidias()
{
    return this->midias;
}

void PlataformaDigital::setMidias(std::list<Midia*>* midias)
{
    this->midias = midias;
}

void PlataformaDigital::addMidia(Midia* midia)
{
    this->midias->push_back(midia);
}

void PlataformaDigital::rmMidia(Midia* midia)
{
    this->midias->remove(midia);
}

void PlataformaDigital::addMidia(Midia* midia, std::list<Produtor*>* produtores)
{
    midia->setProdutores(produtores);
    this->midias->push_back(midia);
}

std::list<Midia::Genero*>* PlataformaDigital::getGeneros()
{
    return this->generos;
}

void PlataformaDigital::setGeneros(std::list<Midia::Genero*>* generos)
{
    this->generos = generos;
}

void PlataformaDigital::addGenero(Midia::Genero* genero)
{
    this->generos->push_back(genero);
}

void PlataformaDigital::rmGenero(Midia::Genero* genero)
{
    this->generos->remove(genero);
}
