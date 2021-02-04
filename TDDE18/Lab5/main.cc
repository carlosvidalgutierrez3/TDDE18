#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string washing(string s){
  try{
    auto open{s.find_first_not_of("(\"'")};
    s.erase(0,open);
    auto close{s.find_last_not_of("!?;,:.\"')")};
    s.erase(close+1);
    auto gen{s.find("'s")};
    s.erase(gen,2);
  }catch(out_of_range e){}
  return s;
}

struct comp{
    template<typename T>
    bool operator()(const T& l, const T& r) const{
        if (l.second != r.second)
            return l.second > r.second;
        return l.first > r.first;
    }
};

int main(int narg, char *argv[]){
  // Check number of inputs
  if(narg < 3 || narg > 4){
    cerr << "Number of parameters is incorrect. Exiting..." << endl;
    return 1;
  }

  // Read file to fs
  ifstream fs(argv[1]);
  if(!fs){
		cerr<<"File was not found.\n";
		return 1;
	}

  istream_iterator<string> iis{fs};
  istream_iterator<string> eos;
  vector<string> v{iis,eos};

  // Wash file words
  transform(v.begin(), v.end(),
  v.begin(), washing);
  vector<string> valid(v.size());

  // Validate words
  auto it = copy_if(v.begin(), v.end(), valid.begin(), [](string s){
    bool r{false};
    string good_chars = {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm-"};
    auto open{s.find_first_not_of(good_chars)};
    auto hyphen{s.find("--")};
    auto fh{s.find_first_of("-")};
    auto lh{s.find_last_of("-")};
    if(open > s.size() && s.size() > 2 && hyphen > s.size() && fh!=0 && lh!= s.size()-1) r = true;
    return r;});
  valid.resize(distance(valid.begin(),it));

  // Convert valid words to lower case
  transform(valid.begin(), valid.end(),
  valid.begin(), [](string s){
        transform(s.begin(),s.end(),s.begin(),[](char c){
          return tolower(c);;
        });
        return s;
  });

  // Count words and save the freq to the map
  map<string,int> m{};
  for_each(valid.begin(), valid.end(), [&m](string word){
    m[word]++;
  });

  // Find longest word
  string longest{*max_element(valid.begin(), valid.end())};

  // set1 stores m ordered by freq
  set<pair<string,int>, comp> set1(m.begin(), m.end());

  // largest number
  string largest{to_string(set1.begin()->second)};

  // Input option cases
  string option = argv[2];

  if(option.compare("-a")==0){
    // Print map adjusting to longest word and number
    for_each(m.begin(), m.end(), [&longest, &largest](const auto &mPair) {
      cout << mPair.first
      << setw(longest.size()-mPair.first.size()+largest.size() + 1)
      << mPair.second << endl;
    });
  }
  else if(option.compare("-f")==0){
    // Print the pairs of the vector
    for_each(set1.begin(), set1.end(), [&longest, &largest](const auto &mPair) {
      cout << setw(longest.size())
      << mPair.first << setw(largest.size() + 1) << mPair.second << '\n';
    });
  }
  else if(option.compare("-o")==0){
    // Print argv[3] chars per line
    if(narg == 3){
      cerr << "Missing max characters per line argument." << endl;
      return 1;
    }
    int max_length= stoi(argv[3]);
    int length{0};
    for_each(valid.begin(), valid.end(), [&length, &max_length](string s){
      if(length+s.size()+1<=max_length){
        length=length+s.size();
        if(length!=s.size()){
          cout<<" ";
          length=length+1;
        }
        cout<<s;
      }
      else {
        cout<<endl<<s;
        length=s.size();
      }
    });
    cout<<endl;
  }

return 0;
}
