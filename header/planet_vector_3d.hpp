//
//  planet_vector_3d.hpp
//  planet_simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_vector_3d_hpp
#define planet_vector_3d_hpp

#include <cmath>

namespace Planet
{

template <typename _type>
class Vector3D
{
public:
  
  /**
   * Constructor.
   */
  Vector3D(_type x=0.0, _type y=0.0, _type z=0.0)
  : m_x(x)
  , m_y(y)
  , m_z(z)
  { }
  
  /**
   * Destructor.
   */
  ~Vector3D()
  { }
  
  /**
   * Get the x position.
   */
  inline _type getX() const
  { return m_x; }
  
  /**
   * Get the y position.
   */
  inline _type getY() const
  { return m_y; }
  
  /**
   * Get the z position.
   */
  inline _type getZ() const
  { return m_z; }
  
  /**
   * Set the x position.
   */
  inline void setX(_type x)
  { m_x = x; }
  
  /**
   * Set the y position.
   */
  inline void setY(_type y)
  { m_y = y; }
  
  /**
   * Set the z position.
   */
  inline void setZ(_type z)
  { m_z = z; }
  
  /**
   * Vector addition.
   */
  Vector3D<_type> operator + (_type factor) const
  {
    return Vector3D<_type>(m_x + factor,
                           m_y + factor,
                           m_z + factor);
  }
  
  /**
   * Vector substraction.
   */
  Vector3D<_type> operator - (_type factor) const
  {
    return Vector3D<_type>(m_x - factor,
                           m_y - factor,
                           m_z - factor);
  }
  
  /**
   * Vector addition.
   */
  Vector3D<_type> operator + (const Vector3D<_type>& vec) const
  {
    return Vector3D<_type>(m_x + vec.m_x,
                           m_y + vec.m_y,
                           m_z + vec.m_z);
  }
  
  /**
   * Vector substraction.
   */
  Vector3D<_type> operator - (const Vector3D<_type>& vec) const
  {
    return Vector3D<_type>(m_x - vec.m_x,
                           m_y - vec.m_y,
                           m_z - vec.m_z);
  }
  
  /**
   * Vector multiplication.
   */
  Vector3D<_type> operator * (_type factor) const
  {
    return Vector3D<_type>(m_x * factor,
                           m_y * factor,
                           m_z * factor);
  }
  
  /**
   * Vector division.
   */
  Vector3D<_type> operator / (_type factor) const
  {
    return Vector3D<_type>(m_x / factor,
                           m_y / factor,
                           m_z / factor);
  }
  
  /**
   * Vector addition.
   */
  const Vector3D<_type>& operator += (_type factor)
  {
    m_x += factor;
    m_y += factor;
    m_z += factor;
    return *this;
  }
  
  /**
   * Vector substraction.
   */
  const Vector3D<_type>& operator -= (_type factor)
  {
    m_x -= factor;
    m_y -= factor;
    m_z -= factor;
    return *this;
  }
  
  /**
   * Vector multiplication.
   */
  const Vector3D<_type>& operator *= (_type factor)
  {
    m_x *= factor;
    m_y *= factor;
    m_z *= factor;
    return *this;
  }
  
  /**
   * Vector addition.
   */
  const Vector3D<_type>& operator += (const Vector3D<_type>& vec)
  {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
    return *this;
  }
  
  /**
   * Vector substraction.
   */
  const Vector3D<_type>& operator -= (const Vector3D<_type>& vec)
  {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;
    return *this;
  }
  
private:
  
  _type m_x;
  _type m_y;
  _type m_z;
  
};

/**
 * Vector addition.
 */
template<typename _type>
Vector3D<_type> operator + (_type factor, const Vector3D<_type>& v)
{ return v + factor; }

/**
 * Vector multiplication.
 */
template<typename _type>
Vector3D<_type> operator * (_type factor, const Vector3D<_type>& v)
{ return v * factor; }

}; /* namespace Planet */

#endif /* planet_vector_3d_hpp */
