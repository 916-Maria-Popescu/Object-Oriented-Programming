#include "Test.h"
#include "..\Domain\Estate.h"
#include "..\Domain\DynamicArray.h"
#include "..\Repository\EstateRepo.h"
#include "..\Service\EstateService.h"
#include <assert.h>
#include <string.h>
#include <accctrl.h>

//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------DOMAIN---------------------------
//----------------------------------------------------------------------------------------------------------------------

void test_estate(){
    Estate e;
    e = createEstate("house", "Baker, 23 B", 300, 40000);
    assert(strcmp(getAddress(&e), "Baker, 23 B") == 0);
    assert(strcmp(getType(&e), "house") == 0);
    assert(getSurface(&e) == 300);
    assert(getPrice(&e) == 40000);
    setPrice(&e, 5000);
    setSurface(&e, 400);
    setType(&e, "penthouse");
    assert(strcmp(getType(&e), "penthouse") == 0);
    assert(getSurface(&e) == 400);
    assert(getPrice(&e) == 5000);
}

void test_dynamic_array(){
    DynamicArray *da;
    Estate e = createEstate("house", "Lyon, 33", 40, 500);
    da = createDynamicArray(10);
    assert(da->length == 0);
    assert(da->capacity == 10);
    add(da, e);
    assert(da->length == 1);
    free(da->elements);
    free(da);
}

