#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const pair<Key, Value>& container) {
    out << '{' << container.first << ',' << container.second << '}';
    return out;
}

template <typename Container, typename CompareFnc>
void SortBy(Container& container, CompareFnc compare_fnc, const bool reverse = false) {
    const size_t container_size = container.size();
    if(container_size < 2) {
        return;
    }
    
    for (size_t i = 0; i < container_size - 1; ++i) {
        for (size_t j = i + 1; j < container_size; ++j) {
            auto& left = container[i];
            auto& right = container[j];
            if (compare_fnc(left, right) || reverse) {
                swap(left, right);
            }
        }
    }
}

template <typename Value>
vector<Value> ConvertContainer(const set<Value>& container) {
    vector<Value> res;
    for (const auto& item : container) {
        res.push_back(item);
    }
    return res;
}

template <typename Key, typename Value>
vector<pair<Key,Value>> ConvertContainer(const map<Key,Value>& container) {
    vector<pair<Key, Value>> res;
    for (const auto& item : container) {
        res.push_back(item);
    }
    return res;
}

template <typename Container>
void PrintContainer(const Container container) {
    bool is_first = true;
    for (const auto& item : container) {
        if (is_first) {
            is_first = false;
            cout << item;
        }
        else {
            cout << ", "s << item;
        }
        
    }
}

template <typename DataType>
vector<DataType> operator+(const vector<DataType>& left, const vector<DataType>& right) {
    vector<DataType> res;
    for (const auto& item : left) {
        res.push_back(item);
    }
    for (const auto& item : right) {
        res.push_back(item);
    }
    return res;
}

unsigned _strlen(const char* text) {
    unsigned length = 0;
    while (*text != '\0') {
        ++text;
        ++length;
    }
    return length;
}

int strstr(const char* text, const char* pattern)
{
    unsigned text_length = _strlen(text);
    unsigned pattern_length = _strlen(pattern);
    if (pattern_length == 0) {
        return 0;
    }
    if (pattern_length > text_length) {
        return -1;
    }
    for (unsigned i = 0; i < text_length; ++i) {
        bool match = true;
        for (unsigned j = 0, k = i; j < pattern_length; ++j, ++k) {
            if (text[k] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

void test()
{
 (0  == strstr("","")) ? cout<<"OK : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl : cout<< "Failed : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl ;
  (0 == strstr("a", "")) ? cout<<"OK : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl : cout<< "Failed : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl ;
  (0 == strstr("a", "a")) ? cout<<"OK : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl : cout<< "Failed : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl ;
  (-1 == strstr("a", "b")) ? cout<<"OK : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl : cout<< "Failed : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl ;
               
  (0 == strstr("aa", "")) ? cout<<"OK : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl : cout<< "Failed : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl ;
  (0 == strstr("aa", "a")) ? cout<<"OK : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl : cout<< "Failed : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl ;
  (0 == strstr("ab", "a")) ? cout<<"OK : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl : cout<< "Failed : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl ;
  (1 == strstr("ba", "a")) ? cout<<"OK : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl : cout<< "Failed : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl ;
  (-1 == strstr("bb", "a")) ? cout<<"OK : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl : cout<< "Failed : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl ;
               
  (0 == strstr("aaa", "")) ? cout<<"OK : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl : cout<< "Failed : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl ;
  (0 == strstr("aaa", "a")) ? cout<<"OK : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl : cout<< "Failed : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl ;
  (1 == strstr("abc", "b")) ? cout<<"OK : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl : cout<< "Failed : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl ;
  (2 == strstr("abc", "c")) ? cout<<"OK : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl : cout<< "Failed : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl ;
  (-1 == strstr("abc", "d")) ? cout<<"OK : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl : cout<< "Failed : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl ;
               
  (-1 == strstr("a", "aa")) ? cout<<"OK : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl : cout<< "Failed : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl ;
  (-1 == strstr("a", "ba")) ? cout<<"OK : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl : cout<< "Failed : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl ;
  (-1 == strstr("a", "ab")) ? cout<<"OK : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl : cout<< "Failed : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl ;
  (-1 == strstr("a", "bb")) ? cout<<"OK : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl : cout<< "Failed : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl ;
               
  (-1 == strstr("a", "aaa")) ? cout<<"OK : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl : cout<< "Failed : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl ;
  (-1 == strstr("aa", "aaa")) ? cout<<"OK : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl : cout<< "Failed : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl ;
  (0 == strstr("aaa", "aaa")) ? cout<<"OK : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl : cout<< "Failed : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl ;
  (0 == strstr("aaab", "aaa")) ? cout<<"OK : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl : cout<< "Failed : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl ;
  (1 == strstr("baaa", "aaa")) ? cout<<"OK : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl : cout<< "Failed : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaaa", "aaa")) ? cout<<"OK : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl : cout<< "Failed : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaab", "aaa")) ? cout<<"OK : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl : cout<< "Failed : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl ;
  (-1 == strstr("abd", "abc")) ? cout<<"OK : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl : cout<< "Failed : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl ;
               
  (2 == strstr("ababc", "abc")) ? cout<<"OK : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl : cout<< "Failed : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl ;
  (3 == strstr("abdabc", "abc")) ? cout<<"OK : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl : cout<< "Failed : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl ;

}

int main() {

    //const char str[] = "hello priv hi world";
    //const char fnd[] = "hello";

    test();
    //cout << strstr("ababc", "abc");

    /* vector<string> words = { "Car"s,"Albatros"s,"Two"s,"War"s,"Bike"s };
    SortBy(words,
        [](const string& left, const string& right) {
            return left > right;
        });
    PrintContainer(words);
    cout << endl << "************************"s << endl;

    vector<int> numbers = { 1,20,11,3,7,9,0 };
    SortBy(numbers,
        [](const int left, const int right) {
            return left > right;
        });
    PrintContainer(numbers);
    cout << endl << "************************"s << endl;

    const set<string> set_of_string = { "man"s,"who"s,"girl"s,"wants" };
    auto vec_from_set = ConvertContainer(set_of_string);
    SortBy(vec_from_set,
        [](const string& left, const string& right) {
            return left > right;
        });
    PrintContainer(vec_from_set);
    cout << endl << "************************"s << endl;
    
    const map<int, string> map_of_string = { {1,"people"s},{2,"second"s},{3,"fan"s},{4,"lux"} };
    auto vec_from_map = ConvertContainer(map_of_string);

    SortBy(vec_from_map,
        [](const pair<int, string>& left, const pair<int, string> right) {
            return left.first > right.first;
        });
    PrintContainer(vec_from_map);

    cout << endl << "************************"s << endl;
    auto words_plus_words = words + words;
    PrintContainer(words_plus_words);

    cout << endl << "************************"s << endl;
    auto numbers_plus_numbers = numbers + numbers;
    PrintContainer(numbers_plus_numbers); */

    return 0;
}