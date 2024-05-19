## @file SerialManager.py
#  @brief This file contains the SerialManager class which manages the serial communication with Arduino.

import serial
import serial.tools.list_ports
import time
import threading
import sys

## @class SerialManager
#  @brief This class is responsible for managing the serial communication with Arduino.
class SerialManager:
    
    ## @brief The constructor.
    #  @details It initializes the serial communication parameters and connects to Arduino.
    #  @param database_connection_manager The DatabaseConnectionManager instance to interact with the database.
    #  @param nfc_manager The RFIDReader instance to interact with the NFC reader.
    def __init__(self, database_connection_manager, nfc_manager):
        self.baud_rate = 9600
        self.connection = None
        self.db = database_connection_manager
        self.nfc = nfc_manager
        self.find_and_connect_arduino()

    ## @brief Find the Arduino device and establish a serial connection.
    #  @details This method looks for the Arduino device in the available serial ports and establishes a connection.
    def find_and_connect_arduino(self):
        ports = list(serial.tools.list_ports.comports())
        for p in ports:
            if p.device.startswith("/dev/ttyACM") or p.device.startswith("/dev/ttyUSB"):
                self.connection = serial.Serial(p.device, self.baud_rate)
                print(f"Connected to Arduino on {p.device}")
                return
        raise Exception("Could not find Arduino")

    ## @brief Continuously read data from Arduino.
    #  @details This method runs in an infinite loop, continuously reading data from Arduino and updating the database.
    def read_from_arduino(self):
        while True:
            if self.connection and self.connection.in_waiting >= 3:
                data = self.connection.readline().decode('utf-8').strip()
                print(f"Received: {data}")
                try:
                    quantity = float(data)
                except ValueError:
                    print("Invalid data received from arduino")
                    sys.exit(1)
                id, text = self.nfc.get_token_data()
                self.db.updateDB(id, text, quantity)
            time.sleep(0.5)

    ## @brief Start the Arduino data reading in a separate thread.
    def start_reading(self):
        threading.Thread(target=self.read_from_arduino, daemon=True).start()
