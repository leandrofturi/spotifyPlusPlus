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

    std::cout << nome << " criada com sucesso!" << std::endl << std::endl;
}

PlataformaDigital::~PlataformaDigital()
{
    for(Assinante* aux : *(this->assinantes)) delete aux;
    for(Produtor* aux : *(this->produtores)) delete aux;
    for(Midia* aux : *(this->midias))
        if(aux->getTipo() == "Musica")
        {
            Musica* auxMus = (Musica*) aux;
            if(auxMus->getAlbum() == "") delete auxMus;
        }
    for(Midia::Genero* aux : *(this->generos)) delete aux;
    for(Album* aux : *(this->albuns)) delete aux;

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
    if(this->buscaAssinante(assinante->getCodigo()) == NULL)
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
    return NULL;
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
    if(this->buscaProdutor(produtor->getCodigo()) == NULL)
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
    return NULL;
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
    if(this->buscaMidia(midia->getCodigo()) == NULL)
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
        if(midAux != NULL) aux->rmMidia(midAux);
    }
    this->midias->remove(midia);
}

Midia* PlataformaDigital::buscaMidia(int codigo)
{
    for(Midia* aux :*this->midias)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
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
    if(this->buscaGenero(genero->getSigla()) == NULL)
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
    return NULL;
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
    if(this->buscaAlbum(album->getCodigo()) == NULL)
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
    return NULL;
}

void PlataformaDigital::carregaArquivoUsuarios(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Carregando usuarios..." << std::endl;

    int contUsu = 0;
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
            nome = cpp_util::removeChar(nome, (char) 13);
            nome = cpp_util::removeChar(nome, (char) 10);

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
                contUsu ++;
            }
            else if(tipo == "U")
            {
                usuario = new Assinante(nome, stoi(codigo));
                this->addAssinante((Assinante*) usuario);
                contUsu ++;
            }
            else if(tipo == "A")
            {
                usuario = new Artista(nome, stoi(codigo));
                this->addProdutor((Artista*) usuario);
                contUsu ++;
            }
        }
    }
    std::cout << contUsu << " usuarios adicionados!" << std::endl << std::endl;
}

void PlataformaDigital::carregaArquivoGeneros(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Carregando generos..." << std::endl;

    int contGen = 0;
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
            nome = cpp_util::removeChar(nome, (char) 13);
            nome = cpp_util::removeChar(nome, (char) 10);

            Midia::Genero* genero;
            genero = new Midia::Genero(nome, sigla);
            this->addGenero(genero);
            contGen ++;
        }
    }
    std::cout << contGen << " generos adicionados!" << std::endl << std::endl;
}

void PlataformaDigital::carregaArquivoMidias(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Carregando midias..." << std::endl;

    int contMid = 0;
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
            nome = cpp_util::removeChar(nome, (char) 13);
            nome = cpp_util::removeChar(nome, (char) 10);
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
            if(gen == NULL)
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
                    if(alb == NULL)
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
                    if(prod == NULL)
                    {
                        std::cout << "ERRO! Produtor nao encontrado!" << std::endl;
                        return;
                    }
                    produtores->push_back(prod);
                }
            }
            this->addMidia(midia, produtores);
            contMid ++;
        }
    }
    delete produtores;
    std::cout << contMid << " midias adicionadas!" << std::endl << std::endl;
}

void PlataformaDigital::carregaArquivoFavoritos(std::ifstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Construindo favoritismos" << std::endl;

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
            if(ass == NULL)
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
                        if(midia == NULL)
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
    std::cout << "Pronto!" << std::endl << std::endl;
}

void PlataformaDigital::escreveEstatisticas()
{
    std::ofstream file;
    file.open("1-estatisticas.txt", std::ios::out);
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Escrevendo estatisticas..." << std::endl;
    
    file << "Horas Consumidas: ";
    double duracao;
    duracao = 0;
    for(Midia::Genero* aux : *this->generos)
        duracao += this->minutosOuvidosPorGenero(aux);
    file << cpp_util::formatsHours(duracao*60);
    file << " minutos" << std::endl;
    file << std::endl;

    file << "Genero mais ouvido: ";
    file << this->generoMaisOuvido()->getNome();
    file << " - ";
    file << cpp_util::formatsHours(60*this->minutosOuvidosPorGenero(this->generoMaisOuvido()));
    file << " minutos" << std::endl;
    file << std::endl;

    file << "Mídias por Gênero:" << std::endl;
    for(Midia::Genero* aux : *this->generos)
    {
        file << aux->getNome();
        file << ":";
        file << cpp_util::formatsHours(60*this->minutosOuvidosPorGenero(aux)) << std:: endl;
    }
    file << std::endl;

    file << "Top 10 Midias:" << std::endl;
    for(std::tuple<Midia*, int> auxTupla : top10Midias())
    {
        file << std::get<0>(auxTupla)->getNome();
        file << ":";
        file << std::get<0>(auxTupla)->getGenero()->getNome();
        file << ":";
        file << std::get<1>(auxTupla) << std:: endl;;
    }
    file << std::endl;

    file << "Top 10 Produtores:" << std::endl;
    for(std::tuple<Produtor*, int> auxTupla : top10Produtores())
    {
        file << std::get<0>(auxTupla)->getNome();
        file << ":";
        file << std::get<1>(auxTupla) << std:: endl;;
    }

    file.close();
    std::cout << get_current_dir_name() << "/1-estatisticas.txt" << std::endl << std::endl;
}

void PlataformaDigital::escreveMidiasPorProdutores()
{
    std::ofstream file;
    file.open("2-produtores.csv", std::ios::out);
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Escrevendo midias por produtores..." << std::endl;

    this->produtores->sort(ordenaCrescPorNome<Produtor>);
    for(Produtor* auxProd : *this->produtores)
        auxProd->escreveMidiasNoArquivo(file);

    file.close();
    std::cout << get_current_dir_name() << "/2-produtores.csv" << std::endl << std::endl;
}

