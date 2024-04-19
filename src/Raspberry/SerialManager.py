import serial
import serial.tools.list_ports
import time
import threading
import sys

class SerialManager:
    def __init__(self, database_connection_manager, nfc_manager):
        self.baud_rate = 9600
        self.connection = None
        self.db = database_connection_manager
        self.nfc = nfc_manager
        self.find_and_connect_arduino()
    
    def find_and_connect_arduino(self):
        ports = list(serial.tools.list_ports.comports())
        for p in ports:
            if "Arduino" in p.description:
                self.connection = serial.Serial(p.device, self.baud_rate)
                print(f"Connected to Arduino on {p.device}")
                return
        raise Exception("Could not find Arduino")
    
    def read_from_arduino(self):
        while True:
            if self.connection and self.connection.in_waiting >= 4:
                data = self.connection.readline().decode('utf-8').strip()
                print(f"Received: {data}")
                try:
                    quantity = float(data)
                except ValueError:
                    print("Invalid data received from arduino")
                    sys.exit(1)
                id, text = self.db.get_token_data()
                self.db.updateDB(id, text, quantity)
            time.sleep(0.5)

    def start_reading(self):
        threading.Thread(target=self.read_from_arduino, daemon=True).start()