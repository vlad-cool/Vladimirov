#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    int cache_size, elements_size, hits = 0, element;
    std::unordered_map<int, int> cache;
    std::cin >> cache_size >> elements_size;
    std::vector<int> elements(elements_size);
    std::unordered_map<int, std::queue<int>> elements_table;

    for (int i = 0; i < elements_size; i++)
    {
        std::cin >> elements[i];

        if (elements_table.count(elements[i]) > 0)
        {
            elements_table[elements[i]].push(i);
        }
        else
        {
            elements_table.insert({elements[i], std::queue<int>()});
        }
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
                auto cur_queue = elements_table[element];
                while (cur_queue.size() > 0 && cur_queue.front() <= i)
                {
                    cur_queue.pop();
                }

                int max_index = 0;
                for (auto iter = cache.begin(); iter != cache.end(); iter++)
                {
                    auto cur_queue = elements_table[iter->first];

                    while (cur_queue.size() > 0 && cur_queue.front() < i)
                    {
                        cur_queue.pop();
                    }
                    
                    if (cur_queue.size() == 0)
                    {
                        cache.erase(iter->first);
                        cache.insert({element, 0});
                        max_index = elements.size();
                        break;
                    }

                    if (cur_queue.front() > max_index)
                    {
                        max_index = cur_queue.front();
                    }
                }

                auto max_iter = elements.begin() + max_index;
                
                if(max_iter != elements.end() && elements_table[element].size() > 0 && max_index > elements_table[element].front())
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
