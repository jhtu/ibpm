#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "BoundaryVector.h"
#include <iostream>
#include <vector>
using namespace std;

class RigidBody;

/*!
\file Geometry.h
\class Geometry

\brief Create, load, and save geometries composed of RigidBody objects.

\author Clancy Rowley
\date  3 Jul 2008

$Revision$
$LastChangedDate$
$LastChangedBy$
$HeadURL$
*/

class Geometry {
public:
    /// Constructor
    Geometry();
    
    /// Destructor
    ~Geometry();

    /// \brief Append the given RigidBody to the list of bodies in the 
    /// current geometry.
    /// Makes a copy of it internally.
    void addBody(const RigidBody& body);

    int getNumPoints() const;

    BoundaryVector getPoints() const;
    
    BoundaryVector getVelocities() const;

    bool isStationary() const;

    void moveBodies(double time) const;
    
    void load(const istream& in);
    
private:
    vector<RigidBody> _bodies;
    int _numPoints;
};

#endif /* _GEOMETRY_H_ */
