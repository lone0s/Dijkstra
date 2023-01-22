#include <iostream>
#include <string>
#include "Dikestra.h"

int main(int argc, char* argv[])
{
    std::ifstream infile;
    std::ostream* outstream;
    std::string infile_name;
    int s;

    switch (argc)
    {
        // pas d'arguments, on demande à l'utilisateur le nom du fichier d'entrée et le noeud de départ. La sortie est sur la console.
        case 1:

            std::cout << "Entrez le nom du fichier d'entrée : ";
            std::getline(std::cin, infile_name);
            infile.open(infile_name);
            std::cout << "Entrez le noeud de depart : ";
            std::cin >> s;

            outstream = &std::cout;

            break;

        // un seul argument le nom du fichier d'entrée, on demande à l'utilisateur le noeud de départ. La sortie est sur la console.
        case 2:

            infile.open(argv[1]);
            std::cout << "Entrez le noeud de depart : ";
            std::cin >> s;
            outstream = &std::cout;

            break;

        // deux arguments le nom du fichier d'entrée et le noeud de départ. La sortie est sur la console.
        case 3:

            infile.open(argv[1]);
            s = std::atoi(argv[2]);
            outstream = &std::cout; 

            break;

        // trois arguments le nom du fichier d'entrée, le noeud de départ et le nom du fichier de sortie.
        case 4:

            infile.open(argv[1]);
            s = std::atoi(argv[2]);

            std::ofstream ofile; 
            ofile.open(argv[3]);
            outstream = &ofile; 

            if (!ofile.is_open()) // si le fichier de sortie n'a pas pu être ouvert
            {
                std::cerr << "Impossible d'ouvrir le fichier de sortie !\n";
                return 1;
            }

            break;
    }

    if (!infile.is_open()) // si le fichier d'entrée n'a pas pu être ouvert
    {
        std::cerr << "Impossible d'ouvrir le fichier d'entrée !\n";
        return 1;
    }

    Dikestra dikestra(infile, outstream, s);

    return 0;
}