void PlataformaDigital::escreveBackup()
{
    std::ofstream file;
    file.open("4-backup.txt", std::ios::out);
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Escrevendo backup..." << std::endl;

    file << "Usuarios:" << std::endl;
    for(Usuario* auxUs : *this->assinantes)
        auxUs->escreveNoArquivo(file);
    for(Usuario* auxUs : *this->produtores)
        auxUs->escreveNoArquivo(file);

    file << std::endl;
    file << "Midias:" << std::endl;
    for(Midia* auxMid : *this->midias)
        auxMid->escreveNoArquivo(file);

    file.close();
    std::cout << get_current_dir_name() << "/4-backup.txt" << std::endl << std::endl;
}

void PlataformaDigital::escreveFavoritas()
{
    std::ofstream file;
    file.open("3-favoritos.csv", std::ios::out);
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    std::cout << "Escrevendo favoritos..." << std::endl;

    this->assinantes->sort(ordenaCrescPorCodigo<Assinante>);
    for(Assinante* auxAss : *this->assinantes)
        auxAss->escreveMidiaNoArquivo(file);

    file.close();
    std::cout << get_current_dir_name() << "/3-favoritos.csv" << std::endl << std::endl;
}

double PlataformaDigital::minutosOuvidosPorGenero(Midia::Genero* genero)
{
    int min = 0;
    for(Assinante* auxAss : *this->assinantes)
        for(Midia* aux : *getFavoritas(auxAss))
            if(aux->getGenero()->getSigla() == genero->getSigla())
                min += aux->getDuracao();

    return min;
}

Midia::Genero* PlataformaDigital::generoMaisOuvido()
{
    int duracao, duracaoMax = 0;
    Midia::Genero* genero;
    for(Midia::Genero* auxGen : *this->generos)
    {
        duracao = 0;
        for(Assinante* auxAss : *this->assinantes)
            for(Midia* auxMid : *(getFavoritas(auxAss)))
                if(auxMid->getGenero()->getSigla() == auxGen->getSigla())
                    duracao += auxMid->getDuracao();

        duracaoMax = MAX(duracaoMax, duracao);
        genero = (duracaoMax == duracao) ? auxGen : genero;
    }
    return genero;
}

std::list<std::tuple<Midia*, int> > PlataformaDigital::top10Midias()
{
    std::list<std::tuple<Midia*, int> > midias;
    for(Midia* auxMid : *this->midias)
        midias.push_back({auxMid, 0});

    for(Assinante* auxAss : *this->assinantes)
        for(Midia* auxMid : *(getFavoritas(auxAss)))
            for(std::tuple<Midia*, int> auxTupla : midias)
                if(auxMid->getCodigo() == std::get<0>(auxTupla)->getCodigo())
                    std::get<1>(auxTupla) ++;

    std::tuple<Midia*, int> auxDeVerdade;
    for(std::tuple<Midia*, int> auxTupla : midias)
        for(std::tuple<Midia*, int> auxTupla2 : midias)
            if(std::get<1>(auxTupla) < std::get<1>(auxTupla2))
            {
                auxDeVerdade = auxTupla;
                auxTupla = auxTupla2;
                auxTupla2 = auxDeVerdade;
            }

    while(midias.size() > 10)
        midias.pop_back();
    
    return midias;
}

std::list<std::tuple<Produtor*, int> > PlataformaDigital::top10Produtores()
{
    std::list<std::tuple<Midia*, int> > midias;
    for(Midia* auxMid : *this->midias)
        midias.push_back({auxMid, 0});

    for(Assinante* auxAss : *this->assinantes)
        for(Midia* auxMid : *(getFavoritas(auxAss)))
            for(std::tuple<Midia*, int> auxTupla : midias)
                if(auxMid->getCodigo() == std::get<0>(auxTupla)->getCodigo())
                    std::get<1>(auxTupla) ++;

    std::list<std::tuple<Produtor*, int> > produtores;
    for(Produtor* auxProd : *this->produtores)
        produtores.push_back({auxProd, 0});
    
    for(std::tuple<Produtor*, int> auxTuplaProd : produtores)
        for(std::tuple<Midia*, int> auxTuplaMidias : midias)
            for(Midia* auxMid : *getMidias(std::get<0>(auxTuplaProd)))
                if(std::get<0>(auxTuplaMidias)->getCodigo() == auxMid->getCodigo())
                    std::get<1>(auxTuplaMidias) += std::get<1>(auxTuplaProd);

    std::tuple<Produtor*, int> auxDeVerdade;
    for(std::tuple<Produtor*, int> auxTupla : produtores)
        for(std::tuple<Produtor*, int> auxTupla2 : produtores)
            if(std::get<1>(auxTupla) < std::get<1>(auxTupla2))
            {
                auxDeVerdade = auxTupla;
                auxTupla = auxTupla2;
                auxTupla2 = auxDeVerdade;
            }

    while(produtores.size() > 10)
        produtores.pop_back();

    return produtores;
}

// FRIEND FUNCTIONS
std::list<Midia*>* getFavoritas(Assinante* assinante)
{
    return assinante->favoritas;
}

std::list<Midia*>* getMidias(Produtor* produtor)
{
    return produtor->midias;
}

template <typename T>
bool ordenaCrescPorCodigo(T *obj1, T *obj2)
{
    return obj1->getCodigo() < obj2->getCodigo();
}

template <typename T>
bool ordenaCrescPorNome(T *obj1, T *obj2)
{
    return cpp_util::stringCompare(obj1->getNome(), obj2->getNome());
}