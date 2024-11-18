#include <functional>
#include "../../../GRAD2/Lab2/DynamicArray.h"


/*
    Сортировка выбором
    Принцип работы:
    1. Находим минимальный элемент в массиве
    2. Меняем его местами с первым элементом
    3. Повторяем для оставшегося массива
*/
template <class T>
class SelectionSorter : public ISorter<T>
{
public:
    void sort(ISorter<T>::Iterator begin, ISorter<T>::Iterator end, ISorter<T>::Comparator comp = std::less<T>()) override
    {
        for (auto i = begin; i != end; ++i)
        {
            auto min = i;
            for (auto j = i + 1; j != end; ++j)
            {
                if (comp(*j, *min))
                {
                    min = j;
                }
            }
            std::swap(*i, *min);
        }
    }
};