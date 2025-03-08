#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main(int ac, char ** av)
{
    stdio_init_all();
    sleep_ms(10000);
    printf("Running CppUTest...");

    const char * fav[5] = {"trafficlight_test", "-c", "-v", "-g", "TrafficLightGroup"};    
    return CommandLineTestRunner::RunAllTests(ac, av);
}