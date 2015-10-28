#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Sales_item {
public:
    friend istream & operator>> (istream &, Sales_item&);
    friend ostream & operator<< (ostream &, const Sales_item&);
    string get_isbn() { return isbn; }
    Sales_item &operator+=(const Sales_item &rhs) {
        this->num += rhs.num;
        return *this;
    }
private:
    string isbn;
    double num;
};

istream & operator>> (istream &is, Sales_item& si) {
    is >> si.isbn >> si.num;
    return is;
}

ostream & operator<< (ostream &os, const Sales_item& si) {
    os << si.isbn << ": " << si.num;
    return os;
}

int main() {
    Sales_item base;
    if (cin >> base) {
        Sales_item next;
        while (cin >> next) {
            if (base.get_isbn() == next.get_isbn()) {
                base += next;
            } else {
                cout << base << endl;
                base = next;
            }
        }
    } else {
        cout << "No data" << endl;
        return 1;
    }
}

