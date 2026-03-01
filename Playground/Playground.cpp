#include <iostream>
#include "Random.hpp";

using namespace BenScr;

int main()
{
    std::cout << "(0-155): " << Random::Next<std::uint16_t>(0, 155) << '\n';
    std::cout << "(0.0f-1.0f): " << Random::Next<float>(0, 1) << '\n';
    std::cout << "(bool): " << Random::NextBool() << '\n';
}