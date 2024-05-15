# Form implementation generated from reading ui file 'GUIsplashy.ui'


import sys
from PySide2 import QtCore, QtGui, QtWidgets
from PySide2.QtWidgets import QTableWidgetItem

from PySide2.QtCore import QTimer
from PySide2.QtCore import (QCoreApplication, QPropertyAnimation, QDate, QDateTime, QMetaObject, QObject, QPoint, QRect, QSize, QTime, QUrl, Qt, QEvent)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont, QFontDatabase, QIcon, QKeySequence, QLinearGradient, QPalette, QPainter, QPixmap, QRadialGradient, QPen)
from PySide2.QtWidgets import *
  
#python file GUIsplashy.py generated from GUIsplashy.ui 
#USING COMMAND:  
#   cd /home/gianluca/Desktop/splashy/python_env
#   pyuic5 GUIsplashy.ui  -o GUIsplashy.py
##########################################################################################################
class Ui_MainWindowSplashy(object):
    def setupUi(self, MainWindowSplashy):
        MainWindowSplashy.setObjectName("MainWindowSplashy")
        MainWindowSplashy.setEnabled(True)
        MainWindowSplashy.resize(480, 320)
        MainWindowSplashy.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.637368, y2:0.943, stop:0 rgba(127, 163, 216, 255), stop:0.989637 rgba(236, 245, 255, 255))")
        
        self.centralwidget = QtWidgets.QWidget(MainWindowSplashy)
        self.centralwidget.setStyleSheet("background: rgb(46, 52, 54)")
        self.centralwidget.setObjectName("centralwidget")
        
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(50, 230, 231, 31))
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("color: rgb(255, 255, 255); background: transparent")
        self.label_3.setObjectName("label_3")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(50, 260, 231, 31))
        self.label_5.setAutoFillBackground(False)
        self.label_5.setStyleSheet("color: rgb(255, 255, 255); background: transparent")
        self.label_5.setObjectName("label_5")
        
        self.layoutWidget_2 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget_2.setGeometry(QtCore.QRect(310, 40, 61, 161))
        self.layoutWidget_2.setObjectName("layoutWidget_2")
        self.layoutWidget_2.setStyleSheet("background: transparent")
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
        self.layoutWidget_3.setGeometry(QtCore.QRect(150, 40, 121, 161))
        self.layoutWidget_3.setObjectName("layoutWidget_3")
        self.layoutWidget_3.setStyleSheet("background: transparent; font: bold")
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
        self.layoutWidget_4.setGeometry(QtCore.QRect(110, 40, 31, 161))
        self.layoutWidget_4.setObjectName("layoutWidget_4")
        self.layoutWidget_4.setStyleSheet("background: transparent")
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
        self.label_3.setGeometry(QtCore.QRect(50, 230, 231, 31))
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("color: rgb(255, 255, 255); background: transparent; font: bold")
        self.label_3.setObjectName("label_3")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(50, 260, 231, 31))
        self.label_5.setAutoFillBackground(False)
        self.label_5.setStyleSheet("color: rgb(255, 255, 255); background: transparent; font: bold")
        self.label_5.setObjectName("label_5")
        self.labelSplashyWeeklyGoal = QtWidgets.QLabel(self.centralwidget)
        self.labelSplashyWeeklyGoal.setGeometry(QtCore.QRect(280, 60, 60, 25))
        self.labelSplashyWeeklyGoal.setStyleSheet("background: transparent; color: white;")
        self.labelSplashyWeeklyGoal.setObjectName("labelSplashyWeeklyGoal")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(130, 100, 201, 27))
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
"}\n"
"QProgressBar::chunk {\n"
"background-color: rgb(63, 126, 216);\n"
"border-radius :12px;\n"
"}     ")
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.horizontalLayout_2.addWidget(self.progressBar)
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(130, 60, 104, 25))
        self.label_4.setStyleSheet("background: transparent; color: white; font: bold")
        self.label_4.setObjectName("label_4")
        self.labelPlasticSaved = QtWidgets.QLabel(self.centralwidget)
        self.labelPlasticSaved.setGeometry(QtCore.QRect(130, 150, 199, 17))
        self.labelPlasticSaved.setStyleSheet("background: transparent; color: white;")
        self.labelPlasticSaved.setObjectName("labelPlasticSaved")
        self.label_literRanking1_2.setText(str("1°"))
        self.label_literRanking2_2.setText(str("2°"))
        self.label_literRanking3_2.setText(str("3°"))
        self.label_literRanking4_2.setText(str("4°"))
        self.label_literRanking5_2.setText(str("5°"))
        self.frame = QtWidgets.QFrame(self.centralwidget)
        self.frame.setGeometry(QtCore.QRect(80, 30, 311, 181))
        self.frame.setStyleSheet("border-radius: 10px; background-color:rgb(60,65,70)")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.frame.lower()
        self.frame_2 = QtWidgets.QFrame(self.centralwidget)
        self.frame_2.setGeometry(QtCore.QRect(40, 230, 381, 61))
        self.frame_2.setStyleSheet("border-radius: 10px; background-color:rgb(60,65,70)")
        self.frame_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame_2.setObjectName("frame_2")
        self.frame_2.lower()
        MainWindowSplashy.setCentralWidget(self.centralwidget)


        self.retranslateUi(MainWindowSplashy)
        QtCore.QMetaObject.connectSlotsByName(MainWindowSplashy)

        # timer per alternare le label delle stats e del ranking
        self.timer = QTimer(MainWindowSplashy)
        self.timer.timeout.connect(self.toggle_labels)
        self.timer.start(5000)  # Timer ogni 5000 millisecondi (5 secondi)

        # timer per controllare la presenza di un userNickname del tag NFC, facendo apparire e sparire label e frame associati
        self.timerNFC = QTimer(MainWindowSplashy)
        self.timerNFC.timeout.connect(self.toggle_labels_NFC)
        self.timerNFC.start(400)  # Timer ogni 400 millisecondi (0.4 secondi)

        # timer update di variabili e schermata
        self.timerUpdate = QTimer(MainWindowSplashy)
        self.timerUpdate.timeout.connect(self.updateUi)
        self.timerUpdate.start(20)  # Timer ogni 20 millisecondi (0.02 secondi)
        




    def toggle_labels(self):
        # Codice per far sparire e apparire le label
        if self.labelPlasticSaved.isVisible():
            self.labelPlasticSaved.hide()
            self.label_4.hide()
            self.progressBar.hide()
            self.labelSplashyWeeklyGoal.hide()

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
            self.labelSplashyWeeklyGoal.show()

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



    def toggle_labels_NFC(self):    
        # Codice per far sparire e apparire label e frame legati al tag NFC
        if self.userNickname == "":
            self.label_3.hide()
            self.label_5.hide()   
            self.frame_2.hide() 

        else:
            self.label_3.show()
            self.label_5.show()   
            self.frame_2.show()    


        

    def retranslateUi(self, MainWindowSplashy):
        _translate = QtCore.QCoreApplication.translate
        MainWindowSplashy.setWindowTitle(_translate("MainWindowSplashy", "MainWindow"))

        self.label_3.setText(_translate("MainWindowSplashy", "WELCOME BACK UserNickname !"))
        self.label_5.setText(_translate("MainWindowSplashy", "#UserPosition with UserTotalLiters L"))
        self.labelPlasticSaved.setText(_translate("MainWindowSplashy", "kg of plastic saved"))
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
        self.labelSplashyWeeklyGoal.setText(_translate("MainWindowSplashy", "TextLabel"))


    
    #ADDING FUNCTIONALITIES TO THE GUI
    #########################################################################################################################à
    def updateUi(self):
    # define constant variables value

        splashyWeeklyGoal = 1400 #in liters
        waterPlasticRatio = 0.035 #kilograms of plastic per liter of water           1 L (water)≈ 0.035 kg (plastic)

    # read value from fluxometer and RFID sensor
        litersErogated = 1 #readFluxometer()
        userID = 1 #readRFID()

    # update user stats in database
        #userDailyLiters = userDailyLiters + litersErogated
        #userTotalLiters = userTotalLiters + litersErogated

    #QUERY NEEDED
        #firstPlace (nickname, totalLiters)
        #secondPlace (nickname, totalLiters)
        #thirdPlace (nickname, totalLiters)

        #current user (nickname, dailyLiters, totalLiters, rankingPosition)  <-given NFC-ID
        getFromDB = 1

    
    # read values from DataBase ####################################
        litersOfTheWeek = getFromDB  
        totalLiters = getFromDB
        plasticSaved = totalLiters * waterPlasticRatio  

        self.userNickname = getFromDB 
        userTotalLiters = getFromDB
        userRankingPosition = getFromDB

        firstNickname = getFromDB
        secondNickname = getFromDB
        thirdNickname = getFromDB
        fourthNickname = getFromDB
        fifthNickname = getFromDB

        firstTotalLiters = getFromDB 
        secondTotalLiters = getFromDB 
        thirdTotalLiters = getFromDB 
        fourthTotalLiters = getFromDB 
        fifthTotalLiters = getFromDB

        #print("check loop update")


        
    # update text of the labels, tables, ecc with the variables value
        
        #progress bar
        self.progressBar.setMaximum(splashyWeeklyGoal)  # Imposta il valore massimo a 40
        self.progressBar.setValue(litersOfTheWeek)    # Imposta il valore corrente (default è 0)

        #labels
        self.labelSplashyWeeklyGoal.setText(str(splashyWeeklyGoal) + " L")
        self.labelPlasticSaved.setText(str(round(plasticSaved, 4)) + " Kg of PLASTIC SAVED")

        #label user
        self.label_3.setText("WELCOME BACK " + str(self.userNickname) + "!")
        self.label_5.setText(str(userRankingPosition) + "°     with " + str(userTotalLiters) + " L")

    
        #ranking column nickname + " L"
        self.label_nickname1.setText(str(firstNickname))
        self.label_nickname2.setText(str(secondNickname))
        self.label_nickname3.setText(str(thirdNickname))
        self.label_nickname4.setText(str(fourthNickname))
        self.label_nickname5.setText(str(fifthNickname))
        #ranking column totalLiters
        self.label_literRanking1.setText(str(firstTotalLiters) + " L")
        self.label_literRanking2.setText(str(secondTotalLiters) + " L")
        self.label_literRanking3.setText(str(thirdTotalLiters) + " L")
        self.label_literRanking4.setText(str(fourthTotalLiters) + " L")
        self.label_literRanking5.setText(str(fifthTotalLiters) + " L")
        


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindowSplashy = QtWidgets.QMainWindow()
    ui = Ui_MainWindowSplashy()
    ui.setupUi(MainWindowSplashy)
    MainWindowSplashy.show()
    sys.exit(app.exec_())
