#include "../bib/PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital()
{
    this->assinantes = new std::list<Assinante*>;
    this->produtores = new std::list<Produtor*>;
    this->midias = new std::list<Midia*>;
    this->generos = new std::list<Midia::Genero*>;
    this->albuns = new std::list<Album*>;
}

PlataformaDigital::PlataformaDigital(std::string nome)
{
    this->nome = nome;

    this->assinantes = new std::list<Assinante*>;
    this->produtores = new std::list<Produtor*>;
    this->midias = new std::list<Midia*>;
    this->generos = new std::list<Midia::Genero*>;
    this->albuns = new std::list<Album*>;
}

PlataformaDigital::~PlataformaDigital()
{
    for(Produtor* aux : *(this->produtores)) delete aux;
    for(Midia* aux : *(this->midias)) delete aux;
    for(Midia::Genero* aux : *(this->generos)) delete aux;

    delete this->produtores;
    delete this->midias;
    delete this->generos;
    delete this->albuns;
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
    if(this->buscaAssinante(assinante->getCodigo()) == *this->assinantes->end())
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
    return *this->assinantes->end();
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
    if(this->buscaProdutor(produtor->getCodigo()) == *this->produtores->end())
        this->produtores->push_back(produtor);
}

void PlataformaDigital::rmProdutor(Produtor* produtor)
{
    this->produtores->remove(produtor);
}

Produtor* PlataformaDigital::buscaProdutor(int codigo)
{
    for(Produtor* aux :*this->produtores)
        if(aux->getCodigo() == codigo) return aux;
    return *this->produtores->end();
}

