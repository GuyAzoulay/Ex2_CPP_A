#include <string>
#include "Direction.hpp"
#include <vector>
using namespace std;
using ariel::Direction;


namespace ariel{
    
    class Notebook{
        private:
            vector<vector<string>> pages;

          public:

            void write(unsigned int page,unsigned int row,unsigned int col, ariel::Direction direction , string const &input);
            void erase(unsigned int page,unsigned int row,unsigned int col, ariel::Direction direction , int length); 
            string read(unsigned int page,unsigned int row,unsigned int col, ariel::Direction direction , int length);
            void show(unsigned int page);
            
            Notebook(){} //constructor method
            ~Notebook(){}
};

    }