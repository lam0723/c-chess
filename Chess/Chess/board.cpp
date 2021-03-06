#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
// TODO: include more headers if necessary
#include "pawn.h"

using namespace std;

Board::Board(Game* game) : game(game), cells() {  // initalize cells' elements to nullptr
    configure();
}

/* Set up the initial game board */
void Board::configure() {
    // TODO:
    // modify this function body to set up the initial board properly;
    // add kings, queens, bishops, knights, rooks at correct positions
    // (can modify/delete provided code here if you feel necessary)

    for (int j = 0; j < W; j++) {
        cells[1][j] = new Pawn(BLACK, 1, j, this);
        cells[6][j] = new Pawn(WHITE, 6, j, this);
    }
    cells[0][0] = new Rook(BLACK, 0, 0, this);
    
    // TODO: add the created pieces to each player's list of pieces
}

bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

void Board::print() {
    cout << "    A   B   C   D   E   F   G   H  " << endl;
    cout << "  ---------------------------------" << endl;
    for (int i = 0; i < H; i++) {
        cout << i + 1;
        for (int j = 0; j < W; j++) {
            cout << " | ";
            if (isEmpty(i, j))
                cout << " ";
            else {
                if (cells[i][j]->getColor() == WHITE)
                    cout << (char)tolower(cells[i][j]->getLabel().at(0));
                else
                    cout << cells[i][j]->getLabel();
            }
        }
        cout << " | " << endl;
        cout << "  ---------------------------------" << endl;
    }
}

bool Board::move(int y1, int x1, int y2, int x2) {
    // (y1, x1) is source and (y2, x2) is destination
    // TODO:
    // check against following invalid cases:
    // - the source is an empty cell
    // - the source and destination are the same position
    // - the destination is out of bound of the board (hint: use OUT_BOUND)
    // - the source piece is not of same color of current turn of the game
    
    // Piece-specific validation
    if (p->isMoveValid(y2, x2) == false)
        return false;
    
    p->move(y2, x2);
    return true;
}

Game* Board::getGame() const {
    return game;
}
