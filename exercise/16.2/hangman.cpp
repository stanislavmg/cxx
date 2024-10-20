#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <vector>

using std::string;
const int NUM = 26;

int main(void)
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	using std::vector;
	std::fstream input("words.txt");
	vector<string> words;
	string tmp;
	string target;
	char play;
	int i;
	int len;

	i = 0;
	while (input >> tmp)
	{
		i++;
		words.push_back(tmp);
	}
	std::srand(time(0));
	cout << "Will you play a word game> <y/n> ";
	cin >> play;
	while (play == 'y')
	{
		target = words[std::rand() % i];
		len = target.size();
		string attempt(target.size(), '-');
		string badchar;
		int guesses = 6;
		cout << "Guess my secret word. It has " << len
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchar.find(letter) != string::npos ||
				attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				guesses--;
				badchar += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchar.size() > 0)
				cout << "Bad choices: " << badchar << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
		cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Buy!\n";
	input.close();
	return (0);
} 