//
//  planet.hpp
//  Planet Simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_hpp
#define planet_hpp

template <typename _type>
class Planet
{
public:
  
  /**
   * Constructor.
   * @param x The initial x position.
   * @param y The initial y position.
   * @param z The initial z position.
   * @param vx
   */
  Planet(_type mass,
         _type x,
         _type y,
         _type z,
         _type vx = 0.0,
         _type vy = 0.0,
         _type vz = 0.0)
  : m_mass(mass)
  , m_x(x)
  , m_y(y)
  , m_z(z)
  , m_vx(vx)
  , m_vy(vy)
  , m_vz(vz)
  { }
  
  /**
   * Destructor.
   */
  ~Planet()
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
  { return m_x; }
  
  /**
   * Get the y coordinate.
   */
  inline _type getY() const
  { return m_y; }
  
  /**
   * Get the z coordinate.
   */
  inline _type getZ() const
  { return m_z; }
  
  /**
   * Get the velocity in the x direction.
   */
  inline _type getVX() const
  { return m_vx; }
  
  /**
   * Get the velocity in the y direction.
   */
  inline _type getVY() const
  { return m_vy; }
  
  /**
   * Get the velocity in the z direction.
   */
  inline _type getVZ() const
  { return m_vz; }
  
  /**
   * Set the mass of the planet.
   */
  inline void setMass(_type mass)
  { m_mass = mass; }
  
  /**
   * Set the x position of the planet.
   */
  inline void setX(_type x)
  { m_x = x; }
  
  /**
   * Set the y position of the planet.
   */
  inline void setY(_type y)
  { m_y = y; }
  
  /**
   * Set the z position of the planet.
   */
  inline void setZ(_type z)
  { m_z = z; }
  
  /**
   * Set the velocity in the x direction.
   */
  inline void setVX(_type vx)
  { m_vx = vx; }
  
  /**
   * Set the velocity in the y direction.
   */
  inline void setVY(_type vy)
  { m_vy = vy; }
  
  /**
   * Set the velocity in the z direction.
   */
  inline void setVZ(_type vz)
  { m_vz = vz; }
  
private:
  
  _type m_mass;
  _type m_x;
  _type m_y;
  _type m_z;
  _type m_vx;
  _type m_vy;
  _type m_vz;
  
};

#endif /* planet_hpp */
