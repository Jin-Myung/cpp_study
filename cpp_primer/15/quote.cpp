#include <string>
#include <iostream>

using namespace std;

class No_derived final {
};

class Quote {
public:
    Quote() = default;
    virtual ~Quote() = default;
    Quote(const string &_bn, const double _up)
        : bn(_bn), up(_up) { }
    string isbn() const { return bn; }
    virtual double net_price(size_t n) const { return n*up; }
private:
    string bn;
protected:
    double up = 0.;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &_bn, const double _up, size_t _qt, double _dc)
        : Quote(_bn, _up), qt(_qt), dc(_dc) { }
    double net_price(size_t) const = 0;
protected:
    size_t qt = 0;
    double dc = 0.;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &_bn, const double _up, size_t _mq, double _dc)
        : Disc_quote(_bn, _up, _mq, _dc) { }
    double net_price(size_t n) const override {
        if (n >= qt) {
            return n * (1-dc) * up;
        } else {
            return n * up;
        }
    }
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n
        << " total due: " << ret
        << endl;
    return ret;
}



int main() {
    return 0;
}

