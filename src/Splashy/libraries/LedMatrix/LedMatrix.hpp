/**
 * @file LedMatrix.hpp
 * @brief File containing the definition of the LedMatrix class.
 */

#include<LedControl.h>
#include "../Config/Config.hpp"
#include "../MySD/MySD.hpp"

#ifndef __LEDMATRIX__
#define __LEDMATRIX__

#define MATRIX_SIZE 8
#define LED_MATRIX_DEVICES_COUNT 1
#define DEFAULT_BRIGHTNESS 8
#define ANIMATION_LINE_LENGTH 11

/**
 * @class LedMatrix
 * @brief Class for controlling a LED matrix.
 *
 * This class provides methods for loading animations from a file,
 * advancing to the next frame of the animation, and displaying the current frame.
 */
class LedMatrix {
    private:
        LedControl lc; ///< LED control object.
        File file; ///< File object for reading animation data.
        byte animation[MATRIX_SIZE]; ///< Array to hold the current animation frame.
        const byte error_animation[MATRIX_SIZE] = {0b00000000, 0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00000000}; ///< Array to hold the error animation frame.

    public:
        /**
         * @brief Constructor for LedMatrix class.
         *
         * Initializes a new instance of the LedMatrix class.
         */
        LedMatrix();

        /**
         * @brief Loads an animation from a file.
         *
         * @param file_path The path to the file containing the animation data.
         * @return true if the animation was loaded successfully, false otherwise.
         */
        bool load_animation(String file_path);

        /**
         * @brief Advances to the next frame of the animation.
         *
         * @return true if the next frame was loaded successfully, false otherwise.
         */
        bool next_frame();

        /**
         * @brief Displays the current frame of the animation.
         */
        void show_frame();

        /**
         * @brief Displays an error animation.
         */
        void show_error();
};

#endif