#pragma once

namespace AdjacencyList {
    /**
     * Permet d'avoir un objet contenant le couple (sommet_successeur,cout)
     */
    class Successor {
    private:
        // Identifie le sommet successeur
        const int idVertex;
        // Poids entre le sommet parent et le sommet en question
        const int weight;

    public:
        inline Successor(const int idSuccessor, const int weight) : idVertex(idSuccessor), weight(weight) {};
        inline Successor() : idVertex(-1),weight(-1) {};
//        inline Successor(const Successor& succ) {this -> idVertex = succ.idVertex;};

/*        inline Successor operator =(const Successor successor) {
            this = new Successor(successor.idVertex,successor.weight);
        }; */
        ~Successor() = default;

        inline const int getSuccessorId() {
            return this -> idVertex;
        };


        inline const int getSuccessorWeight() {
            return this -> weight;
        };

        friend std::ostream& operator << (std::ostream& ostream, const Successor successor);
    };

    std::ostream& operator << (std::ostream& ostream, const Successor successor) {
        ostream << "[successeur : " << successor.idVertex << " | cout : " << successor.weight << "]\n";
        return ostream;
    }
}
