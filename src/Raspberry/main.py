from DatabaseConnectionManager import DatabaseConnectionManager
from NFCReader import NFCReader
from SerialManager import SerialManager
import time

if __name__ == "__main__":
    db = DatabaseConnectionManager()
    nfc = NFCReader()
    nfc.start_reading()
    serial = SerialManager(db, nfc)
    serial.start_reading()
    while True:
        time.sleep(60)
        top5 = db.getTopK(5)
        total = db.getTotalQuantity()
        print(f"Top 5 items: {top5}")
        print(f"Total quantity: {total}")
