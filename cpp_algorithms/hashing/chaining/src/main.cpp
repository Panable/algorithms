#include "hash.h"
#include <cstdlib>
#include <vector>

#define PRINT(x) std::cout << x << std::endl;
#define ARRAY_LEN(x) (sizeof x / sizeof x[0])

int main()
{
    std::string words[] = {
            "apple",  "banana",  "computer", "elephant", "guitar",
         "mountain",   "ocean",    "pencil",    "robot", "sunflower",
        "telescope", "volcano",   "whisper",    "zebra", "galaxy",
          "horizon",  "jungle", "labyrinth",   "meteor", "nocturnal"
    };

    srand(10); // same

    Hash<int> hash;
    for (const std::string& word : words)
    {
        hash.add(word, rand() % 100);
    }

    PRINT(hash.exists("jungle"));
    PRINT(hash.get("jungle"));
}
