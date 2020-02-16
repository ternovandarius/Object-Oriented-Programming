#pragma once
#include "DynamicVector.cpp"

class Repository{
private:
    DynamicVector<Movie> &movie_repo;
public:
    Repository(DynamicVector<Movie> &v) : movie_repo{v} {};
    void addRepo(Movie &m);
    int removeRepo(std::string &name);
    DynamicVector<Movie> get_allRepo();
    void update_by_pos_stringRepo(std::string &name, int pos, int mode);
    void update_by_pos_intRepo(int val, int pos, int mode);
    void lab5(Movie &m);
};

void test_repository();