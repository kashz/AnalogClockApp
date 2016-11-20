#ifndef __COLORS_H__
#define __COLORS_H__

// 0 - 255
struct _rgb256 {
    int red;
    int green;
    int blue;
};
typedef struct _rgb256 ColorRGB256;

// 0 - 1
struct _rgb {
    double red;
    double green;
    double blue;
};
typedef struct _rgb ColorRGB;

ColorRGB ConvertRGB(ColorRGB256 col);
void SetColorRGB256(ColorRGB256 col);

#endif /* __COLORS_H__ */
