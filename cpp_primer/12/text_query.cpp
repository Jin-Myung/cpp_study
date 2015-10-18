#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class qr_t;

class tq_t {
public:
    using line_no = vector<string>::size_type;
    tq_t(ifstream &inf);
    qr_t query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class qr_t {
    friend ostream &print(ostream &os, const qr_t &qr);
public:
    qr_t(string s, shared_ptr<set<tq_t::line_no>> p, shared_ptr<vector<string>> f)
            : sought(s), lines(p), file(f) { }
private:
    string sought;
    shared_ptr<set<tq_t::line_no>> lines;
    shared_ptr<vector<string>> file;
};

tq_t::tq_t(ifstream &inf) : file(new vector<string>) {
    string text;
    while (getline(inf, text)) {
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

qr_t tq_t::query(const string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end()) {
        return qr_t(s, nodata, file);
    } else {
        return qr_t(s, loc->second, file);
    }
}

ostream &print(ostream &os, const qr_t &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
                << *(qr.file->begin()+num) << endl;
    }
    return os;
}

void runQueries(ifstream &inf) {
    tq_t tq(inf);
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
    ifstream inf(argv[1]);
    runQueries(inf);
    return 0;
}
