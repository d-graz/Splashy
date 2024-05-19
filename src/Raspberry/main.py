from DatabaseConnectionManager import DatabaseConnectionManager
from NFCReader import RFIDReader
from SerialManager import SerialManager
from PySide2 import QtWidgets
from GUI import Ui_MainWindowSplashy
import sys

if __name__ == "__main__":

    # set up the database connection
    db = DatabaseConnectionManager()

    # set up the nfc module and start reading
    nfc = RFIDReader()
    nfc.start_reading()

    # set up the serial communication with Arduino and start reading
    serial = SerialManager(db, nfc)
    serial.start_reading()

    # set up the GUI
    app = QtWidgets.QApplication(sys.argv)
    MainWindowSplashy = QtWidgets.QMainWindow()
    ui = Ui_MainWindowSplashy()
    ui.setupUi(MainWindowSplashy, db, nfc)

    # start the cleanup thread for the database
    db.start_clean_up_thread()

    # start the GUI
    MainWindowSplashy.show()

    # run the application
    sys.exit(app.exec_())
