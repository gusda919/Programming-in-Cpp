using namespace std;

#include "text.h"
#include <string>

int main(int argc, char **argv)
{

  string file_name{};
  Text words{};

  if(argc > 2){       

    file_name = argv[1];

    // containing arguments

    std::vector<std::string> arguments(argv + 1, argv + argc);

    //checking for arguments

    Text text{};
    text.copy_file(file_name);

    std::for_each(arguments.begin(), arguments.end(), [&arguments, &text](string word) {
      std::size_t found = word.find_first_of('=');
      string argument;
      string parameters;
    
      if (found)
      {

        std::string left = word.substr(0, found);
        std::string right = word.substr(found + 1);

        if (!right.empty())
        {
          argument = left;
          parameters = right;
        }

      }
      else
      {
        argument = word;
      }

      if (argument == "--print")
      {
        text.print();
        
      }
      if (argument == "--table")
      {
        text.table();
      
      }
      if (argument == "--frequency")
      {
        text.frequency();
      
      }
      if (argument == "--substitute")
      {
        text.substitute(parameters);
        
      }
      if (argument == "--remove")
      {
        text.remove(parameters);
      
      }
  
    });

  } 

  else {
    cout << " invalid amount of arguments" << endl;
  }

  return 0;
}
