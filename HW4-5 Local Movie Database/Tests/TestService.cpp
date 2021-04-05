#include "TestService.h"
#include "../Service/ServiceMovies.h"
#include <cassert>

void TestService::test_add_service() {
    Service s = Service();
    assert(s.repository.all_elements()->size() == 0);

    s.add_service(10, "t", "l", "g", 1900, 120);
    assert(s.repository.all_elements()->operator[](0).getYear() == 1900);
    assert(s.repository.all_elements()->operator[](0).getLikes() == 120);
    assert(s.repository.all_elements()->size() == 1);


    s.add_service(11, "t", "l", "g", 1900, 120);
    assert(s.repository.all_elements()->operator[](1).getYear() == 1900);
    assert(s.repository.all_elements()->operator[](1).getLikes() == 120);
    assert(s.repository.all_elements()->size() == 2);

    s.add_service(12, "t", "l", "g", 1900, 120);
    assert(s.repository.all_elements()->operator[](2).getYear() == 1900);
    assert(s.repository.all_elements()->operator[](2).getLikes() == 120);
    assert(s.repository.all_elements()->size() == 3);

}

void TestService::test_delete_service() {
    Service s = Service();
    s.add_service(10, "t", "l", "g", 1900, 120);
    s.delete_service(10);
    assert(s.repository.all_elements()->size() == 0);


}

void TestService::test_update_service() {
    // Option - - - Attribute
    //    1   - - -   title
    //    2   - - -   likes
    //    3   - - -   year
    //    4   - - -   link
    //    5   - - -   genre
    Service s = Service();
    s.add_service(10, "t", "l", "g", 1900, 120);
    s.update_service(10, "new t", 1);
    assert(s.repository.all_elements()->operator[](0).getTitle() == "new t");

    s.update_service(10, "new g", 5);
    assert(s.repository.all_elements()->operator[](0).getGenre() == "new g");

    s.update_service(10, "20", 2);
    assert(s.repository.all_elements()->operator[](0).getLikes() == 20);

    s.update_service(10, "1904", 3);
    assert(s.repository.all_elements()->operator[](0).getYear() == 1904);

    s.update_service(10, "new l", 4);
    assert(s.repository.all_elements()->operator[](0).getLink() == "new l");

}

void TestService::test_add_watch_list_service() {
    Service s = Service();
    s.add_service(10, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(10);
    assert(s.repository.get_watch_list()->size() == 1);
    assert(s.repository.get_watch_list()->operator[](0).getId() == 10);

    s.add_service(11, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(11);
    assert(s.repository.get_watch_list()->size() == 2);
    assert(s.repository.get_watch_list()->operator[](1).getId() == 11);

}

void TestService::test_delete_watch_list_service() {
    Service s = Service();
    s.add_service(10, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(10);
    assert(s.repository.get_watch_list()->size() == 1);

    s.delete_watch_list_service(10, 1);
    assert(s.repository.get_watch_list()->size() == 0);
    assert(s.repository.all_elements()->operator[](0).getLikes() == 121);

    s.add_service(11, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(11);

    s.delete_watch_list_service(11, 0);
    assert(s.repository.get_watch_list()->size() == 0);
    assert(s.repository.all_elements()->operator[](1).getLikes() == 120);

}


void TestService::test_all() {
    test_add_service();
    test_delete_service();
    test_update_service();
    test_add_watch_list_service();
    test_delete_watch_list_service();
    test_all_movies_by_genre_service();

}

void TestService::test_all_movies_by_genre_service() {
    Service s = Service();
    s.add_service(11, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(11);
    s.add_service(12, "t", "l", "b", 1900, 120);
    s.add_watch_list_service(12);
    s.add_service(13, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(13);
    s.add_service(14, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(14);
    s.add_service(15, "t", "l", "g", 1900, 120);
    s.add_watch_list_service(15);
    DynamicArray<Movie> *result = s.all_movies_by_genre_service("g");
    assert(result->size() == 4);
    assert(result->operator[](0).getId() == 11);

}

