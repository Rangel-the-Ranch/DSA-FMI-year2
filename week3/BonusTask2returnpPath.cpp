#include <iostream>
#include <array>
#include <queue>

template<unsigned boardSize = 8>
class minMoves {
    public:
        minMoves(){
            cleanBoard();
        }

        void getMinMoves(const size_t X, const size_t Y){
            
        }

    private:
        size_t m_Board[boardSize][boardSize];

        void cleanBoard(){
            for(size_t x = 0; x<boardSize; x++){
                for(size_t y = 0; y<boardSize; y++){
                    m_Board[x][y] = 0;
                }
            }
            return;
        }
        bool isMarked(const size_t x,const size_t y)const{
            if(x >= boardSize && y >= boardSize){
                return false;
            }
            return m_Board[x][y];
        }
        /*
        size_t getSteps(size_t x, size_t y)const{
            
            return m_Board[x][y];
        }*/

        bool isValidPosition(const size_t x ,const  size_t y)const{
            return !(x < 0 || x >= boardSize || y < 0 || y>= boardSize);
        }

};

int main() {
    
}