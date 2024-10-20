#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		string res;
		int i = s.size() - 1;

		while (i >= 0){
			while (i >= 0 && isspace(s[i]))
				--i;
			int j = i;
			while (j >= 0 && !isspace(s[j]))
				--j;
			res += s.substr(j + 1, i - j);
			i = j;
			while (i >= 0 && isspace(s[i]))
				--i;
			if (i >= 0)
				res += ' ';
		}
		return res;
    }
};

int main(void){
	Solution test;
	/* simple test */
	cout << test.reverseWords("word") << endl;
	cout << test.reverseWords("a b c d") << endl;
	cout << test.reverseWords("another         brother    child     ") << endl;

	return 0;
}