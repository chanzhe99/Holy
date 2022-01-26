// Copyright Pizza Masters 5, All Rights Reserved.

#ifndef LINQ_H
#define LINQ_H

//! Engine Required
#include "CoreMinimal.h"

//! Others
#include <limits.h>
#include <functional>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>

struct LinqEndException {};

template<typename S, typename T>
class HOLY_API Linq : public UObject
{
private:
	std::function<T(S&)> nextFunction;
	S storage;

public:
	typedef T value_type;

	//! Constructor
	Linq() : nextFunction(), storage() { }
	Linq(std::function<T(S&)> nextFunc, S storage) : nextFunction(nextFunc), storage(storage) { }

	//! Setup
	T Next() { return nextFunction(storage); }

	void ForEach_i(std::function<void(T, int)> apply) const
	{
		Linq<S, T> linq = *this;
		try
		{
			for (int i = 0; ; i++)
			{
				apply(linq.Next(), i);
			}
		}
		catch (LinqEndException&) { }
	}

	void ForEach(std::function<void(T)> apply) const
	{
		return ForEach_i([apply](T value, int) { return apply(value); });
	}

#pragma region Container Exporters

    std::vector<T> ToStdVector() const
    {
        std::vector<T> items;
        ForEach([&items](T value) {
            items.push_back(value);
            });
        return items;
    }

    std::list<T> ToStdList() const
    {
        std::list<T> items;
        ForEach([&items](T value) {
            items.push_back(value);
            });
        return items;
    }

    std::deque<T> ToStdDeque() const
    {
        std::deque<T> items;
        ForEach([&items](T value) {
            items.push_back(value);
            });
        return items;
    }

    std::set<T> ToStdSet() const
    {
        std::set<T> items;
        ForEach([&items](T value) {
            items.insert(value);
            });
        return items;
    }

    std::unordered_set<T> ToStdUnorderedSet() const
    {
        std::unordered_set<T> items;
        ForEach([&items](T value){
            items.insert(value);
            });
        return items;
    }

#pragma endregion

    template<typename F, typename _TIter = typename std::vector<T>::const_iterator>
    Linq<std::tuple<std::vector<T>, _TIter, bool>, T> OrderBy(F transform) const
    {
        std::vector<T> items = ToStdVector();
        std::sort(items.begin(), items.end(), [transform](const T& a, const T& b)
            {
                return transform(a) < transform(b);
            });

        return Linq<std::tuple<std::vector<T>, _TIter, bool>, T>(
            std::make_tuple(items, _TIter(), false),
            [](std::tuple<std::vector<T>, _TIter, bool>& tuple)
            {
                std::vector<T>& vec = std::get<0>(tuple);
                _TIter& it = std::get<1>(tuple);
                bool& flag = std::get<2>(tuple);

                if (!flag)
                {
                    flag = true;
                    it = vec.cbegin();
                }
                if (it == vec.cend())
                {
                    throw LinqEndException();
                }
                return *(it++);
            }
        );
    }

    Linq<std::tuple<std::vector<T>, typename std::vector<T>::const_iterator, bool>, T> OrderBy() const
    {
        return OrderBy([](T value) { return value; });
    }

#pragma region Creators
    
    template<typename T>
    Linq<std::pair<T, T>, typename std::iterator_traits<T>::value_type> from(const T& begin, const T& end)
    {
        return Linq<std::pair<T, T>, typename std::iterator_traits<T>::value_type>(std::make_pair(begin, end),
            [](std::pair<T, T>& pair)
            {
                if (pair.first == pair.second)
                {
                    throw LinqEndException();
                }
                return *(pair.first++);
            }
        );
    }

    template<typename T>
    Linq<std::pair<T, T>, typename std::iterator_traits<T>::value_type> from(const T& it, int n)
    {
        return from(it, it + n);
    }

    template<typename T, int N>
    Linq<std::pair<const T*, const T*>, T> from(T(&array)[N])
    {
        return from((const T*)(&array), (const T*)(&array) + N);
    }

    template<template<class> class TV, typename TT>
    auto from(const TV<TT>& container) -> decltype(from(container.cbegin(), container.cend()))
    {
        return from(container.cbegin(), container.cend());
    }

    // std::list, std::vector, std::dequeue
    template<template<class, class> class TV, typename TT, typename TU>
    auto from(const TV<TT, TU>& container) -> decltype(from(container.cbegin(), container.cend()))
    {
        return from(container.cbegin(), container.cend());
    }

    // std::set
    template<template<class, class, class> class TV, typename TT, typename TS, typename TU>
    auto from(const TV<TT, TS, TU>& container) -> decltype(from(container.cbegin(), container.cend()))
    {
        return from(container.cbegin(), container.cend());
    }

    // std::map
    template<template<class, class, class, class> class TV, typename TK, typename TT, typename TS, typename TU>
    auto from(const TV<TK, TT, TS, TU>& container) -> decltype(from(container.cbegin(), container.cend()))
    {
        return from(container.cbegin(), container.cend());
    }

    // std::array
    template<template<class, size_t> class TV, typename TT, size_t TL>
    auto from(const TV<TT, TL>& container) -> decltype(from(container.cbegin(), container.cend()))
    {
        return from(container.cbegin(), container.cend());
    }

#pragma endregion
};

#endif