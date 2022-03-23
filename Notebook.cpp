#include "Notebook.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

using namespace ariel;

void Notebook:: write(unsigned int page, unsigned int row, unsigned int col, ariel::Direction direction, string const &in)
{
}
void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, ariel::Direction direction, int length){

}
string Notebook:: read(unsigned int page, unsigned int row, unsigned int col, ariel::Direction direction, int length){
    return "Hello";
}
void Notebook::show(unsigned int page){
    
}
