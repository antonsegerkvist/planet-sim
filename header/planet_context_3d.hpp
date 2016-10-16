//
//  planet_context.hpp
//  Planet Simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_context_3d_h
#define planet_context_3d_h

#include <cmath>
#include <iostream>
#include <vector>

#include "planet_planet_3d.hpp"
#include "planet_typedef_3d.hpp"

namespace Planet
{

template <typename _type> class Context3D;
template <typename _type> class Physics3D;
template <typename _type> class Planet3D;

template <typename _type>
class Context3D
{
public:
  
  /**
   * Constructor.
   */
  Context3D(_type constant)
  : m_constant(constant)
  , m_mass()
  , m_position()
  , m_velocity()
  { }
  
  /**
   * Destructor.
   */
  ~Context3D()
  { }
  
  /**
   * Get the planetary constant.
   */
  inline _type getConstant() const
  { return m_constant; }
  
  /**
   * Add a planet to the context.
   */
  inline void addPlanet(const Planet3D<_type>& planet)
  {
    m_mass.push_back(planet.getMass());
    m_position.push_back(planet.getPosition());
    m_velocity.push_back(planet.getVelocity());
  }
  
  /**
   * Print the context to the console.
   */
  void print() const;
  
private:
  
  _type m_constant;
  std::vector<_type> m_mass;
  Vector3DVector<_type> m_position;
  Vector3DVector<_type> m_velocity;
  
private:
  
  friend class Physics3D<_type>;
  
};
  
template <typename _type>
void Context3D<_type>::print() const
{
  for(size_t i=0; i<m_mass.size(); ++i)
  {
    std::cout << m_mass[i] << " "
              << m_position[i].getX() << " "
              << m_position[i].getY() << " "
              << m_position[i].getZ() << " "
              << m_velocity[i].getX() << " "
              << m_velocity[i].getY() << " "
              << m_velocity[i].getZ() << std::endl;
  }
}
  
}; /* namespace Planet */

#endif /* planet_context_h */
