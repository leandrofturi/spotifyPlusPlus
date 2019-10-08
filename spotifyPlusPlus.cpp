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
    file.open("entradas/favoritos.csv");
    //carregaArquivoFavoritos(file);
    file.close();

    return 0;
}