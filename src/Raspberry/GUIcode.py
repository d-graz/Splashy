# Form implementation generated from reading ui file 'GUIsplashy.ui'


import sys
from PySide6 import QtCore, QtGui, QtWidgets
from PySide6.QtWidgets import QTableWidgetItem

from PySide6.QtCore import (QCoreApplication, QPropertyAnimation, QDate, QDateTime, QMetaObject, QObject, QPoint, QRect, QSize, QTime, QUrl, Qt, QEvent)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont, QFontDatabase, QIcon, QKeySequence, QLinearGradient, QPalette, QPainter, QPixmap, QRadialGradient, QPen)
from PySide6.QtWidgets import *
  
#IMPORT PYSIDE2EXTN WIDGET YOU USED IN THE QTDESIGNER FOR DESIGNING.
from PySide2extn.RoundProgressBar import roundProgressBar

#python file GUIsplashy.py generated from GUIsplashy.ui 
#USING COMMAND:  
#   cd /home/gianluca/Desktop/splashy/python_env
#   pyuic5 GUIsplashy.ui  -o GUIsplashy.py
##########################################################################################################


class Ui_MainWindowSplashy(object):
    def setupUi(self, MainWindowSplashy):
        MainWindowSplashy.setObjectName("MainWindowSplashy")
        MainWindowSplashy.resize(800, 406)
        MainWindowSplashy.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.637368, y2:0.943, stop:0 rgba(127, 163, 216, 255), stop:0.989637 rgba(236, 245, 255, 255))")
        self.centralwidget = QtWidgets.QWidget(MainWindowSplashy)
        self.centralwidget.setStyleSheet("background: rgb(85, 87, 83)")
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(20, 20, 211, 17))
        self.label.setStyleSheet("background: transparent")
        self.label.setObjectName("label")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(450, 320, 231, 31))
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("color: rgb(255, 255, 255); background: transparent")
        self.label_3.setObjectName("label_3")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(390, 80, 283, 27))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_4 = QtWidgets.QLabel(self.layoutWidget)
        self.label_4.setStyleSheet("")
        self.label_4.setObjectName("label_4")
        self.horizontalLayout.addWidget(self.label_4)
        self.progressBar = QtWidgets.QProgressBar(self.layoutWidget)
        self.progressBar.setStyleSheet("background: white")
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.horizontalLayout.addWidget(self.progressBar)
        self.labelSplashyWeeklyGoal = QtWidgets.QLabel(self.layoutWidget)
        self.labelSplashyWeeklyGoal.setStyleSheet("background: transparent")
        self.labelSplashyWeeklyGoal.setObjectName("labelSplashyWeeklyGoal")
        self.horizontalLayout.addWidget(self.labelSplashyWeeklyGoal)
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(450, 350, 231, 31))
        self.label_5.setAutoFillBackground(False)
        self.label_5.setStyleSheet("color: rgb(255, 255, 255); background: transparent")
        self.label_5.setObjectName("label_5")
        self.labelPlasticSaved = QtWidgets.QLabel(self.centralwidget)
        self.labelPlasticSaved.setGeometry(QtCore.QRect(390, 140, 170, 17))
        self.labelPlasticSaved.setStyleSheet("background: transparent")
        self.labelPlasticSaved.setObjectName("labelPlasticSaved")
        self.horizontalLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(30, 60, 301, 230))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_nickname1 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_nickname1.setStyleSheet("background: transparent")
        self.label_nickname1.setObjectName("label_nickname1")
        self.verticalLayout.addWidget(self.label_nickname1)
        self.label_nickname2 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_nickname2.setStyleSheet("background: transparent")
        self.label_nickname2.setObjectName("label_nickname2")
        self.verticalLayout.addWidget(self.label_nickname2)
        self.label_nickname3 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_nickname3.setStyleSheet("background: transparent")
        self.label_nickname3.setObjectName("label_nickname3")
        self.verticalLayout.addWidget(self.label_nickname3)
        self.label_nickname4 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_nickname4.setStyleSheet("background: transparent")
        self.label_nickname4.setObjectName("label_nickname4")
        self.verticalLayout.addWidget(self.label_nickname4)
        self.label_nickname5 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_nickname5.setStyleSheet("background: transparent")
        self.label_nickname5.setObjectName("label_nickname5")
        self.verticalLayout.addWidget(self.label_nickname5)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_literRanking1 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_literRanking1.setStyleSheet("background: transparent")
        self.label_literRanking1.setObjectName("label_literRanking1")
        self.verticalLayout_2.addWidget(self.label_literRanking1)
        self.label_literRanking2 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_literRanking2.setStyleSheet("background: transparent")
        self.label_literRanking2.setObjectName("label_literRanking2")
        self.verticalLayout_2.addWidget(self.label_literRanking2)
        self.label_literRanking3 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_literRanking3.setStyleSheet("background: transparent")
        self.label_literRanking3.setObjectName("label_literRanking3")
        self.verticalLayout_2.addWidget(self.label_literRanking3)
        self.label_literRanking4 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_literRanking4.setStyleSheet("background: transparent")
        self.label_literRanking4.setObjectName("label_literRanking4")
        self.verticalLayout_2.addWidget(self.label_literRanking4)
        self.label_literRanking5 = QtWidgets.QLabel(self.horizontalLayoutWidget)
        self.label_literRanking5.setStyleSheet("background: transparent")
        self.label_literRanking5.setObjectName("label_literRanking5")
        self.verticalLayout_2.addWidget(self.label_literRanking5)
        self.horizontalLayout_2.addLayout(self.verticalLayout_2)
        MainWindowSplashy.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindowSplashy)
        QtCore.QMetaObject.connectSlotsByName(MainWindowSplashy)

    def retranslateUi(self, MainWindowSplashy):
        _translate = QtCore.QCoreApplication.translate
        MainWindowSplashy.setWindowTitle(_translate("MainWindowSplashy", "MainWindow"))
        self.label.setText(_translate("MainWindowSplashy", "RANKING OF THE WEEK"))
        self.label_3.setText(_translate("MainWindowSplashy", "WELCOME BACK UserNickname !"))
        self.label_4.setText(_translate("MainWindowSplashy", "MONTHLY GOAL"))
        self.labelSplashyWeeklyGoal.setText(_translate("MainWindowSplashy", "TextLabel"))
        self.label_5.setText(_translate("MainWindowSplashy", "#UserPosition with UserTotalLiters L"))
        self.labelPlasticSaved.setText(_translate("MainWindowSplashy", "kg of plastic saved"))
        self.label_nickname1.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname2.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname3.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname4.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_nickname5.setText(_translate("MainWindowSplashy", "Name1"))
        self.label_literRanking1.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking2.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking3.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking4.setText(_translate("MainWindowSplashy", "liters"))
        self.label_literRanking5.setText(_translate("MainWindowSplashy", "liters"))


    #ADDING FUNCTIONALITIES TO THE GUI
    #########################################################################################################################à
    # define constant variables value

        splashyWeeklyGoal = 1400 #in liters
        waterPlasticRatio = 0.2 #kilograms of plastic per liter of water

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
        plasticSaved = 0
        plasticSaved = plasticSaved + litersErogated * waterPlasticRatio

        userNickname = getFromDB
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


        
    # update text of the labels, tables, ecc with the variables value
        
        #progress bar
        self.progressBar.setMaximum(splashyWeeklyGoal)  # Imposta il valore massimo a 40
        self.progressBar.setValue(litersOfTheWeek)    # Imposta il valore corrente (default è 0)

        #labels
        self.labelSplashyWeeklyGoal.setText(str(splashyWeeklyGoal) + "L")
        self.labelPlasticSaved.setText(str(plasticSaved) + "Kg of PLASTIC SAVED")

        #label user
        self.label_3.setText("WELCOME BACK " + str(userNickname) + "!")
        self.label_5.setText("#" + str(userRankingPosition) + " with " + str(userTotalLiters) + "L")

    
        #ranking column nickname
        self.label_nickname1.setText(str(firstNickname))
        self.label_nickname2.setText(str(secondNickname))
        self.label_nickname3.setText(str(thirdNickname))
        self.label_nickname4.setText(str(fourthNickname))
        self.label_nickname5.setText(str(fifthNickname))
        #ranking column totalLiters
        self.label_literRanking1.setText(str(firstTotalLiters))
        self.label_literRanking2.setText(str(secondTotalLiters))
        self.label_literRanking3.setText(str(thirdTotalLiters))
        self.label_literRanking4.setText(str(fourthTotalLiters))
        self.label_literRanking5.setText(str(fifthTotalLiters))
        

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindowSplashy = QtWidgets.QMainWindow()
    ui = Ui_MainWindowSplashy()
    ui.setupUi(MainWindowSplashy)
    MainWindowSplashy.show()
    sys.exit(app.exec())
