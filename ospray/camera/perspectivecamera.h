#pragma once

#include "camera.h"

namespace ispc {  
  struct PerspectiveCamera_Data;
};

namespace ospray {

  /*! \page perspective_camera Perspective Camera ("perspective")

    \ingroup builtin_cameras
    
    A simple perspective camera. Supports the following 
    <pre>
    vec3f(a) pos;    // camera position
    vec3f(a) dir;    // camera direction
    vec3f(a) up;     // up vector
    float    near;   // camera near plane (not all renderers may support this!)
    float    far;    // camera far plane (not all renderers may support this!)
    float    fovy;   // field of view (camera opening angle) in frame's y dimension
    float    aspect; // aspect ratio (x/y)
    </pre>
  */

  //! Implements a simple perspective camera (see \subpage perspective_camera)
  struct PerspectiveCamera : public Camera {
    /*! \brief constructor \internal also creates the ispc-side data structure */
    PerspectiveCamera();
    //! \brief common function to help printf-debugging 
    /*! Every derived class should overrride this! */
    virtual std::string toString() const { return "ospray::PerspectiveCamera"; }
    virtual void commit();
    
  public:
    // ------------------------------------------------------------------
    // the parameters we 'parsed' from our parameters
    // ------------------------------------------------------------------
    vec3f  pos;
    vec3f  dir;
    vec3f  up;
    float  near;
    float  far;
    float  fovy;
    float  aspect;

    // ------------------------------------------------------------------
    // the internal data we preprocessed from our input parameters
    // ------------------------------------------------------------------
    vec3f dir_00; //!< the direction to point '(0.f,0.f)' on the image plane
    vec3f dir_du; //!< vector spanning x axis of image plane ((0,0)->(1,0))
    vec3f dir_dv; //!< vector spanning y axis of image plane ((0,0)->(0,1))

    ::ispc::PerspectiveCamera_Data *ispcData;
  };
}