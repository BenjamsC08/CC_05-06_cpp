
#include <cctype>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <stdexcept>

template <typename T>
void	extractNumber(const std::string &s, T &tab)
{
	const char *str = s.c_str();
	char *eptr;
	int offset = 0;
	while (42)
	{
		if (*(str + offset) == ' ')
			offset ++;
		long nb = strtol(str + offset, &eptr, 10);
		if ((*eptr != ' ' && *eptr != 0) ||
				(nb > std::numeric_limits<int>::max() ||
				nb < std::numeric_limits<int>::min())
			)
			throw std::runtime_error("Cannot convert number given in args 1");
		tab.push_back(static_cast<int>(nb));
		if (!*eptr)
			break ;
		offset = eptr - str;
	}
}

template <typename C>
size_t	findDichoPos(const C &w, int tf, size_t rb)
{
	if (w.empty())
		return (0);
	if (rb >= w.size())
		rb = w.size() - 1;

	size_t	start = 0;

	while (start <= rb)
    {
        size_t m = start + (rb - start) / 2;

        if (w[m] == tf)
            return m;

        if (w[m] < tf)
            start = m + 1;
        else
        {
            if (m == 0)
                return 0;
            rb = m - 1;
        }
    }
	return (start);
}

template <typename C>
size_t	findRightBorder(int tf,	const C &w)
{
	for (size_t i=0; i < w.size(); i++)
	{
		if (tf == w[i])
			return (i);
	}
	return (w.size() - 1);
}

template <typename C, typename P>
int	deepDive(C &container, C &winner, P &pair)
{
	int tmp = -1;

	if (container.size() == 1)
		return (tmp);

	if (container.size() % 2 !=0)
	{
		tmp = container.back();
		container.pop_back();
	}

	for (size_t i=0; i < container.size() ; i+=2)
	{
		if (container[i] > container[i + 1])
		{
			winner.push_back(container[i]);
			pair.push_back(std::make_pair(container[i], container[i + 1]));
		}
		else
		{
			winner.push_back(container[i + 1]);
			pair.push_back(std::make_pair(container[i + 1], container[i]));
		}
	}
	return (tmp);
}

template <typename C, typename P>
C	remontada(C &container, P &pair, int tmp)
{
	size_t rb = 0;
	size_t dpos = 0;

	std::pair<size_t, size_t> idJ(1,3);
	while (!pair.empty())
	{
		size_t count = idJ.first;

		if (count > pair.size())
			count = pair.size();

		for (size_t i = 0; i < count; i++)
		{
			size_t idx = count - 1 - i;
			if (idx >= pair.size()) break;

			int toInsert = pair[idx].second;
			int nbBounder = pair[idx].first;

			rb = findRightBorder(nbBounder, container);
			dpos = findDichoPos(container, toInsert, rb);
			
			typename C::iterator it = container.begin();
			std::advance(it, dpos);
			container.insert(it, toInsert);

			typename P::iterator pit = pair.begin();
			std::advance(pit, idx);
			pair.erase(pit);
		}
		jacob(idJ);
	}
	if (tmp != -1)
	{
		rb = container.size() - 1;
		dpos = findDichoPos(container, tmp, rb);

		typename C::iterator it = container.begin();
		std::advance(it, dpos);
		container.insert(it, tmp);
	}
	return (container);
}
