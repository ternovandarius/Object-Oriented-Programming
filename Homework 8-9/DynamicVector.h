#pragma once
#include "Domain.cpp"

template <typename TElem>
class DynamicVector{
private:
    TElem *elems;
    int size;
    int capacity;

    void resize();
public:
    DynamicVector(int capacity = 10);
    DynamicVector(const DynamicVector& v);
    DynamicVector& operator=(const DynamicVector& v);
    ~DynamicVector();
    void add(TElem& e);
    int remove(std::string &name);
    int get_size();
    std::string get_one(int pos);
    int search_for_pos(std::string &name);
    void update_by_pos_string(std::string &name, int pos, int mode);
    void update_by_pos_int(int val, int pos, int mode);
    DynamicVector& operator+(TElem &e);
    std::string get_name(int pos);
    Movie& operator[](int pos);
    int get_likes(int pos);
};

template<typename TElem>
DynamicVector<Movie>& operator+(TElem &e, DynamicVector<Movie> &v);

void test_dynamicvector();