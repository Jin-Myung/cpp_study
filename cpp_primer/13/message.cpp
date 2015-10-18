#include <string>
#include <set>

class msg_t;

class fold_t {
public:
    void addMsg(const msg_t *);
    void remMsg(const msg_t *);
private:
    std::set<msg_t *> messages;
};

class msg_t {
    friend class fold_t;
    friend void swap(msg_t &lhs, msg_t &rhs);
public:
    explicit msg_t(const std::string &str = "") : contents(str) { }
    msg_t(const msg_t &m) : contents(m.contents), folders(m.folders) {
        add2fold(m);
    }
    msg_t &operator=(const msg_t &rhs) {
        remove4fold();
        contents = rhs.contents;
        folders = rhs.folders;
        add2fold(rhs);
        return *this;
    }
    msg_t &operator=(msg_t &&rhs) {
        if (this != &rhs) {
            remove4fold();
            contents = std::move(rhs.contents);
            move_fold(&rhs);
        }
        return *this;
    }
    ~msg_t() {
        remove4fold();
    }
    
    void save(fold_t &f) {
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(fold_t &f) {
        folders.erase(&f);
        f.remMsg(this);
    }
private:
    std::string contents;
    std::set<fold_t *> folders;
    void add2fold(const msg_t &m) {
        for (auto f : m.folders) {
            f->addMsg(this);
        }
    }
    void remove4fold() {
        for (auto f : folders) {
            f->remMsg(this);
        }
    }
    void move_fold(msg_t *m) {
        folders = std::move(m->folders);
        for (auto f : folders) {
            f->remMsg(m);
            f->addMsg(this);
        }
        m->folders.clear();
    }
};

void fold_t::addMsg(const msg_t *) {
    
}

void fold_t::remMsg(const msg_t *) {
    
}

void swap(msg_t &lhs, msg_t &rhs) {
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);     // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents);   // swap(string&, string&)
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

int main() {
    return 0;
}
