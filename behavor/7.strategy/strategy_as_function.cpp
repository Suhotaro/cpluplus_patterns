#include <iostream>
#include <functional>
#include <sstream>

using namespace std;

int find_from_begin(string &text, string &word) {
	istringstream ss(text);
	int idx = 0;

	string tmp;
	while(ss >> tmp)
	{
		idx++;
		//printf("	serch: %s %s\n", tmp.c_str(), word.c_str());

		if (tmp.compare(word) == 0)
			return idx;
	}

	return -1;
}

int find_from_end(string &text, string &word) {
	/* serch from end to begin */
	return -1;
}

class Document
{
	string text;
	function<int (string &text, string &word)> strategy;

public:
	Document(string text_, function<int (string &text, string &word)> strategy_) : text(text_), strategy(strategy_) {}
	~Document() {}

	int find_word(string word) {
		int idx = strategy(text, word);
		return idx;
	}
};


int main()
{
	Document document("this is some plain text", find_from_begin);
	printf("find word \"some\": %d\n", document.find_word("some"));
	printf("find word \"hello\": %d\n", document.find_word("hello"));

	/* TODO: add strategy function as lambda end functor, to show full power of std::function object */

	return 0;
}
