//
// details: container.hpp
//

#ifndef ALG2_CONTAINER_HPP
#define ALG2_CONTAINER_HPP


namespace Alg2
{


template <size_t N, typename R> struct container
{
  typedef R value_type;
  typedef R* iterator;
  typedef R& value_reference;

  value_type m_data[N];

  ALG2_CXX11_CONSTEXPR size_t size() const
  {
    return N;
  }
  ALG2_CXX11_CONSTEXPR size_t data_size() const
  {
    return sizeof(R)*N;
  }
  ALG2_CXX11_CONSTEXPR const iterator data() const
  {
    return this->m_data;
  }
  ALG2_CXX14_CONSTEXPR iterator data()
  {
    return this->m_data;
  }
  ALG2_CXX11_CONSTEXPR const iterator begin() const
  {
    return this->m_data;
  }
  iterator begin()
  {
    return this->m_data;
  }
  ALG2_CXX11_CONSTEXPR const iterator end() const
  {
    return this->m_data + N;
  }
  iterator end()
  {
    return this->m_data + N;
  }
  ALG2_CXX11_CONSTEXPR value_type operator [](size_t idx) const
  {
    return this->m_data[idx];
  }
};


} // end of namespace Alg2


#endif
