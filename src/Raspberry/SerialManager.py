import serial
import serial.tools.list_ports
import time
import threading

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
            if self.connection and self.connection.in_waiting > 0:
                data = self.connection.readline().decode('utf-8').strip()
                print(f"Received: {data}")
                #TODO: data should be added to the database (and should be an float value)
            time.sleep(0.5)

    def start_reading(self):
        threading.Thread(target=self.read_from_arduino, daemon=True).start()