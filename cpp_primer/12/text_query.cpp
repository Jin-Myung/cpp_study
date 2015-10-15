#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &infile);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend ostream &print(ostream &os, const QueryResult &qr);
public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f)
            : sought(s), lines(p), file(f) { }
private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &infile) : file(new vector<string>) {
    string text;
    while (getline(infile, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &it = wm[word];
            if (!it) {
                it.reset(new set<line_no>());
            }
            it->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end()) {
        return QueryResult(s, nodata, file);
    } else {
        return QueryResult(s, loc->second, file);
    }
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
                << *(qr.file->begin()+num) << endl;
    }
    return os;
}

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <text file name>\n" << endl;
        return 0;
    }
    ifstream infile(argv[1]);
    runQueries(infile);
    return 0;
}
