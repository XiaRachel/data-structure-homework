/*
 * Insert时间复杂度为o(2nlogn+n/2)
 * Delete_Maximun与Delete_Minimun时间复杂度均为o(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class Mystruct
{
private:
    struct In
    {
        T data;
        int pos;

        In()
        { pos = -1; };

        In(T Data)
        { data = Data; }

        bool operator<(In &b) const
        {
            return this->data < b.data;
        }
    };

    std::vector<In> *List;
    bool tidy = true;
    int minpos, maxpos;
    int size;

    static bool cmp_pos(In &a, In &b)
    {
        return a.pos < b.pos;
    }

public:
    Mystruct()
    {
        List = new std::vector<In>;
        minpos = 0;
        maxpos = 0;
        size = 0;
    }

    ~Mystruct()
    {
        std::vector<In>().swap(*List);
    }

    void insert(int pos, T element)
    {
        std::sort(List->begin(), List->end(), cmp_pos);
        while (!List->empty() && List->begin()->pos == -1) List->erase(List->begin());
        //删除多余项
        List->insert(List->begin() + pos, In(element));
        //插入
        size++;
        for (int i = 0; i < size; (*List)[i].pos = i, i++);
        //重新整理pos位置
        std::sort(List->begin(), List->end());
        //再排序
        minpos = 0;
        maxpos = size - 1;
        tidy = true;
    }

    int getsize()
    { return size; }

    void Delete_Maximun()
    {
        if (size == 0)
            throw std::runtime_error("empty!!");
        (*List)[maxpos--].pos = -1;
        size--;
        tidy = false;
    }

    void Delete_Minimun()
    {
        if (size == 0)
            throw std::runtime_error("empty!!");
        (*List)[minpos++].pos = -1;
        size--;
        tidy = false;
    }

    T &operator[](int i)
    {
        if (!tidy)
        {
            std::sort(List->begin(), List->end(), cmp_pos);
            while (!List->empty() && List->begin()->pos == -1) List->erase(List->begin());
            //删除多余项
            for (int i = 0; i < size; (*List)[i].pos = i, i++);
            //重新整理pos位置
            std::sort(List->begin(), List->end());
            minpos = 0;
            maxpos = size - 1;
            tidy = true;
        }
        if (i >= size || i < 0)
        {
            throw std::runtime_error("size error");
        }
        for (auto it = List->begin(); it != List->end(); it++)
            if (it->pos == i)
                return it->data;
    }
};

template<typename T>
void print(Mystruct<T> &mystruct)
{
    for (int i = 0; i < mystruct.getsize(); i++)
    {
        std::cout << mystruct[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Mystruct<int> mystruct;
    mystruct.insert(mystruct.getsize(), 6);
    mystruct.insert(mystruct.getsize(), 1);
    mystruct.insert(mystruct.getsize(), 4);
    mystruct.insert(mystruct.getsize(), 9);
    mystruct.insert(mystruct.getsize(), 12);
    mystruct.insert(mystruct.getsize(), -5);
    mystruct.insert(mystruct.getsize(), -9);
    std::cout << "原列表:";
    print<int>(mystruct);

    //删除最大元素测试
    mystruct.Delete_Maximun();
    std::cout << "删除最大元素:";
    print<int>(mystruct);

    //删除最小元素测试
    mystruct.Delete_Minimun();
    std::cout << "删除最小元素:";
    print<int>(mystruct);

    //异常捕捉测试
    std::cout << "持续删除最大元素异常捕捉测试:" << std::endl;
    try
    {
        while (true)
        {
            mystruct.Delete_Maximun();
            print<int>(mystruct);
        }
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what();
    }

    return 0;

}
