#include "bib/Album.hpp"
#include "bib/Artista.hpp"
#include "bib/Assinante.hpp"
#include "bib/Midia.hpp"
#include "bib/Musica.hpp"
#include "bib/PlataformaDigital.hpp"
#include "bib/Podcast.hpp"
#include "bib/Podcaster.hpp"
#include "bib/Produtor.hpp"
#include "bib/Usuario.hpp"

#include <ctime>
#include <iostream>
#include "cpp-utils/util/DateUtils.h"
#include "cpp-utils/util/NumberUtils.h"
#include "cpp-utils/util/StringUtils.h"
#include "cpp-utils/util/Tokenizer.h"


int main ()
{
    std::ifstream file;
    PlataformaDigital teste("Teste");
    Midia::Genero genero("Indie", "IN");

    file.open("entradas/usuarios.csv");
    teste.carregaArquivoUsuarios(file);
    file.close();
    //teste.imprimeAssinantes();

    file.open("entradas/generos.csv");
    teste.carregaArquivoGeneros(file);
    file.close();

    file.open("entradas/midias_corrigidas.csv");
    teste.carregaArquivoMidias(file);
    file.close();
    //teste.imprimeMidiasPorGenero(&genero);

    file.open("entradas/favoritos.csv");
    teste.carregaArquivoFavoritos(file);
    file.close();

    
    teste.escreveEstatisticas();


    teste.imprimeAssinantes();
    //teste.imprimeProdutores();
    //teste.imprimeMidias();

    return 0;
}