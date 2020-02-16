//
// Created by terno on 4/2/2019.
//

#include "Iterator.h"

Iterator::Iterator() {
    this->pos=0;
}

void Iterator::add(Movie &mov) {
    this->m.add(mov);
}

Movie Iterator::get_current() {
    if(this->pos==this->m.get_size())
        this->pos=0;
    return this->m[this->pos];
}

void Iterator::display() {
    if(this->m.get_size()==0)
        return;
    this->pos=0;
    Movie movie=this->get_current();
    movie.display();
}

void Iterator::next() {
    if(this->m.get_size()==0)
        return;
    this->pos++;
    Movie movie=this->get_current();
    movie.display();
}

int Iterator::is_empty() {
    if (this->m.get_size()==0)
        return 1;
    return 0;
}

void Iterator::empty_iterator() {
    while(this->is_empty()==0) {
        std::string name;
        name=m.get_name(0);
        this->m.remove(name);
    }
}

void test_iterator()
{
    Iterator i;
    Movie m;
    i.add(m);
    assert(i.get_current().get_title()==m.get_title());
    assert(i.is_empty()==0);
    i.empty_iterator();
    assert(i.is_empty()==1);
}