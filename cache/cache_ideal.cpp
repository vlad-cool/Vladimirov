#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int cache_size, elements_size, hits = 0, element;
    std::unordered_map<int, int> cache;
    std::cin >> cache_size >> elements_size;
    std::vector<int> elements(elements_size);

    for (int i = 0; i < elements_size; i++)
    {
        std::cin >> elements[i];
    }

    for (int i = 0; i < elements_size; i++)
    {
        element = elements[i];

        if (cache.count(element) > 0)
        {
            hits++;
        }
        else
        {
            if (cache.size() < cache_size)
            {
                cache.insert({element, 0});
            }
            else
            {
                auto max_iter = elements.begin();
                for (auto iter = cache.begin(); iter != cache.end(); iter++)
                {
                    max_iter = std::max(max_iter, std::find(elements.begin() + i, elements.end(), iter->first));

                    if (max_iter == elements.end())
                    {
                        cache.erase(iter->first);
                        cache.insert({element, 0});
                        break;
                    }
                }
                
                if(max_iter != elements.end() and max_iter > std::find(elements.begin() + i + 1, elements.end(), element))
                {
                    cache.erase(*max_iter);
                    cache.insert({element, 0});
                }
            }
        }
    }

    std::cout << hits << std::endl;

    return 0;
}
