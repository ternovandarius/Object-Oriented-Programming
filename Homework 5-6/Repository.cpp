//
// Created by terno on 3/25/2019.
//
#include <iostream>
#include "Repository.h"

void Repository::addRepo(Movie &m) {
    /*
     * This function adds a movie to the repo.
     */
    this->movie_repo.add(m);
}

int Repository::removeRepo(std::string &name) {
    /*
     * This function removes a movie from the repo, returning 1 if the remove process was successful.
     */
    return this->movie_repo.remove(name);
}

DynamicVector<Movie> Repository::get_allRepo() {
    /*
     * This function returns the DynamicVector object containing all the movies of the repo.
     */
    return this->movie_repo;
}

void Repository::update_by_pos_stringRepo(std::string &name, int pos, int mode) {
    /*
     * This function updates the string-based fields of a movie on position pos, replacing it with the value name.
     * If mode is 1, it updates the title; if it is 2 it updates the genre; if it is 5, it updates the trailer.
     */
    this->movie_repo.update_by_pos_string(name, pos, mode);
}

void Repository::update_by_pos_intRepo(int val, int pos, int mode) {
    /*
     * This function updates the int-based fields of a movie on position pos, replacing it with the value val.
     * If mode is 3, it updates the year of release; if it is 4, it updates the number of likes.
     */
    this->movie_repo.update_by_pos_int(val, pos, mode);
}

void Repository::lab5(Movie &m) {
    /*
     * This function adds a movie using the + operator of the DynamicVector object.
     */
    this->movie_repo=this->movie_repo+m;
    //this->movie_repo=m+this->movie_repo;
}

void test_repository(){
    DynamicVector<Movie> d;
    Repository repo(d);
    Movie m;
    repo.addRepo(m);
    Movie m2("a", "b", 1, 2, "c");
    repo.addRepo(m2);
    std::string name="a";
    assert(repo.removeRepo(name)==1);
    DynamicVector<Movie> d1;
    d1=repo.get_allRepo();
    assert(d1.get_size()==1);
    repo.lab5(m2);
    repo.update_by_pos_intRepo(10, 0, 4);
    repo.update_by_pos_stringRepo(name, 0, 1);
    d1=repo.get_allRepo();
    assert(d1.get_likes(0)==10);
    assert(d1.get_name(0)==name);
}