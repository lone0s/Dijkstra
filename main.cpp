#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::ifstream infile;
    std::ostream* outstream
    std::string infile_name;
    int s;

    switch (argc)
    {
        case 1:

            std::cout << "Entrez le nom du fichier d'entrée : ";
            std::getline(std::cin, infile_name);
            infile.open(infile_name);
            std::cout << "Entrez le noeud de depart : ";
            std::cin >> s;

            std::ostream* outstream; 
            outstream = &std::cout;
            //(*outstream) << "hello world" << std::endl;

            break;

        case 2:

            infile.open(argv[1]);
            std::cout << "Entrez le noeud de depart : ";
            std::cin >> s;
            outstream = &std::cout;

            break;

        case 3:

            infile.open(argv[1]);
            s = std::atoi(argv[2]); 
            outstream = &std::cout; 

            break;

        case 4:

            infile.open(argv[1]);
            s = std::atoi(argv[2]);

            std::ofstream ofile; 
            ofile.open(argv[3]);
            outstream = &ofile; 

            if (!ofile.is_open())
            {
                std::cerr << "Impossible d'ouvrir le fichier de sortie !\n";
                return 1;
            }

            break;
    }

    if (!infile.is_open())
    {
        std::cerr << "Impossible d'ouvrir le fichier d'entrée !\n";
        return 1;
    }

    return 0;
}
