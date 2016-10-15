//
//  planet_typedef_3d.hpp
//  planet_simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef typedef_h
#define typedef_h

#include <vector>
#include "planet_planet_3d.hpp"
#include "planet_context_3d.hpp"
#include "planet_vector_3d.hpp"

namespace Planet
{

template <typename _type> class Physics3D;
template <typename _type> class Planet3D;
template <typename _type> class Context3D;

// A vector of planets.
template <typename _type>
using Planet3DVector = std::vector<Planet3D<_type> >;

// A vector of position vectors.
template <typename _type>
using Vector3DVector = std::vector<Vector3D<_type> >;

}; /* namespace Planet */
  
#endif /* planet_typedef_3d_h */