void test_domain(){
     test_dynamic_array();
     test_estate();
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------REPOSITORY--------------------
//----------------------------------------------------------------------------------------------------------------------

void test_create_repository(){
    Repository *r = createRepository(50);
    assert(r->array->capacity == 50);
    //destroy(r->array);
    free(r->array->elements);
    free(r->array);
    free(r);
}

void test_add_repo(){
    Repository *r = createRepository(50);

    // adds an valid estate -> should work and return the value 1
    assert(add_estate_repo("house", "Street, 49", 100, 1000, r) == 1);
    assert(strcmp(r->array->elements[0].type, "house") == 0);
    assert(strcmp(r->array->elements[0].address, "Street, 49") == 0);
    assert(r->array->elements[0].price == 1000);
    assert(r->array->elements[0].surface == 100);

    // adds an invalid estate -> shouldn't do anything, except from returning 0
    //         (duplicate address)
    assert(add_estate_repo("house", "Street, 49", 100, 1000, r) == 0);

    free(r->array->elements);
    free(r->array);
    free(r);
}

void test_find_by_address(){
    Repository *r = createRepository(10);
    add_estate_repo("house", "Street, 49", 100, 1000, r);
    add_estate_repo("house", "Street, 6", 100, 1000, r);
    add_estate_repo("house", "Street, 9", 100, 1000, r);
    // should return the index of the elem from the array
    assert(find_estate_by_address("Street, 49", r) == 0);
    assert(find_estate_by_address("Street, 9", r) == 2);
    // should return -1
    // (no estate with this address)
    assert(find_estate_by_address("wrong address", r) == -1);

    free(r->array->elements);
    free(r->array);
    free(r);
}

void test_delete_estate_repo(){
    Repository *r = createRepository(10);
    add_estate_repo("house", "Street, 49", 10, 6000, r);
    add_estate_repo("house", "Street, 6", 100, 1000, r);
    assert(delete_estate_repo("Street, 49", r) == 1);
    assert(r->array->length == 1);
    assert(r->array->elements[0].surface == 100);
    assert(delete_estate_repo("wrong address", r) == 0);

    free(r->array->elements);
    free(r->array);
    free(r);

}
void test_update_estate_type_repo(){
    Repository *r = createRepository(10);
    add_estate_repo("house", "Street, 49", 10, 6000, r);
    assert(update_estate_type_repo("Street, 49", "penthouse", r) == 1);
    assert(strcmp(getType(&r->array->elements[0]), "penthouse") == 0);
    assert(update_estate_type_repo("wrong address", "house", r) == 0);

    free(r->array->elements);
    free(r->array);
    free(r);

}
void test_update_estate_price_repo(){
    Repository *r = createRepository(10);
    add_estate_repo("house", "Street, 49", 10, 6000, r);
    assert(update_estate_price_repo("Street, 49", 10000, r) == 1);
    assert(getPrice(&r->array->elements[0]) == 10000);
    assert(update_estate_price_repo("wrong address", 89, r) == 0);

    free(r->array->elements);
    free(r->array);
    free(r);

}
void test_update_estate_surface_repo(){
    Repository *r = createRepository(10);
    add_estate_repo("house", "Street, 49", 10, 6000, r);
    assert(update_estate_surface_repo("Street, 49", 70, r) == 1);
    assert(getSurface(&r->array->elements[0]) == 70);
    assert(update_estate_price_repo("wrong address", 89, r) == 0);

    free(r->array->elements);
    free(r->array);
    free(r);
}

void test_repository(){
    test_create_repository();
    test_add_repo();
    test_find_by_address();
    test_delete_estate_repo();
    test_update_estate_type_repo();
    test_update_estate_price_repo();
    test_update_estate_surface_repo();
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------SERVICE-----------------------
//----------------------------------------------------------------------------------------------------------------------

void test_create_service(){
    Service *s = createService(10);
    assert(s->repo->array->capacity == 10);
    assert(s->repo->array->length == 0);

    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

}

void test_add_estate(){
    Service *s;
    s = createService(10);
    add_estate("house", "Street, 1", 100, 3000, s);
    assert(s->repo->array->length == 1);
    assert(getSurface(&s->repo->array->elements[0]) == 100);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

}

void test_delete_estate(){
    Service *s;
    s = createService(10);
    add_estate("house", "Street, 1", 100, 3000, s);
    delete_estate("Street, 1", s);
    assert(s->repo->array->length == 0);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

}

void test_update_estate(){
    Service *s;
    s = createService(10);
    add_estate("house", "Street, 1", 100, 3000, s);
    update_estate("Street, 1", "penthouse", 500, 7000, s);
    assert(strcmp(getType(&s->repo->array->elements[0]), "penthouse") == 0);
    assert(getPrice(&s->repo->array->elements[0]) == 7000);
    assert(getSurface(&s->repo->array->elements[0]) == 500);
    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);
}

void test_filter_surface(){
    Service *s;
    Service *s_aux;
    s = createService(10);
    add_estate("house", "Street, 1", 100, 6000, s);
    add_estate("house", "Street, 2", 100, 6001, s);
    add_estate("house", "Street, 11", 300, 30, s);
    add_estate("house", "Street, 21", 100, 300, s);
    s_aux = filter_surface(100, s);
    assert(s_aux->repo->array->length == 3);
    assert(getPrice(&s_aux->repo->array->elements[0]) == 300);
    assert(getPrice(&s_aux->repo->array->elements[1]) == 6000);
    assert(getPrice(&s_aux->repo->array->elements[2]) == 6001);

    free(s_aux->repo->array->elements);
    free(s_aux->repo->array);
    free(s_aux->repo);
    free(s_aux);

    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);
}

void test_filter_address(){
    Service *s;
    Service *s_aux;
    s = createService(10);
    add_estate("house", "Street, 1", 100, 6000, s);
    add_estate("house", "Street, 2", 100, 6001, s);
    add_estate("house", "Street, 11", 300, 30, s);
    add_estate("house", "Street, 21", 100, 300, s);
    s_aux = filter_address("1", s);
    assert(s_aux->repo->array->length == 3);
    assert(getPrice(&s_aux->repo->array->elements[0]) == 30);
    assert(getPrice(&s_aux->repo->array->elements[1]) == 300);
    assert(getPrice(&s_aux->repo->array->elements[2]) == 6000);

    free(s->repo->array->elements);
    free(s->repo->array);
    free(s->repo);
    free(s);

    free(s_aux->repo->array->elements);
    free(s_aux->repo->array);
    free(s_aux->repo);
    free(s_aux);

}


void test_service(){
    test_create_service();
    test_add_estate();
    test_delete_estate();
    test_update_estate();
    test_filter_surface();
    test_filter_address();
}


void test_all(){
    test_domain();
    test_repository();
    test_service();
}
