#include "chai3d.h"
#include "CODE.h"

using namespace chai3d;

// define the radius of the tool (sphere)
inline double toolRadius = 0.06;

// stiffness properties
inline double maxStiffness;

inline double block_scale = 0.03;

inline cODEWorld *ODEWorld;

inline cODEGenericBody *ODEBodyTest3;
inline cMesh *objectTest3;

inline double size2 = 0.40;