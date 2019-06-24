long double sum_value()
{
    return 0;
}

template<class T, class... Args>
long double sum_value(T t, Args... args)
{
    return static_cast<long double>(t) + sum_value(args...);
}