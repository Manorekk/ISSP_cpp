#include <iostream>
#include <vector>
#include <sstream>

std::string nimGameStrategy(const std::vector<int>& piles)
{
    int xorSum = 0;
    for (int pile : piles)
    {
        xorSum ^= pile;
    }
    if (xorSum == 0)
    {
        return "Rob co chcesz, strategia wygrywajaca nie istnieje";
    }
    else
    {
        for (size_t i = 0; i < piles.size(); ++i)
        {
            if ((piles[i] ^ xorSum) < piles[i])
            {
                std::ostringstream oss;
                oss << "Z rzedu nr " << (i+1) << " zabierz " << (piles[i] - (piles[i] ^ xorSum)) << " kamien";
                return oss.str();
            }
        }
    }
    return "";
}

void printHelp()
{
    std::cout << "Program pomaga wygrac w gre nim." << std::endl;
    std::cout << "Skladnia: nim liczba_1 liczba_2 ..." << std::endl;
    std::cout << "Gdzie liczba_1,... to liczby kamieni w kolejnych rzedach" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || (std::string(argv[1]) == "--help") || (std::string(argv[1]) == "-h"))
    {
        printHelp();
    }
    else
    {
        std::vector<int> piles;
        for (int i = 1; i < argc; ++i) {
            piles.push_back(std::stoi(argv[i]));
        }
        std::cout << nimGameStrategy(piles) << std::endl;
    }
    return 0;
}

