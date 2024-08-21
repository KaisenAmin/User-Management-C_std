#include "fmt/fmt.h"
#include "vector/vector.h"
#include "database/postgres.h"
#include "random/random.h"
#include "json/json.h"
#include "time/time.h"
#include "string/string.h"
#include <stdlib.h>


typedef struct {
    int id;
    char name[100];
    char email[100];
    Time* time_registered;
} User;

void add_user(Postgres* pg, Vector* users) {
    User user;

    user.id = random_randint(1, 10);

    sprintf(user.name, "User %d", random_randint(1, 1000));
    sprintf(user.email, "%s@gmail.com", user.name);

    user.time_registered = time_current_time();
    char* time_str = time_to_string(user.time_registered);
    String* data = string_create(time_str);
    String* data_substring = string_create(string_c_str(string_substr(string_substr(data, 1, string_length(data) - 2), 0, 8)));
    fmt_printf("Time is %s\n", string_c_str(data_substring));

    char query[512];
    sprintf(query, "INSERT INTO users (name, email, time_registered) VALUES ('%s', '%s', '%s');"
                , user.name, user.email, string_c_str(data_substring));
    
    postgres_execute_non_query(pg, query);
    vector_push_back(users, &user);

    free(time_str);
    string_deallocate(data);
    string_deallocate(data_substring);
}

void display_users_from_vector(Vector* users) {
    fmt_printf("Data in Vector Container of Users\n");

    for (size_t index = 0; index < vector_size(users); index++) {
        User* user = vector_at(users, index);
        fmt_printf("Id : %d, Name : %s, Email : %s\n", user->id, user->name, user->email);
    }
}

void save_users_to_json(Vector* users) {
    User* user = NULL;
    JsonElement* root = json_create(JSON_ARRAY);

    for (size_t index = 0; index < vector_size(users); index++) {
        user = vector_at(users, index);
        JsonElement* userObject = json_create(JSON_OBJECT);

        JsonElement* id = json_create(JSON_NUMBER);
        id->value.number_val = user->id;
        json_add_to_object(userObject, "id", id);

        JsonElement* name = json_create(JSON_STRING);
        name->value.string_val = user->name;
        json_add_to_object(userObject, "name", name);

        JsonElement* email = json_create(JSON_STRING);
        email->value.string_val = user->email;
        json_add_to_object(userObject, "email", email);

        JsonElement* ti = json_create(JSON_STRING);
        ti->value.string_val = string_strdup(time_to_string(user->time_registered));
        json_add_to_object(userObject, "time_registered", ti);

        json_add_to_array(root, userObject);
    }

    char* serialized_data = json_serialize(root);
    fmt_printf("Json Serialized Data is\n%s\n", serialized_data);

    free(serialized_data);
    json_deallocate(root);
    time_deallocate(user->time_registered);
}

int main() {
    Postgres* pg = postgres_create();
    Vector* users = vector_create(sizeof(User));

    random_seed((unsigned int)time_current_time_in_seconds());
    postgres_init(pg, "test", "postgres", "amin1375", "localhost", "5432");

    if (postgres_connect(pg)) {
        add_user(pg, users);
        display_users_from_vector(users);
        save_users_to_json(users);
    } 
    else {
        fmt_fprintf(stderr, "Can not connect to the database");
    }

    postgres_deallocate(pg);
    vector_deallocate(users);

    return 0;
}