void PlataformaDigital::imprimeProdutores()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Produtores de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Produtor* aux : *this->produtores)
    {
        std::cout << aux->getNome() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

void PlataformaDigital::addMidia(Midia* midia, std::list<Produtor*>* produtores)
{
    for(Produtor* aux : *produtores) aux->addMidia(midia);
    if(this->buscaMidia(midia->getCodigo()) == *this->midias->end())
    {
        this->midias->push_back(midia);
    }
}

void PlataformaDigital::rmMidia(Midia* midia)
{
    Midia* midAux;
    for(Produtor* aux : *this->produtores)
    {
        midAux = aux->buscaMidia(midia->getCodigo());
        //if(midAux == *aux->mi)
    }
    this->midias->remove(midia);
}

Midia* PlataformaDigital::buscaMidia(int codigo)
{
    for(Midia* aux :*this->midias)
        if(aux->getCodigo() == codigo) return aux;
    return *this->midias->end();
}

void PlataformaDigital::imprimeMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Midia* aux : *this->midias)
    {
        std::cout << aux->getTipo() << std::endl;
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->formataDuracao() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

void PlataformaDigital::addGenero(Midia::Genero* genero)
{
    if(this->buscaGenero(genero->getSigla()) == *this->generos->end())
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
    return *this->generos->end();
}

void PlataformaDigital::imprimeMidiasPorGenero(Midia::Genero* genero)
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias do genero " << genero->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    
    for(Midia* aux : *this->midias)
    {
        if(aux->getGenero()->getSigla() == genero->getSigla())
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

void PlataformaDigital::addAlbum(Album* album)
{
    if(this->buscaAlbum(album->getCodigo()) == *this->albuns->end())
        this->albuns->push_back(album);
}

void PlataformaDigital::rmAlbum(Album* album)
{
    this->albuns->remove(album);
}

Album* PlataformaDigital::buscaAlbum(int codigo)
{
    for(Album* aux :*this->albuns)
        if(aux->getCodigo() == codigo) return aux;
    return *this->albuns->end();
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

    std::string codigo;
    std::string tipo;
    std::string nome;

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
            codigo = cpp_util::trim(cel[0]);
            tipo = cpp_util::trim(cel[1]);
            nome = cel[2];

            if(!cpp_util::isNumber(codigo))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }

            Usuario *usuario;
            if(tipo == "P")
            {
                usuario = new Podcaster(nome, stoi(codigo));
                this->addProdutor((Podcaster*) usuario);
            }
            else if(tipo == "U")
            {
                usuario = new Assinante(nome, stoi(codigo));
                this->addAssinante((Assinante*) usuario);
            }
            else if(tipo == "A")
            {
                usuario = new Artista(nome, stoi(codigo));
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

    std::string sigla;
    std::string nome;

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
            sigla = cpp_util::trim(cel[0]);
            nome = cel[1];

            Midia::Genero* genero;
            genero = new Midia::Genero(nome, sigla);
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

    std::string codigo;
    std::string nome;
    std::string tipo;
    std::vector<std::string> vetProdutores;
    std::list<Produtor*>* produtores = new std::list<Produtor*>;
    std::vector<std::string> vetDuracao;
    double duracao;
    std::vector<std::string> vetGeneros;
    std::string temporada;
    std::string album;
    std::string codAlbum;
    std::string anoLancamento;
    cpp_util::Tokenizer tokComma("", ',');

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

            codigo = cpp_util::trim(cel[0]);
            nome = cpp_util::trim(cel[1]);
            tipo = cpp_util::trim(cel[2]);
            tokComma.overwriteStream(cpp_util::trim(cel[3]));
            vetProdutores = tokComma.remaining();
            produtores->clear();
            tokComma.overwriteStream(cpp_util::trim(cel[4]));
            vetDuracao = tokComma.remaining();
            tokComma.overwriteStream(cpp_util::trim(cel[5]));
            vetGeneros = tokComma.remaining();
            temporada = cpp_util::trim(cpp_util::trim(cel[6]));
            album = cpp_util::trim(cel[7]);
            codAlbum = cpp_util::trim(cel[8]);
            anoLancamento = cpp_util::trim(cel[9]);

            if((!cpp_util::isNumber(codigo)) || (!cpp_util::isNumber(anoLancamento)))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            if(vetDuracao.size() == 1) vetDuracao.push_back("0");
            if((!cpp_util::isNumber(cpp_util::trim(vetDuracao[0]))) || (!cpp_util::isNumber(cpp_util::trim(vetDuracao[1]))) || (vetDuracao.size() != 2))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            duracao = (double) (stoi(cpp_util::trim(vetDuracao[0])) + ((double) stoi(cpp_util::trim(vetDuracao[1])) / std::pow(10, cpp_util::trim(vetDuracao[1]).size())));
            
            Midia::Genero* gen = this->buscaGenero(cpp_util::trim(vetGeneros[0]));
            Midia* midia;
            if(gen == *this->generos->end())
            {
                std::cout << "ERRO! Genero nao encontrado!" << std::endl;
                return;
            }
            if(tipo == "M")
            {
                midia = new Musica(nome, std::stoi(codigo), duracao, std::stoi(anoLancamento), gen);

                if(!codAlbum.empty())
                {
                    if(!cpp_util::isNumber(codAlbum))
                    {
                        std::cout << "ERRO! Formato invalido!" << std::endl;
                        return;
                    }
                    Album* alb = this->buscaAlbum(stoi(codAlbum));
                    if(alb == *this->albuns->end())
                    {
                        Album* novoAlb = new Album(album, stoi(codAlbum), duracao, stoi(anoLancamento));
                        novoAlb->addMusica((Musica*) midia);
                        this->addAlbum(novoAlb);
                    }
                }
            }
            else if(tipo == "P")
            {
                if(!cpp_util::isNumber(temporada))
                {
                    std::cout << "ERRO! Formato invalido!" << std::endl;
                    return;
                }
                midia = new Podcast(nome, std::stoi(codigo), duracao, std::stoi(anoLancamento), gen, std::stoi(temporada));
            }
            for(std::string aux : vetProdutores)
            {
                if(!vetProdutores.empty())
                {
                    if(!(cpp_util::isNumber(cpp_util::trim(aux))))
                    {
                        std::cout << "ERRO! Formato invalido!" << std::endl;
                        return;
                    }
                    Produtor* prod = this->buscaProdutor(stoi(cpp_util::trim(aux)));
                    if(prod == *this->produtores->end())
                    {
                        std::cout << "ERRO! Produtor nao encontrado!" << std::endl;
                        return;
                    }
                    produtores->push_back(prod);
                }
            }
            this->addMidia(midia, produtores);
        }
    }
    delete produtores;
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

    std::string codigo;
    std::vector<std::string> vetMidias;
    cpp_util::Tokenizer tokComma("", ',');

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

            codigo = cpp_util::trim(cel[0]);
            tokComma.overwriteStream(cpp_util::trim(cel[1]));
            vetMidias = tokComma.remaining();

            if(!(cpp_util::isNumber(codigo)))
            {
                std::cout << "ERRO! Formato invalido!" << std::endl;
                return;
            }
            Assinante* ass = this->buscaAssinante(stoi(codigo));
            if(ass == *this->assinantes->end())
            {
                std::cout << "ERRO! Assinante nao encontrado!" << std::endl;
                return;
            }
            if(!vetMidias.empty())
            {
                if ((int) vetMidias[0][0] > 31)
                {
                    for(std::string aux : vetMidias)
                    {
                        if(!(cpp_util::isNumber(cpp_util::trim(aux))))
                        {
                            std::cout << "ERRO! Formato invalido!" << std::endl;
                            return;
                        }
                        Midia* midia = this->buscaMidia(stoi(cpp_util::trim(aux)));
                        if(midia == *this->midias->end())
                        {
                            std::cout << "ERRO! Midia nao encontrada!" << std::endl;
                            return;
                        }
                        ass->addFavorita(midia);
                    }
                }
            }
        }
    }
}

//file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');