#pragma once
#include <vector>
#include <exception>
#include "DynamicVector.cpp"

class Repository{
protected:
    std::vector<Movie> &movie_repo;
    std::string file_name;
public:
    Repository(std::vector<Movie> &v, std::string &file);
    virtual void addRepo(Movie &m);
    virtual int removeRepo(std::string &name);
    virtual std::vector<Movie> get_allRepo();
    virtual void update_by_pos_stringRepo(std::string &name, int pos, int mode);
    virtual void update_by_pos_intRepo(int val, int pos, int mode);
    virtual int get_size();
    virtual std::string get_one(int pos);
    virtual int get_likes(int pos);
    virtual int search_for_pos(std::string name);
    virtual Movie& operator[](int pos);
    virtual std::string get_name(int pos);
    virtual void update_file();
    virtual void read_file();
};

void test_repository();

class RepoException: public std::exception{
private:
    std::string msg;
public:
    RepoException(std::string msg);
    const char* what() const noexcept override;
};

class CSVRepository: public Repository{
public:
    CSVRepository(std::vector<Movie> &v, std::string &file);
    void read_file() override;
    void update_file() override;
    void addRepo(Movie &m) override;
    int removeRepo(std::string &name) override;
    std::vector<Movie> get_allRepo() override;
    void update_by_pos_stringRepo(std::string &name, int pos, int mode) override;
    void update_by_pos_intRepo(int val, int pos, int mode) override;
    int get_size() override;
    std::string get_one(int pos) override;
    int get_likes(int pos);
    int search_for_pos(std::string name) override;
    Movie& operator[](int pos) override;
    std::string get_name(int pos) override;
};

class HTMLRepository: public Repository{
public:
    HTMLRepository(std::vector<Movie> &v, std::string &file);
    //void read_file() override;
    void update_file() override;
    void addRepo(Movie &m) override;
    int removeRepo(std::string &name) override;
    std::vector<Movie> get_allRepo() override;
    void update_by_pos_stringRepo(std::string &name, int pos, int mode) override;
    void update_by_pos_intRepo(int val, int pos, int mode) override;
    int get_size() override;
    std::string get_one(int pos) override;
    int get_likes(int pos) override;
    int search_for_pos(std::string name) override;
    Movie& operator[](int pos) override;
    std::string get_name(int pos) override;
};