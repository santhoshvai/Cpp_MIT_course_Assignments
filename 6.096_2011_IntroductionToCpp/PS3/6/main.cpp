#include <iostream>
#include <string>

using std::string;

const string vowels = "aeiou";

string pigLatinify(string str) {
  size_t size = str.size();
  if ( size == 0 ) return str;  // empty string
  if (vowels.find(str[0]) != string::npos) {  // starts with a vowel
    return ( str.substr(1, size-1) + "-" + "way" );
  } else if (str.find("qu") == 0) {  // qu is the first 2 letters
    return (str.substr(2, size-2) + "-" + "quay");
  } else {  // initial consonant
    return (str.substr(1, size-1) + "-" + str[0] + "ay" );
  }
}

int main() {
  string str;
  std::cout << "Enter a word in lower case: " << std::endl;
  std::cin >> str;
  std::cout << pigLatinify(str) << std::endl;
  return 0;
}
