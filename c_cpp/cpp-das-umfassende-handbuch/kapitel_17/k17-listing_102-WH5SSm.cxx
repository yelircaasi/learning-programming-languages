struct Base {
    virtual ~Base() {}; // definieren Sie den Destruktor, machen Sie ihn virtual
    virtual void other();
};

struct Derived : public Base {
    void other() override;
};

int main() {
    Base *obj = new Derived{};
    /* ... mehr Programmzeilen hier ... */
    delete obj;     // klappt, weil Base::~Base virtual ist
}

