#include <iostream>
#include <cstdio>
#include <string>

class AIPlayer{ 
    public:
        
};

class Player{ 
    public: 
        Player(std::string& Iname){ 
            for (int i = 0; i < Iname.length(); i++){ 
                Iname[i] = toupper(Iname[i]);
            }
            std::cout << "Welcome " << Iname << std::endl;
            name = Iname;
        } 

        int makeMove(){ 
            int x = 0;
            if (numOfMoves() < 4){
                std::cout << "whats your move? " << std::endl;
                std::cout << "1. Rock" << std::endl;
                std::cout << "2. Paper" << std::endl;
                std::cout << "3. Scissors" << std::endl; 
                std::cin >> x; 
                if (x > 0 && x < 4) moves[numOfMoves()] = x;
                else std::cout << "Invalid move, try again" << std::endl; 
                return 0;
            }else{ 
                std::cout << "It's a draw" << std::endl;
                return 2;
            }
        }

        int numOfMoves(){ 
            for (int i = 0; i < 5; i++){ 
                if (moves[i] == 0) return i;
            }
            return 5;
        }

    private: 
    std::string name;
    int moves[5] = {};
    int winsLoss[100] = {};      
};

std::string introduction(){ 
    std::string inputName;
    std::cout << "Welcome to Rock Paper Scissors" << std::endl;
    std::cout << "what is your name? ";
    std::cin >> inputName;
    return inputName;
}

int main (){ 
    int winState = 0;
    int gameState = 1;
    std::string playerName = introduction();
    Player playerx(playerName);
    
    while (gameState == 1){ 
        while(winState == 0){ 
            winState = playerx.makeMove();
        }
    }

    return 0;
}