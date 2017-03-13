#include "vector.hpp"

vector_t::vector_t() noexcept
{
	size_ = 0;
	capacity_ = 0;
	ptr_ = new int[capacity_];
}


vector_t::vector_t(unsigned int size)
{
	size_ = size;
	capacity_ = size;
	ptr_ = new int[capacity_]();
}


vector_t::vector_t(const vector_t& other)
{
	delete[] ptr_;
	size_ = other.size_;
	capacity_ = other.capacity_;
	ptr_ = new int[capacity_];
	for (unsigned int i = 0; i < size_; i++)
	{
		ptr_[i] = other.ptr_[i];
	}
}


auto vector_t::operator=(const vector_t& other)->vector_t&
{
	if (this != &other)
	{
		delete[] ptr_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		ptr_ = new int[capacity_];
		for (unsigned int i = 0; i < size_; i++)
		{
			ptr_[i] = other.ptr_[i];
		}
	}

	return *this;
}


vector_t::~vector_t() noexcept
{
	size_ = 0;
	capacity_ = 0;
	delete[] ptr_;
}


auto vector_t::size() const noexcept -> unsigned int
{
	return size_;
}


auto vector_t::capacity() const noexcept -> unsigned int
{
	return capacity_;
}


auto vector_t::push_back(int value) -> void
{
	if (capacity_ == 0)
	{
		delete[] ptr_;
		capacity_ = 1;
		ptr_ = new int[capacity_]();
	}
	else if (size_ + 1 >= capacity_)
	{
		capacity_ *= 2;
		int* nptr = new int[capacity_]();
		for (unsigned int i = 0; i < size_; i++)
		{
			nptr[i] = ptr_[i];
		}
		delete[] ptr_;
		ptr_ = nptr;
	}
	ptr_[size_++] = value;
}


auto vector_t::operator[](unsigned int index) const noexcept -> int
{
	if (index >= size_)
		throw "Index is out of range!\n";

	return ptr_[index];
}
