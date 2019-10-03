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
