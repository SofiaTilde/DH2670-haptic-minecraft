#include "chai3d.h"
#include "CBullet.h"

using namespace chai3d;

// define the radius of the tool (sphere)
inline double toolRadius = 0.06;

// stiffness properties
inline double maxStiffness;

inline double block_scale = 0.2;
inline double box_scale = block_scale * 2;

inline cBulletWorld *bulletWorld;