#include "chess.cpp"

int main()
{
    chs::Chess chess = chs::Chess("r1bq1rk1/pp1nppbp/2p2np1/8/2Q5/2NP1NP1/PP2PPBP/R1B2RK1 b - - 2 9");

    std::cout << chess.position.toString() << std::endl;

    //chess.position.generateMoves();

    std::cout << chess.displayMovesArray(chess.position.generateMoves()) << std::endl;

    std::cin.get();

    return 0;
}