#include <iostream>
#include <sstream>
#include <cstdio>

int main() {
    char text[100];
    float min_speed = 0.0f;
    float max_speed = 150.0f;
    float speed = 0.0f;
    float delta;
    do{
        std::cin >> delta;
        speed += delta;
        speed < min_speed? speed = min_speed: speed;
        speed > max_speed? speed = max_speed: speed;
        std::sprintf(text, "Speed: %.1f km/h",speed);
        std::cout << text << std::endl;
    } while (speed > 0.01);


    return 0;
}

