//
// Created by wuuuudle on 18-9-15.
//

#ifndef INC_1_8_SEARCH_H
#define INC_1_8_SEARCH_H

template <typename T>
int search(T * array, T purpose, int len)
{
    for(int i=0;i<len;i++)
    {
        if(array[i]==purpose)
        {
            return i;
        }
    }
    return -1;
}
#endif //INC_1_8_SEARCH_H
