#ifndef R_IMAGE_PNG_HPP
#define R_IMAGE_PNG_HPP

#include "r-image-types.hpp"

const r_byte R_IMAGE_PNG_SIGNATURE[8] = {
    137, 80, 78, 71, 13, 10, 26, 10
    //\211 P N G \r \n \032 \n
};

enum RImagePNGResult_ {
    RImagePNGResult_Success                     = 0x00,
    RImagePNGResult_Error_InvalidSignature      = 0x01,
    RImagePNGResult_Error_NotEnoughScratchSpace = 0x02,
    RImagePNGResult_Error_Uknown                = 0xFF 
};

typedef r_s32 RImagePNGResult;

struct RImagePNGInfo {
    r_memory          png_data;
    r_size            png_data_size;
    r_size            required_pixel_stream_size;
    r_size            required_scratch_space_size;
    r_b32             valid;
    RImagePixelFormat pixel_format;
    RImagePNGResult   result;
};

namespace r_img {

    r_external r_b8 png_info(RImagePNGInfo& png_info);

    r_external RImagePixelStream*
    png_parse(
        RImagePNGInfo& png_info,
        r_size         pixel_stream_size,
        r_memory*      pixel_stream_memory);
};

#endif //R_IMAGE_PNG_HPP