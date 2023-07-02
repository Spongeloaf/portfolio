// SmartCharArray provides a fixed size container that writes-in data like a stream, but also
// allows array-like read access. There is an implicit null terminator that is imutable.
// The temrinaotr is added automatically, making the actual size of SmartArray size_t + 1.
// 
// Writing to the container is done using the << operator, or the fill function.
// Random access is strictly read-only. Non-null characters may not exist after null 
// characters, and this is enforced by Fill() and '<<' operator.
// 
// The functions GetSize() and GetCapacity() (and most other members, actually)
// are blind to the null terminator. If you fill the array to capacity using the << 
// operator or Fill(), the data is guaranteed to be null terminated.
//
// These provisions make SmartArray easy to use when composing strings, but also suitable
// for use with any function that accepts a const char* array with null termination.
template <size_t _N>
class SmartCharArray
{
	static_assert(_N);
	typedef SmartCharArray<_N>this_type;
	static constexpr size_t _NplusOne = _N + 1;

private:
	this_type& PushChar(char c)
	{
		size_t index = CountElementsToFirstNull();

		if (index >= _N)
			return *this;

		m_buffer[index] = c;
		index++;
		return *this;
	}

public:
	SmartCharArray() { Flush(); }
	SmartCharArray(const SmartCharArray& obj)
	{
		Flush();
		*this << obj;
	};

	// Throws std::out_of_range if pos > size(). 
	constexpr const char& at(size_t s) const {
		if (s < m_buffer.size())
			return m_buffer.at(s);
		else
		{
			static constexpr char nul = '\0';
			return nul;
		}
	} // Here's a thought: Might it be better to simply return a null char if pos > size()?
	
	constexpr const char& front() const { return m_buffer.front(); }
	constexpr const char& back() const { return m_buffer.back(); }
	constexpr const char& LastElement() const {
		if (IsEmpty())
			return m_buffer.front();

		return m_buffer.at(CountElementsToFirstNull() - 1);
	}

	// Null termination guaranteed
	constexpr const char* data() const { return m_buffer.data(); }
	constexpr const typename std::array<char, _NplusOne>::const_iterator begin() const noexcept { return m_buffer.cbegin(); }
	constexpr const typename std::array<char, _NplusOne>::const_iterator end() const noexcept { return m_buffer.cbegin() + CountElementsToFirstNull(); }
	constexpr const typename std::array<char, _NplusOne>::const_iterator cbegin() const noexcept { return m_buffer.cbegin(); }
	constexpr const typename std::array<char, _NplusOne>::const_iterator cend() const noexcept { return m_buffer.cbegin() + CountElementsToFirstNull(); }
	constexpr const typename std::array<char, _NplusOne>::const_reverse_iterator crbegin() const { return m_buffer.crbegin() + (_NplusOne - CountElementsToFirstNull()); }
	constexpr const typename std::array<char, _NplusOne>::const_reverse_iterator crend() const { return m_buffer.crend(); }

	// If non null chars exist after the first null, they will be ignored
	bool IsEmpty() const { return m_buffer.at(0) == '\0'; }
	size_t GetCapacity() const { return _N; }
	size_t GetSize() const { return CountElementsToFirstNull(); }

	void Fill(const char c)
	{
		m_buffer.fill(c);
		m_buffer.back() = '\0';
	}

	// We only need to check the last character because we guarantee the array is filled from front to back
	bool IsFull() const { return m_buffer[_N - 1] != '\0'; };
	void Flush() { m_buffer.fill('\0'); }
	void TrimAllTrailing(char c)
	{
		auto revIter = m_buffer.rbegin();
		while (true)
		{
			if (*revIter == c)
			{
				*revIter = '\0';
				revIter++;
				continue;
			}

			if (*revIter == '\0')
			{
				revIter++;
				continue;
			}

			break;
		}
	}

	void TrimOneTrailing(char c)
	{
		auto revIter = m_buffer.rbegin();
		while (true)
		{
			if (*revIter == '\0')
			{
				revIter++;
				continue;
			}

			if (*revIter == c)
			{
				*revIter = '\0';
				break;
			}

			break;
		}
	}

	const stringView GetStringView() const { return stringView{ data(), GetSize() }; }

	this_type& operator<<(std::string_view str)
	{
		size_t index = CountElementsToFirstNull();

		if (index >= _N)
			return *this;

		for (auto& c : str)
		{
			if (index >= _N || c == '\0')
				return *this;
			m_buffer[index] = c;
			index++;
		}

		return *this;
	}

