#pragma once
#include "Repository.cpp"

class Iterator
{
private:
    DynamicVector<Movie> m;
    int pos;
public:
    Iterator();
    void add(Movie& m);
    Movie get_current();
    void display();
    void next();
    int is_empty();
    void empty_iterator();
};

void test_iterator();