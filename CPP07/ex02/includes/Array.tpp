
template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = NULL;
};

template <typename T>
Array<T>::Array(t_uint size)
{
	this->_size = size;
	this->_array = new T[size];
	for (t_uint i=0; i < size; i++)
		this->_array[i] = T();
};

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
	if (this->_size != 0)
	{
		this->_array = new T[_size];
		for (t_uint i=0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	else
	{
		this->_size = 0;
		this->_array = NULL;
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->_size != 0)
		delete [] this->_array;
};


template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		this->~Array();
		this(other);
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](const t_uint n)
{ 
	if (n >= this->_size)
		throw std::out_of_range("Index bigger than size");
	else
		return(this->_array[n]);
};

template <typename T>
t_uint Array<T>::size()	{	return (this->_size); }
