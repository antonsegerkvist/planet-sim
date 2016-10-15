//
//  planet_planet_3d.hpp
//  Planet Simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_planet_3d_hpp
#define planet_planet_3d_hpp

#include "planet_vector_3d.hpp"

namespace Planet
{

template <typename _type>
class Planet3D
{
public:
  
  /**
   * Constructor.
   * @param mass The mass of the planet.
   * @param position The position of the planet.
   * @param velocity The velocity of the planet.
   */
  Planet3D(_type mass = 0.0,
           const Vector3D<_type>& position = Vector3D<_type>(),
           const Vector3D<_type>& velocity = Vector3D<_type>())
  : m_mass(mass)
  , m_position(position)
  , m_velocity(velocity)
  { }
  
  /**
   * Destructor.
   */
  ~Planet3D()
  { }
  
  /**
   * Get the mass of the planet.
   */
  inline _type getMass() const
  { return m_mass; }
  
  /**
   * Get the x coordinate.
   */
  inline _type getX() const
  { return m_position.getX(); }
  
  /**
   * Get the y coordinate.
   */
  inline _type getY() const
  { return m_position.getY(); }
  
  /**
   * Get the z coordinate.
   */
  inline _type getZ() const
  { return m_position.getZ(); }
  
  /**
   * Get the position.
   */
  inline const Vector3D<_type>& getPosition() const
  { return m_position; }
  
  /**
   * Get the velocity in the x direction.
   */
  inline _type getVX() const
  { return m_velocity.getX(); }
  
  /**
   * Get the velocity in the y direction.
   */
  inline _type getVY() const
  { return m_velocity.getY(); }
  
  /**
   * Get the velocity in the z direction.
   */
  inline _type getVZ() const
  { return m_velocity.getZ(); }
  
  /**
   * Get the velocity.
   */
  inline const Vector3D<_type>& getVelocity() const
  { return m_velocity; }
  
  /**
   * Set the mass of the planet.
   */
  inline void setMass(_type mass)
  { m_mass = mass; }
  
  /**
   * Set the x position of the planet.
   */
  inline void setX(_type x)
  { m_position.setX(x); }
  
  /**
   * Set the y position of the planet.
   */
  inline void setY(_type y)
  { m_position.setY(y); }
  
  /**
   * Set the z position of the planet.
   */
  inline void setZ(_type z)
  { m_position.setZ(z); }
  
  /**
   * Set the position.
   */
  inline void setPosition(const Vector3D<_type>& position)
  { m_position = position; }
  
  /**
   * Set the velocity in the x direction.
   */
  inline void setVX(_type vx)
  { m_velocity.setX(vx); }
  
  /**
   * Set the velocity in the y direction.
   */
  inline void setVY(_type vy)
  { m_velocity.setY(vy); }
  
  /**
   * Set the velocity in the z direction.
   */
  inline void setVZ(_type vz)
  { m_velocity.setZ(vz); }
  
  /**
   * Set the velocity.
   */
  inline void setVelocity(const Vector3D<_type>& velocity)
  { m_velocity = velocity; }
  
private:
  
  _type m_mass;
  Vector3D<_type> m_position;
  Vector3D<_type> m_velocity;
  
};

}; /* namespace Planet */
  
#endif /* planet3d_hpp */
