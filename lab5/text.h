#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cstddef>        

class Text
{
    public:
         Text();
        ~Text() = default;
        void print();
        void copy_file(std::string& file_name);
        void frequency();
        void remove(std::string& word);
        void substitute(std::string& parameters);
        void table();
    
    private:
        std::vector <std::string> wordVector{};
    

};
#endif