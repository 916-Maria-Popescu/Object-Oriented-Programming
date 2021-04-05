#ifndef TESTREPOSITORY_H
#define TESTREPOSITORY_H

class TestRepository{
private:
    static void test_add_repository();
    static void test_remove_repository();
    static void test_update_title_repository();
    static void test_update_genre_repository();
    static void test_update_likes_repository();
    static void test_update_year_repository();
    static void test_update_link_repository();
    static void test_find_movie_by_id();
    static void test_add_watch_list_repository();
    static void test_delete_watch_list_repository();
    static void test_find_by_id_watch_list();
    static void test_like_watch_list_repository();

public:
    TestRepository();
    ~TestRepository();
    static void test_all();
};

#endif //TESTREPOSITORY_H
