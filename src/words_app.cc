#include "repository.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace demo_tdd_cxx;
using namespace std;

void add_new_word();
void get_words(const string &pingyin);

int main()
{
  InitLexicon();

  while (true)
  {
    string input;
    cout << "please enter pinyin , Q to exit , A to add\n>";
    cin >> input;
    while (cin && cin.get() != '\n')
      continue;
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "q")
      break;

    if (input == "a")
    {
      add_new_word();
      continue;
    }

    get_words(input);
  }

  return 0;
}

void add_new_word()
{
  cout << "please enter word,pingin1,pinyin2\n>";
  string word, pingin1, pingin2;
  getline(cin, word, ',');
  getline(cin, pingin1, ',');
  getline(cin, pingin2);
  word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());

  AddZhWord(ZhWord(word, pingin1, pingin2));
}

void get_words(const string &pingyin)
{
  list<string> words = GetWordsFromPinyin(pingyin);
  int size = words.size();
  if (size > 0)
  {
    int j = 1;
    for (string word : words)
    {
      cout << j << "-" << word;
      if (size != j)
      {
        cout << "; ";
      }
      else
      {
        cout << endl;
      }
      j++;
    }

    int select = 1;
    if (cin >> select && select <= size && select >= 1)
    {
      int k = 1;
      for (string word : words)
      {
        if (k == select)
        {
          cout << word << endl;
          AddUsageCount(word);
          break;
        }
        k++;
      }
    }
    else
    {
      cin.clear();
      while (cin && cin.get() != '\n')
        continue;
      cout << "select error!!!" << endl;
    }
  }
  else
  {
    cout << "no word!!!" << endl;
  }
}