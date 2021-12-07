#define ll long long
#define ull unsigned long long

#include <bits/stdc++.h>

using namespace std;

const int BIG_NUM = 1000000007;

// I/O functions \/
template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

vector<string> getWords() {
	string s;
	vector<string> words;
	string line;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> s) {    
		words.push_back(s);
	}
	return words;
}
// I/O functions ^

struct pairhash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        // Szudzik's function
        int a = v.first;
        int b = v.second;
        return (a >= b)? (a * a + a + b) : (a + b * b);
    }
};

int main() {

    return 0;

}
