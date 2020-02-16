//
// Created by terno on 3/25/2019.
//

#include "DynamicVector.h"

template <typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity) {
    this->size=0;
    this->capacity=capacity;
    this->elems= new TElem[this->capacity];
}

template <typename TElem>
void DynamicVector<TElem>::resize() {
    /*
     * This function doubles the capacity.
     */
    this->capacity*=2;
    TElem* new_elems=new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
    {
        new_elems[i]=this->elems[i];
    }
    delete[] this->elems;
    this->elems=new_elems;
}

template <typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector &v) {
    this->size=v.size;
    this->capacity=v.capacity;
    this->elems=new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        this->elems[i]=v.elems[i];
}

template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector& v)
{
    /*
     * Overload of the = operator.
     */
    if (this==&v)
        return *this;

    this->size=v.size;
    this->capacity=v.capacity;
    delete[] this->elems;
    this->elems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        this->elems[i]=v.elems[i];
    return *this;
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector() {
    delete[] this->elems;
}

template <typename TElem>
void DynamicVector<TElem>::add(TElem &e) {
    /*
     * This function adds a TElem element to the DynamicVector.
     */
    int ok=1;
    for (int i = 0; i < this->size; i++)
    {
        if (e.get_title()==this->elems[i].get_title())
            ok=0;
    }
    if(ok==1) {
        if (this->size == this->capacity)
            this->resize();
        this->elems[this->size] = e;
        this->size++;
    }
}

template <typename TElem>
int DynamicVector<TElem>::remove(std::string &name) {
    /*
     * This function removes an element from the DynamicVector. If the process is successful, it returns 1, otherwise, 0.
     */
    int i, ok=0;
    for (i=0; i<this->size; i++)
    {
        if (this->elems[i].get_title()==name)
        {
            for(int j=i; j<this->size-1; j++)
                this->elems[j]=this->elems[j+1];
            this->size--;
            ok=1;
        }
    }
    return ok;
}

template <typename TElem>
int DynamicVector<TElem>::get_size()
{
    /*
     * This function returns the size of the DynamicVector.
     */
    return this->size;
}

template <typename TElem>
std::string DynamicVector<TElem>::get_one(int pos) {
    /*
     * This function returns all the details of the movie at position pos.
     */
    return this->elems[pos].to_string();
}

template <typename TElem>
std::string DynamicVector<TElem>::get_name(int pos){
    /*
     * This function returns the title of the movie at position pos.
     */
    return this->elems[pos].get_title();
}

template <typename TElem>
int DynamicVector<TElem>::search_for_pos(std::string &name)
{
    /*
     * This function returns the position of a movie based on its name.
     */
    for(int i=0; i<this->size; i++)
        if(this->elems[i].get_title()==name)
            return i;
    return -1;
}

template <typename TElem>
void DynamicVector<TElem>::update_by_pos_string(std::string &name, int pos, int mode) {
    if (mode==1)
        this->elems[pos].set_title(name);
    else if (mode==2)
        this->elems[pos].set_genre(name);
    else if (mode==5)
        this->elems[pos].set_trailer(name);
}

template <typename TElem>
void DynamicVector<TElem>::update_by_pos_int(int val, int pos, int mode) {
    if (mode==3)
        this->elems[pos].set_year(val);
    else if(mode==4)
        this->elems[pos].set_likes(val);
}

template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator+(TElem &e) {
    this->add(e);
    return *this;
}

template <typename TElem>
DynamicVector<TElem>& operator+(TElem &e, DynamicVector<TElem> &v)
{
    return v.operator+(e);
}

template <typename TElem>
Movie& DynamicVector<TElem>::operator[](int pos) {
    return this->elems[pos];
}

template <typename TElem>
int DynamicVector<TElem>::get_likes(int pos) {
    return this->elems[pos].get_likes();
}

void test_dynamicvector()
{
    DynamicVector<Movie> d(2);
    Movie m;
    d.add(m);
    Movie m2("a", "b", 1, 2, "c");
    d.add(m2);
    Movie m3("x", "y", 1, 2, "z");
    d.add(m3);
    DynamicVector<Movie> d1=d;
    assert(d1.get_size()==3);
    std::string name="a";
    assert(d.remove(name)==1);
    assert(d1.get_size()==3);
    assert(d.get_size()==2);
    DynamicVector<Movie> d2(d1);
    assert(d2.get_size()==3);
    d2.update_by_pos_int(12, 0, 4);
    assert(d2.get_likes(0)==12);
    d2.update_by_pos_string(name, 0, 1);
    assert(d2.get_name(0)==name);
    d=d+m2;
    assert(d.get_size()==3);
    assert(d1.search_for_pos(name)==1);
    assert(d[1].get_title()==m3.get_title());
}