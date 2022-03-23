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

string s="";
Notebook notebook;
for (unsigned int i = 1 ; i < 3000 ; i++){
    s = "";
    for(unsigned int j = 1 ; j < 3000 ; j*=2){
        
        for(unsigned int k = 1; k <= 100 ; k*=4 ){
            
            s += char('a'+ rand()%26); 
        
            if(k + sizeof(s) <=100){
            CHECK_NOTHROW(notebook.write(i,j,k,h_dir ,s));
            s += char('A'+rand()%26);
            CHECK_NOTHROW(notebook.write(i,j,k,v_dir ,s));
            s += char('a'+ rand()%26);
            CHECK_NOTHROW(notebook.write(i,j,k,h_dir ,s));
            s += char('A'+ rand()%26);
            CHECK_NOTHROW(notebook.write(i,j,k,v_dir ,s));
           
        }
            

    }
}
}
}

TEST_CASE("read"){

string s="";
Notebook notebook;
for (unsigned int i = 1 ; i <100 ; i++){
    s = "";
    for(unsigned int j = 1 ; j < 100 ; j*=2){
        
        for(unsigned int k = 1; k <= 100 ; k*=4 ){
            
            s += char('a'+ rand()%26); 
        
            if(k + sizeof(s) <=100){
            notebook.write(i,j,k,h_dir ,s);
            CHECK(notebook.read(i,j,k,h_dir,s.size()) == s);
            s += char('A'+rand()%26);
            notebook.write(i,j,k,v_dir ,s);
            CHECK(notebook.read(i,j,k,v_dir,s.size()) == s);
            s += char('a'+ rand()%26);
            notebook.write(i,j,k,h_dir ,s);
            CHECK(notebook.read(i,j,k,h_dir,s.size()) == s);
            s += char('A'+ rand()%26);
            notebook.write(i,j,k,v_dir ,s);
            CHECK(notebook.read(i,j,k,v_dir,s.size()) == s);
           
        }
            

    }
}
 }
}






TEST_CASE("erase"){
string s="";
Notebook notebook;
for (unsigned int i = 1 ; i < 100 ; i++){
    s = "";
    for(unsigned int j = 1 ; j < 100 ; j*=2){
        
        for(unsigned int k = 1; k <= 100 ; k*=4 ){
            
            s += char('a'+ rand()%26); 
        
            if(k + sizeof(s) <=100){
            notebook.write(i,j,k,h_dir ,s);
            CHECK_NOTHROW(notebook.erase(i,j,k,h_dir,sizeof(s)));
            CHECK(notebook.read(i,j,k,h_dir,s.size()) != s);
            s += char('A'+rand()%26);
            notebook.write(i,j,k,v_dir ,s);
            CHECK_NOTHROW(notebook.erase(i,j,k,v_dir,sizeof(s)));
            CHECK(notebook.read(i,j,k,v_dir,s.size()) != s);
            
            
        }
            

    }
}
 }
}
