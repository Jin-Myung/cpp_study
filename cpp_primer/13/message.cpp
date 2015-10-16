#include <string>
#include <set>

class Message;

class Folder {
public:
    void addMsg(const Message *);
    void remMsg(const Message *);
private:
    std::set<Message *> messages;
};

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = "") : contents(str) { }
    Message(const Message &m) : contents(m.contents), folders(m.folders) {
        add_to_Folders(m);
    }
    Message &operator=(const Message &rhs) {
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }
    ~Message() {
        remove_from_Folders();
    }
    
    void save(Folder &f) {
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(Folder &f) {
        folders.erase(&f);
        f.remMsg(this);
    }
private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &m) {
        for (auto f : m.folders) {
            f->addMsg(this);
        }
    }
    void remove_from_Folders() {
        for (auto f : folders) {
            f->remMsg(this);
        }
    }
};

void Folder::addMsg(const Message *) {
    
}

void Folder::remMsg(const Message *) {
    
}

void swap(Message &lhs, Message &rhs) {
    using std::swap; // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);     // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents);   // swap(string&, string&)
    // add pointers to each Message to their (new) respective Folders
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

int main() {
    return 0;
}
