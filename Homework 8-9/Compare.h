//
// Created by terno on 4/24/2019.
//
#pragma once

typedef Movie TElem;

class Compare {
public:
    virtual bool compare(TElem t1, TElem t2);
};


class CompareAscendingByYear: public Compare{
    bool compare(TElem t1, TElem t2) override;
};

class CompareDescendingByTitle: public Compare{
    bool compare(TElem t1, TElem t2) override;
};

