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
    for(Produtor* aux : *(this->produtores)) delete aux;
    for(Midia* aux : *(this->midias)) delete aux;
    for(Midia::Genero* aux : *(this->generos)) delete aux;

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

void PlataformaDigital::addAssinante(Assinante* assinante)
{
    this->assinantes->push_back(assinante);
}

void PlataformaDigital::rmAssinante(Assinante* assinante)
{
    this->assinantes->remove(assinante);
}

Assinante* PlataformaDigital::buscaAssinante(int codigo)
{
    for(Assinante* aux : *this->assinantes)
        if(aux->getCodigo() == codigo) return aux;
}

bool PlataformaDigital::isAssinante(Assinante* assinante)
{
    std::list<Assinante*>::iterator it = find(this->assinantes->begin(), this->assinantes->end(), assinante);
    return it != this->assinantes->end();
}

void PlataformaDigital::imprimeAssinantes()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Assinantes de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Assinante* aux : *this->assinantes)
    {
        std::cout << aux->getNome() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

void PlataformaDigital::addProdutor(Produtor* produtor)
{
    this->produtores->push_back(produtor);
}

void PlataformaDigital::rmProdutor(Produtor* produtor)
{
    this->produtores->remove(produtor);
}

bool PlataformaDigital::isProdutor(Produtor* produtor)
{
    std::list<Produtor*>::iterator it = find(this->produtores->begin(), this->produtores->end(), produtor);
    return it != this->produtores->end();
}

void PlataformaDigital::addMidia(Midia* midia)
{
    this->addMidia(midia);
}

void PlataformaDigital::rmMidia(Midia* midia)
{
    this->midias->remove(midia);
}

bool PlataformaDigital::isMidia(Midia* midia)
{
    std::list<Midia*>::iterator it = find(this->midias->begin(), this->midias->end(), midia);
    return it != this->midias->end();
}

void PlataformaDigital::addGenero(Midia::Genero* genero)
{
    this->generos->push_back(genero);
}

void PlataformaDigital::rmGenero(Midia::Genero* genero)
{
    this->generos->remove(genero);
}

Midia::Genero* PlataformaDigital::buscaGenero(std::string sigla)
{
    for(Midia::Genero* aux :*this->generos)
        if(aux->getSigla() == sigla) return aux;
}

bool PlataformaDigital::isGenero(Midia::Genero* genero)
{
    std::list<Midia::Genero*>::iterator it = find(this->generos->begin(), this->generos->end(), genero);
    return it != this->generos->end();
}

void PlataformaDigital::imprimeMidiasPorGenero(Midia::Genero* genero)
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias do genero " << genero->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    
    for(Midia* aux : *this->midias)
    {
        if((aux->getGenero()->getNome() == genero->getNome()) && (aux->getGenero()->getSigla() == genero->getSigla()))
        {
            std::cout << aux->getTipo() << std::endl;
            std::cout << "Nome: " << aux->getNome() << std::endl;
            std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
            std::cout << "Duracao: " << aux->getDuracao() << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "################################" << std::endl << std::endl;
}

void PlataformaDigital::carregaArquivoUsuarios(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }
    int col;
    std::string linha;
    std::vector<std::string> cel;

    getline(file, linha);
	cpp_util::Tokenizer tok(linha, ';');
    col = tok.remaining().size();
    
    while(!file.eof())
    {
        getline(file, linha);
        if(!linha.empty())
        {
            tok.overwriteStream(linha);
            cel = tok.remaining();
            if(cel.size() != col)
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            if(!cpp_util::isNumber(cel[0]))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }

            Usuario *usuario;
            if(cel[1] == "P")
            {
                usuario = new Podcaster(cel[2], stoi(cel[0]));
                this->addProdutor((Podcaster*) usuario);
            }
            else if(cel[1] == "U")
            {
                usuario = new Assinante(cel[2], stoi(cel[0]));
                this->addAssinante((Assinante*) usuario);
            }
            else if(cel[1] == "A")
            {
                usuario = new Artista(cel[2], stoi(cel[0]));
                this->addProdutor((Artista*) usuario);
            }
        }
    }
}

