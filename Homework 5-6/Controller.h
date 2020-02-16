#include "Iterator.cpp"

class Controller{
private:
    Repository &repo;
    Repository &watchlist;
    Iterator &iterator;
public:
    Controller(Repository &r, Repository &w, Iterator &i) : repo{r}, watchlist{w}, iterator{i} {}
    void addController(const std::string title, const std::string genre, const int year, const int likes, const std::string trailer);
    int removeController(std::string &name);
    DynamicVector<Movie> getAllController();
    void update_by_pos_stringController(std::string &name, int pos, int mode);
    void update_by_pos_intController(int val, int pos, int mode);
    void lab5Controller(const std::string title, const std::string genre, const int year, const int likes, const std::string trailer);
    DynamicVector<Movie> get_watchlist() const {return this->watchlist.get_allRepo();}
    void addWatchlist(Movie &movie);
    int deleteWatchlist(std::string &movie);
    void initiateIterator(const std::string &genre);
    Movie get_current();
    void iterate();
    void next();
};

void test_controller();