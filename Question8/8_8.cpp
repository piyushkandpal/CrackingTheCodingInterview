#include<iostream>
#include<vector>
#include<map>

enum Direction { up, down, left, right };
enum Color { White, Black };

class Game
{
    private:
        Player players;
        static Game instance;
        Board board;
        const int ROWS = 10;
        const int COLUMNS = 10;
        Game()
        {
            board = new Board(ROWS,COLUMNS);
            players = new Player[2];
            player[0] = new Player(Black)
            player[0] = new Player(White)
        }
    public:
        static Game getInstance():
        {
            if (instance == NULL)
            {
                instance = new Game;
            }
            return instance;
        }
        Board getBoard()
        {
            return board;
        }
};

class Board
{
    private:
        int blackCount=0;
        int whiteCount = 0;
        Piece **board;
    public:
        Board(int rows,int columns)
        {
            board = new Piece[rows][columns];
        }
        void initialize() { /* initialize center black and white pieces */}
        /* Attempt to place a piece of color color at (row, column).
        15 * Return true if we were successful. */
        boolean placeColor(int row, int column, Color color) { }
        /* flips pieces starting at (row, column) and proceeding in
        21 * direction d. */
    private:
        int flipSection(int row, int column, Color color,Direction d) { ... }
    public: 
        int getScoreForColor(Color c) 
        {
            if (c == Color.Black) return blackCount;
            else return whiteCount;
         }

         /* Update board with additional newPieces pieces of color
        31 * newColor. Decrease score of opposite color. */
        void updateScore(Color newColor, int newPieces) { ... }
     }
/*As described earlier, we implement the black and white pieces with the Piece class,
which has a simple Color variable representing whether it is a black or white piece.
*/
class Piece 
{
    private: 
        Color color;
    public: 
        Piece(Color c) { color = c; }
    void flip() 
    {
        if (color == Black) color = White;
        else color = Black;
     }
    Color getColor() 
    {
        return color; 
    }
};
/*The Player holds only a very limited amount of information. It does not even hold
its own score, but it does have a method one can call to get the score. Player.
getScore () will call out to the GameManager to retrieve this value.
*/
class Player {
    private:
         Color color;
    public:
         Player(Color c) { color = c; }

    int getScore() { ... }

    boolean playPiece(int r, int c) 
    {
        return Game.getlnstanceQ.getBoardQ.placeColor(r, c, color);
    }
    
    Color getColor() { return color; }
};
