// ======================================================================== //
// Copyright 2009-2017 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "sg/common/Node.h"
#include "sg/common/Texture2D.h"

namespace ospray {
  namespace sg {

    /*! \brief Base class for all Material Types */
    struct Material : public Node {
      /*! constructor */
      Material();
      
      /*! \brief returns a std::string with the c++ name of this class */
      virtual    std::string toString() const { return "ospray::viewer::sg::Material"; };
      
      //! 'render' the nodes
      virtual void render(RenderContext &ctx);

      //! a logical name, of no other useful meaning whatsoever
      std::string name; 
      //! indicates the type of material/shader the renderer should use for these parameters
      std::string type;
      //! vector of textures used by the material
      std::vector<std::shared_ptr<Texture2D>> textures;
      
      OSPMaterial ospMaterial;
    };

  } // ::ospray::sg
} // ::ospray
