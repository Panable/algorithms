#include "hash.h"
#include <cstdlib>

#define PRINT(x) std::cout << x << std::endl;
#define ARRAY_LEN(x) (sizeof x / sizeof x[0])

bool isLittleEndian() //testing
{
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}

int main()
{
    std::string words[] = {
            "apple",  "banana",  "computer", "elephant", "guitar",
         "mountain",   "ocean",    "pencil",    "robot", "sunflower",
        "telescope", "volcano",   "whisper",    "zebra", "galaxy",
          "horizon",  "jungle", "labyrinth",   "meteor", "nocturnal"
    };

    srand(10); // same

    Hash<int> hash(hash_djb2);
    for (const std::string& word : words)
    {
        hash.add(word, rand() % 100);
    }

    hash.dump();
    PRINT(hash.exists("jungle"));
    PRINT(hash.get("jungle"));
    hash.remove("jungle");
    PRINT(hash.exists("jungle"));

    // this is how FNV prime offset is calculated
    std::string offset = "chongo <Landon Curt Noll> /\\../\\";
    PRINT(hash_fnv0(offset));

    PRINT(isLittleEndian());
}
