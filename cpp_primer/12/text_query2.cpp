#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

class Query_result {
    friend ostream &operator<<(ostream &, const Query_result&);
public:
    Query_result(shared_ptr<vector<string>> _t, shared_ptr<set<int>> _l)
        : texts(_t), lines(_l) { }
public:
    shared_ptr<vector<string>> texts;
    shared_ptr<set<int>> lines;
};

class Text_query {
public:
    Text_query(ifstream &ifs);
    Query_result query(const string &word);
    void output_index() const;
private:
    shared_ptr<vector<string>> texts;
    map<string, shared_ptr<set<int>>> wm;
};

ostream &operator<<(ostream & os, const Query_result& qr) {
    os << qr.lines->size() << " lines found!!!\n";
    for (const int ln : *(qr.lines)) {
        os << ln << ": " << qr.texts->at(ln-1) << endl;
    }
    os << qr.lines->size() << " lines found!!!\n";
    return os;
}

Text_query::Text_query(ifstream &ifs) : texts(new vector<string>) {
    string line;
    while (getline(ifs, line)) {
        texts->push_back(line);
        istringstream ss(line);
        string word;
        while (ss >> word) {
            auto &ls = wm[word];
            if (!ls) {
                ls.reset(new set<int>);
            }
            ls->insert(texts->size());
        }
    }
}

Query_result Text_query::query(const string &word) {
    static shared_ptr<set<int>> no_data(new set<int>);
    auto it = wm.find(word);
    if (it != wm.end()) {
        return Query_result(texts, it->second);
    } else {
        return Query_result(texts, no_data);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <txt file>\n\n";
        return 0;
    }
    ifstream ifs;
    ifs.open(string(argv[1]));
    if (false == ifs.good()) {
        cout << "Failed to open " << argv[1] << "\n";
    }
    Text_query tq(ifs);
    while (1) {
        cout << "Enter <q> to quit: ";
        string word;
        cin >> word;
        if ("q" == word) {
            break;
        }
        Query_result qr = tq.query(word);
        cout << qr << endl;
    }
    return 0;
}

