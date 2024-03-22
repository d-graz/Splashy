/**
 * @file MySD.hpp
 * @brief MySD library for simplified SD card operations.
 * @version 1.1
 * 
 * This library provides a simplified interface for working with SD cards on Arduino.
 * It wraps the functionality of the Arduino SD library.
 */

#include <SD.h>
#include <SPI.h>
#include "../Config/Config.hpp"

#ifndef __MYSD__
#define __MYSD__

/**
 * @brief Initializes the SD card.
 * 
 * This function initializes the SD card using the SD library. If the SD card is successfully initialized,
 * the function returns true. Otherwise, it returns false.
 * 
 * @return true if the SD card was successfully initialized, false otherwise.
 */
bool init_sd();

/**
 * @brief Opens a file on the SD card.
 * 
 * This function opens a file on the SD card in the specified mode. The mode can be 'r' for read mode or 'w' for write mode.
 * If the file is successfully opened, the function returns a File object representing the opened file.
 * If the file could not be opened, the returned File object will be in a "null" state (i.e., !file will be true).
 * 
 * @param file_path The path to the file on the SD card.
 * @param mode The mode in which to open the file. Can be 'r' for read mode or 'w' for write mode.
 * @return A File object representing the opened file. If the file could not be opened, the returned File object will be in a "null" state.
 */
File open_file(String file_path, char mode);

/**
 * @brief Reads a line from a file.
 * 
 * This function reads a line from a file and stores it in the specified buffer. The buffer should be large enough to hold the line.
 * The function returns true if a line was successfully read, and false otherwise.
 * 
 * @param file The file from which to read the line.
 * @param buffer The buffer in which to store the line.
 * @param buffer_size The size of the buffer.
 * @return true if a line was successfully read, false otherwise.
 */
bool read_line(File file, char* buffer, byte buffer_size);

#endif