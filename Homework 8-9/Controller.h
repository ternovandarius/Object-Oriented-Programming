#include "Iterator.cpp"
#include "Compare.cpp"

class Controller{
private:
    Repository* repo;
    Repository* watchlist;
    Iterator iterator;
public:
    Controller(Repository *r, Repository *w, Iterator i) : repo{r}, watchlist{w}, iterator{i} {}
    void addController(const std::string title, const std::string genre, const int year, const int likes, const std::string trailer);
    int removeController(std::string &name);
    std::vector<Movie> getAllController();
    void update_by_pos_stringController(std::string &name, int pos, int mode);
    void update_by_pos_intController(int val, int pos, int mode);
    void lab5Controller(const std::string title, const std::string genre, const int year, const int likes, const std::string trailer);
    std::vector<Movie> get_watchlist() const {return this->watchlist->get_allRepo();}
    void addWatchlist(Movie movie);
    int deleteWatchlist(std::string &movie);
    void initiateIterator(const std::string &genre);
    Movie get_current();
    void iterate();
    void next();
    Repository* get_repo();
    Repository* get_watchlist();
    void compare(std::vector<Movie> m, Compare* c);
};

void test_controller();