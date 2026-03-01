#pragma once
#include <cstdint>
#include <random>
#include <chrono>
#include <type_traits>


namespace BenScr {
    class Random {
    public:
        Random() = delete;

        static bool NextBool();

        static std::uint8_t NextByte(std::uint8_t min, std::uint8_t max);
        static std::uint8_t NextByte(std::uint8_t max);

        static float NextFloat();
        static float NextFloat(float max);
        static float NextFloat(float min, float max);

        static double NextDouble();
        static double NextDouble(double max);
        static double NextDouble(double min, double max);

        static int NextInt32();
        static  int NextInt32(int max);
        static int NextInt32(int min, int max);

        template<typename T>
        static T Next(T min, T max) {
            if constexpr (std::is_floating_point_v<T>) {
                static thread_local std::uniform_real_distribution<T> dist;
                return dist(s_Gen, typename decltype(dist)::param_type(min, max));
            }
            else if constexpr (std::is_integral_v<T>) {
                static thread_local std::uniform_int_distribution<T> dist;
                return dist(s_Gen, typename decltype(dist)::param_type(min, max));
            }
            else {
                static_assert(std::is_arithmetic_v<T>, "T has to be a type of int or float");
            }
        }

        static void SetSeed(uint32_t seed) { s_Gen.seed(seed); }
        static void RemoveSeed() {
            std::random_device rd;
            s_Gen.seed(rd());
        }
    private:
        inline static thread_local std::mt19937 s_Gen{ std::random_device{}() };
    };
}