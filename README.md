# Random Utiltiy Library
A simple C++ random utility library

## How to use

- Including
```cpp
#include <Random.hpp>
using namespace BenScr;
```

- Functionalities
```cpp
int randInt32 = Random::Next<int>(15, 100);
float randFloat32 = Random::Next<float>(15.f, 100.f);
std::uint8_t randByte = Random::NextByte(0, 256);
bool randBool = Random::NextBool();

Random::SetSeed(5);
Random::RemoveSeed();
```
