//
// Created by terno on 3/25/2019.
//

#include "Controller.h"
void Controller::addController(const std::string title, const std::string genre, const int year, const int likes,
                               const std::string trailer) {
    /*
     * This function creates a movie based on its arguments, then adds that movie to the repository.
     */
    try{
        Movie m{title, genre, year, likes, trailer};
        MovieValidator v;
        v.validate(m);
        this->repo->addRepo(m);
    }catch(MovieException e)
    {
        std::cout<<e.what();
    }
}

int Controller::removeController(std::string &name) {
    /*
     * This function tries to remove a movie from the repo. It returns 1 if it was successful.
     */
    return this->repo->removeRepo(name);
}

std::vector<Movie> Controller::getAllController() {
    /*
     * This function returns the DynamicVector object which contains all movies.
     */
    return this->repo->get_allRepo();
}

void Controller::update_by_pos_stringController(std::string &name, int pos, int mode) {
    /*
     * This function updates the string-based fields of a movie on position pos, replacing it with the value name.
     * If mode is 1, it updates the title; if it is 2 it updates the genre; if it is 5, it updates the trailer.
     */
    this->repo->update_by_pos_stringRepo(name, pos, mode);
}

void Controller::update_by_pos_intController(int val, int pos, int mode) {
    /*
     * This function updates the int-based fields of a movie on position pos, replacing it with the value val.
     * If mode is 3, it updates the year of release; if it is 4, it updates the number of likes.
     */
    this->repo->update_by_pos_intRepo(val, pos, mode);
}

void Controller::lab5Controller(const std::string title, const std::string genre, const int year, const int likes,
                                const std::string trailer) {
    /*
     * This function uses the lab5 function in Repo, solving the in-lab assignment for lab 5.
     */
    Movie m{title, genre, year, likes, trailer};
    //this->repo.lab5(m);
}

void Controller::addWatchlist(Movie movie) {
    /*
     * This function adds a movie to the watchlist.
     */
    this->watchlist->addRepo(movie);
}

int Controller::deleteWatchlist(std::string &movie) {
    /*
     * This function tries to delete a movie from the watchlist based on the name passed as argument.
     * It will return 1 if it is successful.
     */
    return this->watchlist->removeRepo(movie);
}

void Controller::initiateIterator(const std::string &genre) {
    /*
     * This function creates the list of movies to be iterated.
     * If the string passed as argument is blank, then it adds all the movies in the repo.
     */
    this->iterator.empty_iterator();
    std::vector<Movie> m=this->repo->get_allRepo();
    if(genre.size()==0)
    {
        for(int i=0; i<this->repo->get_size(); i++)
        {
            this->iterator.add(m[i]);
        }
    }
    else {
        for (int i=0; i<this->repo->get_size(); i++)
            if(m[i].get_genre()==genre)
                this->iterator.add(m[i]);
    }
}

Movie Controller::get_current() {
    /*
     * This function returns the current movie that the iterator is pointing at.
     */
    return this->iterator.get_current();
}

void Controller::iterate() {
    /*
     * This function begins the iteration process by displaying the first movie trailer on the screen.
     */
    this->iterator.display();
}

void Controller::next() {
    /*
     * This function points the iterator to the next movie, and tells it to display its trailer on the screen.
     */
    this->iterator.next();
}

Repository* Controller::get_repo() {
    return this->repo;
}

Repository* Controller::get_watchlist() {
    return this->watchlist;
}
/*
void test_controller(){
    std::vector<Movie> d;
    Repository r(d);
    std::vector<Movie> d1;
    Repository w(d1);
    Iterator i;
    Controller c{r, w, i};
    c.addController("a", "b", 1, 2, "c");
    std::string name="a";
    assert(c.removeController(name)==1);
    c.addController("a", "b", 1, 2, "c");
    c.lab5Controller("x", "y", 1, 2, "z");
    c.update_by_pos_intController(100, 1, 4);
    c.update_by_pos_stringController(name, 1, 1);
    assert(r[0].get_title()=="a");
    assert(r[1].get_title()=="a");
    assert(r[1].get_likes()==100);
    c.addWatchlist(r[0]);
    c.addWatchlist(r[1]);
    assert(c.deleteWatchlist(name)==1);
    std::string genre="";
    c.initiateIterator(genre);
}*/

void Controller::compare(std::vector<Movie> m, Compare *c) {
    int i, j;
    for(i=0; i<m.size()-1; i++)
    {
        for(j=i+1; j<m.size(); j++)
        {
            if(!c->compare(m[i], m[j]))
            {
                Movie aux;
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
    for(i=0; i<m.size(); i++)
    {
        std::cout<<m[i]<<std::endl;
    }
}