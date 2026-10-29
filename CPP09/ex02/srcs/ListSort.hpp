#ifndef LISTSORT_HPP
# define LISTSORT_HPP

# include <cstddef>
# include <vector>

# include "ListIdx.hpp"

void	jacob(std::pair<size_t, size_t> &i);

void	sortVec(std::vector<int> &tab);
void	sortList(ListIdx<int> &tab);

# include "ListSort.tpp"

#endif
