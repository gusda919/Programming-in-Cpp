#include "text.h"

using namespace std;

Text::Text() : wordVector{}
{    
}

void Text::print()
{
  std::for_each(wordVector.begin(), wordVector.end(), [&](string word) {
    std::cout << " " << word;
  });
  std::cout << endl;
}

void Text::copy_file(string& file_name)
{
  ifstream inFile;
  
  inFile.open(file_name);

  istream_iterator<string> start{inFile};
  istream_iterator<string> end;

  std::copy(start, end, back_inserter(wordVector));
  inFile.close();
}


// table - function

void Text::table()
{

 int width{0};

    for_each(wordVector.begin(), wordVector.end(), [&](string word) 
    {
      if(word.size() > width)
      {
        width = word.size();
      }
    });

  auto out = std::map<std::string, int>{};

  std::for_each(wordVector.begin(), wordVector.end(), [&out](const std::string &w) { out[w]++; });

  auto lines = [width](pair<string, int> const& it)
	{
	  ostringstream oss{};
	  oss <<  left << setw(width) <<  it.first << " " << it.second << std::endl;
	    
	  return oss.str();
	};
    transform(out.begin(), out.end(), ostream_iterator<string>(cout), lines);
  
}




void Text::remove(std::string& word  )
{
  auto out = std::remove(wordVector.begin(), wordVector.end(), std::string(word));

  wordVector.erase(out, wordVector.end());
  
  return ;
} 




void Text::substitute(std::string&  parameters )
{

  std::size_t found = parameters.find_first_of('+');

  if(found) {
    std::string sub = parameters.substr(0,found);
    std::string old = parameters.substr(found+1);

    std::replace(wordVector.begin(), wordVector.end(), std::string(sub), std::string(old));
  
  }
  else {
 
    std::cout << "use operator ̈́̈́'+' for subing words" ;

  }
}


struct comp
{
  template <typename T>

  // Comparator function
  bool operator()(const T &l,
                  const T &r) const
  {
    if (l.second != r.second)
    {
      return l.second > r.second;
    }
    return l.first > r.first;
  }
};


void Text::frequency()
{

  int width{0};

  for_each(wordVector.begin(), wordVector.end(), [&](string word) 
  {
    if(word.size() > width)
    {
      width = word.size();
    }
  });


  auto out = std::map<std::string, int>{};
  std::for_each(wordVector.begin(), wordVector.end(), [&out](const std::string &w) { out[w]++; });

  set<pair<string, int>, comp> S(out.begin(),
                                 out.end());


  auto lines = [width](pair<string, int> const& it)
	{
	    ostringstream oss{};
	    oss <<  left << setw(width) <<  it.first << " " << it.second << std::endl;

	    return oss.str();
	};
    transform(S.begin(), S.end(), ostream_iterator<string>(cout), lines);

}