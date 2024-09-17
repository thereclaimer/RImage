#ifndef R_IMAGE_INTERNAL_MANAGER_HPP
#ifndef R_IMAGE_INTERNAL_MANAGER_HPP

#include "r-image-types.hpp"

struct RImageManager {
    r_memory  scratch_space;
    r_size    scratch_space_size;
    r_address scratch_space_position
};

namespace r_img_internal {

};

#ifndef //R_IMAGE_INTERNAL_MANAGER_HPP