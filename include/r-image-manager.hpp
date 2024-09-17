#ifndef R_IMAGE_MANAGER_HPP
#define R_IMAGE_MANAGER_HPP

#include "r-image-types.hpp"

namespace r_img {

    r_external const r_b8 
    image_manager_create(
        const r_size   scratch_space_size,
              r_memory scratch_space);

    r_external const r_b8 
    image_manager_destroy(r_void);

};

#endif //R_IMAGE_MANAGER_HPP