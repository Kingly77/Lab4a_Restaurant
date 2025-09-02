// COMSC-210 | Lab 4A | Shelby Jordan
// IDE used: Clion

#include <iostream>

struct Restaurants {
    std::string name;
    int age = 0;
    float rating = 0.0;
    std::string type;
    int number_of_items = 0;
};

void get_restaurant_name_input(Restaurants &restaurants) {
    // get_restaurant_name_input() gets input and maybe validates it
    // arguments: Restaurants&
    // returns: void

    std::cout << "Enter the name of the restaurant: ";
    try {
        std::getline(std::cin, restaurants.name);
        if (std::cin.fail()) throw std::exception();
    }catch (std::exception &e) {
        std::cin.ignore();
        std::cout << "Error: Invalid input try again" << std::endl;
        get_restaurant_name_input(restaurants);
    }
}


void collect_restaurant_age_input(Restaurants &restaurants) {
    // collect_restaurant_age_input() gets input and maybe validates it
    // arguments: Restaurants&
    // returns: void

    std::cout << "Enter the age of the restaurant: ";
    try {
        std::cin >> restaurants.age;
        if (std::cin.fail()) throw std::exception();
    }catch (std::exception &e) {
        std::cin.ignore();
        std::cout << "Error: Invalid input try again" << std::endl;
        collect_restaurant_age_input(restaurants);
    }
}

void get_restaurant_rating(Restaurants &restaurants) {
    // get_restaurant_rating() gets input and maybe validates it
    // arguments: Restaurants&
    // returns: void
    std::cout << "Enter the rating of the restaurant: ";
    try {
        std::cin.ignore();
        std::cin >>restaurants.rating;
        if (std::cin.fail()) throw std::exception();
    } catch (std::exception &e) {
        std::cout << "Error: Invalid input try again" << std::endl;
        get_restaurant_rating(restaurants);
    }
}

void get_restaurant_type_input(Restaurants &restaurants) {
    // get_restaurant_type_input() gets input and maybe validates it
    // arguments: Restaurants&
    // returns: void
    std::cout << "Enter the type of the restaurant: ";
    try {
        std::getline(std::cin,restaurants.type);
        if (std::cin.fail()) throw std::exception();
    } catch (std::exception &e) {
        std::cin.ignore();
        std::cout << "Error: Invalid input try again" << std::endl;
        get_restaurant_type_input(restaurants);
    }
}

void get_restaurant_item_count(Restaurants &restaurants) {
    // get_restaurant_item_count() gets input and maybe validates it
    // arguments: Restaurants&
    // returns: void
    std::cout << "Enter the number of items in the restaurant: ";
    try {
        std::cin >> restaurants.number_of_items;
        if (std::cin.fail()) throw std::exception();
    } catch (std::exception &e) {
        std::cin.ignore();
        std::cout << "Error: Invalid input try again" << std::endl;
        get_restaurant_item_count(restaurants);
    }
}

[[nodiscard]]
Restaurants makeRestaurants() {
    // makeRestaurants() Makes an restaurant Struct
    // arguments: void
    // returns: Restaurant
    Restaurants restaurants;

    get_restaurant_name_input(restaurants);
    collect_restaurant_age_input(restaurants);
    get_restaurant_rating(restaurants);
    get_restaurant_type_input(restaurants);
    get_restaurant_item_count(restaurants);
    return restaurants;
}

void displayRestaurant(const Restaurants &restaurant) {
    // displayRestaurant() outputs data
    // arguments: void
    // returns: void
    std::cout << "Name: " << restaurant.name << std::endl;
    std::cout << "Age: " << restaurant.age << std::endl;
    std::cout << "Rating: " << restaurant.rating << std::endl;
    std::cout << "Type: " << restaurant.type << std::endl;
    std::cout << "Number of items: " << restaurant.number_of_items << std::endl;
}

int main() {
    for (auto i = 0; i < 5; i++)
        {
        Restaurants newRestaurant = makeRestaurants();
        displayRestaurant(newRestaurant);
    }
    return 0;
}
