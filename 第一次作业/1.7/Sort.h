//
// Created by wuuuudle on 18-9-15.
//

#ifndef INC_1_7_SORT_H
#define INC_1_7_SORT_H

template <typename T>
void sort(T* array, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (array[i] > array[j])
            {
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
#endif //INC_1_7_SORT_H
