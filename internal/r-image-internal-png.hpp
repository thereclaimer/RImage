#ifndef R_IMAGE_INTERNAL_PNG_HPP
#define R_IMAGE_INTERNAL_PNG_HPP

#include "r-image-types.hpp"

struct RImagePNGChunk {
    r_u32    length;
    r_u32    type;
    r_memory data;
    r_u32    crc;
};

enum RImagePNGChunkType_ {                // CRITICAL | MULTIPLE OK? | ORDERING CONSTRAINTS
    RImagePNGChunkType_IHDR = 0x49484452, //   YES           NO         Must be first
    RImagePNGChunkType_PLTE = 0x504C5445, //   YES           NO         Before IDAT
    RImagePNGChunkType_IDAT = 0x49444154, //   YES           YES        Multiple IDATs must be consecutive
    RImagePNGChunkType_IEND = 0x49454E44, //   YES           NO         Must be last
    RImagePNGChunkType_cHRM = 0x6348524D, //   NO            NO         Before PLTE and IDAT
    RImagePNGChunkType_gAMA = 0x67414D41, //   NO            NO         Before PLTE and IDAT
    RImagePNGChunkType_iCCP = 0x69434350, //   NO            NO         Before PLTE and IDAT
    RImagePNGChunkType_sBIT = 0x73424954, //   NO            NO         Before PLTE and IDAT
    RImagePNGChunkType_sRGB = 0x73524742, //   NO            NO         Before PLTE and IDAT
    RImagePNGChunkType_bKGD = 0x624B4744, //   NO            NO         After PLTE; before IDAT
    RImagePNGChunkType_hIST = 0x68495354, //   NO            NO         After PLTE; before IDAT
    RImagePNGChunkType_tRNS = 0x74524E53, //   NO            NO         After PLTE; before IDAT
    RImagePNGChunkType_pHYs = 0x70485973, //   NO            NO         Before IDAT
    RImagePNGChunkType_sPLT = 0x73504C54, //   NO            YES        Before IDAT
    RImagePNGChunkType_tIME = 0x74494D45, //   NO            NO         None
    RImagePNGChunkType_iTXt = 0x69545874, //   NO            YES        None
    RImagePNGChunkType_tEXt = 0x74455874, //   NO            YES        None
    RImagePNGChunkType_zTXt = 0x7A545874, //   NO            YES        None
};

struct RImagePNG {

};

#endif //R_IMAGE_INTERNAL_PNG_HPP