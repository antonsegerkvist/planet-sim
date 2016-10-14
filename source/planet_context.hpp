//
//  planet_context.hpp
//  Planet Simulator
//
//  Created by Anton Segerkvist on 14/10/16.
//  Copyright © 2016 anton segerkvist. All rights reserved.
//

#ifndef planet_context_h
#define planet_context_h

#include <cmath>
#include <iostream>
#include <vector>

template <typename _type>
class PlanetContext
{
public:
  
  /**
   * Constructor.
   */
  PlanetContext(_type constant)
  : m_constant(constant)
  , m_buffer()
  , m_planets()
  { }
  
  /**
   * Destructor.
   */
  ~PlanetContext()
  { }
  
  /**
   * Get the gravitational constant.
   */
  inline _type getConstant() const
  { return m_constant; }
  
  /**
   * Get the number of planets in the context.
   */
  inline size_t getNumberOfPlanets() const
  { return m_planets.size(); }
  
  /**
   * Add a single planet to the context.
   * @param The planet to add to the context.
   */
  inline void addPlanet(const Planet<_type>& planet)
  {
    m_buffer.push_back(planet);
    m_planets.push_back(planet);
  }
  
  /**
   * Update the planet context by a time using the euler method.
   * @param time The time to update the context by.
   */
  void updateEuler(_type time);
  
  /**
   * Print the planetary context to the terminal.
   */
  void print() const;
  
private:
  
  _type m_constant;
  std::vector<Planet<_type> > m_buffer;
  std::vector<Planet<_type> > m_planets;
  
};

template <typename _type>
void PlanetContext<_type>::updateEuler(_type time)
{
  // Define stack data.
  _type x_acc;
  _type y_acc;
  _type z_acc;
  
  // Start calculating new planet position.
  for(size_t i=0; i<m_planets.size(); ++i)
  {
    // Reset the calculated acceleration.
    x_acc = 0.0;
    y_acc = 0.0;
    z_acc = 0.0;
    
    // Here comes the expensive part.
    for(size_t j=0; j<m_buffer.size(); ++j)
    {
      // We should not inclue the planet it self.
      if(i == j) continue;
      
      // Basic geometry.
      _type mass = m_buffer[j].getMass();
      _type x_len = m_buffer[j].getX() - m_planets[i].getX();
      _type y_len = m_buffer[j].getY() - m_planets[i].getY();
      _type z_len = m_buffer[j].getZ() - m_planets[i].getZ();
      _type len = pow(sqrt(pow(x_len, 2) + pow(y_len, 2) + pow(z_len, 2)), 3);
      
      x_acc += mass * x_len / len;
      y_acc += mass * y_len / len;
      z_acc += mass * z_len / len;
    }
    
    // Update the velocity.
    m_planets[i].setVX(m_planets[i].getVX() + getConstant() * x_acc * time);
    m_planets[i].setVY(m_planets[i].getVX() + getConstant() * y_acc * time);
    m_planets[i].setVZ(m_planets[i].getVZ() + getConstant() * z_acc * time);
    
    // Update the position.
    m_planets[i].setX(m_planets[i].getX() + m_planets[i].getVX() * time);
    m_planets[i].setY(m_planets[i].getY() + m_planets[i].getVY() * time);
    m_planets[i].setZ(m_planets[i].getZ() + m_planets[i].getVZ() * time);
  }
  
  // Copy the buffer.
  m_buffer = m_planets;
}

/*
template <typename _type>
void PlanetContext<_type>::update(_type time)
{
  // Define stack data.
  typename std::vector<Planet<_type> >::iterator it;
  typename std::vector<Planet<_type> >::const_iterator cit;
  
  // Start calculating new planet position.
  for(it = m_planets.begin(); it != m_planets.end(); ++it)
  {
    m_z_force = 0.0;
    m_y_force = 0.0;
    m_z_force = 0.0;
    
    // Here comes the expensive part.
    for(cit = m_buffer.cbegin(); cit != m_buffer.cend(); ++cit)
    {
      if(it == cit) continue;
      
      // Basic geometry.
      _type mass = cit->getMass();
      _type x_len = cit->getX() - it->getX();
      _type y_len = cit->getY() - it->getY();
      _type z_len = cit->getZ() - it->getZ();
      _type len = pow(sqrt(pow(x_len, 2) + pow(y_len, 2) + pow(z_len, 2)), 3);
      
      m_x_force += mass * x_len / len;
      m_y_force += mass * y_len / len;
      m_z_force += mass * z_len / len;
    }
  }
  
  // Copy buffer.
  m_buffer = m_planets;
}
*/

template<typename _type>
void PlanetContext<_type>::print() const
{
  typename std::vector<Planet<_type> >::const_iterator cit;
  for(cit = m_planets.cbegin(); cit != m_planets.cend(); ++cit)
  {
    std::cout << cit->getMass() << " "
              << cit->getX()    << " "
              << cit->getY()    << " "
              << cit->getZ()    << " "
              << cit->getVX()   << " "
              << cit->getVY()   << " "
              << cit->getVZ()   << " "
              << std::endl;
  }
}

#endif /* planet_context_h */
