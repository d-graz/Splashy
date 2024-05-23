##@file GUI.py
#@brief This file was partially generated using Qt Designer.
#
#This file contains the GUI implementation for the application. It was partially generated using Qt Designer, and then further modified to suit the needs of the application.

import sys
from PySide2 import QtCore, QtGui, QtWidgets
from PySide2.QtWidgets import QTableWidgetItem

from PySide2.QtCore import QTimer
from PySide2.QtCore import (QCoreApplication, QPropertyAnimation, QDate, QDateTime, QMetaObject, QObject, QPoint, QRect, QSize, QTime, QUrl, Qt, QEvent)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont, QFontDatabase, QIcon, QKeySequence, QLinearGradient, QPalette, QPainter, QPixmap, QRadialGradient, QPen)
from PySide2.QtWidgets import *
  
## @class Ui_MainWindowSplashy
#  @brief This class is responsible for setting up the user interface of the main window.
#
class Ui_MainWindowSplashy(object):

    ## This function sets up the user interface for the MainWindowSplashy class.
    #  @param self The object pointer.
    #  @param MainWindowSplashy The main window object.
    #  @param database_manager The database manager object.
    #  @param nfc_reader The NFC reader object.
    #  @return None.
    def setupUi(self, MainWindowSplashy, database_manager, nfc_reader):
        self.userNickname = ""
        self.db = database_manager
        self.nfc = nfc_reader
        MainWindowSplashy.setObjectName("MainWindowSplashy")
        MainWindowSplashy.setEnabled(True)
        #MainWindowSplashy.resize(720, 480)
        MainWindowSplashy.showFullScreen()
        MainWindowSplashy.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.637368, y2:0.943, stop:0 rgba(127, 163, 216, 255), stop:0.989637 rgba(236, 245, 255, 255))")
        
        self.centralwidget = QtWidgets.QWidget(MainWindowSplashy)
        self.centralwidget.setStyleSheet("background: rgb(46, 52, 54); font-size: 30px")
        self.centralwidget.setObjectName("centralwidget")
        
        self.layoutWidget_2 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget_2.setGeometry(QtCore.QRect(500, 40, 150, 280))
        self.layoutWidget_2.setObjectName("layoutWidget_2")
        self.layoutWidget_2.setStyleSheet("background: transparent; font-size: 34px")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.layoutWidget_2)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_literRanking1 = QtWidgets.QLabel(self.layoutWidget_2)
        self.label_literRanking1.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking1.setObjectName("label_literRanking1")
        self.verticalLayout_2.addWidget(self.label_literRanking1)
        self.label_literRanking2 = QtWidgets.QLabel(self.layoutWidget_2)
        self.label_literRanking2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking2.setObjectName("label_literRanking2")
        self.verticalLayout_2.addWidget(self.label_literRanking2)
        self.label_literRanking3 = QtWidgets.QLabel(self.layoutWidget_2)
        self.label_literRanking3.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking3.setObjectName("label_literRanking3")
        self.verticalLayout_2.addWidget(self.label_literRanking3)
        self.label_literRanking4 = QtWidgets.QLabel(self.layoutWidget_2)
        self.label_literRanking4.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking4.setObjectName("label_literRanking4")
        self.verticalLayout_2.addWidget(self.label_literRanking4)
        self.label_literRanking5 = QtWidgets.QLabel(self.layoutWidget_2)
        self.label_literRanking5.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking5.setObjectName("label_literRanking5")
        self.verticalLayout_2.addWidget(self.label_literRanking5)
        self.layoutWidget_3 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget_3.setGeometry(QtCore.QRect(200, 40, 300, 280))
        self.layoutWidget_3.setObjectName("layoutWidget_3")
        self.layoutWidget_3.setStyleSheet("background: transparent; font: bold; font-size: 34px")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.layoutWidget_3)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_nickname1 = QtWidgets.QLabel(self.layoutWidget_3)
        self.label_nickname1.setStyleSheet("background: transparent; color: white;")
        self.label_nickname1.setObjectName("label_nickname1")
        self.verticalLayout.addWidget(self.label_nickname1)
        self.label_nickname2 = QtWidgets.QLabel(self.layoutWidget_3)
        self.label_nickname2.setStyleSheet("background: transparent; color: white;")
        self.label_nickname2.setObjectName("label_nickname2")
        self.verticalLayout.addWidget(self.label_nickname2)
        self.label_nickname3 = QtWidgets.QLabel(self.layoutWidget_3)
        self.label_nickname3.setStyleSheet("background: transparent; color: white;")
        self.label_nickname3.setObjectName("label_nickname3")
        self.verticalLayout.addWidget(self.label_nickname3)
        self.label_nickname4 = QtWidgets.QLabel(self.layoutWidget_3)
        self.label_nickname4.setStyleSheet("background: transparent; color: white;")
        self.label_nickname4.setObjectName("label_nickname4")
        self.verticalLayout.addWidget(self.label_nickname4)
        self.label_nickname5 = QtWidgets.QLabel(self.layoutWidget_3)
        self.label_nickname5.setStyleSheet("background: transparent; color: white;")
        self.label_nickname5.setObjectName("label_nickname5")

        self.layoutWidget_4 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget_4.setGeometry(QtCore.QRect(100, 40, 100, 280))
        self.layoutWidget_4.setObjectName("layoutWidget_4")
        self.layoutWidget_4.setStyleSheet("background: transparent; font-size: 34px")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.layoutWidget_4)
        self.verticalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label_literRanking1_2 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_literRanking1_2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking1_2.setObjectName("label_literRanking1_2")
        self.verticalLayout_3.addWidget(self.label_literRanking1_2)
        self.label_literRanking2_2 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_literRanking2_2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking2_2.setObjectName("label_literRanking2_2")
        self.verticalLayout_3.addWidget(self.label_literRanking2_2)
        self.label_literRanking3_2 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_literRanking3_2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking3_2.setObjectName("label_literRanking3_2")
        self.verticalLayout_3.addWidget(self.label_literRanking3_2)
        self.label_literRanking4_2 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_literRanking4_2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking4_2.setObjectName("label_literRanking4_2")
        self.verticalLayout_3.addWidget(self.label_literRanking4_2)
        self.label_literRanking5_2 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_literRanking5_2.setStyleSheet("background: transparent; color: white;")
        self.label_literRanking5_2.setObjectName("label_literRanking5_2")
        self.verticalLayout_3.addWidget(self.label_literRanking5_2)

        self.verticalLayout.addWidget(self.label_nickname5)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(80, 350, 650, 50))
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("color: rgb(255, 255, 255); background: transparent; font: bold")
        self.label_3.setObjectName("label_3")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(80, 400, 650, 50))
        self.label_5.setAutoFillBackground(False)
        self.label_5.setStyleSheet("color: rgb(255, 255, 255); background: transparent; font: bold")
        self.label_5.setObjectName("label_5")
        self.labelMonthlyGoal = QtWidgets.QLabel(self.centralwidget)
        self.labelMonthlyGoal.setGeometry(QtCore.QRect(300, 70, 340, 40))
        self.labelMonthlyGoal.setAlignment(Qt.AlignRight)
        self.labelMonthlyGoal.setStyleSheet("background: transparent; color: white; font-size: 27px")
        self.labelMonthlyGoal.setObjectName("labelMonthlyGoal")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(110, 160, 500, 40))
        self.layoutWidget.setObjectName("layoutWidget")
        self.layoutWidget.setStyleSheet("background: transparent")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.progressBar = QtWidgets.QProgressBar(self.layoutWidget)
        self.progressBar.setStyleSheet("QProgressBar{\n"
"background-color: white;\n"
"border-radius: 12px;\n"
"color: black;\n"
"text-align: center;\n"
"font: bold;\n"
"font-size: 32px\n"
"}\n"
"QProgressBar::chunk {\n"
"background-color: rgb(63, 126, 216);\n"
"border-radius :12px;\n"
"}     ")
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.horizontalLayout_2.addWidget(self.progressBar)
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(80, 70, 350, 40)) 
        self.label_4.setStyleSheet("background: transparent; color: white; font: bold; font-size: 27px")
        self.label_4.setObjectName("label_4")
        self.labelPlasticSaved = QtWidgets.QLabel(self.centralwidget)
        self.labelPlasticSaved.setGeometry(QtCore.QRect(50, 250, 620, 40))
        self.labelPlasticSaved.setAlignment(Qt.AlignCenter)
        self.labelPlasticSaved.setStyleSheet("background: transparent; color: white; font-size: 36px")
        self.labelPlasticSaved.setObjectName("labelPlasticSaved")
        self.label_literRanking1_2.setText(str("1°"))
        self.label_literRanking2_2.setText(str("2°"))
        self.label_literRanking3_2.setText(str("3°"))
        self.label_literRanking4_2.setText(str("4°"))
        self.label_literRanking5_2.setText(str("5°"))
        self.frame = QtWidgets.QFrame(self.centralwidget)
        self.frame.setGeometry(QtCore.QRect(50, 30, 620, 300))
        self.frame.setStyleSheet("border-radius: 15px; background-color:rgb(60,65,70)")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.frame.lower()
        self.frame_2 = QtWidgets.QFrame(self.centralwidget)
        self.frame_2.setGeometry(QtCore.QRect(60, 345, 600, 110))
        self.frame_2.setStyleSheet("border-radius: 15px; background-color:rgb(60,65,70); border: 4px solid white")
        self.frame_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame_2.setObjectName("frame_2")
        self.frame_2.lower()
        MainWindowSplashy.setCentralWidget(self.centralwidget)


        self.retranslateUi(MainWindowSplashy)
        QtCore.QMetaObject.connectSlotsByName(MainWindowSplashy)

        # timer to alternate stats and ranking
        self.timer = QTimer(MainWindowSplashy)
        self.timer.timeout.connect(self.toggle_labels)
        self.timer.start(5000)

        # timer fetch data from NFC reader (making related elements visible or not)
        self.timerNFC = QTimer(MainWindowSplashy)
        self.timerNFC.timeout.connect(self.toggle_labels_NFC)
        self.timerNFC.start(400)

        # timer fetch data from db
        self.timerUpdate = QTimer(MainWindowSplashy)
        self.timerUpdate.timeout.connect(self.updateUi)
        self.timerUpdate.start(200)

    ## @brief Toggles the visibility of certain labels and the progress bar.
    #
    # This method is responsible for controlling the visibility of certain labels and the progress bar in the user interface.
    # If the labelPlasticSaved is visible, it hides the labelPlasticSaved, label_4, progressBar, and labelMonthlyGoal, and shows the labels related to the ranking.
    # If the labelPlasticSaved is not visible, it shows the labelPlasticSaved, label_4, progressBar, and labelMonthlyGoal, and hides the labels related to the ranking.
    # This is useful for switching between different views in the user interface.
    #
    # @param self The instance of the class.
    def toggle_labels(self):
        # Codice per far sparire e apparire le label
        if self.labelPlasticSaved.isVisible():
            self.labelPlasticSaved.hide()
            self.label_4.hide()
            self.progressBar.hide()
            self.labelMonthlyGoal.hide()

            self.label_nickname1.show()
            self.label_nickname2.show()
            self.label_nickname3.show()
            self.label_nickname4.show()
            self.label_nickname5.show()
            self.label_literRanking1.show()
            self.label_literRanking2.show()
            self.label_literRanking3.show()
            self.label_literRanking4.show()
            self.label_literRanking5.show()
            self.label_literRanking1_2.show()
            self.label_literRanking2_2.show()
            self.label_literRanking3_2.show()
            self.label_literRanking4_2.show()
            self.label_literRanking5_2.show()

        else:
            self.labelPlasticSaved.show()
            self.label_4.show()
            self.progressBar.show()
            self.labelMonthlyGoal.show()

            self.label_nickname1.hide()
            self.label_nickname2.hide()
            self.label_nickname3.hide()
            self.label_nickname4.hide()
            self.label_nickname5.hide()
            self.label_literRanking1.hide()
            self.label_literRanking2.hide()
            self.label_literRanking3.hide()
            self.label_literRanking4.hide()
            self.label_literRanking5.hide()
            self.label_literRanking1_2.hide()
            self.label_literRanking2_2.hide()
            self.label_literRanking3_2.hide()
            self.label_literRanking4_2.hide()
            self.label_literRanking5_2.hide()

    ## @brief Toggles the visibility of certain labels and frames related to NFC tag.
    #
    # This method is responsible for controlling the visibility of certain labels and frames in the user interface that are related to the NFC tag.
    # If the user's nickname is empty or None, the labels and frame are hidden. Otherwise, they are shown.
    # This is useful for showing or hiding information based on whether a user is currently identified by an NFC tag.
    #
    # @param self The instance of the class.
    def toggle_labels_NFC(self):    
        # Codice per far sparire e apparire label e frame legati al tag NFC
        if self.userNickname == "" or self.userNickname == None:
            self.label_3.hide()
            self.label_5.hide()   
            self.frame_2.hide() 

        else:
            self.label_3.show()
            self.label_5.show()   
            self.frame_2.show()    
  
    ## @brief Translates the user interface of MainWindowSplashy.
    #
    # This method is responsible for translating the user interface of MainWindowSplashy. It uses the QtCore.QCoreApplication.translate method 
    # to translate the text of various elements in the user interface, such as labels and the window title.
    # The translation is based on the current language setting of the application.
    #
    # @param self The instance of the class.
    # @param MainWindowSplashy The main window of the application, which contains the user interface elements to be translated.
    def retranslateUi(self, MainWindowSplashy):
        _translate = QtCore.QCoreApplication.translate
        MainWindowSplashy.setWindowTitle(_translate("MainWindowSplashy", "MainWindow"))

        self.label_3.setText(_translate("MainWindowSplashy", "WELCOME BACK UserNickname !"))
        self.label_5.setText(_translate("MainWindowSplashy", "#UserPosition with UserTotalLiters L"))
        self.labelPlasticSaved.setText(_translate("MainWindowSplashy", "bottles saved"))
        self.label_4.setText(_translate("MainWindowSplashy", "MONTHLY GOAL:"))
        self.label_literRanking1.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking2.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking3.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking4.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking5.setText(_translate("MainWindowSplashy", "liters"))
        self.label_nickname1.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname2.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname3.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname4.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname5.setText(_translate("MainWindowSplashy", "Name1"))
        self.labelMonthlyGoal.setText(_translate("MainWindowSplashy", "TextLabel"))
    
    ## @brief Updates the user interface with the latest data.
    #
    # This method retrieves data from the database and NFC, calculates some statistics, and updates the user interface with these data.
    # It first defines some constant variables, then reads values from the database and NFC.
    # It gets global information such as the monthly goal, liters of the week, plastic saved, and bottles saved.
    # It also retrieves ranking information and current user information.
    # Finally, it updates the text of the labels, tables, etc. with the retrieved and calculated values.
    #
    # @param self The instance of the class.
    def updateUi(self):
    # define constant variables value

        # read values from database and nfc
        ## get global information
        splashyMonthlyGoal = self.db.liters_montly_goal * self.db.water_plasic_ratio     
        litersOfTheWeek = self.db.getTotalQuantity() * self.db.water_plasic_ratio
        plasticSaved = self.db.getPlasticSaved()
        bottleSaved = plasticSaved / 0.015

        ## get ranking information
        top5 = self.db.getTopK(5)

        firstNickname = top5[0][0]
        secondNickname = top5[1][0]
        thirdNickname = top5[2][0]
        fourthNickname = top5[3][0]
        fifthNickname = top5[4][0]

        firstTotalLiters = top5[0][1]
        secondTotalLiters = top5[1][1]
        thirdTotalLiters = top5[2][1]
        fourthTotalLiters = top5[3][1]
        fifthTotalLiters = top5[4][1]

        ## get current user information
        identification, text = self.nfc.get_user()
        if identification is not None:
            quantity, ranking = self.db.get_user_stats(identification)
            self.userNickname = text
            userTotalLiters = quantity
            userRankingPosition = ranking
        else:
            self.userNickname = ""
            userTotalLiters = 0
            userRankingPosition = -1
        
        # update text of the labels, tables, ecc with the variables value
        
        #progress bar
        self.progressBar.setMaximum(splashyMonthlyGoal)
        self.progressBar.setValue(litersOfTheWeek)

        #labels
        self.labelMonthlyGoal.setText(str(int(splashyMonthlyGoal)) + " kg of plastic")                           
        self.labelPlasticSaved.setText(self.float_to_string(bottleSaved) + " BOTTLES SAVED !")

        #label user
        if userRankingPosition == -1:
            self.label_3.setText("WELCOME " + str(self.userNickname) + "!")
            self.label_5.setText("")
        else:
            self.label_3.setText("WELCOME BACK " + str(self.userNickname) + "!")
            self.label_5.setText(str(userRankingPosition) + "°     with " + self.float_to_string(userTotalLiters) + " L")

    
        #ranking column nickname + " L"
        self.label_nickname1.setText(str(firstNickname))
        self.label_nickname2.setText(str(secondNickname))
        self.label_nickname3.setText(str(thirdNickname))
        self.label_nickname4.setText(str(fourthNickname))
        self.label_nickname5.setText(str(fifthNickname))
        #ranking column totalLiters
        self.label_literRanking1.setText(self.float_to_string(firstTotalLiters) + " L")          
        self.label_literRanking2.setText(self.float_to_string(secondTotalLiters) + " L")
        self.label_literRanking3.setText(self.float_to_string(thirdTotalLiters) + " L")
        self.label_literRanking4.setText(self.float_to_string(fourthTotalLiters) + " L")
        self.label_literRanking5.setText(self.float_to_string(fifthTotalLiters) + " L")

    ## @brief Converts a float value to a string, formatted to two decimal places.
    #
    # This method takes a float value as input and converts it to a string. The float is formatted to two decimal places. 
    # This is useful for displaying float values in a user interface, or when precise control over the formatting is required.
    #
    # @param value The float value to be converted to a string. This should be a valid float. If the input is not a valid float, 
    # the method will raise a ValueError.
    #
    # @return A string representation of the input value, formatted to two decimal places.
    def float_to_string(self, value):
        number = float(value)
        return "{:.2f}".format(number)
        


#if __name__ == "__main__":
#    import sys
#    app = QtWidgets.QApplication(sys.argv)
#    MainWindowSplashy = QtWidgets.QMainWindow()
#    ui = Ui_MainWindowSplashy()
#    ui.setupUi(MainWindowSplashy, None, None)
#    MainWindowSplashy.show()
#    sys.exit(app.exec_())