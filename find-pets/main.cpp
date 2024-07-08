#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

string ReadLine() {
	string str;
	getline(cin, str);
	return str;
}

string RemoveSpacesAndFormatText(const string& text) {
	string res;
	if (!text.empty()) {
		int pos = 0;
		for (const char& ch : text) {
			if (ch == ' ' && (pos == 0 || pos == text.size()-1 || (pos > 0 && res[pos - 1] == ' '))) {
				continue;
			}
			res += ch;
			pos++;
		}
	}
	return res;
}

vector<string> SplitToWords(const string& text) {
	vector<string> word_list;
	if (!text.empty()) {
		string word;
		for (const char& c : text) {
			if (c != ' ') {
				word += c;
			}
			else {
				word_list.push_back(word);
				word.clear();
			}
		}
		if (!word.empty()) {
			word_list.push_back(word);
		}
	}
	return word_list;
}

set<string> ParseIgnoreWordsSet(const string& text) {
	set<string> res;
	if (!text.empty()){
		for (const string& word: SplitToWords(text)) {
			res.insert(word);
		}
	}
	return res;
}

vector<string> ExcludeIgnoreWords(const string& text, const set<string>& ignore_words) {
	vector<string> res;
	if (!text.empty()) {
		for (const string& word : SplitToWords(text)) {
			if (!ignore_words.count(word)) {
				res.push_back(word);
			}
		}
	}
	return res;
}

void AddRecord(vector<pair<int, vector<string>>>& documents, const string& text, const set<string>& ignore_words) {
	int id = 0;

	if (!documents.empty()) {
		id = documents.size();
	}

	documents.push_back({id,ExcludeIgnoreWords(text,ignore_words)});
	
}

vector<pair<int, int>> FindDocument(vector<pair<int, vector<string>>>& documents, const set<string> ignore_words, const string& query) {
	vector<pair<int, int>> res;
	vector<string> search = ExcludeIgnoreWords(query,ignore_words);
	if (!documents.empty() && !search.empty()) {
		for (const auto& [id,document] : documents) {
			int match = 0;
			for (const string& word : document) {
				for (const string& search_word : search) {
					if (word == search_word) {
						match++;
					}
				}
			}
			if (match > 0) {
				res.push_back({ id,match });
			}
		}
	}
	return res;
}

int main() {
	
	cout << "Ignore words: ";
	set<string> ignore_words = ParseIgnoreWordsSet(ReadLine());

	cout << "------------" << endl;
	cout << "Enter database records. Every line is a new record. To finish input type \"FINISH\"" << endl;
	cout << "------------" << endl;
	
	string input;
	vector<pair<int, vector<string>>> documents;

	while (true) {
		input = ReadLine();
		if (input == "FINISH") {
			break;
		}
		AddRecord(documents, input, ignore_words);
	}
	
	cout << "------------" << endl;
	cout << "Type your serach request:" << endl;
	input = ReadLine();
	vector<pair<int, int>> result = FindDocument(documents, ignore_words, input);
	
	if (!result.empty()) {
		cout << "------------" << endl;
		cout << result.size() << " records found." << endl;
		cout << "------------" << endl;
		for (const auto& [id,rel] : result) {
			cout << "document id: " << id << ", relevancy: " << rel << endl;
		}
	}
	else {
		cout << "Records not found" << endl;
	}
}