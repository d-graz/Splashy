/**
 * @file LedMatrix.hpp
 * @brief File containing the definition of the LedMatrix class, which is used for controlling a LED matrix.
 */

#include <Arduino.h>
#include <LedControl.h>
#include "../Config/Config.hpp"
#include "../MySD/MySD.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifndef __LEDMATRIX__
#define __LEDMATRIX__

#define MATRIX_SIZE 8 ///< The size of the LED matrix.
#define LED_MATRIX_DEVICES_COUNT 1 ///< The number of devices in the LED matrix.
#define DEFAULT_BRIGHTNESS 8 ///< The default brightness of the LED matrix.
#define ANIMATION_LINE_LENGTH 11 ///< The length of each line in the animation file.

/**
 * @class LedMatrix
 * @brief Class for controlling a LED matrix.
 *
 * This class provides methods for loading animations from a file,
 * advancing to the next frame of the animation, and displaying the current frame.
 * It inherits from the Task class.
 */
class LedMatrix : public Task {
    private:
        LedControl lc; ///< LED control object used to control the LED matrix.
        File file; ///< File object used to read animation data from a file.
        byte animation[MATRIX_SIZE]; ///< Array to hold the current animation frame.
        byte frame_count; ///< Number of frames in the animation. If 0, the animation is ignored.
        byte current_frame; ///< Index of the current frame in the animation.
        const byte error_animation[MATRIX_SIZE] = {0b00000000, 0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00000000}; ///< Array to hold the error animation frame.

        /**
         * @brief Advances to the next frame of the animation.
         *
         * This method reads the next frame from the animation file and stores it in the animation array.
         *
         * @return true if the next frame was loaded successfully, false otherwise.
         */
        bool next_frame();

        /**
         * @brief Displays the current frame of the animation.
         *
         * This method sends the current frame data to the LED matrix.
         */
        void show_frame();

    public:
        /**
         * @brief Constructor for LedMatrix class.
         *
         * Initializes a new instance of the LedMatrix class. This includes initializing the LED control object and setting the initial state of the LED matrix.
         */
        LedMatrix();

        /**
         * @brief Loads an animation from a file.
         *
         * This method opens the specified file and reads the animation data into memory.
         *
         * @param file_path The path to the file containing the animation data.
         * @param frame_count The number of frames in the animation.
         * @return true if the animation was loaded successfully, false otherwise.
         */
        bool load_animation(String file_path, byte frame_count);

        /**
         * @brief Displays an error animation.
         *
         * This method displays a predefined error animation on the LED matrix.
         */
        void show_error();

        /**
         * @brief Advances to the next frame.
         *
         * This method is overridden from the Task class. It advances to the next frame of the animation and displays it.
         *
         * @return true if there are no error in the process, false otherwise.
         */
        bool next() override;
};

#endif