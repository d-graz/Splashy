/**
 * \file Animations.hpp
 * \brief Header file for the Animations class.
 */

//WARN: Assure to call open_animation before calling next 
#include <SD.h>
#include <SPI.h>

#define DEBUG

#ifndef __ANIMATIONS__
#define __ANIMATIONS__

#define MATRIX_SIZE 8
#define ANIMATION_LINE_SIZE (3 + 2 + 2)*MATRIX_SIZE
#define DATA_PER_LINE 3*MATRIX_SIZE

/**
 * \struct pixel
 * \brief Struct for pixel for argb panels.
 */
typedef struct pixel{
    byte r; ///< Red component of the pixel.
    byte g; ///< Green component of the pixel.
    byte b; ///< Blue component of the pixel.
}pixel_t;

/**
 * \class Animations
 * \brief Class for handling animations.
 */
class Animations {
    private:
        File file; ///< File pointer for the animation.
        pixel_t matrix[MATRIX_SIZE][MATRIX_SIZE]; ///< Pixel matrix for the animation.
    public:
        /**
         * \brief Opens an animation file.
         * \param file_path The path of the animation file.
         */
        bool open_animation(String file_path);

        /**
         * \brief Advances to the next animation.
         */
        bool next();

        /**
         * \brief Returns the pixel matrix.
         * \return A pointer to the pixel matrix.
         */
        pixel_t* get_matrix();

        /**
         * \brief Error function
         */
        void error();

        
};

#endif