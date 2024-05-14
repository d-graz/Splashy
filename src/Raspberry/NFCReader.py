## @file NFCReader.py
#  @brief This file contains the RFIDReader class which manages the NFC card reading operations.

import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
import threading

## @class RFIDReader
#  @brief This class is responsible for reading NFC cards and managing the read data.
class RFIDReader:
    
    ## @brief The constructor.
    #  @details It initializes the NFC card reader and sets up some initial parameters.
    def __init__(self):
        self.reader = SimpleMFRC522()
        self.id = None
        self.text = None
        self.lock = threading.Lock()

    ## @brief Continuously read the NFC card.
    #  @details This method runs in an infinite loop, continuously reading the NFC card.
    def read_card(self):
        while True:
            try:
                # reading the nfc card: blocking call
                identification, text = self.reader.read()
                print(f"ID: {identification}, text: {text}")
                with self.lock:
                    # set the read data from the card
                    self.id = identification
                    self.text = text.strip()
            except:
                print("HW ERR on NFC module")
                break

    ## @brief Get the data from the last read NFC card and reset the stored data.
    #  @return A tuple containing the id and text from the last read NFC card.
    def get_token_data(self):
        with self.lock:
            # get the read data from the card and then cleanup the code
            identification = self.id
            text = self.text
            self.id = None
            self.text = None
        # if the id or text is None, set it to a default value
        if identification is None:
            identification = "None"
        if text is None:
            text = "default"
        return identification, text

    ## @brief Get the data from the last read NFC card without resetting the stored data.
    #  @return A tuple containing the id and text from the last read NFC card.
    def get_user(self):
        with self.lock:
            # get the read data from the card
            identification = self.id
            text = self.text
        return identification, text

    ## @brief Start the NFC card reading in a separate thread.
    def start_reading(self):
        threading.Thread(target=self.read_card, daemon=True).start()