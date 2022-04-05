#include <iostream>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main(){
    int days = 2;
    int current_day = 0;
    int hours = 23;
    int current_hour = 0;
    int temperatureOutside = 0;
    int temperatureInside = 0;
    int switches_state = 0;
    int switches_state_prev = 0;
    int lightTemp = 5000;
    std::string movingOutside;
    std::string lightInside;
    std::string input;
    std::stringstream text;
    while (current_hour < hours && current_day < days){
        switches_state_prev = switches_state;
        std::cout << current_day + 1 << " day " << current_hour << " hour of simulation" << std::endl;
        std::getline ( std::cin, input );
        text << input;
        text >> temperatureOutside >> temperatureInside >> movingOutside >> lightInside;
        if(temperatureOutside < 0 && switches_state_prev & ~WATER_PIPE_HEATING){
            switches_state |= WATER_PIPE_HEATING;
            std::cout << "WATER_PIPE_HEATING is on" << std::endl;
        } else if(temperatureOutside > 5){
            switches_state &= ~WATER_PIPE_HEATING;
            std::cout << "WATER_PIPE_HEATING is off" << std::endl;
        }
        if(((current_hour >= 0 && current_hour < 5) ||
            (current_hour > 16 && current_hour < 24)) && movingOutside == "yes"){
            switches_state |= LIGHTS_OUTSIDE;
            std::cout << "LIGHTS_OUTSIDE is on" << std::endl;
        } else {
            switches_state &= ~LIGHTS_OUTSIDE;
            std::cout << "LIGHTS_OUTSIDE is off" << std::endl;
        }
        if(temperatureInside < 22){
            switches_state |= HEATERS;
            std::cout << "HEATERS is on" << std::endl;
        } else if(temperatureOutside >= 25){
            switches_state &= ~HEATERS;
            std::cout << "HEATERS is off" << std::endl;
        }
        if(temperatureInside > 30){
            switches_state |= CONDITIONER;
            std::cout << "CONDITIONER is on" << std::endl;
        } else if(temperatureOutside <= 25){
            switches_state &= ~CONDITIONER;
            std::cout << "CONDITIONER is off" << std::endl;
        }
        if(lightInside == "yes"){
            switches_state |= LIGHTS_INSIDE;
        } else if(lightInside == "no"){
            switches_state &= ~LIGHTS_INSIDE;
        }
        if((switches_state & LIGHTS_INSIDE) && (current_hour >= 16 && current_hour < 20)){
            lightTemp = 5000 - (current_hour - 16) * (5000 - 2700) / (20 - 16);
        } else if (current_hour == 0) {
            lightTemp = 5000;
        }
        if(switches_state & LIGHTS_INSIDE){
            std::cout << "LIGHTS_INSIDE is on. Light temperature " << lightTemp << std::endl;
        }
        current_hour++;
        if (current_hour == 24){
            current_hour = 0;
            current_day++;
        }
    }
}
