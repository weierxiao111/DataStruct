
struct _truetype
{
	bool get(){return true;}
};

struct _flasetype
{
	bool get() {return false;}
};

template <typename Tp>
struct _typeTraits
{
	typedef _flasetype _isPODtype;
};

template <>
struct _typeTraits<bool>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<char>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<short>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<unsigned char>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<unsigned short>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<int>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<unsigned int>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<long>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<unsigned long>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<long long>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<unsigned long long>
{
	typedef _truetype _isPOtype;
};

template <>
struct _typeTraits<float>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<double>
{
	typedef _truetype _isPODtype;
};

template <>
struct _typeTraits<long double>
{
	typedef _truetype _isPODtype;
};

template <typename T>
struct _typeTraits<T*>
{
	typedef _truetype _isPODtype;
};

template <typename T>
void Copy (T* dest ,const T* src, size_t size)
{

	if (_typeTraits<T>::_isPODtype().get())
	{
		memcpy(dest , src, size*sizeof (T));
	}
	else
	{
		for (size_t i = 0; i < size ; ++i)
		{
			dest[i] = src[i];
		}
	}
}
