#include <cassert>
#include "TestRepository.h"
#include "../Repository/RepositoryMovies.h"

void TestRepository::test_add_repository() {
    Repository repository = Repository();
    int x = repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    assert(x == 1);
    x = repository.add_repository(10, "my title", "link", "comedy", 1900, 345);
    assert(x == 0);
    x = repository.add_repository(11, "title", "link", "comedy", 1900, 345);
    assert(x == 1);
    assert(repository.all_elements()->size() == 2);
}

void TestRepository::test_remove_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    repository.add_repository(11, "title", "link", "comedy", 1900, 345);
    // last elem added has the id 11
    assert(repository.all_elements()->operator[](0).getId() == 10);
    int x = repository.delete_repository(10);
    // the function delete_repository delete should work => should return value 1
    assert(x == 1);
    // the size of the array elements should dec by 1 => size = 1
    assert(repository.all_elements()->size() == 1);
    x = repository.delete_repository(15);
    // the function delete_repository delete should not 'work' => should return value 0 ( no elem found)
    assert(x == 0);
    // the size of the array elements should remain 1
    assert(repository.all_elements()->size() == 1);
    x = repository.delete_repository(10);
    // the function delete_repository delete should not 'work' => should return value 0 ( no elem found)
    // (even though there was an elem with id 10)
    assert(x == 0);
    // the size of the array elements should remain 1
    assert(repository.all_elements()->size() == 1);
    // the id of the first elem should be '11', not '10'
    // (check if the right elem was deleted)
    assert(repository.all_elements()->operator[](0).getId() == 11);

    //
    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.delete_repository(34);
    assert(x == 1);
    assert(repository.get_watch_list()->size() == 0);


}

void TestRepository::test_update_title_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    int x = repository.update_title_repository(10, "new title");
    //function update_title_repository should find the object of class movie with the id "10"
    // => should return 1
    assert(x == 1);
    // the title of the object of class movie with the id "10" should be now "new title"
    assert(repository.all_elements()->operator[](0).getTitle() == "new title");

    x = repository.update_title_repository(11, "new title");
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.update_title_repository(34, "new");
    assert(x == 1);
    assert(repository.get_watch_list()->operator[](0).getTitle() == "new");

}

void TestRepository::test_update_genre_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    int x = repository.update_genre_repository(10, "new genre");
    //function update_title_repository should find the object of class movie with the id "10"
    // => should return 1
    assert(x == 1);
    // the title of the object of class movie with the id "10" should be now "new title"
    assert(repository.all_elements()->operator[](0).getGenre() == "new genre");

    x = repository.update_genre_repository(11, "new genre");
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    x = repository.update_genre_repository(116, "new genre");
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.update_genre_repository(34, "romantic");
    assert(x == 1);
    assert(repository.get_watch_list()->operator[](0).getGenre() == "romantic");

}

void TestRepository::test_update_likes_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    int x = repository.update_likes_repository(10, 1000);
    //function update_title_repository should find the object of class movie with the id "10"
    // => should return 1
    assert(x == 1);
    // the title of the object of class movie with the id "10" should be now "new title"
    assert(repository.all_elements()->operator[](0).getLikes() == 1000);

    x = repository.update_likes_repository(11, 1000);
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    x = repository.update_likes_repository(111, 1000);
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);


    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.update_likes_repository(34, 100);
    assert(x == 1);
    assert(repository.get_watch_list()->operator[](0).getLikes() == 100);

}

void TestRepository::test_update_year_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    int x = repository.update_year_repository(10, 1000);
    //function update_title_repository should find the object of class movie with the id "10"
    // => should return 1
    assert(x == 1);
    // the title of the object of class movie with the id "10" should be now "new title"
    assert(repository.all_elements()->operator[](0).getYear() == 1000);

    x = repository.update_year_repository(11, 1000);
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    x = repository.update_year_repository(100, 1000);
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.update_year_repository(34, 2000);
    assert(x == 1);
    assert(repository.get_watch_list()->operator[](0).getYear() == 2000);

}

void TestRepository::test_update_link_repository() {
    Repository repository = Repository();
    repository.add_repository(10, "title", "link", "comedy", 1900, 345);
    int x = repository.update_link_repository(10, "new link");
    //function update_title_repository should find the object of class movie with the id "10"
    // => should return 1
    assert(x == 1);
    // the title of the object of class movie with the id "10" should be now "new title"
    assert(repository.all_elements()->operator[](0).getLink() == "new link");

    x = repository.update_link_repository(11, "new link");
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    x = repository.update_link_repository(115, "new link");
    //function update_title_repository should not find an object of class movie with the id "11"
    // => should return 0 ( no such elem)
    assert(x == 0);

    repository.add_repository(34, "title", "link", "comedy", 1900, 200);
    repository.add_watch_list_repository(34);
    x = repository.update_link_repository(34, "new");
    assert(x == 1);
    assert(repository.get_watch_list()->operator[](0).getLink() == "new");

}
void TestRepository::test_find_movie_by_id() {
    Repository repository = Repository();
    repository.add_repository(10, "yy", "lk", "cd", 1900, 3665);
    int x = repository.find_movie_by_id(10);
    assert(repository.find_movie_by_id(10) == 0);

    repository.add_repository(11, "title", "link", "comedy", 1904, 33345);
    x = repository.find_movie_by_id(10);
    assert(repository.find_movie_by_id(10) == 0);

    x = repository.find_movie_by_id(11);
    assert(repository.find_movie_by_id(11) == 1);

}
void TestRepository::test_delete_watch_list_repository() {
    Repository r = Repository();
    r.add_repository(1, "t1", "l1", "g1", 11, 1);
    r.add_watch_list_repository(1);
    int x = r.delete_watch_list_repository(1);
    assert(x == 1);
    assert(r.get_watch_list()->size() == 0);
    x = r.delete_watch_list_repository(1);
    assert(x == 0);
    x = r.delete_watch_list_repository(23);
    assert(x == 0);

}

void TestRepository::test_add_watch_list_repository() {
    Repository r = Repository();
    r.add_repository(1, "t1", "l1", "g1", 11, 1);
    assert(r.get_watch_list()->size() == 0);
    int x = r.add_watch_list_repository(1);
    assert(x == 1);
    assert(r.get_watch_list()->size() == 1);
    assert(r.get_watch_list()->operator[](0).getId() == 1);
    x = r.add_watch_list_repository(1);
    assert(x == 0);

}

void TestRepository::test_find_by_id_watch_list() {
    Repository r = Repository();
    r.add_repository(1, "t1", "l1", "g1", 11, 1);
    r.add_watch_list_repository(1);
    int x = r.find_by_id_watch_list(1);
    assert(x == 0);
    x = r.find_by_id_watch_list(33);
    assert(x == -1);
}

void TestRepository::test_like_watch_list_repository() {
    Repository r = Repository();
    r.add_repository(1, "t1", "l1", "g1", 11, 1);
    r.add_watch_list_repository(1);
    r.like_watch_list_repository(1);
    assert(r.all_elements()->operator[](0).getLikes() == 2);

}


void TestRepository::test_all() {
    test_add_repository();
    test_remove_repository();
    test_update_genre_repository();
    test_update_likes_repository();
    test_update_year_repository();
    test_update_link_repository();
    test_update_title_repository();
    test_find_movie_by_id();
    test_add_watch_list_repository();
    test_delete_watch_list_repository();
    test_like_watch_list_repository();
    test_find_by_id_watch_list();

}



TestRepository::TestRepository() = default;

TestRepository::~TestRepository() = default;
