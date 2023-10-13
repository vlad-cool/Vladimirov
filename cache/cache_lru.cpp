#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int cache_size, elements_size, hits = 0, element;
    std::unordered_map<int, int> cache;
    std::vector<int> cached;
    std::cin >> cache_size >> elements_size;

    for (int i = 0; i < elements_size; i++)
    {
        std::cin >> element;
        if (cache.count(element) > 0)
        {
            hits++;
            cached.erase(std::find(cached.begin(), cached.end(), element));
            cached.emplace(cached.begin(), element);
        }
        else
        {
            if (cached.size() < cache_size)
            {
                cached.emplace(cached.begin(), element);
                cache.insert({element, 0});
            }
            else
            {
                cache.erase(cached.back());
                cached.pop_back();
                cached.emplace(cached.begin(), element);
                cache.insert({element, 0});
            }
        }
    }

    std::cout << hits << std::endl;

    return 0;
}