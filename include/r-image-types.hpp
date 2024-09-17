#ifndef R_IMAGE_TYPES_HPP
#define R_IMAGE_TYPES_HPP

#include <r-common.hpp>

enum RImagePixelFormat_ {
    RImagePixelFormat_RGBA = 0,
    RImagePixelFormat_ARGB = 1,
    RImagePixelFormat_ABGR = 2,
    RImagePixelFormat_BGRA = 3 
};

typedef r_u32 RImagePixelFormat;

struct RImagePixelRGBA {
    union {

        r_f32 rgba;
        
        struct {
            r_u8 r;
            r_u8 g;
            r_u8 b;
            r_u8 a;
        };
    };
};

struct RImagePixelARGB {
    union {

        r_f32 argb;
        
        struct {
            r_u8 a;
            r_u8 r;
            r_u8 g;
            r_u8 b;
        };
    };
};

struct RImagePixelABGR {
    union {

        r_f32 abgr;
        
        struct {
            r_u8 a;
            r_u8 b;
            r_u8 g;
            r_u8 r;
        };
    };
};

struct RImagePixelBGRA {
    union {

        r_f32 abgr;
        
        struct {
            r_u8 b;
            r_u8 g;
            r_u8 r;
            r_u8 a;
        };
    };
};

struct RImagePixelStream {
    RImagePixelFormat pixel_format;
    r_size            pixel_count;
    r_size            data_size;
    union {
        r_memory         data;
        RImagePixelRGBA* pixels_rgba;
        RImagePixelARGB* pixels_argb;
        RImagePixelABGR* pixels_abgr;
        RImagePixelBGRA* pixels_bgra;
    }; 
};

#endif //R_IMAGE_TYPES_HPP