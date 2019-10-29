/*
    Trabalho de Programacao III
    Leandro Furlam e Isauflania Ribeiro
    29/10/2019
*/

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


int main (int argc, char *argv[])
{
    std::string fileUsuarios, fileGeneros, fileMidias, fileFavoritas;
    for (int i = 1; i < argc-1; i ++)
    {
        std::string s(argv[i]);
        std::string f(argv[i+1]);
        if(s == "-u")
            fileUsuarios = f;
        else if(s == "-g")
            fileGeneros = f;
        else if(s == "-m")
            fileMidias = f;
        else if(s == "-f")
            fileFavoritas = f;
    }
    PlataformaDigital* plataforma = inicializaSpotifyPlusPlus(fileUsuarios, fileGeneros, fileMidias, fileFavoritas);

    plataforma->escreveBackup();
    plataforma->escreveEstatisticas();
    plataforma->escreveFavoritas();
    plataforma->escreveMidiasPorProdutores();

    delete plataforma;
    return 0;
}