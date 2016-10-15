//
//  planet_math_3d.hpp
//  planet_simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_math_3d_hpp
#define planet_math_3d_hpp

#include "planet_vector_3d.hpp"

namespace Planet
{

/**
 * Calculate the dot product of the two vectors.
 */
template <typename _type>
_type Dot(const Vector3D<_type>& vec1, const Vector3D<_type>& vec2)
{
  return vec1.getX() * vec2.getX()
       + vec1.getY() * vec2.getY()
       + vec1.getZ() * vec2.getZ();
}

/**
 * Calculate the one norm of the 3d vector.
 */
template <typename _type>
_type OneNorm(const Vector3D<_type>& vec)
{
  _type x_1 = fabs(vec.getX());
  _type y_1 = fabs(vec.getY());
  _type z_1 = fabs(vec.getZ());
  return x_1 + y_1 + z_1;
}

/**
 * Calculate the two norm of the 3d vector.
 */
template <typename _type>
_type TwoNorm(const Vector3D<_type>& vec)
{
  _type x_2 = pow(vec.getX(), 2);
  _type y_2 = pow(vec.getY(), 2);
  _type z_2 = pow(vec.getZ(), 2);
  return sqrt(x_2 + y_2 + z_2);
}

/**
 * Calculate the min norm of the 3d vector.
 */
template <typename _type>
_type MinNorm(const Vector3D<_type>& vec)
{
  _type x_m = fabs(vec.getX());
  _type y_m = fabs(vec.getY());
  _type z_m = fabs(vec.getZ());
  return fmin(fmin(x_m, y_m), z_m);
}

/**
 * Calculate the max norm of the 3d vector.
 */
template <typename _type>
_type MaxNorm(const Vector3D<_type>& vec)
{
  _type x_m = fabs(vec.getX());
  _type y_m = fabs(vec.getY());
  _type z_m = fabs(vec.getZ());
  return fmax(fmax(x_m, y_m), z_m);
}

}; /* namespace Planet */
  
#endif /* planet_math_3d_hpp */
