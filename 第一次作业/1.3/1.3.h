class String
{
    public:
        String(const String& re);//复制构造函数，由一个已有的字符串对象re构造一个新的字符串
        String(const char* str);//从字符串数组构造一个String
        String();//构造一个空的字符串
        ~String();//析构函数
        String& operator()(int pos,int len);//取出从pos开始至pos+len的子串
        bool operator == (const String& cmp);//判断两个字符串是否相等
        String operator = (const String& re);//重载=，复制字符串
        String operator + (const String& add);//重载+,拼接字符串
        char& operator [](int i);//重载[],取出字符串的第i个字符
        int find(String& pat);//返回匹配子串的第一个位置，若无匹配子串则返回-1
    private:
        int currentLen;//串的长度
        char * str;//串存放的数组
}