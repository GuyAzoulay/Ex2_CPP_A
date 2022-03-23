#include "doctest.h"
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>

#include <unistd.h>

using namespace std;
using namespace ariel; 


Direction h_dir = Direction::Horizontal;
Direction v_dir = Direction::Vertical;


TEST_CASE("write"){

Notebook notebook;
for (unsigned int i = 1 ; i < 300 ; i++){
    for(unsigned int j = 1 ; j < 300 ; j*=2){
        for(unsigned int k = 1; k < 200 ; k*=4 ){

            CHECK_THROWS(notebook.write(i,j,k,h_dir ,"How_Are_you"));
            CHECK_THROWS(notebook.write(i,j,k,v_dir ,"hello"));
            CHECK_THROWS(notebook.write(i,j,k,h_dir ,"guy"));
            CHECK_THROWS(notebook.write(i,j,k,v_dir ,"sup"));
        }

    }
}

}

TEST_CASE("read"){
Notebook notebook;
CHECK(notebook.read(2,3,6,Direction::Horizontal, 1)== "s");
CHECK(notebook.read(2,3,7,Direction::Horizontal, 11)== "Hello_World");
CHECK(notebook.read(1,6,8,Direction::Horizontal, 1)== "v");
CHECK(notebook.read(2,4,12,Direction::Horizontal, 3)== "guy");
CHECK(notebook.read(2,2,5,Direction::Horizontal, 7)== "azoulay");
CHECK(notebook.read(4,5,6,Direction::Horizontal, 0)== "_");


}


TEST_CASE("erase"){
Notebook notebook;
CHECK(notebook.read(4,6,20,Direction::Horizontal,4)=="guy_");
CHECK_THROWS(notebook.erase(4,6,20,Direction::Horizontal, 4));
CHECK_THROWS(notebook.write(2,2,2,Direction::Vertical, "how_r_u"));
CHECK_THROWS(notebook.erase(2,2,2,Direction::Horizontal, 7));
CHECK_THROWS(notebook.erase(4,5,6,Direction::Horizontal, 8));
CHECK_NOTHROW(notebook.erase(2,1,3,Direction::Horizontal, -1));
CHECK_NOTHROW(notebook.erase(9,5,3,Direction::Horizontal, 0));



}