	// Todo: make this a member function of SmartCharArray
	void TrimWhiteSpace()
	{
		std::array<char, _NplusOne> workingBuffer;
		workingBuffer.fill('\0');
		std::copy(m_buffer.begin(), m_buffer.end(), workingBuffer.begin());

		// Trim tariling whitespace first, because nothing has to move
		for (auto& c : boost::adaptors::reverse(workingBuffer))
		{
			if (c == '\0')
				continue;

			if (c == ' ')
			{
				c = '\0';
				continue;
			}

			break;
		}

		Flush();
		bool pastBeginning = false;

		// skip leading spaces
		for (auto c : workingBuffer)
		{
			if (!pastBeginning)
			{
				if (c == ' ')
					continue;

				if (c == '\0')
					break;
			}

			pastBeginning = true;
			PushChar(c);
		}
	}

	// Returns the position immediately after a delimiter, or this.size() if the delimiter is not found.
	// E.g: input = "abcde", delimiter "bc" returns "3".
	size_t FindDelimitedString(const stringView delimiter) const
	{
		if (delimiter.empty())
			return CountElementsToFirstNull();

		auto iter = delimiter.begin();
		for (size_t i = 0; i < _N; i++)
		{
			if (iter == delimiter.end())
				return i;

			if (m_buffer[i] == *iter)
			{
				iter++;
				continue;
			}

			iter = delimiter.begin();
		}

		return CountElementsToFirstNull();
	}

	this_type& operator<<(const char* s)
	{
		std::string_view view{ s };
		*this << view;
		return *this;
	}

	this_type& operator<<(const char c)
	{
		return PushChar(c);
	}

	this_type& operator<<(const std::string& str)
	{
		std::string_view view{ str };
		*this << view;
		return *this;
	}

	this_type& operator<<(const PooledString& str)
	{
		std::string_view view{ str };
		*this << view;
		return *this;
	}

	this_type& operator<<(const size_t t)
	{
		auto str = std::to_string(t);
		*this << str;
		return *this;
	}

	bool operator=(const char* chars)
	{
		Flush();
		*this << chars;
		return true;
	}

	bool operator=(const PooledString& chars)
	{
		Flush();
		*this << chars;
		return true;
	}

	bool operator=(const std::string& str)
	{
		Flush();
		*this << str;
		return true;
	}

private:
	size_t CountElementsToFirstNull() const
	{
		size_t s = 0;

		for (auto& i : m_buffer)
		{
			if (i != '\0')
				s++;
			else
				break;
		}
		return s;
	}

	std::array<char, _NplusOne> m_buffer; // +1 for null terminator
};

template<size_t _N1, size_t _N2>
SmartCharArray<_N1>& operator<<(SmartCharArray<_N1>& lhs, const SmartCharArray<_N2>& rhs)
{
	lhs << rhs.data();
	return lhs;
}

template<size_t _N1, size_t _N2>
SmartCharArray<_N1>& operator<<(SmartCharArray<_N1>& lhs, const std::array<char, _N2>& rhs)
{
	std::string_view view = { rhs.data(), rhs.size() };
	lhs << view;
	return lhs;
}

// Allows comparison of different sized smart arrays
template<size_t _N1, size_t _N2>
bool operator==(const SmartCharArray<_N1>& lhs, const SmartCharArray<_N2>& rhs)
{
	bool bRet = true;
	const size_t max = std::max(_N1, _N2);
	for (size_t i = 0; i < max; i++)
	{
		if (lhs.at(i) != rhs.at(i))
			bRet = false;

		if (lhs.at(i) == '\0' || rhs.at(i) == '\0')
			break;
	}

	return bRet;
}

// Allows comparison of different sized smart arrays
template<size_t _N1, size_t _N2>
bool operator!=(const SmartCharArray<_N1>& lhs, const SmartCharArray<_N2>& rhs)
{
	return !(lhs == rhs);
}

template<size_t _N1>
bool operator==(const SmartCharArray<_N1>& lhs, const char* rhs)
{
	bool bRet = true;
	size_t lenStr = std::strlen(rhs);

	if (lenStr > _N1)
		return false;

	const size_t max = std::max(_N1, lenStr);
	for (size_t i = 0; i < max; i++)
	{
		if (lhs.at(i) != rhs[i])
			bRet = false;

		if (lhs.at(i) == '\0' || rhs[i] == '\0')
			break;
	}

	return bRet;
}

template<size_t _N1>
bool operator==(const char* lhs, const SmartCharArray<_N1>& rhs)
{
	return rhs == lhs;
}

template<size_t _N1>
bool operator==(const SmartCharArray<_N1>& lhs, const std::string& rhs)
{
	return lhs == rhs.c_str();
}

template<size_t _N1>
std::ostream& operator<<(std::ostream& os, const SmartCharArray<_N1>& arr)
{
	return os << arr.data();
}
