#include "chess.cpp"

int main()
{
    chs::Chess chess = chs::Chess("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    std::cout << chess.position.toString() << std::endl;

    //chess.position.generateMoves();

    std::cout << chess.displayMovesArray(chess.position.generateMoves()) << std::endl;

    return 0;
}