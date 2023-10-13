#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int cache_size, elements_size, hits = 0, element;
    std::unordered_map<int, int> cache;
    std::cin >> cache_size >> elements_size;

    for (int i = 0; i < elements_size; i++)
    {
        std::cin >> element;
        if (cache.count(element) > 0)
        {
            hits++;
            cache[element]++;
        }
        else
        {
            if (cache.size() < cache_size)
            {
                cache.insert({element, 0});
            }
            else
            {
                auto to_delete = std::min_element(cache.begin(), cache.end());
                cache.erase(to_delete);
                cache.insert({element, 0});
            }
        }
    }

    std::cout << hits << std::endl;

    return 0;
}