void PlataformaDigital::carregaArquivoGeneros(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }
    int col;
    std::string linha;
    std::vector<std::string> cel;

    getline(file, linha);
	cpp_util::Tokenizer tok(linha, ';');
    col = tok.remaining().size();
    
    while(!file.eof())
    {
        getline(file, linha);
        if(!linha.empty())
        {
            tok.overwriteStream(linha);
            cel = tok.remaining();
            if(cel.size() != col)
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            
            Midia::Genero* genero;
            genero = new Midia::Genero(cel[0], cel[1]);
            this->addGenero(genero);
        }
    }
}

void PlataformaDigital::carregaArquivoMidias(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }
    int col;
    std::string linha;
    std::vector<std::string> cel;
    cpp_util::Tokenizer tokComma("", ',');
    Midia::Genero* gen;
    Midia* mid;

    getline(file, linha);
	cpp_util::Tokenizer tok(linha, ';');
    col = tok.remaining().size();
    
    while(!file.eof())
    {
        getline(file, linha);
        if(!linha.empty())
        {
            tok.overwriteStream(linha);
            cel = tok.remaining();
            if(cel.size() != col)
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            /*
                0- codigo (int)
                1- nome (string)
                2- tipo (string)
                3- produtores (vector int)
                4- duracao (vector int)
                5- genero (vector string)
                6- temporada (int)
                7- album (string)
                8- ano publicacao (int)
            */

            if(!cpp_util::isNumber(cel[0]))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            tokComma.overwriteStream(cel[5]);
            for(std::string sigla : tokComma.remaining())
            {
                gen = this->buscaGenero(sigla);
                if(gen == *this->generos->end())
                {
                    std::cout << "ERRO! Genero nao encontrado!" << std::endl;
                    return;
                }
                if(cel[2] == "M")
                {
                    mid = new Musica(cel[1], stoi(cel[0]), 0.0, stoi(cel[8]), gen);
                }
                else if(cel[2] == "P")
                {
                    if(!cpp_util::isNumber(cel[6]))
                    {
                        std::cout << "ERRO! Formato invalido!" << std::endl;
                        return;
                    }
                    mid = new Podcast(cel[1], stoi(cel[0]), 0.0, stoi(cel[8]), gen, stoi(cel[6]));
                }
                else
                {
                    std::cout << "ERRO! Tipo invalido!" << std::endl;
                    return;
                }
                // produtor
                // insere o album
                this->addMidia(mid);
            }
        }
    }
}

void PlataformaDigital::carregaArquivoFavoritos(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }
    int col;
    std::string linha;
    std::vector<std::string> cel;

    getline(file, linha);
	cpp_util::Tokenizer tok(linha, ';');
    col = tok.remaining().size();
    
    while(!file.eof())
    {
        getline(file, linha);
        if(!linha.empty())
        {
            tok.overwriteStream(linha);
            cel = tok.remaining();
            if(cel.size() != col)
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            if(!cpp_util::isNumber(cel[0]))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            for(Assinante* aux : *this->assinantes)
            {
                if(aux->getCodigo() == stoi(cel[0]))
                {
                    cpp_util::Tokenizer newTok(cel[1], ',');
                    cel.clear();
                    cel = newTok.remaining();
                    for (std::string s : cel)
                    {
                        if(!cpp_util::isNumber(s))
                        {
                            std::cout << "ERRO! Formato invalido!" << std::endl;
                            return;
                        }
                        for(Midia* aux2 : *this->midias)
                        {
                            if(aux2->getCodigo() == stoi(s))
                            {
                                aux->addFavorita(aux2);
                                return;
                            }
                        }
                        std::cout << "ERRO! Midia nao encontrada!" << std::endl;
                        return;
                    }
                }
            }
            std::cout << "ERRO! Assinante nao encontrado!" << std::endl;
            return;
        }
    }
}

//file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');